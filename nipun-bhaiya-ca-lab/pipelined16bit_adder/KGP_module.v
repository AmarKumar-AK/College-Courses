module KGP(a, b, kgp_one, kgp_two);
input [15:0] a;
input [15:0] b;
output [16:0] kgp_one;
output [16:0] kgp_two;

// always @ (kgp_two | kgp_one) begin
// 	$display("k %h %h", kgp_two, kgp_one);
// end
assign kgp_one[0] = 1'b0; //cin
assign kgp_two[0] = 1'b0;
generate
	genvar i;
	for(i=1; i<17; i=i+1) begin
		assign kgp_one[i] = a[i-1]&b[i-1];
		assign kgp_two[i] = a[i-1]^b[i-1];
	end
endgenerate

endmodule