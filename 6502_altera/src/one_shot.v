module one_shot(
	input clk,
	input button,
	output reg pulse
);

/*
one_shot one_shot_inst0(
	.clk(),
	.button(),
	.pulse()
);
*/

reg q;

always @(posedge button) begin
	if (pulse) begin
		q <= 0;
	end else begin
		q <= 1;
	end
end

always @(posedge clk) begin
	pulse <= q;
end

endmodule