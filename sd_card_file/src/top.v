module top(
	input            clk,
	input            rst_n,
	input            key1,
	output			  uart_tx,
	input				  uart_rx//,
	/*
	output           SD_nCS,
	output           SD_DCLK,
	output           SD_MOSI,
	input            SD_MISO,
	output [5:0]     seg_sel,
	output [7:0]     seg_data
	*/
);
reg [657:0] outstr;
reg str_ready = 0;

string_writer writer(
	.clk(clk),
	.rst_n(rst_n), 
	.line(outstr), 
	.send(str_ready),
	.uart_tx(uart_tx),
	.uart_rx(uart_rx)
	);


always @(posedge clk or negedge rst_n) begin
	if(~rst_n) begin
		str_ready = 0;
	end else begin
		if(~key1) begin
			outstr <= "Hello Wolrd!\n\0";
			str_ready <= 1;
		end else
			str_ready = 0;
	end
end
endmodule