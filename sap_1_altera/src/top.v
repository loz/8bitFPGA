module top(
	input clk,
	input rst_n,
	input key1,
	input key2,
	input key3,
	output[7:0]seg_sel,
   output[7:0]seg_data,
	output [3:0] led
);

localparam PROGRAM="programs/fibonaci.txt";

reg manual = 1;  //allow sitching manual/auto stepping
always @(posedge ~key3) begin
	manual <= ~manual;
end

wire one_shot_clock;
//wire reset = ~rst_n;
//wire latch = ~key2;
//w=ire enable = ~key3;
//wire button = ~key1;

wire [7:0] w_bus;
wire [7:0] w_val_in;

wire [7:0] control;

wire w_enable; // = control[0];
wire alu_enable; // = control[1];
wire alu_sub; // = control[2];
wire reset = ~key2 | control[3];



wire [7:0] mem_control;
wire addr_write; // = mem_control[0];
wire mem_write; // = mem_control[1];
wire mem_out; // = mem_control[2];
wire [3:0] mem_addr_out;
wire [7:0] mem_data_out;

wire [7:0] ireg_control;
wire i_latch; // = ireg_control[0];
wire i_enable; // = ireg_control[1];
wire [7:0] ireg_out;
wire [3:0] i_instruction;

wire [7:0] pctr_control;
wire p_jump; // = pctr_control[0];
wire p_output_enable; //= pctr_control[1];
wire p_counter_enable; // = pctr_control[2];
wire [3:0] pctr_out;

wire [15:0] output_dec;
wire [7:0] output_control;
wire o_latch; // = output_control[0];
wire [7:0] output_out;

wire [7:0] a_control;
wire a_latch; // = a_control[0];
wire a_enable; // = a_control[1];

wire [7:0] b_control;
wire b_latch; // = b_control[0];
wire b_enable; // = b_control[1];

wire [7:0] a_reg_out;
wire [7:0] b_reg_out;

wire alu_C;
wire alu_Z;

//Clock
wire auto_clock;
slow_clock #(.SIZE(18))(
	.clk(clk),
	.reset(reset),
	.slow(auto_clock)
);

wire button = manual ? (~key1 | control[4]) : auto_clock; //Clock

//Output Display
wire[6:0] seg_data_0;
seg_decoder seg_decoder_m0(
    .bin_data  (output_dec[15:12]),
    .seg_data  (seg_data_0)
);
wire[6:0] seg_data_1;
seg_decoder seg_decoder_m1(
    .bin_data  (output_dec[11:8]),
    .seg_data  (seg_data_1)
);
wire[6:0] seg_data_2;
seg_decoder seg_decoder_m2(
    .bin_data  (output_dec[7:4]),
    .seg_data  (seg_data_2)
);
wire[6:0] seg_data_3;
seg_decoder seg_decoder_m3(
    .bin_data  (output_dec[3:0]),
    .seg_data  (seg_data_3)
);

//ALU
sap_alu sap_alu_inst(
	.a_reg_data(a_reg_out),
	.b_reg_data(b_reg_out),
	.DATA(w_bus),
	.enable(alu_enable),
	.sub(alu_sub),
	.C(alu_C),
	.Z(alu_Z)
);

//RAM
sap_ram #(.MEM_INIT_FILE(PROGRAM)) sap_ram_inst0(
	.clk(one_shot_clock),
	.write_enable(mem_write),
	.output_enable(mem_out),
	.address_enable(addr_write),
	.DATA(w_bus),
	.ADDR_OUT(mem_addr_out),
	.DATA_OUT(mem_data_out)
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


virtual_IO_8_bit #(.NAME("WBUS")) vio_w_bus(
	.probe(w_bus),  //  probes.probe
	.source(w_val_in)  // sources.source
);

//
virtual_IO_8_bit #(.NAME("CTRL")) vio_control(
	.probe({6'b000000,alu_C, alu_Z}),  //  probes.probe
	.source(control)  // sources.source
);

//   
virtual_IO_8_bit #(.NAME("AREG")) vio_a_reg(
	.probe(a_reg_out),  //  probes.probe
	.source(a_control)  // sources.source
);

// 
virtual_IO_8_bit #(.NAME("BREG")) vio_b_reg(
	.probe(b_reg_out),  //  probes.probe
	.source(b_control)  // sources.source
);

