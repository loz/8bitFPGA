module sap_alu(
	input [7:0] a_reg_data,
	input [7:0] b_reg_data,
	inout [7:0] DATA,
	input enable,
	input sub,
	output C, //Carry Flag
	output Z //Zero Flag
);

/*
sap_alu sap_alu_inst0(
	.a_reg_data(),
	.b_reg_data(),
	.DATA(),
	.enable(),
	.sub(),
	.C(),
	.Z()
);
*/

wire [8:0] alu_plus = a_reg_data + b_reg_data;
wire [8:0] alu_minus = {1'b1,a_reg_data} - b_reg_data; //To Cause CARRY

wire [7:0]  alu_result;

assign {C,alu_result} = (sub) ? alu_minus : alu_plus;
assign Z = ({C,alu_result} == 9'd0) ? 1'b1 : 1'b0;

assign DATA = (enable) ? alu_result : 8'bZZZZZZZZ;

endmodule