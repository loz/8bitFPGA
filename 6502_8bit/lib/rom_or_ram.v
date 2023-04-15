`default_nettype none
`timescale 1ns / 1ps

module rom_or_ram #(MEM_INIT_FILE="", RESET_VECTOR=0, SIZE=8192)(
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
rom_or_ram rom_or_ram_inst0(
	.clk(),
	.write_enable(),
	.output_enable(),
	.ADDRESS(),
	.DATA()
);
*/

reg [7:0] memory [0:SIZE-1];
initial begin
  if (MEM_INIT_FILE != "") begin
    $readmemh(MEM_INIT_FILE, memory);
  end
  if (RESET_VECTOR) begin
	 memory[15'h1FFC] = 8'h00;
	 memory[15'h1FFD] = 8'h80;
  end
end


always @(negedge clk) begin
	if (write_enable) begin
		memory[ADDRESS] <= DATA_IN;
	end
end

assign DATA_OUT = output_enable ? memory[ADDRESS] : 8'bZZZZZZZZ;
assign Q1_DATA_OUT = Q1_CLOCK ?   memory[Q1_ADDRESS] : 8'bZZZZZZZZ;
endmodule