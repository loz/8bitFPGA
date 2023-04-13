// Project F Library - 1280x720p60 Display
// (C)2022 Will Green, open source hardware released under the MIT License
// Learn more at https://projectf.io

`default_nettype none
`timescale 1ns / 1ps

module display_1024_600 #(
    CORDW=12,    // signed coordinate width (bits)
    H_RES=1024,  // horizontal resolution (pixels)
    V_RES=600,   // vertical resolution (lines)
    H_FP=50,    // horizontal front porch
    H_SYNC=105,   // horizontal sync
    H_BP=144,    // horizontal back porch
    V_FP=3,      // vertical front porch
    V_SYNC=10,    // vertical sync
    V_BP=11,     // vertical back porch
    H_POL=0,     // horizontal sync polarity (0:neg, 1:pos)
    V_POL=1      // vertical sync polarity (0:neg, 1:pos)
    ) (
    input  wire logic clk_pix,  // pixel clock
    input  wire logic rst_pix,  // reset in pixel clock domain
    output      logic hsync,    // horizontal sync
    output      logic vsync,    // vertical sync
    output      logic de,       // data enable (low in blanking interval)
    output      logic frame,    // high at start of frame
    output      logic line,     // high at start of line
    output      logic signed [CORDW-1:0] sx,  // horizontal screen position
    output      logic signed [CORDW-1:0] sy   // vertical screen position
    );

    // horizontal timings
    //localparam signed H_STA  = 0 - H_FP - H_SYNC - H_BP;    // horizontal start
    localparam H_STA = 0;
    localparam signed HS_STA = H_STA + H_FP;                // sync start
    localparam signed HS_END = HS_STA + H_SYNC;             // sync end
    localparam signed HA_STA = 0;                           // active start
    localparam signed HA_END = H_RES - 1;                   // active end

    // vertical timings
    //localparam signed V_STA  = 0 - V_FP - V_SYNC - V_BP;    // vertical start
    localparam signed V_STA  = 0;    // vertical start
    localparam signed VS_STA = V_STA + V_FP;                // sync start
    localparam signed VS_END = VS_STA + V_SYNC;             // sync end
    localparam signed VA_STA = 0;                           // active start
    localparam signed VA_END = V_RES - 1;                   // active end

    logic signed [CORDW-1:0] x, y;  // screen position

    // control signals
    always_ff @(posedge clk_pix) begin
        de    <= (y >= VA_STA && x >= HA_STA);
        frame <= (y == V_STA  && x == H_STA);
        line  <= (x == H_STA);
        if (rst_pix) begin
            de <= 0;
            frame <= 0;
            line <= 0;
        end
    end

    // calculate horizontal and vertical screen position
    always_ff @(posedge clk_pix) begin
        if(x == 1023) begin
            if(y == 599) begin
                y <= 0;
            end else begin
                y <= y + 1;
            end
            x <= 0;
        end else begin
            x <= x + 1;
        end
        if (rst_pix) begin
            x <= H_STA;
            y <= V_STA;
        end
    end

    // delay screen position to match sync and control signals
    always_ff @ (posedge clk_pix) begin
        sx <= x;
        sy <= y;
        if (rst_pix) begin
            sx <= H_STA;
            sy <= V_STA;
        end
    end
endmodule
