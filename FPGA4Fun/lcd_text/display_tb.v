`include "display.v"

module test();
    reg clk = 0;
    reg ready = 0;
    reg [7:0] message = 8'h00;

    wire complete = 0;
    wire ce; // = 0;
    wire rw; // = 0;
    wire rs; // = 0;
    wire [7:0] tdata;
    
    display #(16'd2) d(
        .clk(clk),
        .ready(ready),
        .msg_byte(message),
        .init_complete(complete),
        .disp_ce(ce),
        .disp_rw(rw),
        .disp_rs(rs),
        .data(tdata)
    );


    always
        #1 clk = ~clk;

    initial begin
        $display("Starting DISPLAY_INIT");
        $monitor("CE %u", ce);
        $monitor("CE %u", rw);
        $monitor("CE %u", rs);
        $monitor("Data %b", tdata);
        #30 message=8'd40;
        #1 ready=1;
        #1 ready=0;

        #1000 $finish;
    end

    initial begin
        $dumpfile("display.vcd");
        $dumpvars(0,test);
    end
endmodule
