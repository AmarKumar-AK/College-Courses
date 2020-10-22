module KGP(a, b, kgp_one, kgp_two);
input [31:0] a;
input [31:0] b;
output [32:0] kgp_one;
output [32:0] kgp_two;

assign kgp_one[0] = 1'b0;
assign kgp_two[0] = 1'b0;
generate
	genvar i;
	for(i=1; i<33; i=i+1) begin
		assign kgp_one[i] = a[i-1]&b[i-1];
		assign kgp_two[i] = a[i-1]^b[i-1];
	end
endgenerate

endmodule