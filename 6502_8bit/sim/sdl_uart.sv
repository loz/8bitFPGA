module sdl_uart(clk, obyte_ready, obyte, sdl_byte, sdl_byte_ready);
   input clk;
   output obyte_ready;
   output [7:0] obyte;
   input  [7:0] sdl_byte;
   input sdl_byte_ready;


   assign obyte_ready = sdl_byte_ready;
   assign obyte = sdl_byte;

endmodule