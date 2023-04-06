
`ifndef DIGITS10_H
`define DIGITS10_H

/*
ROM module with 5x5 bitmaps for the digits 0-9.

digits10_case - Uses the case statement.
digits10_array - Uses an array and initial block.

These two modules are functionally equivalent.
*/

// module for 10-digit bitmap ROM
module digits10_case(digit, yofs, bits);
  
  input [3:0] digit;		// digit 0-9
  input [2:0] yofs;		// vertical offset (0-4)
  output reg [4:0] bits;	// output (5 bits)

  // combine {digit,yofs} into single ROM address
  wire [6:0] caseexpr = {digit,yofs};
  
  always @(*)
    case (caseexpr)/*{w:5,h:5,count:10}*/
      7'o00: bits = 5'b11111;
      7'o01: bits = 5'b10001;
      7'o02: bits = 5'b10001;
      7'o03: bits = 5'b10001;
      7'o04: bits = 5'b11111;

      7'o10: bits = 5'b01100;
      7'o11: bits = 5'b00100;
      7'o12: bits = 5'b00100;
      7'o13: bits = 5'b00100;
      7'o14: bits = 5'b11111;

      7'o20: bits = 5'b11111;
      7'o21: bits = 5'b00001;
      7'o22: bits = 5'b11111;
      7'o23: bits = 5'b10000;
      7'o24: bits = 5'b11111;

      7'o30: bits = 5'b11111;
      7'o31: bits = 5'b00001;
      7'o32: bits = 5'b11111;
      7'o33: bits = 5'b00001;
      7'o34: bits = 5'b11111;

      7'o40: bits = 5'b10001;
      7'o41: bits = 5'b10001;
      7'o42: bits = 5'b11111;
      7'o43: bits = 5'b00001;
      7'o44: bits = 5'b00001;

      7'o50: bits = 5'b11111;
      7'o51: bits = 5'b10000;
      7'o52: bits = 5'b11111;
      7'o53: bits = 5'b00001;
      7'o54: bits = 5'b11111;

      7'o60: bits = 5'b11111;
      7'o61: bits = 5'b10000;
      7'o62: bits = 5'b11111;
      7'o63: bits = 5'b10001;
      7'o64: bits = 5'b11111;

      7'o70: bits = 5'b11111;
      7'o71: bits = 5'b00001;
      7'o72: bits = 5'b00001;
      7'o73: bits = 5'b00001;
      7'o74: bits = 5'b00001;

      7'o100: bits = 5'b11111;
      7'o101: bits = 5'b10001;
      7'o102: bits = 5'b11111;
      7'o103: bits = 5'b10001;
      7'o104: bits = 5'b11111;

      7'o110: bits = 5'b11111;
      7'o111: bits = 5'b10001;
      7'o112: bits = 5'b11111;
      7'o113: bits = 5'b00001;
      7'o114: bits = 5'b11111;

      default: bits = 0;
    endcase
endmodule

