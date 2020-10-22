module RegFile(read1, read2, write, dataToWrite, reset, dataRead1, dataRead2, dataWritten);
input [3:0]read1;
input [3:0]read2;
input [3:0]write;
input [15:0]dataToWrite;
input wire reset;
output [15:0]dataRead1;
output [15:0]dataRead2;
output [15:0]dataWritten;
reg [15:0]imem [0:15];
always @ (reset) begin
	imem[0] <= 16'h0001;
	imem[1] <= 16'h0002;
	imem[2] <= 16'h0003;
	imem[3] <= 16'h0004;
	imem[4] <= 16'h0005;
	imem[5] <= 16'h0006;
	imem[6] <= 16'h0007;
	imem[7] <= 16'h0008;
	imem[8] <= 16'h0009;
	imem[9] <= 16'h000A;
	imem[10] <= 16'h000B;
	imem[11] <= 16'h000C;
	imem[12] <= 16'h000D;
	imem[13] <= 16'h000E;
	imem[14] <= 16'h000F;
	imem[15] <= 16'h0000;
end

assign dataRead1 = imem[read1 & 4'b1111];
assign dataRead2 = imem[read2 & 4'b1111];
always @ (~reset) begin
	imem[write & 4'b1111] <= reset == 1'b0 ? dataToWrite : imem[write & 4'b1111];
end
assign dataWritten = imem[write & 4'b1111];

endmodule