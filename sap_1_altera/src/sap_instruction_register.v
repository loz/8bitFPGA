module sap_instruction_register(
	input clk,
	input reset,
	inout [7:0] DATA,
	output [3:0] INSTRUCTION,
	output [7:0] REG_OUT,
	input latch,
	input enable
);


/*

sap_instruction_register sap_instruction_register_inst0(
	.clk(),
	.reset(),
	.DATA(),
	.INSTRUCTION(),
	.REG_OUT(),
	.latch(),
	.enable()
);

*/


reg [7:0] r;

always @(posedge clk) begin
	if (reset) begin
		r <= 0;
	end else begin
		if (latch) begin
			r <= DATA;
		end
	end
end

assign DATA = (enable) ? {4'bZZZZ,r[3:0]} : 8'bZZZZZZZZ; //Only sending 4LSB out
assign INSTRUCTION = r[7:4]; //Always sending the instruction to the I OUT
assign REG_OUT = r;

endmodule