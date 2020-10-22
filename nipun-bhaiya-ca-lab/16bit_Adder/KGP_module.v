module KGP(a, b, kgp_one, kgp_two, cin);
input [15:0] a;
input [15:0] b;
input cin;
output [16:0] kgp_one;
output [16:0] kgp_two;

assign kgp_one[0] = cin;
assign kgp_two[0] = 1'b0;
generate
	genvar i;
	for(i=1; i<17; i=i+1) begin
		assign kgp_one[i] = a[i-1]&b[i-1];
		assign kgp_two[i] = a[i-1]^b[i-1];
	end
endgenerate

endmodule