// 
virtual_IO_8_bit #(.NAME("MEMD")) vio_memd(
	.probe(mem_data_out),  //  probes.probe
	.source(mem_control)  // sources.source
);

virtual_IO_8_bit #(.NAME("ADRG")) vio_addr_reg(
	.probe(mem_addr_out),  //  probes.probe
	.source()  // sources.source
);

virtual_IO_8_bit #(.NAME("IREG")) vio_ireg(
	.probe(ireg_out),  //  probes.probe
	.source(ireg_control)  // sources.source
);

virtual_IO_8_bit #(.NAME("PCTR")) vio_program_counter(
	.probe({4'b0000,pctr_out}),  //  probes.probe
	.source(pctr_control)  // sources.source
);

virtual_IO_8_bit #(.NAME("OREG")) vio_output_register(
	.probe(output_out),  //  probes.probe
	.source(output_control)  // sources.source
);



/* New probes wipes config when rescanning, squatting some */
wire [7:0] CLSB;
wire [7:0] CMSB;

virtual_IO_8_bit #(.NAME("CBUS")) vio_control_bus(
	.probe(CMSB),  //  probes.probe
	.source()  // sources.source
);

virtual_IO_8_bit #(.NAME("CLOG")) vio_control_logic(
	.probe(CLSB),  //  probes.probe
	.source()  // sources.source
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

wire f_latch;
wire [7:0] f_flags;

sap_flags_register flags_register(
	.clk(one_shot_clock),
	.reset(reset),
	.IN({alu_C, alu_Z, 6'b000000}), //putting in the flags
	.OUT(f_flags), //Here's where flags go
	.latch(f_latch),
);

assign led[0] = f_flags[7];
assign led[1] = f_flags[6];
assign led[2] = 0;
assign led[3] = 0;

sap_instruction_register sap_instruction_register_inst0(
	.clk(one_shot_clock),
	.reset(reset),
	.DATA(w_bus),
	.INSTRUCTION(i_instruction),
	.REG_OUT(ireg_out),
	.latch(i_latch),
	.enable(i_enable)
);

sap_program_counter sap_program_counter_inst0(
	.clk(one_shot_clock),
	.reset(reset),
	.DATA(w_bus),
	.REG_OUT(pctr_out),
	.jump(p_jump),
	.output_enable(p_output_enable),
	.counter_enable(p_counter_enable)
);

sap_output_register sap_output_register_inst0(
	.clk(one_shot_clock),
	.reset(reset),
	.DATA(w_bus),
	.REG_OUT(output_out),
	.DEC_OUT(output_dec),
	.latch(o_latch)
);


/* The Control Logic */
/*
wire w_enable; // = control[0];
wire alu_enable; // = control[1];
wire alu_sub; // = control[2];
wire addr_write; // = mem_control[0];
wire mem_write; // = mem_control[1];
wire mem_out; // = mem_control[2];
wire i_latch; // = ireg_control[0];
wire i_enable; // = ireg_control[1];
wire [3:0] i_instruction;
wire p_jump; // = pctr_control[0];
wire p_output_enable; //= pctr_control[1];
wire p_counter_enable; // = pctr_control[2];
wire o_latch; // = output_control[0];
wire a_latch; // = a_control[0];
wire a_enable; // = a_control[1];
wire b_latch; // = b_control[0];
wire b_enable; // = b_control[1];
*/

sap_control_logic sap_control_logic_inst0(
	.clk(one_shot_clock),
	.reset(reset),
	.instruction(i_instruction),
	.flags(f_flags),
	.halt(), //TODO
	.maddr_latch(addr_write),
	.ram_latch(mem_write),
	.ram_out(mem_out),
	.instruction_latch(i_latch),
	.instruction_out(i_enable),
	.a_reg_latch(a_latch),
	.a_reg_out(a_enable),
	.alu_out(alu_enable),
	.alu_sub(alu_sub),
	.b_reg_latch(b_latch),
	.output_latch(o_latch),
	.counter_enable(p_counter_enable),
	.counter_out(p_output_enable),
	.jump(p_jump),
	.flag_latch(f_latch),
	.CBUS_OUT({CMSB,CLSB})
);

assign w_bus = (w_enable) ? w_val_in : 8'bZZZZZZZZ;

endmodule