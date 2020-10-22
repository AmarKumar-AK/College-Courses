module fullAdder16 (
    input [15:0]a,
    input [15:0]b,
    input cin,
    output [15:0]sum,
    output ca
);
    wire w0;

    fullAdder8 FA_0(a[7:0],b[7:0],cin,sum[7:0],w0);
    fullAdder8 FA_1(a[15:8],b[15:8],w0,sum[15:8],ca);

endmodule
