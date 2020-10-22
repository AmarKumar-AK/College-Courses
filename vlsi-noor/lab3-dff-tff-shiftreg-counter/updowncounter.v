`include "tff.v"
module sync_updown(a,t,clock,reset,q);
input t,clock, reset;
input a;
output [3:0]q;

wire x0,x1,x2;
tff T0(t,clock, reset,q[0]);

assign x0=(q[0]&a)|(~q[0]&~a);
tff T1(x0,clock, reset,q[1]);

assign x1=(q[1]&q[0]&a)|(~q[0]&~a&~q[1]);
tff T2(x1,clock, reset,q[2]);

assign x2=(q[2]&q[1]&q[0]&a)|(~q[0]&~a&~q[1]&~q[2]);
tff T3(x2,clock, reset,q[3]);
endmodule
