`include "mac/mac.v"
module top;
reg [15:0]a,b;
reg clk,reset;
wire [35:0]c;
mac m1(a,b,c,clk,reset);
initial
begin
#0 clk=1; reset=1; a=0; b=0;
#5 reset=0;
end
always
begin
#5 clk=~clk;
end
always
begin
#10 a=0; b=4;
#10 a=1; b=6;
#10 a=4; b=17;
#10 a=9; b=34;
#10 a=16; b=57;
#10 a=25; b=86;
#10 a=36; b=121;
#10 a=49; b=162;
#10 a=64; b=209;
#10 a=81; b=262;
#10 a=100; b=321;
#10 a=121; b=410;
end
initial begin
	#121$display("%d",c);
	#120 $finish;
end
endmodule
