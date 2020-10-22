`include "instruction.v"

module top;

    reg clk;                    //clock
    reg [15:0]address;         //requested address from CPU
    reg readwriteEn;           //for load/store instruction
    reg [15:0] writedata;      //data to write to
    wire readhitmiss;          //1-hit,0-miss
    wire writehitmiss;         //1-hit,0-miss
    wire[15:0] readdata;       //data from cache to CPU

InsCache ins(clk,address,readwriteEn,writedata,readhitmiss,writehitmiss,readdata);

initial
begin
	clk=1'b0;
    
    #5 address=16'd1; readwriteEn=1'b0; writedata=16'd183;
    #5 address=16'd2; readwriteEn=1'b1; writedata=16'd183;
    #5 address=16'd1; readwriteEn=1'b1; writedata=16'd44;
    #5 address=16'd1; readwriteEn=1'b0; writedata=16'd183;
    #5 address=16'd2; readwriteEn=1'b0; writedata=16'd183;
    #5 address=16'd1; readwriteEn=1'b1; writedata=16'd18; 
    #5 address=16'd2; readwriteEn=1'b0; writedata=16'd183;
    #5 address=16'd1; readwriteEn=1'b0; writedata=16'd183;
end
always
    #5 clk=!clk;
    
initial
begin
    $monitor($time, " - address = %h , readwriteEn = %h , writedata = %h , readhitmiss = %h , writehitmiss = %h , readdata = %h",address,readwriteEn,writedata,readhitmiss,writehitmiss,readdata);
    #40 $finish;
end
endmodule