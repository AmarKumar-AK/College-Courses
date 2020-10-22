//32KB Data Cache - 8-word block size(128-bits)
//2-bit = tag , 11-bit = setnumber , 3-bit=offset
module DataCache
(
    input clk,
    input wire[15:0] address,       //requested address from CPU
    input wire readEn,              //for read of data
    input wire writeEn,             //for write of data
    input wire[15:0] writedata,     //data to write to
    output reg readhitmiss,         //1-hit,0-miss
    output reg writehitmiss,        //1-hit,0-miss
    output reg[15:0] readdata       //data from cache to CPU
);

reg [1:0]tag[2047:0];               //array of tags for making changes
reg[2047:0] valid;                  //if the address contains or fetched the data
reg[2047:0] dirty;                  //if there is write made in cache
reg [127:0]CacheData[2047:0];       //complete Cache    
reg [15:0]MemoryData[65535:0];     //complete memory
reg readcomparator;                 //checking tag on cache for read
reg writecomparator;                //checking tag on cache for write

wire [1:0]readtag;
wire [1:0]writetag;
wire [10:0]readset;
wire [10:0]writeset;
wire [2:0]readoff;
wire [2:0]writeoff;

assign readtag[1:0] = address[15:14];       //assigning tag,set,and offset of address by CPU
assign writetag[1:0] = address[15:14];
assign readset[10:0] = address[13:3];
assign writeset[10:0] = address[13:3];
assign readoff[2:0] = address[2:0];
assign writeoff[2:0] = address[2:0];

initial
begin
    valid <= 2048'd0;                       //assigning initial tag,dirty and valid bits to zeros.
    dirty <= 2048'd0;
    tag[0][2047:0] <= 2048'd0;
    tag[1][2047:0] <= 2048'd0;
end

