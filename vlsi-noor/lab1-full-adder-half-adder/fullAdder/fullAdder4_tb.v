 `include "fullAdder.v"

module top;

reg [3:0]a, b;
reg cin;
wire [3:0]sum;
wire ca;

	fullAdder4 FA_0(a,b,cin,sum,ca);

initial
begin
	// a=4'b1010; b=4'b1010 ; cin=1'b0;
    // #5 a=4'b1010; b=4'b1010 ; cin=1'b1;
    // #5 a=4'b1011; b=4'b1010 ; cin=1'b0;
    // #5 a=4'b1011; b=4'b1010 ; cin=1'b1;
	a={$random}%16;	b={$random}%16;	cin=1'b0;
	#5 a={$random}%16;	b={$random}%16;	cin=1'b0;
	
end

initial
begin
	$monitor($time, " a = %d, b = %d, c = %d, Sum = %d, ca = %d",a,b,cin,sum, ca);
	$dumpfile("fullAdder4.vcd");
	$dumpvars;
end

endmodule