module digits10_array(digit, yofs, bits);
  
  input [3:0] digit;		// digit 0-9
  input [2:0] yofs;		// vertical offset (0-4)
  output [4:0] bits;		// output (5 bits)

  reg [4:0] bitarray[0:15][0:4]; // ROM array (16 x 5 x 5 bits)
  reg [4:0] fakearray[0:4];

  assign bits = bitarray[digit][yofs];	// assign module output
  //assign bits = fakearray[yofs];
  
  integer i,j;
  
  initial begin/*{w:5,h:5,count:10}*/
  
    fakearray[0] = 5'b01100;
    fakearray[1] = 5'b00100;
    fakearray[2] = 5'b00100;
    fakearray[3] = 5'b00100;
    fakearray[4] = 5'b11111;
  
    bitarray[0][0] = 5'b11111;
    bitarray[0][1] = 5'b10001;
    bitarray[0][2] = 5'b10001;
    bitarray[0][3] = 5'b10001;
    bitarray[0][4] = 5'b11111;

    bitarray[1][0] = 5'b01100;
    bitarray[1][1] = 5'b00100;
    bitarray[1][2] = 5'b00100;
    bitarray[1][3] = 5'b00100;
    bitarray[1][4] = 5'b11111;
	 
    bitarray[2][0] = 5'b11111;
    bitarray[2][1] = 5'b00001;
    bitarray[2][2] = 5'b11111;
    bitarray[2][3] = 5'b10000;
    bitarray[2][4] = 5'b11111;

    bitarray[3][0] = 5'b11111;
    bitarray[3][1] = 5'b00001;
    bitarray[3][2] = 5'b11111;
    bitarray[3][3] = 5'b00001;
    bitarray[3][4] = 5'b11111;

    bitarray[4][0] = 5'b10001;
    bitarray[4][1] = 5'b10001;
    bitarray[4][2] = 5'b11111;
    bitarray[4][3] = 5'b00001;
    bitarray[4][4] = 5'b00001;

    bitarray[5][0] = 5'b11111;
    bitarray[5][1] = 5'b10000;
    bitarray[5][2] = 5'b11111;
    bitarray[5][3] = 5'b00001;
    bitarray[5][4] = 5'b11111;

    bitarray[6][0] = 5'b11111;
    bitarray[6][1] = 5'b10000;
    bitarray[6][2] = 5'b11111;
    bitarray[6][3] = 5'b10001;
    bitarray[6][4] = 5'b11111;

    bitarray[7][0] = 5'b11111;
    bitarray[7][1] = 5'b00001;
    bitarray[7][2] = 5'b00001;
    bitarray[7][3] = 5'b00001;
    bitarray[7][4] = 5'b00001;

    bitarray[8][0] = 5'b11111;
    bitarray[8][1] = 5'b10001;
    bitarray[8][2] = 5'b11111;
    bitarray[8][3] = 5'b10001;
    bitarray[8][4] = 5'b11111;

    bitarray[9][0] = 5'b11111;
    bitarray[9][1] = 5'b10001;
    bitarray[9][2] = 5'b11111;
    bitarray[9][3] = 5'b00001;
    bitarray[9][4] = 5'b11111;
	 
    bitarray[10][0] = 5'b00000;
    bitarray[10][1] = 5'b00000;
    bitarray[10][2] = 5'b00000;
    bitarray[10][3] = 5'b00000;
    bitarray[10][4] = 5'b00000;
	 
    bitarray[11][0] = 5'b11111;
    bitarray[11][1] = 5'b11111;
    bitarray[11][2] = 5'b11111;
    bitarray[11][3] = 5'b11111;
    bitarray[11][4] = 5'b11111;
	 
    bitarray[12][0] = 5'b00000;
    bitarray[12][1] = 5'b00000;
    bitarray[12][2] = 5'b00000;
    bitarray[12][3] = 5'b00000;
    bitarray[12][4] = 5'b00000;
	 
    bitarray[13][0] = 5'b10000;
    bitarray[13][1] = 5'b11000;
    bitarray[13][2] = 5'b11100;
    bitarray[13][3] = 5'b11110;
    bitarray[13][4] = 5'b11111;
	 
    bitarray[14][0] = 5'b00000;
    bitarray[14][1] = 5'b00000;
    bitarray[14][2] = 5'b00000;
    bitarray[14][3] = 5'b00000;
    bitarray[14][4] = 5'b00000;

    bitarray[15][0] = 5'b11111;
    bitarray[15][1] = 5'b01111;
    bitarray[15][2] = 5'b00111;
    bitarray[15][3] = 5'b00011;
    bitarray[15][4] = 5'b00001;

	 /*
    // clear unused array entries
    for (i = 10; i <= 15; i=i+1)
      for (j = 0; j <= 4; j=j+1) 
        bitarray[i][j] = 0;
	*/
  end
endmodule

module test_numbers_top(clk, reset, display_on, hpos, vpos, rgb);
  
  input clk, reset;
  output [2:0] rgb;

  input display_on;
  input [8:0] hpos;
  input [8:0] vpos;
  
  wire [3:0] digit = hpos[7:4];
  wire [2:0] xofs  = hpos[3:1];
  wire [2:0] yofs  = vpos[3:1];
  wire [4:0] bits;
  
  digits10_case numbers(
    .digit(digit),
    .yofs(yofs),
    .bits(bits)
  );

  wire r = display_on && 0;
  wire g = display_on && bits[xofs ^ 3'b111];
  wire b = display_on && 0;
  assign rgb = {b,g,r};

endmodule

`endif
