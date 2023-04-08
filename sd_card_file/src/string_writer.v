module string_writer(clk, rst_n, line, send, uart_tx, uart_rx);
	input clk;
	input rst_n;
	input [650:0] line;
	input send;
	output uart_tx;
	input uart_rx;

wire sender_ready;
reg ready_to_send;
reg [657:0] to_send;
wire [7:0] char;
assign char = to_send[657:650];
reg [31:0] wait_ctr = 0;

reg[7:0]                         tx_data;
reg[7:0]                         tx_str;
reg                              tx_data_valid;
wire                             tx_data_ready;

uart_tx sender
(
	.clk(clk),                         //clock input
	.rst_n(rst_n),                     //asynchronous reset input, low active 
	//.tx_data(char),                    //data to send
	//.tx_data_valid(ready_to_send),     //data to be sent is valid
	//.tx_data_ready(sender_ready),      //send ready
	.tx_data(tx_data),                    //data to send
	.tx_data_valid(tx_data_valid),     //data to be sent is valid
	.tx_data_ready(tx_data_ready),      //send ready
	.tx_pin(uart_tx)                   //serial data output
);


always @(posedge clk or negedge rst_n) begin
	if(~rst_n) begin
		to_send[657:650] <= 8'b00000000;
		ready_to_send <= 0;
	end else begin
		if(tx_data_valid && tx_data_ready) begin
			tx_data_valid <= 1'b0;
		end else if(~tx_data_valid && send) begin
			tx_data <= "J";
			tx_data_valid <= 1'b1;
		end
			
			//if(tx_data_valid == 1'b1 && tx_data_ready == 1'b1 && tx_cnt < 8'd12)//Send 12 bytes data
			//begin
			//	tx_cnt <= tx_cnt + 8'd1; //Send data counter
			//end
			//else if(tx_data_valid && tx_data_ready)//last byte sent is complete
			//begin
			//	tx_cnt <= 8'd0;
			//	tx_data_valid <= 1'b0;
			//	state <= WAIT;
			//end
			//else if(~tx_data_valid)
			//begin
			//tx_data_valid <= 1'b1;
			//end
	/*
		if(send) begin
			to_send <= line;
			ready_to_send <= 0;
		end else if(sender_ready) begin
			if(char != 8'b00000000) begin
				if(wait_ctr >= 50_000_000) begin
					//send
					ready_to_send <= 1;
					to_send <= to_send[649:0]; //shift chars
					wait_ctr <= 31'd0;
				end else begin
					wait_ctr <= wait_ctr + 31'd1;
				end
			end else begin
				ready_to_send <= 0;
			end
		end
	*/
	end
end

endmodule