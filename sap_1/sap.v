`include "src/button_debounce.v"
`include "src/led_byte.v"
`include "src/sap_register.v"

module sap(
    input clk,
    input btn1,
    input btn2,
    output reg [5:0] led
);

reg [7:0] abyte;

reg reset = 1;
reg active;
wire btn1_b;
wire btn2_b;

button_debounce bbtn1(
    .clk(clk),
    .button_i(btn1),
    .button_o(btn1_b)
);

button_debounce bbtn2(
    .clk(clk),
    .button_i(btn2),
    .button_o(btn2_b)
);

wire [7:0] a_debug;
reg a_clear = 0;
reg a_load = 0;
reg a_oe = 0;
reg [7:0] data_out;

//Create A Register
sap_register a_register(
    .clk(clk),
    .output_enable(a_eo),
    .load(a_load),
    .data(abyte), //our bus
    .clear(a_clear),
    .data_out(data_out),
    .debug_out(a_debug)  
);

//Wire up the DEBUG out from A
led_byte leds(
    .i_byte(a_debug),
    .led(led)
);


always @(posedge clk) begin
    if(reset) begin
        abyte <= 0;
        reset <= 0;
    end

    if (~btn1_b && ~active) begin
        abyte <=  abyte + 1;
        active <= 1;
        end
    else if(btn1_b)
        active <= 0;
    
    if (~btn2_b) begin
        a_load = 1;
    end
end

endmodule