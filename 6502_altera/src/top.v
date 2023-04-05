module top(
	input clk,
	input rst_n,
	input key1,
	input key2,
	input key3//,
	//output[7:0]seg_sel,
   //output[7:0]seg_data,
	//output [3:0] led
);


reg manual = 1;  //allow sitching manual/auto stepping
always @(posedge ~key3) begin
	manual <= ~manual;
end

wire one_shot_clock;
wire reset = ~key2;

//Clock
wire auto_clock;
slow_clock #(.SIZE(18))(
	.clk(clk),
	.reset(reset),
	.slow(auto_clock)
);

wire clock = manual ? ~key1 : auto_clock; //Clock

clock_pulser clock_pulser_inst0(
	.clk(clk),
	.button(clock),
	.one_clock_pulse(one_shot_clock)
);

//6502
wire [15:0] address_bus;
wire [7:0] data_in;
wire [7:0] data_out;
wire write_enable;
wire irq = 0;
wire non_mask_irq = 0;
wire ready = 1;

wire rom_enable;
assign rom_enable = address_bus[15];
wire [14:0] address;
assign address = address_bus[14:0];
wire [7:0] ram_inout;
wire [7:0] rom_inout;
//reg [7:0] data_bus;

cpu cpu_6502(
	.clk(one_shot_clock),
	.reset(reset),
	.AB(address_bus),
	.DI(data_in),
	.DO(data_out),
	.WE(write_enable),
	.IRQ(irq),
	.NMI(non_mask_irq),
	.RDY(ready)
);

/*
always @(posedge clk) begin
	if(write_enable) begin
		data_bus <= data_out;
	end else begin
		data_bus <= (rom_enable ? rom_inout : ram_inout);
	end
end

assign data_in = write_enable ? 8'bZZZZZZZZ : data_bus;
assign rom_inout = ( rom_enable & write_enable) ? data_bus : 8'bZZZZZZZZ;
assign ram_inout = (~rom_enable & write_enable) ? data_bus : 8'bZZZZZZZZ;
*/

//assign data_in = write_enable ? 8'bZZZZZZZZ : (rom_enable ? rom_inout : ram_inout);
assign data_in = rom_inout;
assign rom_inout = ( rom_enable & write_enable) ? data_out : 8'bZZZZZZZZ;
assign ram_inout = (~rom_enable & write_enable) ? data_out : 8'bZZZZZZZZ;

rom_or_ram #(.RESET_VECTOR(1), .MEM_INIT_FILE("roms/example1.txt")) rom(
	.clk(one_shot_clock),
	.write_enable(1'b0), //ROM not RAM!
   .output_enable(rom_enable),
	.ADDRESS(address),
	.DATA(rom_inout)
);


//Probes
virtual_IO_16 #(.NAME("CADDR")) addr_probe (
	.source(), // sources.source
	.probe(address_bus)   //  probes.probe
);

wire [15:0] c_data = {data_in,data_out};
virtual_IO_16 #(.NAME("CDATA")) data_probe (
	.source(), // sources.source
	.probe(c_data)   //  probes.probe
);

virtual_IO_16 #(.NAME("DBUS")) dbus_probe (
	.source(), // sources.source
	.probe({rom_enable, address})   //  probes.probe
);
endmodule