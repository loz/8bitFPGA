// Ported From:
// Project F: Framebuffers - 16 Colour David (iCEBreaker 12-bit DVI Pmod)
// (C)2022 Will Green, open source hardware released under the MIT License
// Learn more at https://projectf.io/posts/framebuffers/

`default_nettype none
`timescale 1ns / 1ps

module hedgehog (
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
    localparam CORDW = 12;  // screen coordinate width in bits
    logic signed [CORDW-1:0] sx, sy;
    logic hsync, vsync, de, line;
	 
	 assign vga_out_hs = hsync;
	 assign vga_out_vs = vsync;
	 wire clk_pix;
	 wire rst_pix;
	 wire frame;
	 
	 assign rst_pix = ~rst_n;
	 
	 //generate video pixel clock
	 videopll_49 video_pll_m0(
		.inclk0(clk),
		.c0(clk_pix)
	);
	
	 display_1024_600 #(
		.CORDW(CORDW)
	 ) display_inst (
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


// screen dimensions (must match display_inst)
    localparam H_RES = 1024;

    // colour parameters
    localparam CHANW = 4;         // colour channel width (bits)
    localparam COLRW = 3*CHANW;   // colour width: three channels (bits)
    localparam CIDXW = 4;         // colour index width (bits)
    localparam TRANS_INDX = 'h9;  // transparant colour index
    localparam PAL_FILE = "../res/hedgehog_4b.mem";  // palette file
 
    // sprite parameters
    localparam SX_OFFS    =  3;  // horizontal screen offset (pixels): +1 for CLUT
    localparam SPR_WIDTH  = 32;  // bitmap width in pixels
    localparam SPR_HEIGHT = 20;  // bitmap height in pixels
    localparam SPR_SCALE  =  2;  // 2^2 = 4x scale
    localparam SPR_DRAWW  = SPR_WIDTH * 2**SPR_SCALE;  // draw width
    localparam SPR_SPX    =  2;  // horizontal speed (pixels/frame)
    localparam SPR_FILE   = "../res/hedgehog.mem";  // bitmap file

    logic signed [CORDW-1:0] sprx, spry;  // draw sprite at position (sprx,spry)

    // update sprite position once per frame
    always_ff @(posedge clk_pix) begin
        if (frame) begin
            if (sprx <= -SPR_DRAWW) sprx <= H_RES;  // move back to right of screen
            else sprx <= sprx - SPR_SPX;  // otherwise keep moving left
        end
        if (rst_pix) begin  // start off screen and level with grass
            sprx <= H_RES;
            spry <= 240;
        end
    end

    logic drawing;  // drawing at (sx,sy)
    logic [CIDXW-1:0] spr_pix_indx;  // pixel colour index
    sprite #(
        .CORDW(CORDW),
        .H_RES(H_RES),
        .SX_OFFS(SX_OFFS),
        .SPR_FILE(SPR_FILE),
        .SPR_WIDTH(SPR_WIDTH),
        .SPR_HEIGHT(SPR_HEIGHT),
        .SPR_SCALE(SPR_SCALE),
        .SPR_DATAW(CIDXW)
        ) sprite_hedgehog (
        .clk(clk_pix),
        .rst(rst_pix),
        .line,
        .sx,
        .sy,
        .sprx,
        .spry,
        .pix(spr_pix_indx),
        .drawing
    );

    // colour lookup table
    logic [COLRW-1:0] spr_pix_colr;
    clut_simple #(
        .COLRW(COLRW),
        .CIDXW(CIDXW),
        .F_PAL(PAL_FILE)
        ) clut_instance (
        .clk_write(clk_pix),
        .clk_read(clk_pix),
        .we(0),
        .cidx_write(0),
        .cidx_read(spr_pix_indx),
        .colr_in(0),
        .colr_out(spr_pix_colr)
    );

    // account for transparency and delay drawing signal to match CLUT delay (1 cycle)
    logic drawing_t1;
    always_ff @(posedge clk_pix) drawing_t1 <= drawing && (spr_pix_indx != TRANS_INDX);

	 
    // background colour
    logic [COLRW-1:0] bg_colr;
    always_ff @(posedge clk_pix) begin
        if (line) begin
            if      (sy == 0)   bg_colr <= 12'h239;
            else if (sy == 80)  bg_colr <= 12'h24A;
            else if (sy == 140) bg_colr <= 12'h25B;
            else if (sy == 190) bg_colr <= 12'h26C;
            else if (sy == 230) bg_colr <= 12'h27D;
            else if (sy == 265) bg_colr <= 12'h29E;
            else if (sy == 295) bg_colr <= 12'h2BF;
            else if (sy == 320) bg_colr <= 12'h260;
        end
    end
	 
    // paint colour: sprite or background
    logic [CHANW-1:0] paint_r, paint_g, paint_b;
    always_comb {paint_r, paint_g, paint_b} = (drawing_t1) ? spr_pix_colr : bg_colr;
	 
    always_comb begin
        vga_out_r = (de) ? {1'b0, paint_r} : 5'h0;
        vga_out_g = (de) ? {1'b0, paint_g, 1'b0} : 5'h0;
        vga_out_b = (de) ? {1'b0, paint_b} : 5'h0;
    end
endmodule