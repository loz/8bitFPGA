//////////////////////////////////////////////////////////////////////////////////
//   vga color bar test                                                         //
//                                                                              //
//  Author: meisq                                                               //
//          msq@qq.com                                                          //
//          ALINX(shanghai) Technology Co.,Ltd                                  //
//          heijin                                                              //
//     WEB: http://www.alinx.cn/                                                //
//     BBS: http://www.heijin.org/                                              //
//                                                                              //
//////////////////////////////////////////////////////////////////////////////////
//                                                                              //
// Copyright (c) 2017,ALINX(shanghai) Technology Co.,Ltd                        //
//                    All rights reserved                                       //
//                                                                              //
// This source file may be used and distributed without restriction provided    //
// that this copyright statement is not removed from the file and that any      //
// derivative work contains the original copyright notice and the associated    //
// disclaimer.                                                                  //
//                                                                              //
//////////////////////////////////////////////////////////////////////////////////

//================================================================================
//  Revision History:
//  Date          By            Revision    Change Description
//--------------------------------------------------------------------------------
//2017/7/20                    1.0          Original
//*******************************************************************************/
module top(
	input                       clk,
	input                       rst_n,
	//vga output        
	output                      vga_out_hs, //vga horizontal synchronization         
	output                      vga_out_vs, //vga vertical synchronization                  
	output[4:0]                 vga_out_r,  //vga red
	output[5:0]                 vga_out_g,  //vga green
	output[4:0]                 vga_out_b   //vga blue
	
);

wire                            video_clk;
wire                            video_hs;
wire                            video_vs;
wire                            video_de;
wire[7:0]                       video_r;
wire[7:0]                       video_g;
wire[7:0]                       video_b;

assign vga_out_hs = video_hs;
assign vga_out_vs = video_vs;
assign vga_out_r  = video_r[7:3]; //discard low bit data
assign vga_out_g  = video_g[7:2]; //discard low bit data
assign vga_out_b  = video_b[7:3]; //discard low bit data

//generate video pixel clock
video_pll video_pll_m0(
	.inclk0(clk),
	.c0(video_clk));

wire [11:0] hpos;
wire [11:0] vpos;
	
hvsync_generator hsync_gen(
	.clk(video_clk),
	.reset(~rst_n),
	.hsync(video_hs),
	.vsync(video_vs),
	.display_on(video_de),
	.hpos(hpos),
	.vpos(vpos)
);	

wire [2:0] rgb;

rgb_mapper rmap(
	.rgb(rgb),
	.rgb_r(video_r),
	.rgb_g(video_g),
	.rgb_b(video_b)
);

wire [8:0] m_hpos;
wire [8:0] m_vpos;

screen_mapper smap(
	.hpos(hpos),
	.vpos(vpos),
	.mapped_hpos(m_hpos),
	.mapped_vpos(m_vpos),
);

sprite_bitmap_top ttop(
	.clk(clk),
	.reset(~rst_n),
	.display_on(video_de),
	.hpos(m_hpos),
	.vpos(m_vpos),
	.hsync(video_hs),
	.vsync(video_vs),
	.rgb(rgb)
);

endmodule