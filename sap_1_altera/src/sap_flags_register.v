module sap_flags_register(
	input clk,
	input reset,
	input [7:0] IN,
	output [7:0] OUT,
	input latch
);


/*

sap_flags_register flags_register(
	.clk(one_shot_clock),
	.reset(reset),
	.IN({alu_C, alu_C, 6'b000000}), //putting in the flags
	.OUT(f_flags), //Here's where flags go
	.latch(f_latch),
);
);

*/


reg [7:0] r;

always @(posedge clk) begin
	if (reset) begin
		r <= 0;
	end else begin
		if (latch) begin
			r <= IN;
		end
	end
end

assign OUT = r;

endmodule