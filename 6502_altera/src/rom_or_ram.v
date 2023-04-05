module rom_or_ram #(MEM_INIT_FILE="", RESET_VECTOR=0)(
	input clk,
	input write_enable,
	input output_enable,
	input [14:0] ADDRESS,
	inout [7:0] DATA
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

localparam SIZE = 32768;

reg [7:0] memory [SIZE];

initial begin
  if (MEM_INIT_FILE != "") begin
    $readmemh(MEM_INIT_FILE, memory);
  end
  if (RESET_VECTOR) begin
	 memory[15'h7FFC] = 8'h00;
	 memory[15'h7FFD] = 8'h80;
  end
end

always @(posedge clk) begin
	if (write_enable) begin
		memory[ADDRESS] <= DATA;
	end
end
 

assign DATA = (output_enable) ? memory[ADDRESS] : 8'bZZZZZZZZ;

endmodule