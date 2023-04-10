module sd_card_scanner(clk, rst_n, key1, SD_nCS, SD_DCLK, SD_MOSI, SD_MISO, debug_string, debug_send, debug_ready);
	input            clk;
	input            rst_n;
	input				  key1;
	output           SD_nCS;
	output           SD_DCLK;
	output           SD_MOSI;
	input            SD_MISO;
	output reg [(80*8)-1:0] debug_string;
	output reg			  debug_send;
	input 				debug_ready;

parameter S_IDLE         = 0;
parameter S_READ         = 1;
parameter S_READ_DONE    = 2;
parameter S_HALT			 = 3;
parameter S_GET_BOOT_INFO = 4;


reg[6:0] state;
reg[6:0] next_state;
reg[9:0] state_rd_cnt;

wire             sd_init_done;
reg              sd_sec_read;
reg[31:0]        sd_sec_read_addr;
wire[7:0]        sd_sec_read_data;
wire             sd_sec_read_data_valid;
wire             sd_sec_read_end;

reg[9:0]         rd_cnt;
reg[7:0]         read_data;
wire [7:0]		  as_char;

reg[32:0] limit;

`include "hxchar.v"

assign as_char = (read_data < 8'h20 || read_data > 8'h7E) ? "." :
                 read_data;  // Visible characters

always @(posedge clk or negedge rst_n) begin
	if(rst_n == 1'b0) begin
		state <= S_IDLE;
		debug_string <= "RESET\n\r";
		debug_send <= 1;
		rd_cnt <= 10'd0;
		read_data <= 8'd0;	
		sd_sec_read <= 1'b0;	
		limit <= 0;
	end else begin
		if(~debug_ready) begin
			debug_send <= 0;
		end else if (debug_send) begin
			debug_send <= 0;
		end else begin
			case(state)
				S_IDLE: begin
					debug_string <= "IDLE->S_GET_BOOT_INFO\n\r";
					debug_send <= 1;
					state_rd_cnt <= 0;
					state <= S_GET_BOOT_INFO;
				end
				S_GET_BOOT_INFO: begin
					//if(state_rd_cnt == 0) begin
					//end else if(state_rd_cnt < 3) begin
					//end else
					//end
					sd_sec_read_addr <= 32'h00_00_00_00; //BOOT AREA
					state <= S_READ;
				end
				S_READ: begin
					if(sd_sec_read_data_valid == 1'b1)
							rd_cnt <= rd_cnt + 10'd1;
					else
						rd_cnt <= 10'd0;
						
					if(sd_sec_read_data_valid == 1'b1 && rd_cnt == 10'd0) begin
						read_data <= sd_sec_read_data;
						if(limit % 24 == 0)
							//debug_string <= {"\n\r[",hxchar[sd_sec_read_data],"]",as_char, " "};
							debug_string <= {"\n\r",as_char, ""};
						else
							//debug_string <= {"[",hxchar[sd_sec_read_data],"]",as_char, " "};
							debug_string <= {as_char, ""};
						debug_send <= 1;
						state <= S_READ_DONE;
						sd_sec_read <= 0;
						limit <= limit+1;

						if(limit > 4096) //MBR
							state <= S_HALT;
						//state <= S_HALT;
					end
					
					if(sd_sec_read_end == 1'b1) begin
						state <= S_HALT;
						sd_sec_read <= 1'b0;
					end else begin
						sd_sec_read <= 1'b1;
					end
				end
				S_READ_DONE: begin
					sd_sec_read_addr <= sd_sec_read_addr + 1;
					sd_sec_read <= 1;
					state <= S_READ;
				end
				S_HALT: begin
					if(key1) begin
						limit <= 0;
						debug_string <= "--Next--";
						debug_send <= 1;
						state <= S_READ;
					end
				end
			endcase
		end			
	end
end

/*
always@(posedge clk or negedge rst_n)
begin
	if(rst_n == 1'b0)
	begin
		state <= S_IDLE;
		sd_sec_read <= 1'b0;
		sd_sec_write <= 1'b0;
	end
	else if(sd_init_done == 1'b0)
	begin
		state <= S_IDLE;
	end
	else
		case(state)
			S_IDLE:
			begin
				state <= S_READ;
			end
			
			S_READ:
			begin
				if(sd_sec_read_end == 1'b1)
				begin
					state <= S_END;
					sd_sec_read <= 1'b0;
				end
				else
				begin
					sd_sec_read <= 1'b1;
				end                 
			end         
			S_END:
			begin
				if(button_negedge == 1'b1)
					state <= S_WRITE;
			end
			default:
				state <= S_IDLE;
		endcase
end
*/

sd_card_top  sd_card_top_m0(
	.clk                       (clk                    ),
	.rst                       (~rst_n                 ),
	.SD_nCS                    (SD_nCS                 ),
	.SD_DCLK                   (SD_DCLK                ),
	.SD_MOSI                   (SD_MOSI                ),
	.SD_MISO                   (SD_MISO                ),
	.sd_init_done              (sd_init_done           ),
	.sd_sec_read               (sd_sec_read            ),
	.sd_sec_read_addr          (sd_sec_read_addr       ),
	.sd_sec_read_data          (sd_sec_read_data       ),
	.sd_sec_read_data_valid    (sd_sec_read_data_valid ),
	.sd_sec_read_end           (sd_sec_read_end        )
);
	
endmodule