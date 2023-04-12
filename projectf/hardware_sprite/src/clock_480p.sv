module clock_480p (
	input wire logic clk_50m,
	input wire logic rst_n,
	output logic clk_pix
	);

logic [1:0] ctr;

assign clk_pix = ctr[1];

always @(posedge clk_50m) begin
	ctr <= ctr + 1'b1;
end 
	
endmodule