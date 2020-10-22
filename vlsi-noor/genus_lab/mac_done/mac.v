`include "Wallac16bit.v"
// `include "FullAdder38.v"
`include "FullADDER38new.v"
`include "dflip38.v"

module MAC(a,b,out,clk,reset);

    input [15:0] a;
    input [15:0] b;
    input clk,reset;

    output [37:0]out;
    wire [37:0]w2;
    wire [37:0]w3;
    wire carryt;
    wire [37:0]w1;

    wall16bit buildingawall(a,b,w1[31:0]); //multiplier
    // wall16bit buildingawall(a,b,w1); //multiplier
    assign w1[37:32] = 6'd0;
    dflip38flop d2(w1,clk,reset,w3);
    FullAdder38new F1(w3,w2,out,carryt);
    dflip38flop d1(out,clk,reset,w2);




endmodule // MAC
