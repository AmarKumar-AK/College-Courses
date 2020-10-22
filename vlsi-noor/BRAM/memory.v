`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 01/28/2018 09:38:06 PM
// Design Name: 
// Module Name: memory
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module memory_in(
    input clk,
    input wen_in,
    input [5:0] addr_in,
    input [7:0] dina_in,
    output [7:0] dout_in
    );
   
    blk_mem_gen_0 memory_mod_in(clk, wen_in, addr_in, dina_in, dout_in);
endmodule

//////////////////////////////////////////////////////////////////////////////////

module memory_out(
    input clk,
    input wen_out,
    input [5:0] addr_out,
    input [8:0] dina_out,
    output [8:0] dout_out
    );
   
    blk_mem_gen_1 memory_mod_out(clk, wen_out, addr_out, dina_out, dout_out);
endmodule


//////////////////////////////////////////////////////////////////////////////////
module FullAdder( a, b, c, sum, carry);
	input a,b,c;
	output sum,carry;
	assign sum = a^b^c;
	assign carry = (a&b)|(b&c)|(c&a);
endmodule

module FullAdder4Bit( a, b, cin, sum, carry);
	input [3:0] a,b;
	input cin;
	output [3:0] sum;
	output carry;
	wire [2:0] c;
	
	FullAdder f1_1(a[0], b[0], cin, sum[0], c[0]);
	FullAdder f1_2(a[1], b[1], c[0], sum[1], c[1]);
	FullAdder f1_3(a[2], b[2], c[1], sum[2], c[2]);
	FullAdder f1_4(a[3], b[3], c[2], sum[3], carry);
	
endmodule

module FullAdder8Bit( a, b, cin, sum, carry);
	input [7:0] a,b;
	input cin;
	output [7:0] sum;
	output carry;
	wire c;
	
	FullAdder4Bit f4_1(a[3:0], b[3:0], cin, sum[3:0], c);
	FullAdder4Bit f4_2(a[7:4], b[7:4], c, sum[7:4], carry);
	
endmodule

//////////////////////////////////////////////////////////////////////////////////

module TFlipFlop(t,clk,reset, q, qb);
input t,clk,reset;
output reg q,qb;

reg temp=0;

always @(posedge clk or posedge reset) 
begin
	if (reset==0) 
	begin
		if(t==1)
			temp= ~temp;
		else
			temp=temp;
	end
	
	q=temp;
	qb=~temp;
end

endmodule


//////////////////////////////////////////////////////////////////////////////////
module UpDownCounter(UpDown,clk,reset,counter);
input UpDown, clk, reset;
output wire [6:1] counter;

wire [6:1] reverseCounter;

wire [5:1] andGateOutput_q;
wire [5:1] andGateOutput_qb;
wire [5:1] orGateOutput;

TFlipFlop tff_1(1'b1, clk, reset, counter[1], reverseCounter[1]);
and a_1q(andGateOutput_q[1], counter[1], UpDown);
and a_1qb(andGateOutput_qb[1], reverseCounter[1], ~UpDown);
or a_1(orGateOutput[1], andGateOutput_q[1], andGateOutput_qb[1]);

TFlipFlop tff_2(orGateOutput[1], clk, reset, counter[2], reverseCounter[2]);
and a_2q(andGateOutput_q[2], counter[2], andGateOutput_q[1]);
and a_2qb(andGateOutput_qb[2], reverseCounter[2], andGateOutput_qb[1]);
or a_2(orGateOutput[2], andGateOutput_q[2], andGateOutput_qb[2]);

TFlipFlop tff_3(orGateOutput[2], clk, reset, counter[3], reverseCounter[3]);
and a_3q(andGateOutput_q[3], counter[3], andGateOutput_q[2]);
and a_3qb(andGateOutput_qb[3], reverseCounter[3], andGateOutput_qb[2]);
or a_3(orGateOutput[3], andGateOutput_q[3], andGateOutput_qb[3]);

TFlipFlop tff_4(orGateOutput[3], clk, reset, counter[4], reverseCounter[4]);
and a_4q(andGateOutput_q[4], counter[4], andGateOutput_q[3]);
and a_4qb(andGateOutput_qb[4], reverseCounter[4], andGateOutput_qb[3]);
or a_4(orGateOutput[4], andGateOutput_q[4], andGateOutput_qb[4]);

TFlipFlop tff_5(orGateOutput[4], clk, reset, counter[5], reverseCounter[5]);
and a_5q(andGateOutput_q[5], counter[5], andGateOutput_q[5]);
and a_5qb(andGateOutput_qb[5], reverseCounter[5], andGateOutput_qb[5]);
or a_5(orGateOutput[5], andGateOutput_q[5], andGateOutput_qb[5]);

TFlipFlop tff_6(orGateOutput[5], clk, reset, counter[6], reverseCounter[6]);

endmodule


//////////////////////////////////////////////////////////////////////////////////

