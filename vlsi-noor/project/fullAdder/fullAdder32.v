module fullAdder32 (
    input [31:0]a,
    input [31:0]b,
    input cin,
    output [31:0]sum,
    output ca
);
    wire w0;

    fullAdder16 FA_0(a[15:0],b[15:0],cin,sum[15:0],w0);
    fullAdder16 FA_1(a[31:16],b[31:16],w0,sum[31:16],ca);

endmodule
