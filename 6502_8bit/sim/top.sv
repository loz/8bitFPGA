
`default_nettype none
`timescale 1ns / 1ps

module top #(parameter CORDW=12) (  // coordinate width
    input  wire logic clk_pix,             // pixel clock
    input  wire logic rst_pix,             // sim reset
    output      logic signed [CORDW-1:0] sdl_sx,  // horizontal SDL position
    output      logic signed [CORDW-1:0] sdl_sy,  // vertical SDL position
    output      logic sdl_de,              // data enable (low in blanking interval)
    output      logic sdl_frame,
    output      logic [7:0] sdl_r,         // 8-bit red
    output      logic [7:0] sdl_g,         // 8-bit green
    output      logic [7:0] sdl_b          // 8-bit blue
    );

    // display sync signals and coordinates
    logic signed [CORDW-1:0] sx, sy;
    logic de, line, frame;
    display_1024_600 display_inst (
        .clk_pix,
        .rst_pix(rst_pix),
        .sx(sx),
        .sy(sy),
        .line(line),
        .frame(frame),
        .hsync(),
        .vsync(),
        .de(de)
    );

    // paint colours: white inside square, blue outside
    logic [3:0] paint_r, paint_g, paint_b;
    ppu_char ppu (
        .clk(clk_pix),
        .rst_n(~rst_pix),
        .sx,
        .sy,
        .line,
        .frame,
        .de,
        .paint_r,
        .paint_g,
        .paint_b
    );

    // SDL output (8 bits per colour channel)
    always_ff @(posedge clk_pix) begin
        sdl_sx <= sx;
        sdl_sy <= sy;
        sdl_de <= de;
        sdl_frame <= frame;
        sdl_r <= {2{paint_r}};  // double signal width from 4 to 8 bits
        sdl_g <= {2{paint_g}};
        sdl_b <= {2{paint_b}};
    end
endmodule
