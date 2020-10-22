// `include "tff.v"

module tff_tb;
reg t, clk, reset;
wire q;

initial
	begin
$dumpfile("tff_tb.vcd");
$dumpvars(0,tff_tb);
end

tff t1(t, clk, reset, q);


initial
begin
reset=0;
clk =0;
t=0;
end

always 
#5  clk =  ! clk; 

  always #10 t=~t;


always@(clk)
	begin
 		$display($time,"  t=%b, clk=%b, rst=%b,q=%b\n", t, clk, reset, q);
	end 

initial

	#100 $finish;
endmodule
