// `include "multi16.v"
`include "main.v"
module top;
reg [15:0]a,b;
wire [15:0]res;

fpm m1(a,b,res);

initial begin
// a=2.25  // b=-126.5  // res = -286.875
    a=16'b0100000010000000; b=16'b1101100000000100;
end

initial begin
    $monitor("a=%b b=%b  res=%b",a,b,res);
end
endmodule