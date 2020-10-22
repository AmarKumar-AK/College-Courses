`include "main.v"
module top;
reg select;
reg [4:0]readAddress1,readAddress2;
reg [4:0]writeAddress;
reg [15:0]writeData;
wire [15:0]readData1,readData2;

register r1(select,readAddress1,readAddress2,readData1,readData2,writeAddress,writeData);

initial begin
    #0 select = 1'b1; readAddress1 = 5'b00001; readAddress2 = 5'b00011;
    #5 select = 1'b0; writeAddress = 5'b00001; writeData = 16'd15;
    #5 select = 1'b0; writeAddress = 5'b00011; writeData = 16'd10;
    #5 select = 1'b1; readAddress1 = 5'b00001; readAddress2 = 5'b00011;
end


always@(*)
begin 
    $monitor($time , "     readData1=%d    readData2=%d",readData1,readData2);
end
endmodule
