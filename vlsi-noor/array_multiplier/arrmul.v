`include"fullAdder.v"
module arrmul(a,b,out);
input [3:0]a,b;
output [7:0]out;
wire [39:0]w;

genvar i;
for(i=0 ; i<4 ; i=i+1)
begin
    assign w[i] = a[i] & b[0];
end

for(i=4 ; i<8 ; i=i+1)
begin
    assign w[i] = a[i-4] & b[1];
end

for(i=8 ; i<12 ; i=i+1)
begin
    assign w[i] = a[i-8] & b[2];
end

for(i=12 ; i<16 ; i=i+1)
begin
    assign w[i] = a[i-12] & b[3];
end

assign out[0]=w[0];
fulladder a17(1'b0,w[1],w[4],w[16],w[17]);
fulladder a18(1'b0,w[2],w[5],w[18],w[19]);
fulladder a19(1'b0,w[3],w[6],w[20],w[21]);

fulladder a20(w[8],w[17],w[18],w[22],w[23]);
fulladder a21(w[9],w[19],w[20],w[24],w[25]);
fulladder a22(w[10],w[7],w[21],w[26],w[27]);

fulladder a23(w[12],w[23],w[24],w[28],w[29]);
fulladder a24(w[13],w[25],w[26],w[30],w[31]);
fulladder a25(w[14],w[11],w[27],w[32],w[33]);

fulladder a26(1'b0,w[29],w[30],w[34],w[35]);
fulladder a27(w[31],w[32],w[35],w[36],w[37]);
fulladder a28(w[15],w[33],w[37],w[38],w[39]);

assign out[1]=w[16];
assign out[2]=w[22];
assign out[3]=w[28];
assign out[4]=w[34];
assign out[5]=w[36];
assign out[6]=w[38];
assign out[7]=w[39];

endmodule