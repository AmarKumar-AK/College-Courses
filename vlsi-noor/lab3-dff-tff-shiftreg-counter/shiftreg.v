`include "dff.v"
`include "mux.v"

module shiftreg(a,s,q,clk,reset);
input [3:0]a;
input [1:0]s;
input clk,reset;
output [3:0]q;
wire x0,x1,x2,x3;

mux m1(q[0],q[1],1'b0,a[0],s,x0);
dff d1(x0,clk,reset,q[0]);

mux m2(q[1],q[2],q[0],a[1],s,x1);
dff d2(x1,clk,reset,q[1]);

mux m3(q[2],q[3],q[1],a[2],s, x2);
dff d3(x2,clk,reset,q[2]);

mux m4(q[3],1'b0,q[2],a[3],s,x3);
dff d4(x3,clk,reset,q[3]);

endmodule
