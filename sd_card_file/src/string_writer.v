module string_writer(clk, rst_n, line, send, ready, uart_tx, uart_rx);
	input clk;
	input rst_n;
	input [650:0] line;
	input send;
	output ready;
	output uart_tx;
	input uart_rx;

localparam MAXBIT = (80*8)-1;
reg [MAXBIT:0] to_send;

wire [7:0] char;
assign char = to_send[7:0];
reg [7:0] counter;
reg [7:0] stack[80];

reg[7:0]                         tx_data;
reg[7:0]                         tx_str;
reg                              tx_data_valid;
wire                             tx_data_ready;

localparam IDLE = 0;
localparam SCANNING = 1;
localparam SENDING = 2;

reg [2:0] state;
assign ready = (state == IDLE);

uart_tx sender
(
	.clk(clk),                         //clock input
	.rst_n(rst_n),                     //asynchronous reset input, low active 
	.tx_data(tx_data),                  //data to send
	.tx_data_valid(tx_data_valid),     //data to be sent is valid
	.tx_data_ready(tx_data_ready),     //send ready
	.tx_pin(uart_tx)                   //serial data output
);


always @(posedge clk or negedge rst_n) begin
	if(~rst_n) begin
		state <= IDLE;
	end else if (send && state == IDLE) begin
		to_send <= line;
		counter <= 0;
		state <= SCANNING;
	end else if (state == SCANNING) begin
		//Shift the bits to make first chart at MSB
		if(char != 8'b00000000) begin //Push chars on to the stack
				counter <= counter + 1;
				stack[counter] <= char;
				to_send <= (to_send >> 8);
		end else begin
			counter <= counter - 1;
			state <= SENDING;
		end
	end else begin
		if(tx_data_valid && tx_data_ready) begin
			tx_data_valid <= 1'b0;
		end else if(~tx_data_valid && state == SENDING) begin
			if(counter == 0) begin
				state <= IDLE;
				tx_data <= stack[counter];
				tx_data_valid <= 1'b1;
			end else begin
				tx_data <= stack[counter];
				counter <= counter - 1;
				tx_data_valid <= 1'b1;
			end
		end
	end
end

endmodule