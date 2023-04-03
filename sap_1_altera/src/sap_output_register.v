 module sap_output_register(
	input clk,
	input reset,
	input [7:0] DATA,
	output [7:0] REG_OUT,
	output [15:0] DEC_OUT,
	input latch
);

 function [15:0] driveBCD(input integer val);
	begin
      driveBCD[3:0] = val % 10;
      driveBCD[7:4] = (val / 10) % 10;
      driveBCD[11:8] = (val / 100) % 10;
      driveBCD[15:12] = (val / 1000) % 10;
	end
 endfunction

/*

sap_output_register sap_output_register_inst0(
	.clk(),
	.reset(),
	.DATA(),
	.REG_OUT(),
	.DEC_OUT(),
	.latch()
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

assign REG_OUT = r;
assign DEC_OUT = driveBCD(r);


endmodule