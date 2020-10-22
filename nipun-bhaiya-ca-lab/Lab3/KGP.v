module KGP(output [16:0]kgp1, output [16:0]kgp2, input [15:0]a, input [15:0]b);


genvar i;
generate

	for(i=16;i>0;i=i-1) begin
		assign kgp1[i] = a[i-1] & b[i-1];
		assign kgp2[i] = a[i-1] ^ b[i-1];
	end
endgenerate

endmodule