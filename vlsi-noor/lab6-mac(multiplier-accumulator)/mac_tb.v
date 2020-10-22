`include "mac.v"
module top;

reg [15:0]a,b;
reg clk,reset;
wire [35:0]c;

mac m1(a,b,c,clk,reset);

initial begin
#0 clk=1; reset=1; a=200; b=300;
#5 reset=0;
end

always
begin
#5 clk=~clk;
end

always
begin
#10 a=a+5;b=b-5;
end

initial begin
    // $monitor($time  , "clk=%d, reset=%d, a=%d, b=%d, c=%d",clk,reset,a,b,c);
    $monitor($time  , " a=%d, b=%d, c=%d",a,b,c);
    #100 $finish;
end
endmodule