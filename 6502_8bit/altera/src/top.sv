// Project F: FPGA Graphics - ported from iCEBreaker

`default_nettype none
`timescale 1ns / 1ps

module top (
    input  wire logic clk,      		    // 50 MHz clock
    input  wire logic rst_n,            // reset button
    output      logic vga_out_hs,       // VGA horizontal sync
    output      logic vga_out_vs,       // VGA vertical sync
    //output    logic dvi_de,         // DVI data enable
    output      logic [4:0] vga_out_r,  // 4-bit VGA red
    output      logic [5:0] vga_out_g,  // 4-bit VGA green
    output      logic [4:0] vga_out_b   // 4-bit VGA blue
    );

	 
	 ppu_char ttop(
		.clk,
		.rst_n,
		.vga_out_hs,
		.vga_out_vs,
		.vga_out_r,
		.vga_out_g,
		.vga_out_b
	);
endmodule
