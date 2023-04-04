module sap_control_logic(
	input clk,
	input reset,
	input [3:0] instruction,
	input [7:0] flags,
	output halt,
	output maddr_latch,
	output ram_latch,
	output ram_out,
	output instruction_latch,
	output instruction_out,
	output a_reg_latch,
	output a_reg_out,
	output alu_out,
	output alu_sub,
	output b_reg_latch,
	output output_latch,
	output counter_enable,
	output counter_out,
	output jump,
	output flag_latch,
	output [15:0] CBUS_OUT
);

/*
sap_control_logic sap_control_logic_inst0(
	.clk(),
	.reset(),
	.instruction(),
	.flags(),
	.halt(),
	.maddr_latch(),
	.ram_latch(),
	.ram_out(),
	.instruction_latch(),
	.instruction_out(),
	.a_reg_latch(),
	.a_reg_out(),
	.alu_out(),
	.alu_sub(),
	.b_reg_latch(),
	.output_latch(),
	.counter_enable(),
	.counter_out(),
	.jump(),
	.flag_latch()
);
*/

localparam HALT = 16'b1000_0000_0000_0000; //Halt signal
localparam MI   = 16'b0100_0000_0000_0000; //Memoy Address In
localparam RI   = 16'b0010_0000_0000_0000; //Ram In
localparam RO   = 16'b0001_0000_0000_0000; //Ram Out
localparam IO   = 16'b0000_1000_0000_0000; //Instruction In
localparam II   = 16'b0000_0100_0000_0000; //Instruction Out
localparam AI   = 16'b0000_0010_0000_0000; //A Reg In
localparam AO   = 16'b0000_0001_0000_0000; //A Reg Out
localparam SMO  = 16'b0000_0000_1000_0000; //ALU Out
localparam SU   = 16'b0000_0000_0100_0000; //ALU Sub
localparam BI   = 16'b0000_0000_0010_0000; //B Reg In
localparam OI   = 16'b0000_0000_0001_0000; //Output Reg In
localparam CE   = 16'b0000_0000_0000_1000; //Counter Enable
localparam CO   = 16'b0000_0000_0000_0100; //Counter Out
localparam JE   = 16'b0000_0000_0000_0010; //Jump Enable
localparam FI	 = 16'b0000_0000_0000_0001; //Flag In

localparam FLAG_C = 7;
localparam FLAG_Z = 6;

reg [15:0] c_bus;
assign halt = c_bus[15];
assign maddr_latch = c_bus[14];
assign ram_latch = c_bus[13];
assign ram_out = c_bus[12];
assign instruction_out = c_bus[11];
assign instruction_latch = c_bus[10];
assign a_reg_latch = c_bus[09];
assign a_reg_out = c_bus[08];
assign alu_out = c_bus[07];
assign alu_sub = c_bus[06];
assign b_reg_latch = c_bus[05];
assign output_latch = c_bus[04];
assign counter_enable = c_bus[03];
assign counter_out = c_bus[02];
assign jump = c_bus[01];
assign flag_latch = c_bus[00];

reg HALTED;
reg [1:0] MICRO_STATE;

localparam FETCH = 0;
localparam DECODE = 1;
localparam EXECUTE = 2;

reg [3:0] MICRO_INSTR;

localparam NOP = 4'b0000;
localparam LDA = 4'b0001;
localparam ADD = 4'b0010;
localparam SUB = 4'b0011;
localparam STA = 4'b0100;
localparam LDI = 4'b0101;
localparam JMP = 4'b0110;
localparam JC  = 4'b0111;
localparam JZ  = 4'b1000;
localparam OUT = 4'b1110;
localparam HLT = 4'b1111;

always @(negedge clk) begin //Logic runs Offset from main clock
	if (reset) begin
		MICRO_STATE <= FETCH;
		HALTED <= 0;
	end else if (HALTED) begin
		HALTED <=1; //STAY STOPPED
	end else begin
		case(MICRO_STATE)
			FETCH: begin
				c_bus <= MI | CO | CE;
				MICRO_STATE <= DECODE;
				MICRO_INSTR <= 0;
			end
			DECODE: begin
				c_bus <= RO | II;
				MICRO_STATE <= EXECUTE;

			end
			EXECUTE: begin
				case(instruction)
					NOP:
						MICRO_STATE <= FETCH;
					LDA: begin
						case(MICRO_INSTR)
							0:
								c_bus <= IO | MI;
							1: begin
								c_bus <= RO | AI;
								MICRO_STATE <= FETCH;
							end
						endcase
						MICRO_INSTR <= MICRO_INSTR + 1;
					end
					ADD: begin
						case(MICRO_INSTR)
							0:
								c_bus <= IO | MI;
							1:
								c_bus <= RO | BI;
							2: begin
								c_bus <= SMO | AI | FI;
								MICRO_STATE <= FETCH;
							end
						endcase
						MICRO_INSTR <= MICRO_INSTR + 1;
					end
					SUB: begin
						case(MICRO_INSTR)
							0:
								c_bus <= IO | MI;
							1:
								c_bus <= RO | BI;
							2: begin
								c_bus <= SMO | SU | AI | FI;
								MICRO_STATE <= FETCH;
							end
						endcase
						MICRO_INSTR <= MICRO_INSTR + 1;
					end
					STA: begin
						case(MICRO_INSTR)
							0:
								c_bus <= IO | MI;
							1: begin
								c_bus <= RI | AO;
								MICRO_STATE <= FETCH;
							end
						endcase
						MICRO_INSTR <= MICRO_INSTR + 1;
					end
					LDI: begin
						case(MICRO_INSTR)
							0: begin
								c_bus <= IO | AI;
								MICRO_STATE <= FETCH;
							end
						endcase
						MICRO_INSTR <= MICRO_INSTR + 1;
					end
					JMP: begin
						case(MICRO_INSTR)
							0: begin
								c_bus <= IO | JE;
								MICRO_STATE <= FETCH;
							end
						endcase
						MICRO_INSTR <= MICRO_INSTR + 1;
					end
					JC: begin
						case(MICRO_INSTR)
							0: begin
								if(flags[FLAG_C])
									c_bus <= IO | JE;
								MICRO_STATE <= FETCH;
							end
						endcase
						MICRO_INSTR <= MICRO_INSTR + 1;
					end
					JZ: begin
						case(MICRO_INSTR)
							0: begin
								if(flags[FLAG_Z])
									c_bus <= IO | JE;
								MICRO_STATE <= FETCH;
							end
						endcase
						MICRO_INSTR <= MICRO_INSTR + 1;
					end					
					OUT: begin
						case(MICRO_INSTR)
							0: begin
								c_bus <= AO | OI;
								MICRO_STATE <= FETCH;
							end
						endcase
						MICRO_INSTR <= MICRO_INSTR + 1;
					end
					HLT: begin
						HALTED <= 1;
					end
				endcase
			end
		endcase
	end
end

assign CBUS_OUT = c_bus;

endmodule