`include "main.v"
module top;
reg clk,reset;
wire [15:0]out;

insFetch f1(clk,reset,out);

initial 
    begin
        #0 reset = 1'b1;
        clk = 1'b0;
    end
    
initial
#5 reset =1'b0;

always
#10  clk =  ! clk; 

    
always@(clk or reset or out)
	begin
 		$monitor($time," clk = %b reset =%b out = %b\n", clk,reset,out);
	end 

initial

	#100 $finish;

endmodule // top