always@(clk)
begin
    //checking on cache whether the block exist or not to decide hit or miss for both read as well as write.
    readcomparator <= !(readtag[1]^tag[readset[10:0]][1]) & !(readtag[0]^tag[readset[10:0]][0]);
    readhitmiss <= readcomparator&valid[readset[10:0]];
    writecomparator <= !(writetag[1]^tag[writeset[10:0]][1]) & !(writetag[0]^tag[writeset[10:0]][0]);
    writehitmiss <= writecomparator&valid[writeset[10:0]];

    //if readaddress found and read enabled.
    if(readhitmiss == 1'b1 && readEn == 1'b1)
    begin                                               //comparing the requested address offset within the cache block to find the matched address.
        if(readoff[2:0] == 3'd0)
        begin
            readdata[15:0]=CacheData[readset[10:0]][15:0];
        end
        else if(readoff[2:0] == 3'd1)
        begin
            readdata[15:0]=CacheData[readset[10:0]][31:16];
        end
        else if(readoff[2:0] == 3'd2)
        begin
            readdata[15:0]=CacheData[readset[10:0]][47:32];
        end
        else if(readoff[2:0] == 3'd3)
        begin
            readdata[15:0]=CacheData[readset[10:0]][63:48];
        end
        else if(readoff[2:0] == 3'd4)
        begin
            readdata[15:0]=CacheData[readset[10:0]][79:64];
        end
        else if(readoff[2:0] == 3'd5)
        begin
            readdata[15:0]=CacheData[readset[10:0]][95:80];
        end
        else if(readoff[2:0] == 3'd6)
        begin
            readdata[15:0]=CacheData[readset[10:0]][111:96];
        end
        else if(readoff[2:0] == 3'd7)
        begin
            readdata[15:0]=CacheData[readset[10:0]][127:112];
        end
    end
    else if(readhitmiss == 1'b0 && readEn == 1'b1)         //if readaddress not found in cache and read is enabled.
    begin
        if(dirty[readset[10:0]]==1'b1)                           //checking if the block is dirty then write it to memory.
        begin
           MemoryData[{tag[readset[10:0]][1:0],readset[10:0],3'd0}][15:0]=CacheData[readset[10:0]][15:0];
           MemoryData[{tag[readset[10:0]][1:0],readset[10:0],3'd1}][15:0]=CacheData[readset[10:0]][31:16];
           MemoryData[{tag[readset[10:0]][1:0],readset[10:0],3'd2}][15:0]=CacheData[readset[10:0]][47:32];
           MemoryData[{tag[readset[10:0]][1:0],readset[10:0],3'd3}][15:0]=CacheData[readset[10:0]][63:48];
           MemoryData[{tag[readset[10:0]][1:0],readset[10:0],3'd4}][15:0]=CacheData[readset[10:0]][79:64];
           MemoryData[{tag[readset[10:0]][1:0],readset[10:0],3'd5}][15:0]=CacheData[readset[10:0]][95:80];
           MemoryData[{tag[readset[10:0]][1:0],readset[10:0],3'd6}][15:0]=CacheData[readset[10:0]][111:96];
           MemoryData[{tag[readset[10:0]][1:0],readset[10:0],3'd7}][15:0]=CacheData[readset[10:0]][127:112];

           dirty[readset[10:0]]=1'b0;
        end
        //After writing replace the block with new block from memory.
        CacheData[readset[10:0]][15:0]=MemoryData[{readtag[1:0],readset[10:0],3'd0}][15:0];
        CacheData[readset[10:0]][31:16]=MemoryData[{readtag[1:0],readset[10:0],3'd1}][15:0];
        CacheData[readset[10:0]][47:32]=MemoryData[{readtag[1:0],readset[10:0],3'd2}][15:0];
        CacheData[readset[10:0]][63:48]=MemoryData[{readtag[1:0],readset[10:0],3'd3}][15:0];
        CacheData[readset[10:0]][79:64]=MemoryData[{readtag[1:0],readset[10:0],3'd4}][15:0];
        CacheData[readset[10:0]][95:80]=MemoryData[{readtag[1:0],readset[10:0],3'd5}][15:0];
        CacheData[readset[10:0]][111:96]=MemoryData[{readtag[1:0],readset[10:0],3'd6}][15:0];
        CacheData[readset[10:0]][127:112]=MemoryData[{readtag[1:0],readset[10:0],3'd7}][15:0];

        tag[readset[10:0]][1:0]=readtag[1:0];
        valid[readset[10:0]]=1'b1;
        
        //comparing the requested address offset within the cache block to find the matched address.
        if(readoff[2:0] == 3'd0)
        begin
            readdata[15:0]=CacheData[readset[10:0]][15:0];
        end
        else if(readoff[2:0] == 3'd1)
        begin
            readdata[15:0]=CacheData[readset[10:0]][31:16];
        end
        else if(readoff[2:0] == 3'd2)
        begin
            readdata[15:0]=CacheData[readset[10:0]][47:32];
        end
        else if(readoff[2:0] == 3'd3)
        begin
            readdata[15:0]=CacheData[readset[10:0]][63:48];
        end
        else if(readoff[2:0] == 3'd4)
        begin
            readdata[15:0]=CacheData[readset[10:0]][79:64];
        end
        else if(readoff[2:0] == 3'd5)
        begin
            readdata[15:0]=CacheData[readset[10:0]][95:80];
        end
        else if(readoff[2:0] == 3'd6)
        begin
            readdata[15:0]=CacheData[readset[10:0]][111:96];
        end
        else if(readoff[2:0] == 3'd7)
        begin
            readdata[15:0]=CacheData[readset[10:0]][127:112];
        end
    end
    //updating write comparator incase of write enabled.
    writecomparator <= !(writetag[1]^tag[writeset[10:0]][1]) & !(writetag[0]^tag[writeset[10:0]][0]);
    writehitmiss <= writecomparator&valid[writeset[10:0]];

    if(writehitmiss == 1'b1 && writeEn == 1'b1)
    begin                                                       //comparing the requested address offset within the cache block to find the matched address.
       if(writeoff[2:0] == 3'd0)
        begin
            CacheData[writeset[10:0]][15:0]=writedata[15:0];
        end
        else if(writeoff[2:0] == 3'd1)
        begin
            CacheData[writeset[10:0]][31:16]=writedata[15:0];
        end
        else if(writeoff[2:0] == 3'd2)
        begin
            CacheData[writeset[10:0]][47:32]=writedata[15:0];
        end
        else if(writeoff[2:0] == 3'd3)
        begin
            CacheData[writeset[10:0]][63:48]=writedata[15:0];
        end
        else if(writeoff[2:0] == 3'd4)
        begin
            CacheData[writeset[10:0]][79:64]=writedata[15:0];
        end
        else if(writeoff[2:0] == 3'd5)
        begin
            CacheData[writeset[10:0]][95:80]=writedata[15:0];
        end
        else if(writeoff[2:0] == 3'd6)
        begin
            CacheData[writeset[10:0]][111:96]=writedata[15:0];
        end
        else if(writeoff[2:0] == 3'd7)
        begin
            CacheData[writeset[10:0]][127:112]=writedata[15:0];
        end

        dirty[writeset[10:0]]=1'b1;
        valid[writeset[10:0]]=1'b1; 
    end
    else if(writehitmiss == 1'b0 && writeEn == 1'b1)
    begin
        if(readhitmiss == 1'b1)
        begin
            writehitmiss = 1'b1;
            $display("%d",writehitmiss);
        end
        if(dirty[writeset[10:0]]==1'b1)                           //checking if the block is dirty then write it to memory.
        begin
           MemoryData[{tag[writeset[10:0]][1:0],writeset[10:0],3'd0}][15:0]=CacheData[writeset[10:0]][15:0];
           MemoryData[{tag[writeset[10:0]][1:0],writeset[10:0],3'd1}][15:0]=CacheData[writeset[10:0]][31:16];
           MemoryData[{tag[writeset[10:0]][1:0],writeset[10:0],3'd2}][15:0]=CacheData[writeset[10:0]][47:32];
           MemoryData[{tag[writeset[10:0]][1:0],writeset[10:0],3'd3}][15:0]=CacheData[writeset[10:0]][63:48];
           MemoryData[{tag[writeset[10:0]][1:0],writeset[10:0],3'd4}][15:0]=CacheData[writeset[10:0]][79:64];
           MemoryData[{tag[writeset[10:0]][1:0],writeset[10:0],3'd5}][15:0]=CacheData[writeset[10:0]][95:80];
           MemoryData[{tag[writeset[10:0]][1:0],writeset[10:0],3'd6}][15:0]=CacheData[writeset[10:0]][111:96];
           MemoryData[{tag[writeset[10:0]][1:0],writeset[10:0],3'd7}][15:0]=CacheData[writeset[10:0]][127:112];

           dirty[writeset[10:0]]=1'b0;
        end
        //After writing replace the block with new block from memory.
        CacheData[writeset[10:0]][15:0]=MemoryData[{writetag[1:0],writeset[10:0],3'd0}][15:0];
        CacheData[writeset[10:0]][31:16]=MemoryData[{writetag[1:0],writeset[10:0],3'd1}][15:0];
        CacheData[writeset[10:0]][47:32]=MemoryData[{writetag[1:0],writeset[10:0],3'd2}][15:0];
        CacheData[writeset[10:0]][63:48]=MemoryData[{writetag[1:0],writeset[10:0],3'd3}][15:0];
        CacheData[writeset[10:0]][79:64]=MemoryData[{writetag[1:0],writeset[10:0],3'd4}][15:0];
        CacheData[writeset[10:0]][95:80]=MemoryData[{writetag[1:0],writeset[10:0],3'd5}][15:0];
        CacheData[writeset[10:0]][111:96]=MemoryData[{writetag[1:0],writeset[10:0],3'd6}][15:0];
        CacheData[writeset[10:0]][127:112]=MemoryData[{writetag[1:0],writeset[10:0],3'd7}][15:0];

        tag[writeset[10:0]][1:0]=writetag[1:0];
        valid[writeset[10:0]]=1'b1;
        
        //comparing the requested address offset within the cache block to find the matched address.
        if(writeoff[2:0] == 3'd0)
        begin
            CacheData[writeset[10:0]][15:0]=writedata[15:0];
        end
        else if(writeoff[2:0] == 3'd1)
        begin
            CacheData[writeset[10:0]][31:16]=writedata[15:0];
        end
        else if(writeoff[2:0] == 3'd2)
        begin
            CacheData[writeset[10:0]][47:32]=writedata[15:0];
        end
        else if(writeoff[2:0] == 3'd3)
        begin
            CacheData[writeset[10:0]][63:48]=writedata[15:0];
        end
        else if(writeoff[2:0] == 3'd4)
        begin
            CacheData[writeset[10:0]][79:64]=writedata[15:0];
        end
        else if(writeoff[2:0] == 3'd5)
        begin
            CacheData[writeset[10:0]][95:80]=writedata[15:0];
        end
        else if(writeoff[2:0] == 3'd6)
        begin
            CacheData[writeset[10:0]][111:96]=writedata[15:0];
        end
        else if(writeoff[2:0] == 3'd7)
        begin
            CacheData[writeset[10:0]][127:112]=writedata[15:0];
        end

        dirty[writeset[10:0]]=1'b1;
    end
    //$display("readdata - %d readhitmiss - %d",readdata,readhitmiss);
end
endmodule