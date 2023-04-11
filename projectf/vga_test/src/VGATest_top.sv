// Project F: FPGA Graphics - ported from iCEBreaker

`default_nettype none
`timescale 1ns / 1ps

module VGATest_top (
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
    logic hsync, vsync, de;
	 
	 assign vga_out_hs = hsync;
	 assign vga_out_vs = vsync;
	 wire video_clk;
	 
	 //generate video pixel clock
	 videopll_49 video_pll_m0(
		.inclk0(clk),
		.c0(video_clk)
	);
	
	 display_1024_600 display_inst(
		.clk_pix(video_clk),   				// pixel clock
		.rst_pix(~rst_n),   // reset in pixel clock domain
		.sx,  				// horizontal screen position
		.sy,  				// vertical screen position
		.hsync,     		// horizontal sync
		.vsync,     		// vertical sync
		.de         		// data enable (low in blanking interval)
    );
	 
	 //these are visible for 1024x768 on my ali LCD
	 /*
	 localparam START_X = 1;
	 localparam END_X = 990;
	 localparam START_Y = 0;
	 localparam END_Y = 766;
	 */
	 
	 localparam START_X = 0;
	 localparam END_X = 1023;
	 localparam START_Y = 0;
	 localparam END_Y = 599;

    // define a square with screen coordinates
    logic square;
    always_comb begin
			//990/2 +/- 100
			//766/2 +/- 100
        square = (sx > 412 && sx < 612) && (sy > 200 && sy < 400);
    end

    // paint colour: white inside square, blue outside
    logic [5:0] paint_r, paint_g, paint_b;
    always_comb begin
        paint_r = (square) ? 4'hF : (sx == START_X || sy == START_Y) ? 4'hF: 4'h1;
        paint_g = (square) ? 5'b11111 : 5'h3;
        paint_b = (square) ? 4'hF : (sx == END_X || sy == END_Y) ? 4'hF : 4'h7;
    end

    // display colour: paint colour but black in blanking interval
    //logic [3:0] display_r, display_g, display_b;
    always_comb begin
        vga_out_r = (de) ? paint_r[4:0] : 5'h0;
        vga_out_g = (de) ? paint_g[5:0] : 5'h0;
        vga_out_b = (de) ? paint_b[4:0] : 5'h0;
    end
endmodule
