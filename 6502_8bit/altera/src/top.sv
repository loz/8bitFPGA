// Project F: FPGA Graphics - ported from iCEBreaker

`default_nettype none
`timescale 1ns / 1ps

module top #(parameter CORDW=12) (
    input  wire logic clk,      		    // 50 MHz clock
    input  wire logic rst_n,            // reset button
    output      logic vga_out_hs,       // VGA horizontal sync
    output      logic vga_out_vs,       // VGA vertical sync
    //output    logic dvi_de,         // DVI data enable
    output      logic [4:0] vga_out_r,  // 4-bit VGA red
    output      logic [5:0] vga_out_g,  // 4-bit VGA green
    output      logic [4:0] vga_out_b   // 4-bit VGA blue
    );
	 
	 wire clk_pix;
	 wire rst_pix;
	 assign rst_pix = ~rst_n;
	 
	 //generate video pixel clock

	 videopll_49 video_pll_m0(
		.inclk0(clk),
		.c0(clk_pix)
	);
	 
    // display sync signals and coordinates
    logic signed [CORDW-1:0] sx, sy;
    logic de, line, frame;
    display_1024_600 display_inst (
        .clk_pix,
        .rst_pix(rst_pix),
        .sx(sx),
        .sy(sy),
        .line(line),
        .frame(frame),
        .hsync(vga_out_hs),
        .vsync(vga_out_vs),
        .de(de)
    );
	 
   // paint colours: white inside square, blue outside
    logic [3:0] paint_r, paint_g, paint_b;
    ppu_char ppu (
        .clk(clk_pix),
        .rst_n(~rst_pix),
        .sx,
        .sy,
        .line,
        .frame,
        .de,
        .paint_r,
        .paint_g,
        .paint_b
    );
	 
    always_comb begin
        vga_out_r = (de) ? {1'b0, paint_r} : 5'h0;
        vga_out_g = (de) ? {1'b0, paint_g, 1'b0} : 5'h0;
        vga_out_b = (de) ? {1'b0, paint_b} : 5'h0;
    end
	 
endmodule
