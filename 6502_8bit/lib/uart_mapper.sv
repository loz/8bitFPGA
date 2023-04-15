//Basic UART mapper
module uart_mapper(clk, rst_n, data_bus, interupt, clear_interupt, uart_byte, uart_byte_ready);
    input clk;
    input rst_n;
    output [7:0] data_bus;
    output interupt;
    input clear_interupt;
    input [7:0] uart_byte;
    input uart_byte_ready;

    reg [7:0] data_byte;
    reg byte_ready;

    assign data_bus = data_byte;
    assign interupt = byte_ready; 

    always_ff @(posedge clk) begin
        if(uart_byte_ready && ~byte_ready) begin
            data_byte <= uart_byte;
            byte_ready <= 1;
        end else if (clear_interupt && byte_ready) begin
            byte_ready <= 0;
        end
    end
endmodule