// `include "updowncounter.v"

module updowncounter_tb;
reg clk,reset;
wire [3:0]q;

reg a;
reg t;
initial
begin
	$dumpfile("updowncounter_tb.vcd");
	$dumpvars(0,updowncounter_tb);
end

sync_updown u1(a,t,clk,reset,q);


initial
begin
a=1;
clk =0;
t=1;
reset=1;
#5 reset=0;
// after 145 unit time 
#145 a=0;
end

always 
#5  clk =  ! clk; 



always@(q)
	begin
 		$display($time ," clk=%b, rst=%b,q=%b\n", clk, reset, q);
	end 

initial

	#300 $finish;
endmodule
