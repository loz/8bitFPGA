module charmap(
	input [8:0] char,
	input [8:0] xoffset,
	input [8:0] yoffset,
	output bitmap
);

	logic [8:0] charmap[95*8];
	
    initial begin
			$readmemb("../res/font.mem", charmap);
    end
	 
	wire availchar;
	assign availchar = (char<32) ? 0 : char-31;
	
	wire [8:0] row;
	assign row=charmap[(availchar*8)+yoffset];
	assign bitmap = row[xoffset];

endmodule