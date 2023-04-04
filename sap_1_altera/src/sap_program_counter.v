module sap_program_counter(
	input clk,
	input reset,
	inout [7:0] DATA,
	output [3:0] REG_OUT,
	input jump,
	input output_enable,
	input counter_enable
);


/*

sap_program_counter sap_program_counter_inst0(
	.clk(),
	.reset(),
	.DATA(),
	.REG_OUT(),
	.jump(),
	.output_enable(),
	.counter_enable()
);

*/


reg [3:0] r;

always @(posedge clk) begin
	if (reset) begin
		r <= 0;
	end else begin
		if (jump) begin
			r <= DATA[3:0]; //Only 4LSB
		end else if (counter_enable) begin
			r <= r + 1;
		end
	end
end

assign DATA = (output_enable) ? {4'bzzzz,r} : 8'bZZZZZZZZ;
assign REG_OUT = r;

endmodule