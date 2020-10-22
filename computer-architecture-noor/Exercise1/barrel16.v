`include "mux2.v"
module barrel_shifter_16bit (in, ctrl, out);
  input  [15:0] in;
  input [3:0] ctrl;
  output [15:0] out;
  wire [15:0] x,y,z;


//8bit shift right
mux2X1  ins_87 (.in0(in[15]),.in1(1'b0),.sel(ctrl[3]),.out(z[15]));
mux2X1  ins_86 (.in0(in[14]),.in1(1'b0),.sel(ctrl[3]),.out(z[14]));
mux2X1  ins_85 (.in0(in[13]),.in1(1'b0),.sel(ctrl[3]),.out(z[13]));
mux2X1  ins_84 (.in0(in[12]),.in1(1'b0),.sel(ctrl[3]),.out(z[12]));
mux2X1  ins_83 (.in0(in[11]),.in1(1'b0),.sel(ctrl[3]),.out(z[11]));
mux2X1  ins_82 (.in0(in[10]),.in1(1'b0),.sel(ctrl[3]),.out(z[10]));
mux2X1  ins_81 (.in0(in[9]),.in1(1'b0),.sel(ctrl[3]),.out(z[9]));
mux2X1  ins_80 (.in0(in[8]),.in1(1'b0),.sel(ctrl[3]),.out(z[8]));
mux2X1  ins_97 (.in0(in[7]),.in1(in[15]),.sel(ctrl[3]),.out(z[7]));
mux2X1  ins_96 (.in0(in[6]),.in1(in[14]),.sel(ctrl[3]),.out(z[6]));
mux2X1  ins_95 (.in0(in[5]),.in1(in[13]),.sel(ctrl[3]),.out(z[5]));
mux2X1  ins_94 (.in0(in[4]),.in1(in[12]),.sel(ctrl[3]),.out(z[4]));
mux2X1  ins_93 (.in0(in[3]),.in1(in[11]),.sel(ctrl[3]),.out(z[3]));
mux2X1  ins_92 (.in0(in[2]),.in1(in[10]),.sel(ctrl[3]),.out(z[2]));
mux2X1  ins_91 (.in0(in[1]),.in1(in[9]),.sel(ctrl[3]),.out(z[1]));
mux2X1  ins_90 (.in0(in[0]),.in1(in[8]),.sel(ctrl[3]),.out(z[0]));


//4bit shift right
mux2X1  ins_77 (.in0(z[15]),.in1(1'b0),.sel(ctrl[2]),.out(x[15]));
mux2X1  ins_76 (.in0(z[14]),.in1(1'b0),.sel(ctrl[2]),.out(x[14]));
mux2X1  ins_75 (.in0(z[13]),.in1(1'b0),.sel(ctrl[2]),.out(x[13]));
mux2X1  ins_74 (.in0(z[12]),.in1(1'b0),.sel(ctrl[2]),.out(x[12]));
mux2X1  ins_73 (.in0(z[11]),.in1(z[15]),.sel(ctrl[2]),.out(x[11]));
mux2X1  ins_72 (.in0(z[10]),.in1(z[14]),.sel(ctrl[2]),.out(x[10]));
mux2X1  ins_71 (.in0(z[9]),.in1(z[13]),.sel(ctrl[2]),.out(x[9]));
mux2X1  ins_70 (.in0(z[8]),.in1(z[12]),.sel(ctrl[2]),.out(x[8]));
mux2X1  ins_17 (.in0(z[7]),.in1(z[11]),.sel(ctrl[2]),.out(x[7]));
mux2X1  ins_16 (.in0(z[6]),.in1(z[10]),.sel(ctrl[2]),.out(x[6]));
mux2X1  ins_15 (.in0(z[5]),.in1(z[9]),.sel(ctrl[2]),.out(x[5]));
mux2X1  ins_14 (.in0(z[4]),.in1(z[8]),.sel(ctrl[2]),.out(x[4]));
mux2X1  ins_13 (.in0(z[3]),.in1(z[7]),.sel(ctrl[2]),.out(x[3]));
mux2X1  ins_12 (.in0(z[2]),.in1(z[6]),.sel(ctrl[2]),.out(x[2]));
mux2X1  ins_11 (.in0(z[1]),.in1(z[5]),.sel(ctrl[2]),.out(x[1]));
mux2X1  ins_10 (.in0(z[0]),.in1(z[4]),.sel(ctrl[2]),.out(x[0]));
 
//2 bit shift right
 
mux2X1  ins_67 (.in0(x[15]),.in1(1'b0),.sel(ctrl[1]),.out(y[15]));
mux2X1  ins_66 (.in0(x[14]),.in1(1'b0),.sel(ctrl[1]),.out(y[14]));
mux2X1  ins_65 (.in0(x[13]),.in1(x[15]),.sel(ctrl[1]),.out(y[13]));
mux2X1  ins_64 (.in0(x[12]),.in1(x[14]),.sel(ctrl[1]),.out(y[12]));
mux2X1  ins_63 (.in0(x[11]),.in1(x[13]),.sel(ctrl[1]),.out(y[11]));
mux2X1  ins_62 (.in0(x[10]),.in1(x[12]),.sel(ctrl[1]),.out(y[10]));
mux2X1  ins_61 (.in0(x[9]),.in1(x[11]),.sel(ctrl[1]),.out(y[9]));
mux2X1  ins_60 (.in0(x[8]),.in1(x[10]),.sel(ctrl[1]),.out(y[8]));
mux2X1  ins_27 (.in0(x[7]),.in1(x[9]),.sel(ctrl[1]),.out(y[7]));
mux2X1  ins_26 (.in0(x[6]),.in1(x[8]),.sel(ctrl[1]),.out(y[6]));
mux2X1  ins_25 (.in0(x[5]),.in1(x[7]),.sel(ctrl[1]),.out(y[5]));
mux2X1  ins_24 (.in0(x[4]),.in1(x[6]),.sel(ctrl[1]),.out(y[4]));
mux2X1  ins_23 (.in0(x[3]),.in1(x[5]),.sel(ctrl[1]),.out(y[3]));
mux2X1  ins_22 (.in0(x[2]),.in1(x[4]),.sel(ctrl[1]),.out(y[2]));
mux2X1  ins_21 (.in0(x[1]),.in1(x[3]),.sel(ctrl[1]),.out(y[1]));
mux2X1  ins_20 (.in0(x[0]),.in1(x[2]),.sel(ctrl[1]),.out(y[0]));
 
//1 bit shift right
mux2X1  ins_57 (.in0(y[15]),.in1(1'b0),.sel(ctrl[0]),.out(out[15]));
mux2X1  ins_56 (.in0(y[14]),.in1(y[15]),.sel(ctrl[0]),.out(out[14]));
mux2X1  ins_55 (.in0(y[13]),.in1(y[14]),.sel(ctrl[0]),.out(out[13]));
mux2X1  ins_54 (.in0(y[12]),.in1(y[13]),.sel(ctrl[0]),.out(out[12]));
mux2X1  ins_53 (.in0(y[11]),.in1(y[12]),.sel(ctrl[0]),.out(out[11]));
mux2X1  ins_52 (.in0(y[10]),.in1(y[11]),.sel(ctrl[0]),.out(out[10]));
mux2X1  ins_51 (.in0(y[9]),.in1(y[10]),.sel(ctrl[0]),.out(out[9]));
mux2X1  ins_50 (.in0(y[8]),.in1(y[9]),.sel(ctrl[0]),.out(out[8]));
mux2X1  ins_07 (.in0(y[7]),.in1(y[8]),.sel(ctrl[0]),.out(out[7]));
mux2X1  ins_06 (.in0(y[6]),.in1(y[7]),.sel(ctrl[0]),.out(out[6]));
mux2X1  ins_05 (.in0(y[5]),.in1(y[6]),.sel(ctrl[0]),.out(out[5]));
mux2X1  ins_04 (.in0(y[4]),.in1(y[5]),.sel(ctrl[0]),.out(out[4]));
mux2X1  ins_03 (.in0(y[3]),.in1(y[4]),.sel(ctrl[0]),.out(out[3]));
mux2X1  ins_02 (.in0(y[2]),.in1(y[3]),.sel(ctrl[0]),.out(out[2]));
mux2X1  ins_01 (.in0(y[1]),.in1(y[2]),.sel(ctrl[0]),.out(out[1]));
mux2X1  ins_00 (.in0(y[0]),.in1(y[1]),.sel(ctrl[0]),.out(out[0]));
 
endmodule