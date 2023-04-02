module sap_ram(
	input clk,
	input write_enable,
	input output_enable,
	input address_enable,
	inout [7:0] DATA,
	output [3:0] ADDR_OUT,
	output [7:0] DATA_OUT
);

/*
sap_ram sap_ram_inst0(
	.clk(),
	.write_enable(),
	.output_enable(),
	.address_enable(),
	.DATA(),
	.ADDR_OUT(),
	.DATA_OUT()
);
);
*/

reg [7:0] memory [16];
reg [3:0] add_reg;

assign ADDR_OUT = add_reg;
assign DATA_OUT = memory[add_reg];

always @(posedge clk) begin
	if (address_enable) begin
		add_reg <= DATA[3:0];
	end else begin
		if (write_enable) begin
			memory[add_reg] <= DATA;
		end
	end
end
 

assign DATA = (output_enable) ? memory[add_reg] : 8'bZZZZZZZZ;

endmodule