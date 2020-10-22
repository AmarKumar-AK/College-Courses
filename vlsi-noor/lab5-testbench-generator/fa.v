`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:  
// Design Name: 
// Module Name: 
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision: Version 0.01
// Additional Comments:
// 
////////////////////////////  tcbn45-low : med : high  ///////////////////////////
//
//
//	Time (ps)	=  : - : - 
//	Power (nW)	=    -  :  -  :  -   	Leackage - Dynamic
//	Area (nm^2)	=   : - : -
//
//
/////////////////////////////  slow-low : med : high  ////////////////////////////
//
//
//	Time (ps)	=  : - : - 
//	Power (nW)	=    -  :  -  :  -   	Leackage - Dynamic
//	Area (nm^2)	=   : - : -
//
//
/////////////////////////////  fast-low : med : high  ////////////////////////////
//
//
//	Time (ps)	=  : - : - 
//	Power (nW)	=    -  :  -  :  -   	Leackage - Dynamic
//	Area (nm^2)	=   : - : -
//
//
//////////////////////////////////////////////////////////////////////////////////


module fa(x,y,z,sum, carry);

output sum,carry;
input x,y,z;

wire w;	
	assign 	 w = x ^ y;
        assign	 sum = w ^ z;
	assign 	 carry = (x & y)|(w & z);
endmodule

