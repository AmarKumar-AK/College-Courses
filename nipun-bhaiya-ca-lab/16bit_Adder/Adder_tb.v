`include "../16bit_Adder/Main.v"

module top;

reg [15:0] a;
reg [15:0] b;
reg cin;
wire [15:0] sum;
wire overflow;

	RCA main_0(a,b,overflow,cin,sum);

initial
begin
	a=`A;
	b=`B;
	cin=`cin;
end

initial
begin
	$monitor("Time = %2d, a = %d, b = %d, overflow = %d, Sum = %d",$time,a,b,overflow,sum);
	$dumpfile("Adder.vcd");
	$dumpvars(0, top);
end

endmodule