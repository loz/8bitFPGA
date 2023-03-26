/*
    debug tool, LED byte
    will only show the lower 6 bits of a byte as board has native 6 LEDs
*/

module led_byte(
    input [7:0] i_byte ,
    output [5:0] led 
);

    assign led = ~(i_byte[5:0]); //INVERT as LED as active low

endmodule