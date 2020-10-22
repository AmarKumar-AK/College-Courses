module top;

reg [15:0] a;
reg [15:0] b;
reg addOrSub;
wire [15:0]result;

	FPA main_0(a,b,addOrSub,result);

initial
begin
	a=16'b0_11101_1011111101;
	b=16'b0_11101_1100100000;
	addOrSub=1'b0;
end

initial
begin
	$monitor("Time = %2d,\n a = %b,\n b = %b,\n Sum = %b",$time,a,b,result);
	$dumpfile("FloatingPointAdder.vcd");
	$dumpvars(0, top);
end

endmodule