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
    output wire [15:0] tapaddress,
    output wire [7:0] data
    );

    //6502
    wire [15:0] address_bus;
    reg [7:0] data_capture;
    wire  [7:0] data_in;
    wire [7:0] data_out;
    wire write_enable;
    wire irq = 0;
    wire non_mask_irq = 0;
    wire ready = 1;
    
    assign tapaddress = address_bus;
    assign data = data_in;

    wire rom_enable;
    assign rom_enable = address_bus[15];
    wire [14:0] address;
    assign address = address_bus[14:0];
    wire [7:0] ram_inout;
    wire [7:0] rom_inout;
    //reg [7:0] data_bus;

    wire [7:0] READPORT[0:8192];
    
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

    /*
	    All the confusion, the conlusion I have to work is
	    DATA IN must be left alone unless there is a change, 
	    when address bus changes it must not clock data change until later cycle
	    (essentially ROM->RAM switch was IMMEDIATE whilst data_in was staggered, thus
	    ROM enable on a cycle should WRITe to Data_bus at end of cycle, and RAM enable
	    would write next cycle, but not lose what was written in rom prior,
	    essentially assigning data wire directly to rom_enable ? will drop rom output
	    too soon. rather data bus should just be as is, and writing to it should be
	    up to the cucle of the ROM/RAM module and ignore otherwise.
    */
    //always_ff @(posedge clk_pix) begin
        assign data_in = rom_inout;
    //end
    //assign rom_inout = ( rom_enable & write_enable) ? data_out : 8'bZZZZZZZZ;
    //assign ram_inout = (~rom_enable & write_enable) ? data_out : 8'bZZZZZZZZ;

    rom_or_ram #(.RESET_VECTOR(1), .MEM_INIT_FILE("../roms/hello.mem")) rom(
	    .clk(clk_pix),
	    .write_enable(1'b0), //ROM not RAM!
       .output_enable(rom_enable),
	    .ADDRESS(address),
	    .DATA(rom_inout),
        .READPORT
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
        .vidmem(READPORT[4096:8191]),
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
