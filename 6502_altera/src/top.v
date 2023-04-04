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

endmodule