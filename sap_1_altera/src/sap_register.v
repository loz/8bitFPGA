module sap_register(
	input clk,
	input reset,
	inout [7:0] DATA,
	output [7:0] REG_OUT,
	input latch,
	input enable
);


/*

sap_register sap_register_inst0(
	.clk(),
	.reset(),
	.DATA(),
	.REG_OUT(),
	.latch(),
	.enable(),
	
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

assign DATA = (enable) ? r : 8'bZZZZZZZZ;
assign REG_OUT = r;

endmodule