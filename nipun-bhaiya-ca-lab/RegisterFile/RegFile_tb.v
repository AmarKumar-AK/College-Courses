module RegFileTB();
reg [3:0] read1, read2, write;
reg [15:0] dataToWrite;
wire [15:0] dataRead1;
wire [15:0] dataRead2;
wire [15:0] dataWritten;
reg Reset;

RegFile submodule1(read1, read2, write, dataToWrite, Reset, dataRead1, dataRead2, dataWritten);

initial begin
    Reset <= 1'b1;
    #5;
    Reset <= 1'b0;
    read1 <= 4'b0000;
    read2 <= 4'b1111;
    #1;
    write <= 4'b1101;
    dataToWrite <= 16'hFFFA;
    #100;
    $finish;
end

initial
begin
    $monitor("Time = %2d, read1 = %b, read2 = %b\ndataToWrite = %h, dataRead1 = %h, dataRead2 = %h\ndataWritten at [%b] = %h\n",$time,read1,read2,dataToWrite,dataRead1,dataRead2,write,dataWritten);
    $dumpfile("RegFile.vcd");
    $dumpvars(0, RegFileTB);
end
endmodule
