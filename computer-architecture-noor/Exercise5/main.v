//register file
module register(select,readAddress1,readAddress2,readData1,readData2,writeAddress,writeData);
input select;//1 for read//0 for write
reg [15:0]imem[0:31];
input [4:0]readAddress1,readAddress2;
input [4:0]writeAddress;
input [15:0]writeData;
output reg [15:0]readData1,readData2;

initial begin
    imem[0] <= 16'b0;imem[1] <= 16'b0;imem[2] <= 16'b0;imem[3] <= 16'b0;imem[4] <= 16'b0;imem[5] <= 16'b0;imem[6] <= 16'b0;imem[7] <= 16'b0;imem[8] <= 16'b0;imem[9] <= 16'b0;imem[10] <= 16'b0;imem[11] <= 16'b0;imem[12] <= 16'b0;imem[13] <= 16'b0;imem[14] <= 16'b0;imem[15] <= 16'b0;imem[16] <= 16'b0;imem[17] <= 16'b0;imem[18] <= 16'b0;imem[19] <= 16'b0;imem[20] <= 16'b0;imem[21] <= 16'b0;imem[22] <= 16'b0;imem[23] <= 16'b0;imem[24] <= 16'b0;imem[25] <= 16'b0;imem[26] <= 16'b0;imem[27] <= 16'b0;imem[28] <= 16'b0;imem[29] <= 16'b0;imem[30] <= 16'b0;imem[31] <= 16'b0;
end

always @(*)
begin
    if(select)
    begin
        readData1 <= imem[readAddress1];
        readData2 <= imem[readAddress2];
    end 
    else
    begin
        imem[writeAddress] <= writeData; 
    end
end

endmodule

//  initial begin
//     for (i = 0; i < 256; i = i + 1) begin 
//          #1  $display(" Address = %g  Data = %h",i,ram[i]);
//      ram[i] <= 0; // Initialize the RAM with 0
//        #1  $display(" Address = %g  Data = %h",i,ram[i]);
//     end
//      #1  $finish;
//  end

// ////////////////////////
// integer i;
// initial begin
//     for (i = 0; i < 32; i = i + 1)
//     begin
//         r[i] =16'd10;
//     end
// end 

// generate
// genvar i;
// // initial begin
//     for (i = 0; i < 32; i = i + 1)
//     begin
//         r[i] =16'd10;
//     end
// // end
// endgenerate
