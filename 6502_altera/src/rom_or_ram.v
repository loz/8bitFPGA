module rom_or_ram #(MEM_INIT_FILE="", RESET_VECTOR=0)(
	input clk,
	input write_enable,
	input output_enable,
	input [14:0] ADDRESS,
	inout reg [7:0] DATA
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

localparam SIZE = 8192; // Too big for MK9 slots 32768;

reg [7:0] memory [0:SIZE];
reg [12:0] addr;
reg [7:0] buffwrite;

initial begin
  if (MEM_INIT_FILE != "") begin
    $readmemh(MEM_INIT_FILE, memory);
  end
  if (RESET_VECTOR) begin
	 //memory[15'h0080] = 8'h80;
	 memory[15'h1FFC] = 8'h00;
	 memory[15'h1FFD] = 8'h80;
  end
end


always @(negedge clk) begin
	if (write_enable) begin
		memory[ADDRESS] <= DATA;
	end
	addr <= ADDRESS[12:0];
	if(output_enable) begin
		buffwrite <= memory[ADDRESS];
	end
	DATA <= buffwrite;
end
/*

virtual_IO_16 #(.NAME("MADR")) mem_addr_probe (
	.source(), // sources.source
	.probe({1'b0,addr})   //  probes.probe
);
virtual_IO_16 #(.NAME("MVAL")) mem_val_probe (
	.source(), // sources.source
	.probe({memory[addr],8'd0})   //  probes.probe
);
*/
 

//assign DATA = (output_enable) ? memory[addr] : 8'bZZZZZZZZ;
//assign DATA = (output_enable) ? 8'hea : 8'bZZZZZZZZ;
endmodule