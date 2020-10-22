// `include "subtracter/sub.v"
module sub4( a, b, c, d, br);
input [3:0]a, b;
input c;
output [3:0]d;
output br;
wire [3:0]w;
sub1 s0(a[0],b[0],c,d[0],w[0]);
sub1 s1(a[1],b[1],w[0],d[1],w[1]);
sub1 s2(a[2],b[2],w[1],d[2],w[2]);
sub1 s3(a[3],b[3],w[2],d[3],br);
endmodule

