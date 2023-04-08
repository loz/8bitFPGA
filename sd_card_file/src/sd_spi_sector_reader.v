
//--------------------------------------------------------------------------------------------------------
// Module  : sd_spi_sector_reader
// Type    : synthesizable, IP's sub module
// Standard: SystemVerilog 2005 (IEEE1800-2005)
//--------------------------------------------------------------------------------------------------------

module sd_spi_sector_reader #(
    parameter SPI_CLK_DIV = 50  // SD spi_sck freq = clk freq/(2*SPI_CLK_DIV)
                                // modify SPI_CLK_DIV to change the SPI speed
                                // for example, when clk=50MHz, SPI_CLK_DIV=50,then spi_sck=50MHz/(2*50)=500kHz
                                // 500kHz is a typical SPI speed for SDcard
)(
    input  rstn,
    input  clk,
    // SDcard spi interface
    output spi_ssn, spi_sck, spi_mosi,
    input  spi_miso,
    // card status (for debug)
    output [ 1:0]  card_type,
    output [ 3:0]  card_stat,
    // user read sector command interface
    input  start, 
    input  [31:0]  sector_no,
    output reg done,
    // data readout
    output rvalid,
    output [ 8:0]  raddr,  // raddr from 0 to 511, because the sector size is 512
    output [ 7:0]  rdata
);

localparam CMD8_VALID_RES  = 8'hAA;

localparam NONE = 0;
localparam SDv1 = 1;
localparam SDv2 = 2;
localparam SDHCv2 = 3;
reg [1:0] cardtype = NONE;
//enum logic [1:0] {NONE, SDv1, SDv2, SDHCv2} cardtype = NONE;
localparam RESET = 0;
localparam CMD0  = 1;
localparam CMD8  = 2;
localparam CMD1  = 3;
localparam CMD8FAILED = 4;
localparam ACMD41 = 5;
localparam CMD58 = 6;
localparam CMD16 = 7;
localparam IDLE = 8;
localparam READING = 9;
reg [3:0] cardstate = RESET;
//enum logic [3:0] {RESET, CMD0, CMD8, CMD1, CMD8FAILED, ACMD41, CMD58, CMD16, IDLE, READING} cardstate = RESET;

reg  spistart=1'b0;
wire spidone;
reg  [47:0] cmd=0, acmd=0;
wire [47:0] cmdres;
reg  [ 7:0] waitcycle=64, precycle=0, startcycle=0, cmdrcycle=0, acmdcycle=0, midcycle=0, recycle=0;
wire [ 7:0] cmdrsp, acmdrsp, rwrsp;
reg  [31:0] target_sector = 0;
wire [31:0] target_sector_w = (cardtype==SDHCv2) ? sector_no : ( (cardtype==SDv2 || cardtype==SDv1) ? sector_no*512 : 0 );

initial done = 1'b0;
initial begin rvalid = 1'b0; raddr = 9'h0; rdata = 8'h0; end
assign card_type = cardtype;
assign card_stat = cardstate;

