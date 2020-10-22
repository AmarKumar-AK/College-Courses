module fullAdder24 (
    input [23:0]a,
    input [23:0]b,
    input cin,
    output [23:0]sum,
    output ca
);
    wire w0;
    wire w1;

    fullAdder8 FA_0(a[7:0],b[7:0],cin,sum[7:0],w0);
    fullAdder8 FA_1(a[15:8],b[15:8],w0,sum[15:8],w1);
    fullAdder8 FA_2(a[23:16],b[23:16],w1,sum[23:16],ca);

endmodule