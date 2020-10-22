// `include "Wallac16bit.v"

module top1;

reg [15:0] a;
reg [15:0] b;
wire [31:0] asn;

wall16bit w12(a,b,asn);

initial
begin

a = 16'd38 ; b = 16'd61 ; #10   ;
a = 16'd255 ; b = 16'd255 ; #10   ;
a = 16'd58 ; b = 16'd381 ; #10   ;
a = 16'd88 ; b = 16'd61 ; #10   ;
a = 16'd6109 ; b = 16'd4589 ; #10;


end




initial
begin
$monitor("time = %2d , a = %d , b = %d ,ans = %d",$time , a,b, asn);
$dumpfile("wallace16_tb.vcd");
$dumpvars(0,top1);

end





endmodule
