module uart_input(clk, rst_n, uart_rx, uart_byte, uart_byte_ready);
	input                        clk;
	input                        rst_n;
	input                        uart_rx;
	output						[7:0] uart_byte;
	output						uart_byte_ready;

	parameter                        CLK_FRE = 50;//Mhz
	//localparam                       IDLE =  0;

	//localparam                       WAIT =  2;   //wait 1 second and send uart received data
	wire[7:0]                        rx_data;
	wire                             rx_data_valid;
	wire                             rx_data_ready;
	//reg[31:0]                        wait_cnt;
	//reg[3:0]                         state;
	assign rx_data_ready = 1'b1;//always can receive data,
	
	assign uart_byte_ready = rx_data_valid;
	assign uart_byte = rx_data;
	
	uart_rx#
	(
		.CLK_FRE(CLK_FRE),
		.BAUD_RATE(115200)
	) uart_rx_inst
	(
		.clk                        (clk                      ),
		.rst_n                      (rst_n                    ),
		.rx_data                    (rx_data                  ),
		.rx_data_valid              (rx_data_valid            ),
		.rx_data_ready              (rx_data_ready            ),
		.rx_pin                     (uart_rx                  )
	);

endmodule