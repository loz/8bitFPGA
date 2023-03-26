/*
    An inspectable register, similar to the SAP example
    Thus there's content inspector which doesn't interfere with output
*/

module sap_register(
    input clk,
    input output_enable,
    input load,
    input [7:0] data,
    input clear,
    output reg [7:0] data_out,
    output reg [7:0] debug_out
);

always @(posedge clk) begin
    if (output_enable)
        data_out <= debug_out;
    if (load)
        debug_out <= data;
end

endmodule