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
    output      logic [7:0] sdl_b,          // 8-bit blue
    input       logic [7:0] sdl_uart_byte,
    input       logic sdl_uart_byte_ready,
    output wire [15:0] tapaddress,
    output wire [7:0] data,
    output wire rw,
    output wire irqtap
    );

    //6502
    wire [15:0] address_bus;
    wire [7:0] data_bus;

    assign tapaddress = address_bus;
    assign data = data_bus;
    assign rw = write_enable;
    assign irqtap = irq;

    
    reg  [7:0] data_in;
    wire [7:0] data_out;
    wire write_enable;
    wire irq = interupt;
    wire non_mask_irq = 0;
    wire ready = 1;
    cpu6502 cpu_6502(
    	.clk(clk_pix),
    	.reset(rst_pix),
    	.AB(address_bus),
    	.DI(data_in),
    	.DO(data_out),
    	.WE(write_enable),
    	.IRQ(irq),
    	.NMI(non_mask_irq),
    	.RDY(ready)
    );//6502


    always_ff @(posedge clk_pix) begin
        if (~write_enable)
           data_in <= data_bus;
    end
    assign data_bus = (write_enable) ? data_out : 
                      (rom_enable ? rom_out : 
                        uart_enabled ? uart_byte : ram_out);
    //assign ram_inout = (~rom_enable & write_enable) ? data_bus : 8'bZZZZZZZZ;

    wire rom_enable;
    assign rom_enable = address_bus[15];
    wire [14:0] address;
    assign address = address_bus[14:0];
    wire [7:0] ram_out;
    wire [7:0] rom_out;
    //rom #(.RESET_VECTOR(1), .MEM_INIT_FILE("../roms/current.mem")) rom0(
    rom #(.MEM_INIT_FILE("../roms/current.mem")) rom0(
	    .clk(clk_pix),
        .output_enable(rom_enable),
	    .ADDRESS(address),
	    .DATA_OUT(rom_out)
    );

	wire [14:0] ppu_address;
	wire [7:0]  ppu_data;
    rom_or_ram ram(
	    .clk(clk_pix),
	    .write_enable(write_enable), //ROM not RAM!
        .output_enable(~rom_enable),
	    .ADDRESS(address),
	    .DATA_IN(data_bus),
        .DATA_OUT(ram_out),
        .Q1_ADDRESS(ppu_address),
        .Q1_DATA_OUT(ppu_data)
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
        .vid_address(ppu_address),
		.vid_data(ppu_data),
        .paint_r,
        .paint_g,
        .paint_b
    );

    //Get bytes from UART
    logic [7:0] uart_byte;
    logic uart_byte_ready;
    sdl_uart sd_uart(
        .clk(clk_pix),
        .obyte_ready(uart_byte_ready),
        .obyte(uart_byte),
        .sdl_byte(sdl_uart_byte),
        .sdl_byte_ready(sdl_uart_byte_ready)
    );

    //Map into the Address/CPU/DataBus
    logic [7:0] uart_out;
    logic interupt;
    logic clear_interupt;
    logic uart_enabled;
    assign uart_enabled = address_bus[14];
    assign clear_interupt = write_enable && uart_enabled; //14th bit is IRQ Clear, when written to
    uart_mapper umapper (
        .clk(clk_pix),
        .rst_n(~rst_pix),
        .data_bus(uart_out),
        .interupt(interupt),
        .clear_interupt(clear_interupt),
        .uart_byte(uart_byte),
        .uart_byte_ready(uart_byte_ready)
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
