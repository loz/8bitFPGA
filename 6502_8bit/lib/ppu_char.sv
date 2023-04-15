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
    input [7:0] vidmem[4096], //Optional, if not RAMOUT
	 output [14:0] vid_address,
	 input  [7:0]  vid_data,
    output [CHANW-1:0] paint_r,
    output [CHANW-1:0] paint_g,
    output [CHANW-1:0] paint_b
    );

    // colour parameters
    localparam COLRW = 3*CHANW;   // colour width: three channels (bits)
	 
	 localparam TEXTCOL = (1024 / 8)/2 ;
	 localparam TEXTROW = (600 / 8) / 2;
	 localparam TEXT_W = $clog2(TEXTCOL+1);
	 localparam TEXT_H = $clog2(TEXTROW+1);
	 
	 localparam BUFFSIZE = (TEXTCOL*TEXTROW);

	 logic [TEXT_W-1:0] text_column;
	 logic [TEXT_H-1:0] text_row;
	 
	 assign text_column = ((sx>>1) / 8); //Scaled by 2x
	 assign text_row =    ((sy>>1) / 8);
	 
	 logic [8:0] char;

	 localparam VIDEO_RAM = 'h1000;
	 assign char = ((text_row >= TEXTROW) ? " " : vid_data);
	 assign vid_address = VIDEO_RAM + ((text_row * TEXTCOL) + text_column);

	 wire bitmap;
	 charmap font_map(
		.char(char),
		.xoffset((sx>>1) % 8),
		.yoffset((sy>>1) % 8),
		.bitmap
	 );

    always_comb {paint_r, paint_g, paint_b} = (bitmap) ? 12'hFFF : 12'd0 ;
	 
endmodule