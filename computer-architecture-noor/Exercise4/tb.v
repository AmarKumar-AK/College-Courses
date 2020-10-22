`include "bshift.v"
module top;
reg [15:0]a;
reg [3:0]select;
reg direction;
wire [15:0]out;

bshift b1(a,select,direction,out);

initial begin
    a=16'd11; select=4'd2; direction=1'b0;
end

initial begin
    $monitor("a=%b   out=%b",a,out);
end
endmodule