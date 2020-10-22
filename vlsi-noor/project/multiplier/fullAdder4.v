module fullAdder4 (
    input [3:0]a,
    input [3:0]b,
    input cin,
    output [3:0]sum,
    output ca
);
    wire w0,w1,w2;

    fullAdder FA_0(a[0],b[0],cin,sum[0],w0);
    fullAdder FA_1(a[1],b[1],w0,sum[1],w1);
    fullAdder FA_2(a[2],b[2],w1,sum[2],w2);
    fullAdder FA_3(a[3],b[3],w2,sum[3],ca);

endmodule
