module count(clk,reset,counter);
input clk, reset;
 output[63:0] counter;
reg [63:0] counter_up;
always @(posedge clk or posedge reset)
begin
if(reset)
 counter_up <= 6'd0;
else
 counter_up <= counter_up + 6'd1;
end 
assign counter = counter_up;
endmodule