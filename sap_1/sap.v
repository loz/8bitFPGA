module sap(
    input clk,
    output reg [5:0] led
);

always @(posedge clk) begin
    led <= 6'b100110;
end
endmodule