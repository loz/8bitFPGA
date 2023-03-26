/*
    debug tool, LED byte
    will only show the lower 6 bits of a byte as board has native 6 LEDs
*/

module led_byte(
    input clk,
    input [7:0] i_byte,
    output reg [5:0] led 
);

always @(posedge clk) begin
    led <= 6'b110000; //~(i_byte[5:0]); //INVERT as LED as active low
end

endmodule