`include "../Wallace_tree_mult/32bit_RCA.v"
`include "../Wallace_tree_mult/XOR.v"
`include "../Wallace_tree_mult/KGP_module.v"
`include "../Wallace_tree_mult/Parallel_prefix.v"
`include "../Wallace_tree_mult/CarrySave.v"

module WallaceTree(a, b, out);
input [15:0] a;
input [15:0] b;
output [31:0] out;

wire overflow;
wire [31:0] p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16;
wire [31:0] u1,u2,u3,u4,u5,u6,u7,u8,u9,u10,u11,u12,u13,u14;
wire [31:0] v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,v13,v14;
assign p1 = b[0] ? {16'b0, a} : 32'b0;
assign p2 = b[1] ? {15'b0, a, 1'b0} : 32'b0;
assign p3 = b[2] ? {14'b0, a, 2'b0} : 32'b0;
assign p4 = b[3] ? {13'b0, a, 3'b0} : 32'b0;
assign p5 = b[4] ? {12'b0, a, 4'b0} : 32'b0;
assign p6 = b[5] ? {11'b0, a, 5'b0} : 32'b0;
assign p7 = b[6] ? {10'b0, a, 6'b0} : 32'b0;
assign p8 = b[7] ? {9'b0, a, 7'b0} : 32'b0;
assign p9 = b[8] ? {8'b0, a, 8'b0} : 32'b0;
assign p10 = b[9] ? {7'b0, a, 9'b0} : 32'b0;
assign p11 = b[10] ? {6'b0, a, 10'b0} : 32'b0;
assign p12 = b[11] ? {5'b0, a, 11'b0} : 32'b0;
assign p13 = b[12] ? {4'b0, a, 12'b0} : 32'b0;
assign p14 = b[13] ? {3'b0, a, 13'b0} : 32'b0;
assign p15 = b[14] ? {2'b0, a, 14'b0} : 32'b0;
assign p16 = b[15] ? {1'b0, a, 15'b0} : 32'b0;

CarrySave CS1(p1,p2,p3,u1,v1);
CarrySave CS2(p4,p5,p6,u2,v2);
CarrySave CS3(p7,p8,p9,u3,v3);
CarrySave CS4(p10,p11,p12,u4,v4);
CarrySave CS5(p13,p14,p15,u5,v5);
CarrySave CS6(v1,u1,u2,u6,v6);
CarrySave CS7(u3,v3,v2,u7,v7);
CarrySave CS8(v4,u4,u5,u8,v8);
CarrySave CS9(u6,v6,u7,u9,v9);
CarrySave CS10(v7,u8,v8,u10,v10);
CarrySave CS11(u9,v9,u10,u11,v11);
CarrySave CS12(v10,v5,p16,u12,v12);
CarrySave CS13(u11,v11,u12,u13,v13);
CarrySave CS14(u13,v13,v12,u14,v14);

RCA CLA(u14, v14, overflow, out);

endmodule