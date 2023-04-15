`default_nettype none
`timescale 1ns / 1ps

module myram_2port #(SIZE=8192)(
	input clk,
	input write_enable,
	input output_enable,
	input [14:0] ADDRESS,
	input [7:0] DATA_IN,
	output [7:0] DATA_OUT,
	input Q1_CLOCK,
	input [14:0] Q1_ADDRESS,
	output [7:0] Q1_DATA_OUT
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
assign mapped_address = ADDRESS[ASPACE-1:0];

wire [ASPACE-1:0] mapped_address_q1;
assign mapped_address_q1 = Q1_ADDRESS[ASPACE-1:0];



always @(negedge clk) begin
	if (write_enable) begin
		memory[mapped_address] <= DATA_IN;
	end
end

assign DATA_OUT = memory[mapped_address];
assign Q1_DATA_OUT = memory[mapped_address_q1];

endmodule