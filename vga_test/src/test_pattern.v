/*
	implementation of test_pattern from: 
	https://8bitworkshop.com/v3.10.0/?platform=verilog&file=test_hvsync.v#
*/

module test_pattern(
	input clk,
	input reset,
	input display_on,
	output reg [7:0] rgb_r,
	output reg [7:0] rgb_g,
	output reg [7:0] rgb_b,
	input [11:0] hpos,
	input [11:0] vpos
);

reg r;
reg g;
reg b;

always@(posedge clk or posedge reset)
begin
	r <= display_on & (((hpos&7) == 0) | ((vpos&7)==0));
	g <= display_on & vpos[4];
	b <= display_on & hpos[4];

	rgb_r <= {r,r,r,r,r,r,r,r};
	rgb_g <= {g,g,g,g,g,g,g,g};
	rgb_b <= {b,b,b,b,b,b,b,b};
end

/*
localparam FULL = 8'b1111_1111;
localparam OFF  = 8'b0000_0000;
localparam WIDTH = 1024;

always@(posedge clk or posedge reset)
begin
	if(reset == 1'b1)
		begin
			rgb_r <= 8'h00;
			rgb_g <= 8'h00;
			rgb_b <= 8'h00;
		end
	else if(display_on)
		if(hpos == 12'd1)
			begin
				rgb_r <= FULL;
				rgb_g <= FULL;
				rgb_b <= FULL;
			end
		else if(hpos == (WIDTH/8) * 1)
			begin
				rgb_r <= FULL;
				rgb_g <= OFF;
				rgb_b <= OFF;
			end         
		else if(hpos == (WIDTH/8) * 2)
			begin
				rgb_r <= OFF;
				rgb_g <= FULL;
				rgb_b <= OFF;
			end
		else if(hpos == (WIDTH/8) * 3)
			begin
				rgb_r <= OFF;
				rgb_g <= OFF;
				rgb_b <= FULL;
			end
		else if(hpos == (WIDTH/8) * 4)
			begin
				rgb_r <= FULL;
				rgb_g <= FULL;
				rgb_b <= OFF;
			end
		else if(hpos == (WIDTH/8) * 5)
			begin
				rgb_r <= OFF;
				rgb_g <= FULL;
				rgb_b <= FULL;
			end
		else if(hpos == (WIDTH/8) * 6)
			begin
				rgb_r <= FULL;
				rgb_g <= OFF;
				rgb_b <= FULL;
			end 
		else if(hpos == (WIDTH/8) * 7)
			begin
				rgb_r <= OFF;
				rgb_g <= OFF;
				rgb_b <= OFF;
			end
		else
			begin
				rgb_r <= rgb_r;
				rgb_g <= rgb_g;
				rgb_b <= rgb_b;
			end         
	else
		begin
			rgb_r <= 8'h00;
			rgb_g <= 8'h00;
			rgb_b <= 8'h00;
		end
end
*/
endmodule