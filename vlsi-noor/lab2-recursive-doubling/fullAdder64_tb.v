`include "fullAdder64.v"
module top;
reg [63:0]a,b;
reg cin;
wire [63:0]sum;
wire ca;

fullAdder64 F1(a,b,c,sum,ca);

initial
begin
#0 a=100; b=200; cin=0;
end

initial
begin
$monitor("%d",sum);
end
endmodule