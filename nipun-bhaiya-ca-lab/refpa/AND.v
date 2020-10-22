module AND(output cout, input [15:0]a, input [15:0]b, input [15:0]kgp);

assign cout = (a[15] & b[15]) | (kgp[14] & a[15] ^ b[15]);

endmodule