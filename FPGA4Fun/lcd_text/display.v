module display(
	input clk,
	input ready,
	input [7:0] msg_byte,
	output reg init_complete,
	output disp_ce, //Clock Enable
	output disp_rw, //Read/Write
	output disp_rs, //Register Select
	output reg[7:0] data
);

reg [1:0] state = 0;
reg sending = 0;

localparam DEV_INIT = 0;
localparam DEV_READY = 1;

localparam SETUP_INSTRUCTIONS = 5;

reg [(SETUP_INSTRUCTIONS*8)-1:0] startupCommands = {
	8'b00111000, //Set 8bit mode, 2line display, 5x8 font
	8'b00001110, //In, cursor on, no blink
	8'b00000110, //Entry mode, shift cursor automaticaly
	8'b00000001, //Clear Display
	8'b00000010 //Home
};

reg [8:0] curcommand = 0;

always @(posedge clk) begin
    case (state)
        DEV_INIT: begin
			if (curcommand < SETUP_INSTRUCTIONS) begin
				if (~sending) begin
					init_complete <= 0;
					data <= startupCommands[curcommand];
					disp_ce <= 1;
					disp_rw <= 1;
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
				sending <= 0;
				state <= DEV_READY;
			end
		end
		DEV_READY: begin
			if(ready) begin
				data <= msg_byte;
				disp_ce <= 1;
				disp_rw <= 1;
				disp_rs <= 1;
			end
			else begin
				disp_ce <= 0;
				disp_rw <= 0;
				disp_rs <= 0;
			end
		end
	endcase
end

endmodule