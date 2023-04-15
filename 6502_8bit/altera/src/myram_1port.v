`default_nettype none
`timescale 1ns / 1ps

module myram_1port #(SIZE=8192)(
	input clk,
	input write_enable,
	input output_enable,
	input [7:0] DATA_IN,
	input [14:0] ADDRESS,
	output [7:0] DATA_OUT
);

/*
rom rom_inst0(
	.clk(),
	.write_enable(),
	.output_enable(),
	.ADDRESS(),
	.DATA_OUT()
);
*/


localparam ASPACE=$clog2(SIZE);


reg [7:0] memory [0:SIZE-1];
wire [ASPACE-1:0] mapped_address;


always @(negedge clk) begin
	if (write_enable) begin
		memory[mapped_address] <= DATA_IN;
	end
end

//assign DATA_OUT = output_enable ? memory[ADDRESS] : 8'bZZZZZZZZ;
assign DATA_OUT = memory[mapped_address];

endmodule