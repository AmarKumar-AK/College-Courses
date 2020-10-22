`include "mac/multi16.v"
`include "mac/fullAdder36.v"
`include "mac/dff.v"
module mac(a,b,c,clk,reset);
input [15:0]a,b;
output [35:0]c;
input clk,reset;
wire [35:0]w,r;
wire ca;
// wire [35:0]result;

multi16 m1(a,b,w[31:0]);
assign w[32]=1'b0;
assign w[33]=1'b0;
assign w[34]=1'b0;
assign w[35]=1'b0;


dff d1(c,clk,reset,r);
fullAdder36 f1(r,w,1'b0,c,ca);

endmodule


