/*
	creating an interface to support:
	https://8bitworkshop.com/v3.10.0/?platform=verilog&file=test_hvsync.v#
*/
`include "video_define.v"
module hvsync_generator(clk, reset, hsync, vsync, display_on, hpos, vpos);

  input clk;
  input reset;
  output hsync, vsync;
  output display_on;
  output [11:0] hpos;
  output [11:0] vpos;
 
//video timing parameter definition
`ifdef  VIDEO_1280_720
parameter H_ACTIVE = 16'd1280;           //horizontal active time (pixels)
parameter H_FP = 16'd110;                //horizontal front porch (pixels)
parameter H_SYNC = 16'd40;               //horizontal sync time(pixels)
parameter H_BP = 16'd220;                //horizontal back porch (pixels)
parameter V_ACTIVE = 16'd720;            //vertical active Time (lines)
parameter V_FP  = 16'd5;                 //vertical front porch (lines)
parameter V_SYNC  = 16'd5;               //vertical sync time (lines)
parameter V_BP  = 16'd20;                //vertical back porch (lines)
parameter HS_POL = 1'b1;                 //horizontal sync polarity, 1 : POSITIVE,0 : NEGATIVE;
parameter VS_POL = 1'b1;                 //vertical sync polarity, 1 : POSITIVE,0 : NEGATIVE;
`endif

//480x272 9Mhz
`ifdef  VIDEO_480_272
parameter H_ACTIVE = 16'd480; 
parameter H_FP = 16'd2;       
parameter H_SYNC = 16'd41;    
parameter H_BP = 16'd2;       
parameter V_ACTIVE = 16'd272; 
parameter V_FP  = 16'd2;     
parameter V_SYNC  = 16'd10;   
parameter V_BP  = 16'd2;     
parameter HS_POL = 1'b0;
parameter VS_POL = 1'b0;
`endif

//640x480 25.175Mhz
`ifdef  VIDEO_640_480
parameter H_ACTIVE = 16'd640; 
parameter H_FP = 16'd16;      
parameter H_SYNC = 16'd96;    
parameter H_BP = 16'd48;      
parameter V_ACTIVE = 16'd480; 
parameter V_FP  = 16'd10;    
parameter V_SYNC  = 16'd2;    
parameter V_BP  = 16'd33;    
parameter HS_POL = 1'b0;
parameter VS_POL = 1'b0;
`endif

//800x480 33Mhz
`ifdef  VIDEO_800_480
parameter H_ACTIVE = 16'd800; 
parameter H_FP = 16'd40;      
parameter H_SYNC = 16'd128;   
parameter H_BP = 16'd88;      
parameter V_ACTIVE = 16'd480; 
parameter V_FP  = 16'd1;     
parameter V_SYNC  = 16'd3;    
parameter V_BP  = 16'd21;    
parameter HS_POL = 1'b0;
parameter VS_POL = 1'b0;
`endif

//800x600 40Mhz
`ifdef  VIDEO_800_600
parameter H_ACTIVE = 16'd800; 
parameter H_FP = 16'd40;      
parameter H_SYNC = 16'd128;   
parameter H_BP = 16'd88;      
parameter V_ACTIVE = 16'd600; 
parameter V_FP  = 16'd1;     
parameter V_SYNC  = 16'd4;    
parameter V_BP  = 16'd23;    
parameter HS_POL = 1'b1;
parameter VS_POL = 1'b1;
`endif

//1024x768 65Mhz
`ifdef  VIDEO_1024_768
parameter H_ACTIVE = 16'd1024;
parameter H_FP = 16'd24;      
parameter H_SYNC = 16'd136;   
parameter H_BP = 16'd160;     
parameter V_ACTIVE = 16'd768; 
parameter V_FP  = 16'd3;      
parameter V_SYNC  = 16'd6;    
parameter V_BP  = 16'd29;     
parameter HS_POL = 1'b0;
parameter VS_POL = 1'b0;
`endif

//1920x1080 148.5Mhz
`ifdef  VIDEO_1920_1080
parameter H_ACTIVE = 16'd1920;
parameter H_FP = 16'd88;
parameter H_SYNC = 16'd44;
parameter H_BP = 16'd148; 
parameter V_ACTIVE = 16'd1080;
parameter V_FP  = 16'd4;
parameter V_SYNC  = 16'd5;
parameter V_BP  = 16'd36;
parameter HS_POL = 1'b1;
parameter VS_POL = 1'b1;
`endif

parameter H_TOTAL = H_ACTIVE + H_FP + H_SYNC + H_BP;//horizontal total time (pixels)
parameter V_TOTAL = V_ACTIVE + V_FP + V_SYNC + V_BP;//vertical total time (lines)

reg hs_reg;                      //horizontal sync register
reg vs_reg;                      //vertical sync register
reg hs_reg_d0;                   //delay 1 clock of 'hs_reg'
reg vs_reg_d0;                   //delay 1 clock of 'vs_reg'
reg[11:0] h_cnt;                 //horizontal counter
reg[11:0] v_cnt;                 //vertical counter
reg [11:0] hpos_i;
reg [11:0] vpos_i;
reg [11:0] hpos_d0;
reg [11:0] vpos_d0;
reg h_active;                    //horizontal video active
reg v_active;                    //vertical video active
//wire video_active;               //video active(horizontal active and vertical active)
reg video_active_d0;             //delay 1 clock of video_active
assign hsync = hs_reg_d0;
assign vsync = vs_reg_d0;
assign video_active = h_active & v_active;
assign de = video_active_d0;
assign display_on = video_active_d0;
assign vpos = vpos_d0;
assign hpos = hpos_d0;

always@(posedge clk or posedge reset)
begin
	if(reset == 1'b1)
		begin
			hs_reg_d0 <= 1'b0;
			vs_reg_d0 <= 1'b0;
			video_active_d0 <= 1'b0;
		end
	else
		begin
			hs_reg_d0 <= hs_reg;
			vs_reg_d0 <= vs_reg;
			video_active_d0 <= video_active;
		end
end

always@(posedge clk or posedge reset)
begin
	if(reset == 1'b1)
		h_cnt <= 12'd0;
	else if(h_cnt == H_TOTAL - 1)//horizontal counter maximum value
		h_cnt <= 12'd0;
	else
		h_cnt <= h_cnt + 12'd1;
end

always@(posedge clk or posedge reset)
begin
	if(reset == 1'b1) begin
		hpos_i <= 12'd0;
		hpos_d0 <= hpos_i;
	end else if(h_cnt >= H_FP + H_SYNC + H_BP - 1) begin //horizontal video active
		hpos_i <= h_cnt - (H_FP[11:0] + H_SYNC[11:0] + H_BP[11:0] - 12'd1);
		hpos_d0 <= hpos_i;
	end else begin
		hpos_i <= hpos_i;
		hpos_d0 <= hpos_i;
	end
end

always@(posedge clk or posedge reset)
begin
	if(reset == 1'b1) begin
		v_cnt <= 12'd0;
		vpos_i <= 12'd0;
		vpos_d0 <= vpos_i;
	end
	else if(h_cnt == H_FP  - 1)//horizontal sync time
		if(v_cnt == V_TOTAL - 1) begin//vertical counter maximum value
			v_cnt <= 12'd0;
			vpos_i <= 12'd0;
			vpos_d0 <= vpos_i;
		end else begin
			v_cnt <= v_cnt + 12'd1;
			vpos_i <= v_cnt + 12'd1;
			vpos_d0 <= vpos_i;
		end
	else begin
		v_cnt <= v_cnt;
		vpos_i <= vpos_i;
		vpos_d0 <= vpos_i;
	end
end

always@(posedge clk or posedge reset)
begin
	if(reset == 1'b1)
		hs_reg <= 1'b0;
	else if(h_cnt == H_FP - 1)//horizontal sync begin
		hs_reg <= HS_POL;
	else if(h_cnt == H_FP + H_SYNC - 1)//horizontal sync end
		hs_reg <= ~hs_reg;
	else
		hs_reg <= hs_reg;
end

always@(posedge clk or posedge reset)
begin
	if(reset == 1'b1)
		h_active <= 1'b0;
	else if(h_cnt == H_FP + H_SYNC + H_BP - 1)//horizontal active begin
		h_active <= 1'b1;
	else if(h_cnt == H_TOTAL - 1)//horizontal active end
		h_active <= 1'b0;
	else
		h_active <= h_active;
end

always@(posedge clk or posedge reset)
begin
	if(reset == 1'b1)
		vs_reg <= 1'd0;
	else if((v_cnt == V_FP - 1) && (h_cnt == H_FP - 1))//vertical sync begin
		vs_reg <= HS_POL;
	else if((v_cnt == V_FP + V_SYNC - 1) && (h_cnt == H_FP - 1))//vertical sync end
		vs_reg <= ~vs_reg;  
	else
		vs_reg <= vs_reg;
end

always@(posedge clk or posedge reset)
begin
	if(reset == 1'b1)
		v_active <= 1'd0;
	else if((v_cnt == V_FP + V_SYNC + V_BP - 1) && (h_cnt == H_FP - 1))//vertical active begin
		v_active <= 1'b1;
	else if((v_cnt == V_TOTAL - 1) && (h_cnt == H_FP - 1)) //vertical active end
		v_active <= 1'b0;   
	else
		v_active <= v_active;
end

endmodule
