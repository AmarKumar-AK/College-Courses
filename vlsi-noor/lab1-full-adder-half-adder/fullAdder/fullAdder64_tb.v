 `include "fullAdder32.v"
 `include "fullAdder16.v"
 `include "fullAdder8.v"
 `include "fullAdder4.v"
 `include "fullAdder.v"

module top;

reg [63:0]a, b;
reg cin;
wire [63:0]sum;
wire ca;

	fullAdder64 FA_0(a,b,cin,sum,ca);

initial
begin
	a={$random}%500; b={$random}%300000 ; cin=1'b0;
    #5 a={$random}%300000; b={$random}%300000 ; cin=1'b1;
    #5 a={$random}%300000; b={$random}%300000 ; cin=1'b0;
    #5 a={$random}%300000; b={$random}%300000 ; cin=1'b1;
	
end

initial
begin
	$monitor($time, "a = %d, b = %d, c = %d, Sum = %d, ca = %d",a,b,cin,sum, ca);
	$dumpfile("fullAdder64.vcd");
	$dumpvars;
end

endmodule
