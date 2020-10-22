module fullAdder8 (
    input [7:0]a,
    input [7:0]b,
    input cin,
    output [7:0]sum,
    output ca
);
    wire w0;

    fullAdder4 FA_0(a[3:0],b[3:0],cin,sum[3:0],w0);
    fullAdder4 FA_1(a[7:4],b[7:4],w0,sum[7:4],ca);

endmodule
