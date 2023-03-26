module clock_divider(
    input clk,
    input reset,
    output reg clk_div2,
    output reg clk_div4,
    output reg clk_div8,
    output reg clk_div16,
    output reg clk_div32
);

reg [23:0] counter;

always @(posedge clk) begin
    if (!reset)
        counter <= 24'd0;
    else if (counter < 24'd1349_999)       // 0.05s delay
        counter <= counter + 1'd1;
    else begin
        counter <= 24'd0;
        clk_div2 <= ~clk_div2;
    end
end


    always @(posedge clk_div2)
        clk_div4 <= ~clk_div4;

    always @(posedge clk_div4)
        clk_div8 <= ~clk_div8;

    always @(posedge clk_div8)
        clk_div16 <= ~clk_div16;

    always @(posedge clk_div16)
        clk_div32 <= ~clk_div32;

endmodule