always @ (posedge clk or negedge rstn) begin
    if(~rstn) begin
        done <= 1'b0;
        spistart<=1'b0; cmd<=48'h00_00000000_00; acmd<=48'h00_00000000_00; waitcycle<= 64; precycle<=  0; startcycle<=0; cmdrcycle<=0; acmdcycle<=0; midcycle<= 0;recycle<=0;
        cardtype  <=  NONE;
        cardstate <= RESET;
        target_sector <= 0;
    end else begin
        done <= 1'b0;
        spistart<=1'b0; cmd<=48'h00_00000000_00; acmd<=48'h00_00000000_00; waitcycle<= 64; precycle<=  0; startcycle<=0; cmdrcycle<=0; acmdcycle<=0; midcycle<= 0;recycle<=0;
        if(spidone) begin
            case(cardstate)
            RESET : cardstate <= CMD0;
            CMD0  : if(cmdrsp==8'h01) cardstate <= CMD8;
            CMD1  : if(cmdrsp==8'h00) cardstate <= IDLE;
            CMD8  : if(cmdrsp==8'h01) begin  // SDv2.0
                        if(cmdres[0+:8]==CMD8_VALID_RES)  // CMD8 success
                            cardstate <= ACMD41;
                        else
                            cardstate <= CMD8FAILED;
                    end else begin   // SDv1
                        cardstate <= CMD1;   // TODO: SDv1
                        cardtype  <= SDv1;
                    end
            ACMD41: if(cmdrsp==8'h01 && acmdrsp==8'h00) cardstate <= CMD58;
            CMD58 : if(~cmdrsp[7]) begin  // SDv2.0
                        if((cmdres[3*8+:8]&8'hC0)==8'hC0)  // done initialize, SDHCv2
                            cardtype  <= SDHCv2;
                        else                               // done initialize, SDv2
                            cardtype  <= SDv2;
                        cardstate <= CMD16;
                    end
            CMD16 :    if(cmdrsp==8'h00)  cardstate <= IDLE;
            IDLE  :    if( (~cmdrsp[7]) && rwrsp==8'hFE) begin cardstate <= READING;            end
            READING  : if( (~cmdrsp[7]) && rwrsp==8'hFE) begin cardstate <= IDLE   ; done<=1'b1; end
            endcase
        end else begin
            case(cardstate)
            RESET  : cardstate <= CMD0;
            CMD0   : begin    spistart<=1'b1; cmd<=48'h40_00000000_95 ; acmd<=48'h00_00000000_00; waitcycle<=255; precycle<=20; startcycle<=0; cmdrcycle<=0; acmdcycle<=0; midcycle<= 0;recycle<=0; end
            CMD1   : begin    spistart<=1'b1; cmd<=48'h41_00000000_ff ; acmd<=48'h00_00000000_00; waitcycle<= 16; precycle<= 0; startcycle<=0; cmdrcycle<=0; acmdcycle<=0; midcycle<= 0;recycle<=0; end
            CMD8   : begin    spistart<=1'b1; cmd<=48'h48_000001aa_87 ; acmd<=48'h00_00000000_00; waitcycle<= 16; precycle<= 0; startcycle<=1; cmdrcycle<=4; acmdcycle<=0; midcycle<= 0;recycle<=0; end
            ACMD41 : begin    spistart<=1'b1; cmd<=48'h77_00000000_FF ; acmd<=48'h69_40000000_FF; waitcycle<= 16; precycle<= 0; startcycle<=1; cmdrcycle<=0; acmdcycle<=6; midcycle<= 0;recycle<=0; end
            CMD58  : begin    spistart<=1'b1; cmd<=48'h7a_00000000_FF ; acmd<=48'h00_00000000_00; waitcycle<= 16; precycle<= 0; startcycle<=1; cmdrcycle<=4; acmdcycle<=0; midcycle<= 0;recycle<=0; end
            CMD16  : begin    spistart<=1'b1; cmd<=48'h50_00000200_FF ; acmd<=48'h00_00000000_00; waitcycle<= 16; precycle<= 0; startcycle<=1; cmdrcycle<=2; acmdcycle<=0; midcycle<= 0;recycle<=0; end
            IDLE   : if(start) begin
                       target_sector <= target_sector_w;
                       spistart<=1'b1; cmd<={8'h51,target_sector_w,8'hFF}; acmd<=48'h00_00000000_00; waitcycle<=  6; precycle<= 0; startcycle<=0; cmdrcycle<=4; acmdcycle<=0; midcycle<=99;recycle<=2;
                     end
            READING: begin
                       spistart<=1'b1; cmd<={8'h51,target_sector  ,8'hFF}; acmd<=48'h00_00000000_00; waitcycle<=  6; precycle<= 0; startcycle<=0; cmdrcycle<=4; acmdcycle<=0; midcycle<=99;recycle<=2;
                     end
            endcase
        end
    end
end

reg rvalid_session;
reg [15:0] rindex_session;
reg [ 7:0] rdata_session;

always @ (posedge clk or negedge rstn) begin
    if(~rstn) begin
        rvalid <= 1'b0;
        raddr  <= 9'h0;
        rdata  <= 8'h0;
    end else begin
        if(cardstate==READING && rvalid_session && (rindex_session>=16'd2 && rindex_session<16'd514)) begin
            rvalid <= 1'b1;
            raddr  <= 9'd1 - $unsigned(rindex_session[8:0]); //(9)'(rindex_session);
            rdata  <= rdata_session;
        end else begin
            rvalid <= 1'b0;
            raddr  <= 9'h0;
            rdata  <= 8'h0;
        end
    end
end

spi_session spi_session_i (
    .rstn         ( rstn            ),
    .clk          ( clk             ),
    // SPI interface
    .spi_ssn      ( spi_ssn         ),
    .spi_sck      ( spi_sck         ),
    .spi_mosi     ( spi_mosi        ),
    .spi_miso     ( spi_miso        ),
    // control interface
    .start        ( spistart        ),
    .done         ( spidone         ),
    .clkdiv       ( SPI_CLK_DIV     ),
    .cmd          ( cmd             ),
    .acmd         ( acmd            ),
    // control interface (cycle time control parameters)
    .waitcycle    ( waitcycle       ),
    .precycle     ( precycle        ),
    .startcycle   ( startcycle      ),
    .cmdcycle     ( 6               ),
    .cmdrcycle    ( cmdrcycle       ),
    .acmdcycle    ( acmdcycle       ),
    .acmdrcycle   ( 0               ),
    .midcycle     ( midcycle        ),
    .stopcycle    ( 255             ),
    .recycle      ( recycle         ),
    // cmd result interface
    .cmdrsp       ( cmdrsp          ), 
    .acmdrsp      ( acmdrsp         ),
    .rwrsp        ( rwrsp           ),
    .cmdres       ( cmdres          ),
    .acmdres      (                 ),
    // data readout
    .rvalid       ( rvalid_session  ),
    .rindex       ( rindex_session  ),
    .rdata        ( rdata_session   )
);

endmodule
