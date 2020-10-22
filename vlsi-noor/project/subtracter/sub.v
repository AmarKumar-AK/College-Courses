module sub1( a, b, c, d, br);
input a, b, c;
output d, br;
assign d= a ^ b ^ c;
assign br=(( ~a)& (b ^ c)) | (b & c);
endmodule