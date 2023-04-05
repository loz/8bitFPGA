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

//Probes
virtual_IO_16 #(.NAME("ADDR")) addr_probe (
	.source(), // sources.source
	.probe(address_bus)   //  probes.probe
);

wire [15:0] p_data_in;
assign data_in = p_data_in[7:0];
virtual_IO_16 #(.NAME("DATA")) data_probe (
	.source(p_data_in), // sources.source
	.probe({one_shot_clock,write_enable,6'b00_0000,data_out})   //  probes.probe
);
endmodule