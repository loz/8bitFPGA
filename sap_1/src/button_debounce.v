/*
    A button debounce module
    clk: FPGA clock
    button_i: The button to be debounced (active LOW)
    button_o: The output to be used in place of button directly (active LOW
*/
module button_debounce(
    input clk,
    input button_i,
    output reg button_o
);

reg [15:0] counter;

always @(posedge clk) begin
    if(~button_i) 
        if (counter < 16'b1111111111111111)
            counter <= counter + 1'd1;
        else
            button_o = 0;
    else
        button_o = 1;
end


endmodule