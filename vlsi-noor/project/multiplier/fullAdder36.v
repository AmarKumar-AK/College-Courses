module fullAdder36 (
    input [35:0]a,
    input [35:0]b,
    input cin,
    output [35:0]sum,
    output ca
);
    wire w0;

    fullAdder4 FA_0(a[3:0],b[3:0],cin,sum[3:0],w0);
    fullAdder4 FA_1(a[7:4],b[7:4],w0,sum[7:4],w1);
    fullAdder4 FA_2(a[11:8],b[11:8],w1,sum[11:8],w2);
    fullAdder4 FA_3(a[15:12],b[15:12],w2,sum[15:12],w3);
    fullAdder4 FA_4(a[19:16],b[19:16],w3,sum[19:16],w4);
    fullAdder4 FA_5(a[23:20],b[23:20],w4,sum[23:20],w5);
    fullAdder4 FA_6(a[27:24],b[27:24],w5,sum[27:24],w6);
    fullAdder4 FA_7(a[31:28],b[31:28],w6,sum[31:28],w7);
    fullAdder4 FA_8(a[35:32],b[35:32],w7,sum[35:32],ca);
    
endmodule