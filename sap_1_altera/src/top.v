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
wire reset = ~rst_n;
wire latch = ~key2;
wire enable = ~key3;
wire button = ~key1;

wire [7:0] w_bus;
reg [7:0] w_drive_r; //Temporary

wire [7:0] reg_out;

wire[6:0] seg_data_0;
seg_decoder seg_decoder_m0(
    .bin_data  (reg_out[7:4]),
    .seg_data  (seg_data_0)
);
wire[6:0] seg_data_1;
seg_decoder seg_decoder_m1(
    .bin_data  (reg_out[3:0]),
    .seg_data  (seg_data_1)
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
    .seg_data_2 ({1'b1,8'hFF}),
    .seg_data_3 ({1'b1,8'hFF}),
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

sap_register sap_register_inst0(
	.clk(one_shot_clock),
	.reset(reset),
	.DATA(w_bus),
	.REG_OUT(reg_out),
	.latch(latch),
	.enable(enable)
);

always @(posedge one_shot_clock) begin
	if (reset) begin
		w_drive_r <= 8'h42;
	end else if (latch) begin
		w_drive_r <= w_drive_r + 1;
	end
end

assign w_bus = (latch) ? w_drive_r : 8'bZZZZZZZZ;

endmodule