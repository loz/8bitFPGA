`default_nettype none
`timescale 1ns / 1ps

module ppu_char (
    input  wire logic clk,      		    // 50 MHz clock
    input  wire logic rst_n,            // reset button
    output      logic vga_out_hs,       // VGA horizontal sync
    output      logic vga_out_vs,       // VGA vertical sync
    //output    logic dvi_de,         // DVI data enable
    output      logic [4:0] vga_out_r,  // 4-bit VGA red
    output      logic [5:0] vga_out_g,  // 4-bit VGA green
    output      logic [4:0] vga_out_b   // 4-bit VGA blue
    );

    // colour parameters
    localparam CHANW = 4;         // colour channel width (bits)
    localparam COLRW = 3*CHANW;   // colour width: three channels (bits)
	 
	 localparam TEXTCOL = (1024 / 8)/2 ;
	 localparam TEXTROW = (300 / 8) / 2;
	 localparam TEXT_W = $clog2(TEXTCOL);
	 localparam TEXT_H = $clog2(TEXTROW);
	 
    // display sync signals and coordinates
    localparam CORDW = 11;  // screen coordinate width in bits
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

    // background colour
	 logic [TEXT_W-1:0] text_column;
	 logic [TEXT_H-1:0] text_row;
	 logic [TEXT_W-1:0] last_column = 0;
	 logic [TEXT_H-1:0] last_row = 0;
	 
	 assign text_column = ((sx>>1) / 8); //Scaled by 2x
	 assign text_row =    ((sy>>1) / 8);
	 
	 logic [8:0] char;
	 
    logic [COLRW-1:0] bg_colr;
	 logic [1:0] shade;
	 localparam MESSAGE = "!This is a Message$$ ";
	 //assign char = text_column+30; //MESSAGE[(text_column * text_row) % 20];
	 assign char = ((text_row * TEXTROW) + text_column) % 128;
	 
	 /*
		if(last_row != text_row) begin
			last_row <= text_row;
		end else if(last_column != text_column) begin
			if (text_column == 0)
				shade <= text_row;
			else
				shade <= shade + 1;
			last_column <= text_column;
		end
		case(shade)
			0: char <= "!";
			1: char <= " ";
			2: char <= "$";
			3: char <= "#";
		endcase
    end
	 */
	 
	 wire bitmap;
	 charmap font_map(
		.char(char),
		.xoffset((sx>>1) % 8),
		.yoffset((sy>>1) % 8),
		.bitmap
	 );
	 
    // paint colour: sprite or background
    logic [CHANW-1:0] paint_r, paint_g, paint_b;
    always_comb {paint_r, paint_g, paint_b} = (bitmap) ? 12'hFFFF : 12'd0 ;
	 
    always_comb begin
        vga_out_r = (de) ? {1'b0, paint_r} : 5'h0;
        vga_out_g = (de) ? {1'b0, paint_g, 1'b0} : 5'h0;
        vga_out_b = (de) ? {1'b0, paint_b} : 5'h0;
    end
	 
endmodule