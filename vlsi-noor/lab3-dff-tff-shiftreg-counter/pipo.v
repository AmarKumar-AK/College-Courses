`include "dff.v"

module pipo(d,q,clk);
	input [3:0]d;
	input clk;
	output [3:0]q;

dff d1(d[0],clk,1'b0,q[0]);
dff d2(d[1],clk,1'b0,q[1]);
dff d3(d[2],clk,1'b0,q[2]);
dff d4(d[3],clk,1'b0,q[3]);
endmodule	
