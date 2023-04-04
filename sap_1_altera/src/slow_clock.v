module slow_clock #(parameter SIZE=15)(
	input clk,
	input reset,
	output slow
);

/*
slow_clock #(.SIZE(15))(
	.clk(),
	.reset(),
	.slow()
);
*/


reg [SIZE:0] counter;

always @(posedge clk) begin
	if(reset) begin
		counter <= 0;
	end else begin
		counter <= counter + 1;
	end
end

assign slow = counter[SIZE];

endmodule