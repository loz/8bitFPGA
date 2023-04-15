`default_nettype none
`timescale 1ns / 1ps

module rom_or_ram #(MEM_INIT_FILE="", RESET_VECTOR=0, SIZE=8192)(
	input clk,
	input write_enable,
	input output_enable,
	input [14:0] ADDRESS,
	input [7:0] DATA_IN,
	output [7:0] DATA_OUT,
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
//reg [12:0] addr;
//reg [7:0] buffwrite;
//reg [7:0] buffwrite_d0;

//reg data_ready = 0;

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
		memory[ADDRESS] <= DATA_IN;
	end
	//addr <= ADDRESS[12:0];
	/*
	if(output_enable) begin
		buffwrite <= memory[ADDRESS];
		data_ready <= 1;
	end else if (data_ready == 1) begin
		buffwrite_d0 <= buffwrite;
		data_ready <= 0;
	end
	*/
end

//assign DATA = buffwrite_d0; //#data_ready ? buffwrite : 8'bZZZZZZZZ;
//assign DATA = output_enable ? memory[ADDRESS] : 8'bZZZZZZZZ; //buffwrite_d0; //#data_ready ? buffwrite : 8'bZZZZZZZZ;
assign DATA_OUT = output_enable ? memory[ADDRESS] : 8'bZZZZZZZZ; //buffwrite_d0; //#data_ready ? buffwrite : 8'bZZZZZZZZ;
assign Q1_DATA_OUT = memory[Q1_ADDRESS];
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