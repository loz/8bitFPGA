module top(
	input clk,
	input rst_n,
	input key1,
	input key2,
	input key3,
	output[7:0]seg_sel,
    output[7:0]seg_data
);

wire one_shot_clock;
//wire reset = ~rst_n;
//wire latch = ~key2;
//w=ire enable = ~key3;
//wire button = ~key1;

wire [7:0] w_bus;
wire [7:0] w_val_in;

wire [7:0] control;

wire w_enable = control[0];
wire alu_enable = control[1];
wire alu_sub = control[2];
wire reset = control[3];
wire button = control[4]; //Clock


wire [7:0] a_control;
wire a_latch = a_control[0];
wire a_enable = a_control[1];

wire [7:0] b_control;
wire b_latch = b_control[0];
wire b_enable = b_control[1];

wire [7:0] a_reg_out;
wire [7:0] b_reg_out;

wire alu_C; // = LED0;
wire alu_Z; // = LED1;

//A Register
wire[6:0] seg_data_0;
seg_decoder seg_decoder_m0(
    .bin_data  (a_reg_out[7:4]),
    .seg_data  (seg_data_0)
);
wire[6:0] seg_data_1;
seg_decoder seg_decoder_m1(
    .bin_data  (a_reg_out[3:0]),
    .seg_data  (seg_data_1)
);

//B Register
wire[6:0] seg_data_2;
seg_decoder seg_decoder_m2(
    .bin_data  (b_reg_out[7:4]),
    .seg_data  (seg_data_2)
);
wire[6:0] seg_data_3;
seg_decoder seg_decoder_m3(
    .bin_data  (b_reg_out[3:0]),
    .seg_data  (seg_data_3)
);

sap_alu sap_alu_inst(
	.a_reg_data(a_reg_out),
	.b_reg_data(b_reg_out),
	.DATA(w_bus),
	.enable(alu_enable),
	.sub(alu_sub),
	.C(alu_C),
	.Z(alu_Z)
);


wire[6:0] seg_data_6;
seg_decoder seg_decoder_m6(
    .bin_data  (w_bus[7:4]),
    .seg_data  (seg_data_6)
);
wire[6:0] seg_data_7;
seg_decoder seg_decoder_m7(
    .bin_data  (w_bus[3:0]),
    .seg_data  (seg_data_7)
);

seg_scan seg_scan_m0(
    .clk        (clk),
    .rst_n      (rst_n),
    .seg_sel    (seg_sel),
    .seg_data   (seg_data),
    .seg_data_0 ({1'b1,seg_data_0}),      //The  decimal point at the highest bit,and low level effecitve
    .seg_data_1 ({1'b1,seg_data_1}), 
    .seg_data_2 ({1'b1,seg_data_2}),
    .seg_data_3 ({1'b1,seg_data_3}),
    .seg_data_4 ({1'b1,8'hFF}),
	 .seg_data_5 ({1'b1,8'hFF}),
	 .seg_data_6 ({1'b1,seg_data_6}),
    .seg_data_7 ({1'b1,seg_data_7})
);

clock_pulser clock_pulser_inst0(
	.clk(clk),
	.button(button),
	.one_clock_pulse(one_shot_clock)
);

virtual_IO_8_bit vio_w_bus(
	.probe(w_bus),  //  probes.probe
	.source(w_val_in)  // sources.source
);

virtual_IO_8_bit vio_control(
	.probe({6'b000000,alu_C, alu_Z}),  //  probes.probe
	.source(control)  // sources.source
);

virtual_IO_8_bit vio_a_reg(
	.probe(a_reg_out),  //  probes.probe
	.source(a_control)  // sources.source
);

virtual_IO_8_bit vio_b_reg(
	.probe(b_reg_out),  //  probes.probe
	.source(b_control)  // sources.source
);

sap_register a_register(
	.clk(one_shot_clock),
	.reset(reset),
	.DATA(w_bus),
	.REG_OUT(a_reg_out),
	.latch(a_latch),
	.enable(a_enable)
);

sap_register b_register(
	.clk(one_shot_clock),
	.reset(reset),
	.DATA(w_bus),
	.REG_OUT(b_reg_out),
	.latch(b_latch),
	.enable(b_enable)
);

assign w_bus = (w_enable) ? w_val_in : 8'bZZZZZZZZ;

endmodule