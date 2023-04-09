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
reg [(80*8)-1:0] outstr;
reg str_ready = 0;

string_writer writer(
	.clk(clk),
	.rst_n(rst_n), 
	.line(outstr), 
	.send(str_ready),
	.uart_tx(uart_tx),
	.uart_rx(uart_rx)
	);

reg pressed =0;

always @(posedge clk or negedge rst_n) begin
	if(~rst_n) begin
		str_ready = 0;
	end else begin
		if(~key1) begin
			if(pressed)
				str_ready <= 0;
			else begin
				outstr <= "Hello Rosie!\n\r";
				str_ready <= 1;
				pressed <= 1;
			end
		end else begin
			pressed <= 0;
			str_ready <= 0;
		end
	end
end
endmodule