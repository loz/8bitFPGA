// Project F: FPGA Graphics - ported from iCEBreaker

`default_nettype none
`timescale 1ns / 1ps

module top #(parameter CORDW=12) (
    input  wire logic clk,      		    // 50 MHz clock
    input  wire logic rst_n,            // reset button
    output      logic vga_out_hs,       // VGA horizontal sync
    output      logic vga_out_vs,       // VGA vertical sync
    //output    logic dvi_de,         // DVI data enable
    output      logic [4:0] vga_out_r,  // 4-bit VGA red
    output      logic [5:0] vga_out_g,  // 4-bit VGA green
    output      logic [4:0] vga_out_b   // 4-bit VGA blue
    );
	 
	 
	 wire clk_pix;
	 wire reset;
	 wire rst_pix;
	 assign rst_pix = ~rst_n;
	 assign reset = ~rst_n;
	 
	 wire clk_sys;
	 //slow_clock #(.SIZE(16)) cpu_clock (
	//	.clk(clk),
	//	.outclock(clk_sys)
	 //);
	 assign clk_sys = clk;
	 
    //6502
    wire [15:0] address_bus;
    wire [7:0] data_bus;
    reg  [7:0] data_in;
    wire [7:0] data_out;
	 
	 virtualprobe_16bit #(.NAME("CPU0")) cpu_probe0 (
		.probe({data_in, data_out})
	  );
	 virtualprobe_16bit #(.NAME("ADDR")) addr_probe0 (
		.probe(address_bus)
	 ); 
	 
    wire write_enable;
    wire irq = 0;
    wire non_mask_irq = 0;
    wire ready = 1;
    cpu6502 cpu_6502(
    	.clk(clk_sys),
    	.reset(reset),
    	.AB(address_bus),
    	.DI(data_in),
    	.DO(data_out),
    	.WE(write_enable),
    	.IRQ(irq),
    	.NMI(non_mask_irq),
    	.RDY(ready)
    );//6502

	 always_ff @(posedge clk_sys) begin
    //    //if (~write_enable)
            data_in <= (rom_enable ? rom_out : ram_out);
    end
	 
	 //assign data_in = (rom_enable ? rom_out : ram_out);
	 
	 //This appears to be the bug.  Doesn't look like RAM reading is working!
    //assign data_bus = (write_enable) ? data_out : (rom_enable ? rom_out : ram_out);

    wire rom_enable;
    assign rom_enable = address_bus[15];
    wire [14:0] address;
    assign address = address_bus[14:0];
    wire [7:0] ram_out;
    wire [7:0] rom_out;
    rom #(.RESET_VECTOR(1), .MEM_INIT_FILE("../roms/current.mem")) rom0(
	    .clk(clk_sys),
       .output_enable(rom_enable),
	    .ADDRESS(address),
	    .DATA_OUT(rom_out)
    );
	 
	 wire [14:0] ppu_address;
	 wire [7:0]  ppu_data;
	 virtualprobe_16bit #(.NAME("PPU0")) ppu_probe0 (
		.probe({write_enable,rom_enable,clk_sys,5'd0, ppu_data})
	  );
	 virtualprobe_16bit #(.NAME("PADR")) ppu_probe1 (
		.probe({1'b0, ppu_address})
	 );

	 /*
	 ram_1port ram_1port_inst (
		.address(address),
		.clock(clk_sys),
		.data(data_out),
		.wren(write_enable),
	   .q(ram_out)
 	 );
	 */
	 /*
	 myram_2port #(.SIZE(4096)) ram_2port_inst (
		.ADDRESS(address),
		.clk(clk_sys),
		.DATA_IN(data_out),
		.write_enable(write_enable),
	   .DATA_OUT(ram_out),
		.Q1_ADDRESS(ppu_address),
		.Q1_DATA_OUT(ppu_data)
 	 );
	 */
	 
	 ram_2port	ram_2port_inst (
		.address_a ( address ),
		.address_b ( ppu_address ),
		.clock_a ( ~clk_sys ),     //Read/Write on Negative Edge
		.clock_b ( clk_pix ),
		.data_a ( data_out ),
		//.data_b ( data_b_sig ),  //PPU does not write
		.wren_a ( write_enable ),
		.wren_b ( 1'b0 ),          //PPU does not write
		.q_a ( ram_out ),
		.q_b ( ppu_data )
	);
	
	 
	 //generate video pixel clock
	 videopll_49 video_pll_m0(
		.inclk0(clk),
		.c0(clk_pix)
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
        .hsync(vga_out_hs),
        .vsync(vga_out_vs),
        .de(de)
    );
	 
   // paint colours: white inside square, blue outside
    logic [3:0] paint_r, paint_g, paint_b;
	 //logic [7:0] fake_data = 8'h42;
    ppu_char ppu(
        .clk(clk_pix),
        .rst_n(rst_n),
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
	 
    always_comb begin
        vga_out_r = (de) ? {1'b0, paint_r} : 5'h0;
        vga_out_g = (de) ? {1'b0, paint_g, 1'b0} : 5'h0;
        vga_out_b = (de) ? {1'b0, paint_b} : 5'h0;
    end
	 
endmodule
