`default_nettype none

module screen
#(
  parameter STARTUP_WAIT = 32'd10000000
)
(
    input clk,
    output io_sclk,
    output io_sdin,
    output io_cs,
    output io_dc,
    output io_reset,
    output reg [7:0] led
);

// Constants for interacting with display registers.
localparam ST7789_TFTWIDTH    = 240;
localparam ST7789_TFTHEIGHT   = 240;

localparam ST7789_NOP         = 8'h00;
localparam ST7789_SWRESET     = 8'h01;
localparam ST7789_RDDID       = 8'h04;
localparam ST7789_RDDST       = 8'h09;
localparam ST7789_RDDPM       = 8'h0A;
localparam ST7789_RDDMADCTL   = 8'h0B;
localparam ST7789_RDDCOLMOD   = 8'h0C;
localparam ST7789_RDDIM       = 8'h0D;
localparam ST7789_RDDSM       = 8'h0E;
localparam ST7789_RDDSDR      = 8'h0F;

localparam ST7789_SLPIN       = 8'h10;
localparam ST7789_SLPOUT      = 8'h11;
localparam ST7789_PTLON       = 8'h12;
localparam ST7789_NORON       = 8'h13;

localparam ST7789_INVOFF      = 8'h20;
localparam ST7789_INVON       = 8'h21;
localparam ST7789_GAMSET      = 8'h26;
localparam ST7789_DISPOFF     = 8'h28;
localparam ST7789_DISPON      = 8'h29;
localparam ST7789_CASET       = 8'h2A;
localparam ST7789_RASET       = 8'h2B;
localparam ST7789_RAMWR       = 8'h2C;
localparam ST7789_RAMRD       = 8'h2E;

localparam ST7789_PTLAR       = 8'h30;
localparam ST7789_VSCRDEF     = 8'h33;
localparam ST7789_TEOFF       = 8'h34;
localparam ST7789_TEON        = 8'h35;
localparam ST7789_MADCTL      = 8'h36;
localparam ST7789_VSCRSADD    = 8'h37;
localparam ST7789_IDMOFF      = 8'h38;
localparam ST7789_IDMON       = 8'h39;
localparam ST7789_COLMOD      = 8'h3A;
localparam ST7789_RAMWRC      = 8'h3C;
localparam ST7789_RAMRDC      = 8'h3E;

localparam ST7789_TESCAN      = 8'h44;
localparam ST7789_RDTESCAN    = 8'h45;

localparam ST7789_WRDISBV     = 8'h51;
localparam ST7789_RDDISBV     = 8'h52;
localparam ST7789_WRCTRLD     = 8'h53;
localparam ST7789_RDCTRLD     = 8'h54;
localparam ST7789_WRCACE      = 8'h55;
localparam ST7789_RDCABC      = 8'h56;
localparam ST7789_WRCABCMB    = 8'h5E;
localparam ST7789_RDCABCMB    = 8'h5F;

localparam ST7789_RDABCSDR    = 8'h68;

localparam ST7789_RDID1       = 8'hDA;
localparam ST7789_RDID2       = 8'hDB;
localparam ST7789_RDID3       = 8'hDC;

localparam ST7789_RAMCTRL     = 8'hB0;
localparam ST7789_RGBCTRL     = 8'hB1;
localparam ST7789_PORCTRL     = 8'hB2;
localparam ST7789_FRCTRL1     = 8'hB3;

localparam ST7789_GCTRL       = 8'hB7;
localparam ST7789_DGMEN       = 8'hBA;
localparam ST7789_VCOMS       = 8'hBB;

localparam ST7789_LCMCTRL     = 8'hC0;
localparam ST7789_IDSET       = 8'hC1;
localparam ST7789_VDVVRHEN    = 8'hC2;

localparam ST7789_VRHS        = 8'hC3;
localparam ST7789_VDVSET      = 8'hC4;
localparam ST7789_VCMOFSET    = 8'hC5;
localparam ST7789_FRCTR2      = 8'hC6;
localparam ST7789_CABCCTRL    = 8'hC7;
localparam ST7789_REGSEL1     = 8'hC8;
localparam ST7789_REGSEL2     = 8'hCA;
localparam ST7789_PWMFRSEL    = 8'hCC;

localparam ST7789_PWCTRL1     = 8'hD0;
localparam ST7789_VAPVANEN    = 8'hD2;
//localparam ST7789_CMD2EN      = 8'hDF5A6902; ??This is much bigger
localparam ST7789_PVGAMCTRL   = 8'hE0;
localparam ST7789_NVGAMCTRL   = 8'hE1;
localparam ST7789_DGMLUTR     = 8'hE2;
localparam ST7789_DGMLUTB     = 8'hE3;
localparam ST7789_GATECTRL    = 8'hE4;
localparam ST7789_PWCTRL2     = 8'hE8;
localparam ST7789_EQCTRL      = 8'hE9;
localparam ST7789_PROMCTRL    = 8'hEC;
localparam ST7789_PROMEN      = 8'hFA;
localparam ST7789_NVMSET      = 8'hFC;
localparam ST7789_PROMACT     = 8'hFE;

//Colours for convenience
localparam ST7789_BLACK       = 16'h0000; //0b 00000 000000 00000
localparam ST7789_BLUE        = 16'h001F; //0b 00000 000000 11111
localparam ST7789_GREEN       = 16'h07E0; //0b 00000 111111 00000
localparam ST7789_RED         = 16'hF800; //0b 11111 000000 00000
localparam ST7789_CYAN        = 16'h07FF; //0b 00000 111111 11111
localparam ST7789_MAGENTA     = 16'hF81F; //0b 11111 000000 11111
localparam ST7789_YELLOW      = 16'hFFE0; //0b 11111 111111 00000
localparam ST7789_WHITE       = 16'hFFFF; //0b 11111 111111 11111

  localparam STATE_INIT_POWER = 8'd0;
  localparam STATE_LOAD_INIT_CMD = 8'd1;
  localparam STATE_SEND = 8'd2;
  localparam STATE_CHECK_FINISHED_INIT = 8'd3;
  localparam STATE_LOAD_DATA = 8'd4;

  reg [32:0] counter = 0;
  reg [2:0] state = 0;

  reg dc = 1;
  reg sclk = 1;
  reg sdin = 0;
  reg reset = 1;
  reg cs = 0;

  reg [7:0] dataToSend = 0;
  reg [3:0] bitNumber = 0;  
  reg [9:0] pixelCounter = 0;

  localparam SETUP_INSTRUCTIONS = 64;

localparam COMMAND = 1'b0;
localparam DATA = 1'b1;
localparam ZERO_BYTE = 8'h00;

// COMMANDS ARE CMD, MODE (Data/Command)
reg [(SETUP_INSTRUCTIONS*9)-1:0] startupCommands = {
   ST7789_SLPOUT, COMMAND,
   ST7789_MADCTL, COMMAND,
   ZERO_BYTE, DATA,
   ST7789_COLMOD, COMMAND,
   8'h05, DATA,
   ST7789_PORCTRL, COMMAND,
   8'h0C, DATA,
   8'h0C, DATA,
   ST7789_GCTRL, COMMAND,
   8'h35, DATA,

   ST7789_VCOMS, COMMAND,
   8'h1A, DATA,
   ST7789_LCMCTRL, COMMAND,
   8'h2C, DATA,
   ST7789_VDVVRHEN, COMMAND,
   8'h01, DATA,
   ST7789_VRHS, COMMAND,
   8'h0B, DATA,
   ST7789_VDVSET, COMMAND,
   8'h20, DATA,

   ST7789_FRCTR2, COMMAND,
   8'h0F, DATA,
   ST7789_PWCTRL1, COMMAND,
   8'hA4, DATA,
   8'hA1, DATA,
   ST7789_INVON, COMMAND,
   ST7789_PVGAMCTRL, COMMAND,
   8'h00, DATA,
   8'h19, DATA,
   8'h1E, DATA,

   8'h0A, DATA,
   8'h09, DATA,
   8'h15, DATA,
   8'h3D, DATA,
   8'h44, DATA,
   8'h51, DATA,
   8'h12, DATA,
   8'h03, DATA,
   8'h00, DATA,
   8'h3F, DATA,

   8'h3F, DATA,
   ST7789_NVGAMCTRL, COMMAND,
   8'h00, DATA,
   8'h18, DATA,
   8'h1E, DATA,
   8'h0A, DATA,
   8'h09, DATA,
   8'h25, DATA,
   8'h3F, DATA,
   8'h43, DATA,

   8'h52, DATA,
   8'h33, DATA,
   8'h03, DATA,
   8'h00, DATA,
   8'h3F, DATA,
   8'h3F, DATA,
   ST7789_DISPON, COMMAND,
   ST7789_CASET, COMMAND,
   8'h00, DATA,
   8'd240, DATA, //240px wide

   ST7789_RASET, COMMAND,
   8'h00, DATA,
   8'd240, DATA, //240px tall
   ST7789_RAMWR, COMMAND
};

  reg [7:0] commandIndex = SETUP_INSTRUCTIONS * 9; //57 9bit instructions {byte,mode}

  assign io_sclk = sclk;
  assign io_sdin = sdin;
  assign io_dc = dc;
  assign io_reset = reset;
  assign io_cs = cs;

  reg [7:0] screenBuffer [1023:0];
  initial $readmemh("image.hex", screenBuffer);

  reg [7:0] spi_byte;
  reg spi_dmode;

  always @(posedge clk) begin
    case (state)
      STATE_INIT_POWER: begin
        counter <= counter + 1;
        if (counter < STARTUP_WAIT)
          reset <= 1;
        else if (counter < STARTUP_WAIT * 2)
          reset <= 0;
        else if (counter < STARTUP_WAIT * 3)
          reset <= 1;
        else begin
          state <= STATE_LOAD_INIT_CMD;
          counter <= 32'b0;
        end
      end
      STATE_LOAD_INIT_CMD: begin
        led <= 7'b011111;
        {spi_byte, spi_dmode} <= startupCommands[(commandIndex-1)-:9'd8];
        dc <= spi_dmode; //MODE
        dataToSend <= spi_byte; //BYTE
        state <= STATE_SEND;
        bitNumber <= 3'd7;
        cs <= 0;
        commandIndex <= commandIndex - 8'd9; //MOVE to next COMMAND
      end
      STATE_SEND: begin
        if (counter == 32'd0) begin
          sclk <= 0;
          sdin <= dataToSend[bitNumber];
          counter <= 32'd1;
        end
        else begin
          counter <= 32'd0;
          sclk <= 1;
          if (bitNumber == 0)
            state <= STATE_CHECK_FINISHED_INIT;
          else
            bitNumber <= bitNumber - 1;
        end
      end
      STATE_CHECK_FINISHED_INIT: begin
          cs <= 1;
          if (commandIndex == 0)
            state <= STATE_LOAD_DATA; 
          else
            state <= STATE_LOAD_INIT_CMD; 
      end
      STATE_LOAD_DATA: begin
          led <= 7'b101111;
          pixelCounter <= pixelCounter + 1;
          cs <= 0;
          dc <= 1;
          bitNumber <= 3'd7;
          state <= STATE_SEND;
          if (pixelCounter < 136)
            dataToSend <= 8'b01010111;
          else
            dataToSend <= 0;
        /*
        pixelCounter <= pixelCounter + 1;
        cs <= 0;
        dc <= 1;
        bitNumber <= 3'd7;
        state <= STATE_SEND;
        dataToSend <= screenBuffer[pixelCounter];
        */
      end
    endcase
  end
endmodule
