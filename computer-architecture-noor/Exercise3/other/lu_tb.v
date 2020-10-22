`include "lu.v"
module top;
reg [15:0]a;
wire [15:0]res;

// and16 a1(a,b,res);
twoscomplement a1(a,res);

initial begin
    a=16'd65535;
end

initial begin
    $monitor("a=%b         res=%b",a,res);
end
endmodule