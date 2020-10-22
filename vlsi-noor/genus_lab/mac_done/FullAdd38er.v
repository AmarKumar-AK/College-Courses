// 2 16, 1 4 ,1 2

`include "RCA4bit.v"

`include "RCA16bit.v"
`include "full_add.v"


module RCA38b(A,B,Sum,Carry);

input [37:0]A;input [37:0]B;
output Carry , [37:0]Sum;

RCA16bit()


endmodule // RCA38b
