`default_nettype none
`timescale 1ns / 1ps

module ppu_char #(
    CORDW=12,    // signed coordinate width (bits)
    H_RES=1024,  // horizontal resolution (pixels)
    V_RES=600,   // vertical resolution (lines)
	CHANW = 4
	)(
    input  wire logic clk,      		    // 50 MHz clock
    input  wire logic rst_n,            // reset button
    input logic signed [CORDW-1:0] sx,
    input logic signed [CORDW-1:0] sy,
    input line,
    input frame,
    input de,
    output [CHANW-1:0] paint_r,
    output [CHANW-1:0] paint_g,
    output [CHANW-1:0] paint_b
	/*
    output      logic vga_out_hs,       // VGA horizontal sync
    output      logic vga_out_vs,       // VGA vertical sync
    //output    logic dvi_de,         // DVI data enable
    output      logic [4:0] vga_out_r,  // 4-bit VGA red
    output      logic [5:0] vga_out_g,  // 4-bit VGA green
    output      logic [4:0] vga_out_b   // 4-bit VGA blue
	*/
    );

    // colour parameters
    localparam COLRW = 3*CHANW;   // colour width: three channels (bits)
	 
	 localparam TEXTCOL = (1024 / 8)/2 ;
	 localparam TEXTROW = (600 / 8) / 2;
	 localparam TEXT_W = $clog2(TEXTCOL+1);
	 localparam TEXT_H = $clog2(TEXTROW+1);
	 
	 localparam BUFFSIZE = (TEXTCOL*TEXTROW);
	 reg [7:0]text_buffer[TEXTCOL*TEXTROW];

	 logic [TEXT_W-1:0] text_column;
	 logic [TEXT_H-1:0] text_row;
	 
	 assign text_column = ((sx>>1) / 8); //Scaled by 2x
	 assign text_row =    ((sy>>1) / 8);
	 
	 logic [8:0] char;

	 assign char = (text_row >= TEXTROW) ? " " : text_buffer[((text_row * TEXTCOL) + text_column)];
	 
	 initial begin
		for(int i=0;i<BUFFSIZE;i=i+1) begin
			text_buffer[i] = " ";
		end
		text_buffer[00] = "T";
		text_buffer[01] = "h";
		text_buffer[02] = "i";
		text_buffer[03] = "s";
		text_buffer[04] = " ";
		text_buffer[05] = "i";
		text_buffer[06] = "s";
		text_buffer[07] = " ";
		text_buffer[08] = "a";
		text_buffer[09] = " ";
		text_buffer[10] = "m";
		text_buffer[11] = "e";
		text_buffer[12] = "s";
		text_buffer[13] = "s";
		text_buffer[14] = "a";
		text_buffer[15] = "g";
		text_buffer[16] = "e";
		text_buffer[17] = " ";
		text_buffer[18] = "i";
		text_buffer[19] = "n";
		text_buffer[20] = " ";
		text_buffer[21] = "t";
		text_buffer[22] = "h";
		text_buffer[23] = "e";
		text_buffer[24] = " ";
		text_buffer[25] = "b";
		text_buffer[26] = "u";
		text_buffer[27] = "f";
		text_buffer[28] = "f";
		text_buffer[29] = "e";
		text_buffer[30] = "r";
		text_buffer[31] = "!";

   	for(int i=0;i<100;i=i+1) begin
			text_buffer[80+i] = i+30;
		end
	end
	 
	 wire bitmap;
	 charmap font_map(
		.char(char),
		.xoffset((sx>>1) % 8),
		.yoffset((sy>>1) % 8),
		.bitmap
	 );

    always_comb {paint_r, paint_g, paint_b} = (bitmap) ? 12'hFFF : 12'd0 ;
	 
endmodule