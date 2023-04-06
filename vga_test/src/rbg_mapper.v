module rgb_mapper(
	input [2:0] rgb,
	output [7:0] rgb_r,
	output [7:0] rgb_g,
	output [7:0] rgb_b
);

	wire r = rgb[0];
	wire g = rgb[1];
	wire b = rgb[2];
	
	assign rgb_r = {r,r,r,r,r,r,r,r};
	assign rgb_g = {g,g,g,g,g,g,g,g};
	assign rgb_b = {b,b,b,b,b,b,b,b};	
endmodule