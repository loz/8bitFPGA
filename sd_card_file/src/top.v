module top(
	input            clk,
	input            rst_n,
	input            key1,
	output			  uart_tx,
	input				  uart_rx,
	output           SD_nCS,
	output           SD_DCLK,
	output           SD_MOSI,
	input            SD_MISO/*,
	output [5:0]     seg_sel,
	output [7:0]     seg_data
	*/
);
wire [(80*8)-1:0] outstr;
wire str_ready;
wire writer_ready;

string_writer writer(
	.clk(clk),
	.rst_n(rst_n), 
	.line(outstr),
	.ready(writer_ready),
	.send(str_ready),
	.uart_tx(uart_tx),
	.uart_rx(uart_rx)
	);

sd_card_scanner scanner(
	.clk(clk),
	.rst_n(rst_n),
	.key1(~key1),
	.SD_nCS(SD_nCS),
	.SD_DCLK(SD_DCLK),
	.SD_MOSI(SD_MOSI),
	.SD_MISO(SD_MISO),
	.debug_string(outstr),
	.debug_send(str_ready),
	.debug_ready(writer_ready)
);

reg pressed =0;

/*
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
*/
endmodule