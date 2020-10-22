`include "counter.v"
module top;
reg clk, reset;
wire [63:0] counter;

count dut(clk, reset, counter);

initial begin 
clk=0;
reset=1;
forever #5 clk=~clk;
end

initial begin
#1;
reset=0;
$monitor("%d",counter);
#1000 $finish;
// $display("%d",counter);
end

endmodule