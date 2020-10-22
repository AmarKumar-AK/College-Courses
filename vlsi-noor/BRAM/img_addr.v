`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 01/28/2018 09:39:39 PM
// Design Name: 
// Module Name: img_addr
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


module imageadder(
    input clk,
    input wen,
    input reset,
    input UpDown,
    input [5:0] addr,
    input [7:0] dina_1, dina_2,
    input [7:0] dout_1, dout_2,
    input [8:0] dina,
    output [8:0] dout
    );
    
    memory_in i0(clk, 1'b1, addr, dina_1, dout_1);
    memory_in i1(clk, 1'b1, addr, dina_2, dout_2);
    
    FullAdder8Bit add8(dout_1, dout_2, 1'b0, dina[7:0], dina[8]);
    
    memory_out out1(clk, 1'b1, addr, dina, dout);
    
    
    UpDownCounter up(UpDown,clk,reset,addr);
    
endmodule
