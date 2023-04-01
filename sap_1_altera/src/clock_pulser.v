module clock_pulser(
	input clk,
	input button,
	output one_clock_pulse
);

/*
clock_pulser clock_pulser_inst0(
	.clk(),
	.button(),
	.one_clock_pulse()
);
*/

wire pulse_debounced;
wire one_shot_clk;

debounce debounce_inst0(
	.clk(clk),
	.button_in(button),
	.button_debounced(pulse_debounced)
);

one_shot one_shot_inst0(
	.clk(clk),
	.button(button),
	.pulse(one_shot_clk)
);

assign one_clock_pulse = one_shot_clk;

endmodule