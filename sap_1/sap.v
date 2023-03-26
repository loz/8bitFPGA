`include "src/button_debounce.v"

module sap(
    input clk,
    input btn1,
    output reg [5:0] led
);

reg active;
wire btn1_b;

button_debounce bbtn(
    .clk(clk),
    .button_i(btn1),
    .button_o(btn1_b)
);

always @(posedge clk) begin
    if (~btn1_b && ~active) begin
        led <= ~(~led +1);
        active <= 1;
        end
    else if(btn1_b)
        active <= 0;
    
end
endmodule