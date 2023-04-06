/*
	implementation of test_pattern from: 
	https://8bitworkshop.com/v3.10.0/?platform=verilog&file=test_hvsync.v#
*/

module test_pattern(clk, reset, display_on, hpos, vpos, rgb);
  
  input clk, reset;
  output [2:0] rgb;

  input display_on;
  input [8:0] hpos;
  input [8:0] vpos;

  // Assign each color bit to individual wires.
  wire r = display_on & (((hpos&7)==0) | ((vpos&7)==0));
  wire g = display_on & vpos[4];
  wire b = display_on & hpos[4];
  
  // Concatenation operator merges the red, green, and blue signals
  // into a single 3-bit vector, which is assigned to the 'rgb'
  // output. The IDE expects this value in BGR order.
  assign rgb = {b,g,r};
endmodule