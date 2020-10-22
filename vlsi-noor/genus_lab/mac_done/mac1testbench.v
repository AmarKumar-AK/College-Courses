// `include "mac1att.v"


module top ;


reg [15:0] A,B;
reg clk,reset;
wire [37:0]out;

// wire [37:0];
MAC m12(A,B,out,clk,reset);

initial begin
  clk = 0;
  reset =1;
  clk = 1;
end

always
  #5 clk =!clk;

// end
initial
begin
  #2;
  A = 16'd0; B = 16'd0;#10 reset = 0;
  #30 A = 16'd12 ; B = 16'd14;
  #30 A = 16'd102 ; B = 16'd14;
  #30 A = 16'd72 ; B = 16'd54;
  #30 A = 16'd0; B=16'd0;
  #200$finish;
end

initial begin
  $monitor($time,"\nA %d B  %d out = %d",A,B,out);
end



endmodule // top
