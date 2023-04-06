module screen_mapper(
	input [11:0] hpos,
	input [11:0] vpos,
	output [8:0] mapped_hpos,
	output [8:0] mapped_vpos
);

	
	assign mapped_hpos = hpos[10:2];
	assign mapped_vpos = vpos[10:2];

endmodule