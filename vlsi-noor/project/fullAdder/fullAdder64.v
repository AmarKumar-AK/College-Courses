module fullAdder64 (
    input [63:0]a,
    input [63:0]b,
    input cin,
    output [63:0]sum,
    output ca
);
    wire w0;

    fullAdder32 FA_0(a[31:0],b[31:0],cin,sum[31:0],w0);
    fullAdder32 FA_1(a[63:32],b[63:32],w0,sum[63:32],ca);

endmodule
