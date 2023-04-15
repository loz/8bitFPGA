`default_nettype none
`timescale 1ns / 1ps

module rom #(MEM_INIT_FILE="", RESET_VECTOR=0, SIZE=8192)(
	input clk,
	input output_enable,
	input [14:0] ADDRESS,
	output [7:0] DATA_OUT
);

/*
rom rom_inst0(
	.clk(),
	.output_enable(),
	.ADDRESS(),
	.DATA_OUT()
);
*/

reg [7:0] memory [0:SIZE-1];
wire [12:0] mapped_address;
assign mapped_address = ADDRESS[12:0];

initial begin
  if (MEM_INIT_FILE != "") begin
    $readmemh(MEM_INIT_FILE, memory);
  end
  if (RESET_VECTOR) begin
	 memory[13'h1FFC] = 8'h00;
	 memory[13'h1FFD] = 8'h80;
  end
end

assign DATA_OUT = output_enable ? memory[mapped_address] : 8'bZZZZZZZZ;

endmodule