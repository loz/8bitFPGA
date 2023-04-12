// Ported From:
// Project F: Framebuffers - 16 Colour David (iCEBreaker 12-bit DVI Pmod)
// (C)2022 Will Green, open source hardware released under the MIT License
// Learn more at https://projectf.io/posts/framebuffers/

`default_nettype none
`timescale 1ns / 1ps

module david_scaled (
    input  wire logic clk,      		    // 50 MHz clock
    input  wire logic rst_n,            // reset button
    output      logic vga_out_hs,       // VGA horizontal sync
    output      logic vga_out_vs,       // VGA vertical sync
    //output    logic dvi_de,         // DVI data enable
    output      logic [4:0] vga_out_r,  // 4-bit VGA red
    output      logic [5:0] vga_out_g,  // 4-bit VGA green
    output      logic [4:0] vga_out_b   // 4-bit VGA blue
    );

    // display sync signals and coordinates
    localparam CORDW = 11;  // screen coordinate width in bits
    logic signed [CORDW-1:0] sx, sy;
    logic hsync, vsync;
	 logic de, frame, line;
	 
	 assign vga_out_hs = hsync;
	 assign vga_out_vs = vsync;
	 wire clk_pix;
	 wire clk_sys;
	 logic rst_pix;
	 assign clk_sys = clk;
	 
	 logic clk_pix_locked;
	
	 //generate video pixel clock
	 videopll_49 video_pll_m0(
		.inclk0(clk),
		.c0(clk_pix),
		.locked(clk_pix_locked)
	);
	
	 display_1024_600 display_inst(
		.clk_pix(clk_pix),   				// pixel clock
		.rst_pix(~rst_n),   // reset in pixel clock domain
		.sx,  				// horizontal screen position
		.sy, 					// vertical screen position
		.frame,
		.line,
		.hsync,     		// horizontal sync
		.vsync,     		// vertical sync
		.de         		// data enable (low in blanking interval)
    );
	 always_ff @(posedge clk_pix) rst_pix <= !clk_pix_locked;  // wait for clock lock

    // library resource path
    localparam LIB_RES = "../res";

    // bitmap images
    localparam BMAP_IMAGE = "../res/david.mem";
    // localparam BMAP_IMAGE = {LIB_RES,"/test/test_box_160x120.mem"};

    // colour palettes
    localparam PAL_FILE = "../res/grey16_4b.mem";
    // localparam PAL_FILE = {LIB_RES,"/palettes/greyinvert16_4b.mem"};
    // localparam PAL_FILE = {LIB_RES,"/palettes/sepia16_4b.mem"};
    // localparam PAL_FILE = {LIB_RES,"/palettes/sweetie16_4b.mem"};

    // colour parameters
    localparam CHANW = 4;        // colour channel width (bits)
    localparam COLRW = 3*CHANW;  // colour width: three channels (bits)
    localparam CIDXW = 4;        // colour index width (bits)

	 // framebuffer (FB)
    localparam FB_WIDTH  = 160;  // framebuffer width in pixels
    localparam FB_HEIGHT = 120;  // framebuffer height in pixels
    localparam FB_SCALE  =   5;  // framebuffer display scale (1-63)
    localparam FB_PIXELS = FB_WIDTH * FB_HEIGHT;  // total pixels in buffer
    localparam FB_ADDRW  = $clog2(FB_PIXELS);  // address width
    localparam FB_DATAW  = CIDXW;  // colour bits per pixel

    // pixel read address and colour
    logic [FB_ADDRW-1:0] fb_addr_read;
    logic [FB_DATAW-1:0] fb_colr_read;

   // framebuffer memory
    bram_sdp #(
        .WIDTH(FB_DATAW),
        .DEPTH(FB_PIXELS),
        .INIT_F(BMAP_IMAGE)
    ) bram_inst (
        .clk_write(clk_sys),
        .clk_read(clk_sys),
        .we(),
        .addr_write(),
        .addr_read(fb_addr_read),
        .data_in(),
        .data_out(fb_colr_read)
    );

    // display flags in system clock domain
    logic frame_sys, line_sys, line0_sys;
    xd xd_frame (.clk_src(clk_pix), .clk_dst(clk_sys),
        .flag_src(frame), .flag_dst(frame_sys));
    xd xd_line  (.clk_src(clk_pix), .clk_dst(clk_sys),
        .flag_src(line),  .flag_dst(line_sys));
    xd xd_line0 (.clk_src(clk_pix), .clk_dst(clk_sys),
        .flag_src(line && sy==0), .flag_dst(line0_sys));

    // count lines for scaling via linebuffer
    logic [$clog2(FB_SCALE):0] cnt_lb_line;
    always_ff @(posedge clk_sys) begin
        if (line0_sys) cnt_lb_line <= 0;
        else if (line_sys) begin
            cnt_lb_line <= (cnt_lb_line == FB_SCALE-1) ? 0 : cnt_lb_line + 1;
        end
    end

    // which screen lines need linebuffer?
    logic lb_line;
    always_ff @(posedge clk_sys) begin
        if (line0_sys) lb_line <= 1;  // enable from sy==0
        if (frame_sys) lb_line <= 0;  // disable at frame start
    end

    // enable linebuffer input
    logic lb_en_in;
    logic [$clog2(FB_WIDTH)-1:0] cnt_lbx;  // horizontal pixel counter
    always_comb lb_en_in = (lb_line && cnt_lb_line == 0 && cnt_lbx < FB_WIDTH);

    // calculate framebuffer read address for linebuffer
    always_ff @(posedge clk_sys) begin
        if (line_sys) begin  // reset horizontal counter at start of line
            cnt_lbx <= 0;
        end else if (lb_en_in) begin  // increment address when LB enabled
            fb_addr_read <= fb_addr_read + 1;
            cnt_lbx <= cnt_lbx + 1;
        end
        if (frame_sys) fb_addr_read <= 0;  // reset address at frame start
    end

    // enable linebuffer output
    logic lb_en_out;
    localparam LAT_LB = 3;  // output latency compensation: lb_en_out+1, LB+1, CLUT+1
    always_ff @(posedge clk_pix) begin
        lb_en_out <= (sy >= 0 && sy < (FB_HEIGHT * FB_SCALE)
            && sx >= -LAT_LB && sx < (FB_WIDTH * FB_SCALE) - LAT_LB);
    end

    // display linebuffer
    logic [FB_DATAW-1:0] lb_colr_out;
    linebuffer_simple #(
        .DATAW(FB_DATAW),
        .LEN(FB_WIDTH)
    ) linebuffer_instance (
        .clk_sys,
        .clk_pix,
        .line,
        .line_sys,
        .en_in(lb_en_in),
        .en_out(lb_en_out),
        .scale(FB_SCALE),
        .data_in(fb_colr_read),
        .data_out(lb_colr_out)
    );

    // colour lookup table (CLUT)
    logic [COLRW-1:0] fb_pix_colr;
    clut_simple #(
        .COLRW(COLRW),
        .CIDXW(CIDXW),
        .F_PAL(PAL_FILE)
        ) clut_instance (
        .clk_write(clk_pix),
        .clk_read(clk_pix),
        .we(0),
        .cidx_write(0),
        .cidx_read(lb_colr_out),
        .colr_in(0),
        .colr_out(fb_pix_colr)
    );

    // paint screen
    logic paint_area;  // area of screen to paint
    logic [CHANW-1:0] paint_r, paint_g, paint_b;  // colour channels
    always_comb begin
        paint_area = (sy >= 0 && sy < (FB_HEIGHT * FB_SCALE)
            && sx >= 0 && sx < FB_WIDTH * FB_SCALE);
        {paint_r, paint_g, paint_b} = (de && paint_area) ? fb_pix_colr : 12'h000;
    end
	 
    always_comb begin
        vga_out_r = (de) ? (sy % 2 == 0 ? {1'b0, paint_r>>1} : {1'b0, paint_r} ): 5'h0;
        vga_out_g = (de) ? (sy % 2 == 0 ? {1'b0, paint_g>>1,1'b0} : {1'b0, paint_g,1'b0} ): 5'h0;
        vga_out_b = (de) ? (sy % 2 == 0 ? {1'b0, paint_b>>1} : {1'b0, paint_b} ): 5'h0;
    end
endmodule