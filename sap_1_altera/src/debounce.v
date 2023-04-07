module debounce(
	input clk,
	input button_in,
	output button_debounced
);

/*
debounced debounce_inst0(
	.clk(),
	.button_in(),
	.button_debounced()
);
*/


parameter DEBOUNCE_TIME = 50_000_000;

reg [31:0] debounce_counter;
reg state;

always @(posedge clk) begin
	if (button_in !== state && debounce_counter < DEBOUNCE_TIME) begin
		debounce_counter <= debounce_counter + 1;
	end else if (debounce_counter == DEBOUNCE_TIME) begin
		state <= button_in;
		debounce_counter <= 0;
	end else begin
		debounce_counter <= 0;
	end
end

assign button_debounced = state;

endmodule