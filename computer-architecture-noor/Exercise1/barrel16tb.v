`include "barrel16.v"
module barrel_shifter_16bit_tb;
  reg [15:0] in;
  reg [3:0] ctrl;
  wire [15:0] out; 
  
barrel_shifter_16bit uut(.in(in), .ctrl(ctrl), .out(out));
  
initial 
 begin
    $display($time, " << Starting the Simulation >>");
        in= 16'd0;  ctrl=4'd0; //no shift
    #10 in=16'd128; ctrl= 4'd4; //shift 4 bit
    #10 in=16'd128; ctrl= 4'd2; //shift 2 bit
    #10 in=16'd128; ctrl= 4'd1; //shift by 1 bit
    #10 in=16'b000100000000000; ctrl= 4'd8; //shift by 7bit
  end
    initial begin
      $monitor("Input=%d, Control=%d, Output=%d",in,ctrl,out);
    end
endmodule