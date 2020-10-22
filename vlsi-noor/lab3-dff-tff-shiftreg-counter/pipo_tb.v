`include "pipo.v"
module pipo_tb;
reg [3:0]d;
wire [3:0]q;
reg clk;
initial
begin
	$dumpfile("pipo_tb.vcd");
	$dumpvars(0,pipo_tb);
end

pipo p1(d,q,clk);

initial
begin
	clk=1;
end
initial
begin
	d=4'b1001;
end



always
	#5 clk=!clk;

always@(*)
begin
	$display($time," clk=%b d=%b q=%b",clk,d,q);
end

initial 
	#30 $finish;
endmodule
