//instruction fetch
`include "doub.v"
module insFetch(input clk,input reset, output [15:0]out);

reg [15:0]imem[0:1023];

reg [15:0]counterIn;

initial begin
	counterIn <=16'b0;
end

initial begin
	imem[0]<=16'b1;
	imem[1] <= 16'b101;
	imem[2]<=16'b111;
	imem[3]<=16'b110;
	imem[4]<=16'b1001;
end
wire faltu;//not for use
wire [15:0]temp;//storing pc
reg [15:0]temp1;//for storing ouput data from register
doub d1(counterIn,16'd1,1'b0,temp,faltu);

always@(posedge clk or posedge reset)
	if(!reset)
	begin
        temp1 <=imem[temp];
        counterIn <= temp;
	     		 
 	end
	else
	begin
		counterIn <= 16'b1111111111111111;
	end
		
assign out = temp1;

endmodule