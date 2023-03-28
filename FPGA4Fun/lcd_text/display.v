module display
#(
    parameter DELAY_FRAMES = 100 //65000 // 27,000,000 (27Mhz) / 115200 Baud rate
)
(
	input clk,
	input ready,
	input [7:0] msg_byte,
	output reg init_complete,
	output reg disp_ce, //Clock Enable
	output reg disp_rw, //Read/Write
	output reg disp_rs, //Register Select
	output reg[7:0] data
);

reg [1:0] state = 0;
reg sending = 0;


localparam DEV_INIT_WAIT = 0;
localparam DEV_INIT = 1;
localparam DEV_READY = 2;

localparam SETUP_INSTRUCTIONS = 5;


reg [7:0] startupCommands[0:5];

initial begin
	startupCommands[0] = 8'b00110000; //Set 8bit mode, 2line display, 5x8 font
	startupCommands[1] = 8'b00001110; //In, cursor on, no blink
	startupCommands[2] = 8'b00000110; //Entry mode, shift cursor automaticaly
	startupCommands[3] = 8'b00000001; //Clear Display
	startupCommands[4] = 8'b00000010; //Home
end


reg [8:0] curcommand = 0;
reg [15:0] waitcounter = 0;

always @(posedge clk) begin
    case (state)
		DEV_INIT_WAIT: begin
			init_complete <= 0;
			disp_ce <= 0;
			disp_rw <= 1; //0;
			disp_rs <= 0;
			if(waitcounter < DELAY_FRAMES)
				waitcounter <= waitcounter + 1;
			else
				state <= DEV_INIT;
		end
        DEV_INIT: begin
			if (curcommand < SETUP_INSTRUCTIONS) begin
				if (~sending) begin
					data <= startupCommands[curcommand];
					disp_ce <= 1;
					disp_rw <= 0; //1;
					disp_rs <= 0;
					sending <= 1;
					curcommand <= curcommand + 1;
				end
				else begin
					disp_ce <= 0;
					sending <= 0;
				end
			end
			else begin
				init_complete <= 1;
				disp_ce <= 0;
				disp_rw <= 1; //0;
				disp_rs <= 1;
				sending <= 0;
				data <= 8'bZ;
				state <= DEV_READY;
			end
		end
		DEV_READY: begin
			if(ready) begin
				data <= msg_byte;
				disp_ce <= 1;
				disp_rw <= 0; //1;
				disp_rs <= 1;
			end
			else begin
				disp_ce <= 0;
				disp_rw <= 1; //0;
				disp_rs <= 1;
			end
		end
	endcase
end

endmodule