module dff(d,clk,reset,q);
input [35:0]d;
input clk, reset;
output [35:0]q;
reg[35:0] q;

always@(posedge clk or posedge reset)
	if(reset==1)
 		q = 36'b0;
	else
		q = d;

endmodule
