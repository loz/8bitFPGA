`include "display.v"
`include "uart_in.v"

module top(
	input clk,
    input uart_rx,
    output reg led,
	output disp_ce, //Clock Enable
	output disp_rw, //Read/Write
	output disp_rs, //Register Select
	output reg[7:0] data
);

//reg [15:0] slowclock = 0;

reg data_ready;
reg [7:0] bus;

reg init_complete;

reg [23:0] slowclock = 0;
reg inclock = 0;

display disp(
    .clk(inclock),
 //   .clk(clk),
    .init_complete(init_complete),
    .ready(data_ready), //when UART byte ready
    .disp_ce(disp_ce),
    .disp_rw(disp_rw),
    .disp_rs(disp_rs),
    .data(data) //UART data => Display Data
);

/*
uart_in uain(
    .clk(slowclock[30]),
//    .clk(clk),
    .uart_rx(uart_rx),
    .byte_in(bus),
    .ready(data_ready)
);
*/

reg init = 1;

always @(posedge clk) begin
    if(init) begin
        disp_ce <= 0;
        init <= 0;
    end
    if(slowclock == 135000) begin
        slowclock <= 0;
        inclock <= ~inclock;
        //disp_ce <= ~disp_ce;
        led <= ~led;
    end
    else
        slowclock <= slowclock + 1;
end

/*
always @(posedge slowclock[30]) begin
    if(init) begin
        led <= 1;
        init <= 0;
    end

    if(init_complete & data_ready) begin
        data <= 8'd40;
        led <= 0;
    end
end
*/

endmodule