`include "main.v"
module top;
reg [15:0]a,b;
reg [2:0]select;
wire [15:0]out;

lu_new l1(a,b,out,select);

initial begin
    a=16'd10; b=16'd12; select=3'b000;
    #5 select=3'b001;
    #5 select=3'b010;
    #5 select=3'b011;
    #5 select=3'b100;
    #5 select=3'b101;
    #5 select=3'b110;
    #5 select=3'b111;
end

initial begin
    $monitor("a=%b    b=%b     res=%b",a,b,out);
end
endmodule