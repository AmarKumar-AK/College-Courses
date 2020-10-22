`include "recursive_doubling/doub.v"
module doub64 (
    input [63:0]a,
    input [63:0]b,
    input cin,
    output [63:0]sum,
    output ca
);
    wire w0,w1,w2;
    doub d1(a[15:0],b[15:0],cin,sum[15:0],w0);
    doub d2(a[31:16],b[31:16],w0,sum[31:16],w1);
    doub d3(a[47:32],b[47:32],w1,sum[47:32],w2);
    doub d4(a[63:48],b[63:48],w2,sum[63:48],ca);

endmodule
