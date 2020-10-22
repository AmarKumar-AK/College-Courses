module Parallel_Prefix(kgp_one, kgp_two, final_kgp);
input [16:0] kgp_one;
input [16:0] kgp_two;
output [15:0] final_kgp;
wire [15:0] kgp_three;
wire [15:0] kgp_four;
wire [15:0] kgp_five;
wire [15:0] kgp_six;
wire [15:0] kgp_seven;
wire [15:0] kgp_eight;
wire [15:0] kgp_nine;

assign kgp_three[0] = kgp_one[0];
assign kgp_four[0] = kgp_two[0];

generate
	genvar i;
	for(i=15; i>=1; i=i-1) begin
		assign kgp_three[i] = (kgp_one[i-1]&kgp_two[i])+kgp_one[i];
		assign kgp_four[i] = kgp_two[i]&kgp_two[i-1];
	end

	assign kgp_five[0] = kgp_three[0];
	assign kgp_five[1] = kgp_three[1];
	for(i=15; i>=2; i=i-1) begin
		assign kgp_five[i] = (kgp_three[i-2]&kgp_four[i])+kgp_three[i];
		assign kgp_six[i] = kgp_four[i]&kgp_four[i-2];
	end

	for(i=0; i<4; i=i+1) begin
		assign kgp_seven[i] = kgp_five[i];
	end
	for(i=15; i>=4; i=i-1) begin
		assign kgp_seven[i] = (kgp_five[i-4]&kgp_six[i])+kgp_five[i];
		assign kgp_eight[i] = kgp_six[i]&kgp_six[i-4];
	end

	for(i=0; i<8; i=i+1) begin
		assign final_kgp[i] = kgp_seven[i];
	end
	for(i=15; i>=8; i=i-1) begin
		assign final_kgp[i] = (kgp_seven[i-8]&kgp_eight[i])+kgp_seven[i];
	end
endgenerate

endmodule