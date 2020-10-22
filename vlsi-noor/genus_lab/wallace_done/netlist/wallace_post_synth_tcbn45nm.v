
// Generated by Cadence Encounter(R) RTL Compiler v14.10-s022_1

// Verification Directory fv/wallace 

module wallace(a, b, result);
  input [7:0] a, b;
  output [15:0] result;
  wire [7:0] a, b;
  wire [15:0] result;
  wire [7:0] r1;
  wire [7:0] r2;
  wire [9:0] t0;
  wire [7:0] c0;
  wire [7:0] r3;
  wire [7:0] r4;
  wire [7:0] r5;
  wire [9:0] t1;
  wire [7:0] c1;
  wire [12:0] t2;
  wire [7:0] c2;
  wire [7:0] r6;
  wire [7:0] r7;
  wire [9:0] t3;
  wire [7:0] c3;
  wire [14:0] t4;
  wire [9:0] c4;
  wire [14:0] t5;
  wire [10:0] c5;
  wire [10:0] car;
  wire n_91, \r0[0]_BAR , \r0[1] , \r0[2] , \r0[3] , \r0[4] , \r0[5] ,
       \r0[6] ;
  wire \r0[7] ;
  assign n_91 = 1'b0;
  fullAdder f0(\r0[2] , r1[1], r2[0], t0[2], c0[1]);
  fullAdder f1(\r0[3] , r1[2], r2[1], t0[3], c0[2]);
  fullAdder f10(r3[6], r4[5], r5[4], t1[6], c1[5]);
  fullAdder f11(r3[7], r4[6], r5[5], t2[10], c1[6]);
  fullAdder f12(t0[3], c0[1], t1[0], t2[3], c2[1]);
  fullAdder f13(t0[4], c0[2], t1[1], t2[4], c2[2]);
  fullAdder f14(t0[5], c0[3], t1[2], t2[5], c2[3]);
  fullAdder f15(t0[6], c0[4], t1[3], t2[6], c2[4]);
  fullAdder f16(t0[7], c0[5], t1[4], t2[7], c2[5]);
  fullAdder f17(t0[8], c0[6], t1[5], t2[8], c2[6]);
  fullAdder f18(t0[9], c0[7], t1[6], t2[9], c2[7]);
  fullAdder f19(c1[2], r6[1], r7[0], t3[2], c3[1]);
  fullAdder f2(\r0[4] , r1[3], r2[2], t0[4], c0[3]);
  fullAdder f20(c1[3], r6[2], r7[1], t3[3], c3[2]);
  fullAdder f21(c1[4], r6[3], r7[2], t3[4], c3[3]);
  fullAdder f22(c1[5], r6[4], r7[3], t3[5], c3[4]);
  fullAdder f23(c1[6], r6[5], r7[4], t3[6], c3[5]);
  fullAdder f24(c1[7], r6[6], r7[5], t3[7], c3[6]);
  fullAdder f25(t2[5], c2[2], t3[0], t4[5], c4[2]);
  fullAdder f26(t2[6], c2[3], t3[1], t4[6], c4[3]);
  fullAdder f27(t2[7], c2[4], t3[2], t4[7], c4[4]);
  fullAdder f28(t2[8], c2[5], t3[3], t4[8], c4[5]);
  fullAdder f29(t2[9], c2[6], t3[4], t4[9], c4[6]);
  fullAdder f3(\r0[5] , r1[4], r2[3], t0[5], c0[4]);
  fullAdder f30(t2[10], c2[7], t3[5], t4[10], c4[7]);
  fullAdder f31(t4[7], c4[3], c3[0], t5[7], c5[3]);
  fullAdder f32(t4[8], c4[4], c3[1], t5[8], c5[4]);
  fullAdder f33(t4[9], c4[5], c3[2], t5[9], c5[5]);
  fullAdder f34(t4[10], c4[6], c3[3], t5[10], c5[6]);
  fullAdder f35(t4[11], c4[7], c3[4], t5[11], c5[7]);
  fullAdder f36(t4[12], c4[8], c3[5], t5[12], c5[8]);
  fullAdder f37(t4[13], c4[9], c3[6], t5[13], c5[9]);
  fullAdder f38(t5[5], c5[0], n_91, result[5], car[0]);
  fullAdder f39(t5[6], c5[1], car[0], result[6], car[1]);
  fullAdder f4(\r0[6] , r1[5], r2[4], t0[6], c0[5]);
  fullAdder f40(t5[7], c5[2], car[1], result[7], car[2]);
  fullAdder f41(t5[8], c5[3], car[2], result[8], car[3]);
  fullAdder f42(t5[9], c5[4], car[3], result[9], car[4]);
  fullAdder f43(t5[10], c5[5], car[4], result[10], car[5]);
  fullAdder f44(t5[11], c5[6], car[5], result[11], car[6]);
  fullAdder f45(t5[12], c5[7], car[6], result[12], car[7]);
  fullAdder f46(t5[13], c5[8], car[7], result[13], car[8]);
  fullAdder f47(t5[14], c5[9], car[8], result[14], car[9]);
  fullAdder f5(\r0[7] , r1[6], r2[5], t0[7], c0[6]);
  fullAdder f6(r3[2], r4[1], r5[0], t1[2], c1[1]);
  fullAdder f7(r3[3], r4[2], r5[1], t1[3], c1[2]);
  fullAdder f8(r3[4], r4[3], r5[2], t1[4], c1[3]);
  fullAdder f9(r3[5], r4[4], r5[3], t1[5], c1[4]);
  HalfAdder h0(\r0[1] , r1[0], result[1], c0[0]);
  HalfAdder h1(r1[7], r2[6], t0[8], c0[7]);
  HalfAdder h10(t4[4], c4[0], result[4], c5[0]);
  HalfAdder h11(t4[5], c4[1], t5[5], c5[1]);
  HalfAdder h12(t4[6], c4[2], t5[6], c5[2]);
  HalfAdder h13(c5[10], car[9], result[15], car[10]);
  HalfAdder h14(r6[7], r7[6], t4[13], c3[7]);
  HalfAdder h15(t4[14], c3[7], t5[14], c5[10]);
  HalfAdder h2(r3[1], r4[0], t1[1], t3[0]);
  HalfAdder h3(r4[7], r5[6], t2[11], c1[7]);
  HalfAdder h4(t0[2], c0[0], result[2], c2[0]);
  HalfAdder h5(c1[1], r6[0], t3[1], c3[0]);
  HalfAdder h6(t2[3], c2[0], result[3], c4[0]);
  HalfAdder h7(t2[4], c2[1], t4[4], c4[1]);
  HalfAdder h8(t2[11], t3[6], t4[11], c4[8]);
  HalfAdder h9(t2[12], t3[7], t4[12], c4[9]);
  CKND2BWP g127(.I (\r0[0]_BAR ), .ZN (result[0]));
  CKND2D3BWP g510(.A1 (a[0]), .A2 (b[0]), .ZN (\r0[0]_BAR ));
  CKAN2D0BWP g511(.A1 (a[1]), .A2 (b[1]), .Z (r1[1]));
  CKAN2D0BWP g512(.A1 (a[3]), .A2 (b[1]), .Z (r1[3]));
  CKAN2D0BWP g513(.A1 (a[7]), .A2 (b[0]), .Z (\r0[7] ));
  CKAN2D0BWP g514(.A1 (a[6]), .A2 (b[0]), .Z (\r0[6] ));
  CKAN2D0BWP g515(.A1 (a[7]), .A2 (b[7]), .Z (t4[14]));
  CKAN2D0BWP g516(.A1 (a[7]), .A2 (b[1]), .Z (r1[7]));
  CKAN2D0BWP g517(.A1 (a[5]), .A2 (b[7]), .Z (r7[5]));
  CKAN2D0BWP g518(.A1 (a[4]), .A2 (b[7]), .Z (r7[4]));
  CKAN2D0BWP g519(.A1 (a[3]), .A2 (b[7]), .Z (r7[3]));
  CKAN2D0BWP g520(.A1 (a[2]), .A2 (b[3]), .Z (r3[2]));
  CKAN2D0BWP g521(.A1 (a[2]), .A2 (b[7]), .Z (r7[2]));
  CKAN2D0BWP g522(.A1 (a[1]), .A2 (b[7]), .Z (r7[1]));
  CKAN2D0BWP g523(.A1 (a[4]), .A2 (b[6]), .Z (r6[4]));
  CKAN2D0BWP g524(.A1 (a[5]), .A2 (b[6]), .Z (r6[5]));
  CKAN2D0BWP g525(.A1 (a[3]), .A2 (b[3]), .Z (r3[3]));
  CKAN2D0BWP g526(.A1 (a[6]), .A2 (b[6]), .Z (r6[6]));
  CKAN2D0BWP g527(.A1 (a[7]), .A2 (b[6]), .Z (r6[7]));
  CKAN2D0BWP g528(.A1 (a[4]), .A2 (b[3]), .Z (r3[4]));
  CKAN2D0BWP g529(.A1 (a[3]), .A2 (b[6]), .Z (r6[3]));
  CKAN2D0BWP g530(.A1 (a[0]), .A2 (b[7]), .Z (r7[0]));
  CKAN2D0BWP g531(.A1 (a[1]), .A2 (b[6]), .Z (r6[1]));
  CKAN2D0BWP g532(.A1 (a[2]), .A2 (b[0]), .Z (\r0[2] ));
  CKAN2D0BWP g533(.A1 (a[0]), .A2 (b[2]), .Z (r2[0]));
  CKAN2D0BWP g534(.A1 (a[0]), .A2 (b[6]), .Z (r6[0]));
  CKAN2D0BWP g535(.A1 (a[7]), .A2 (b[5]), .Z (t2[12]));
  CKAN2D0BWP g536(.A1 (a[5]), .A2 (b[3]), .Z (r3[5]));
  CKAN2D0BWP g537(.A1 (a[5]), .A2 (b[5]), .Z (r5[5]));
  CKAN2D0BWP g538(.A1 (a[4]), .A2 (b[5]), .Z (r5[4]));
  CKAN2D0BWP g539(.A1 (a[3]), .A2 (b[5]), .Z (r5[3]));
  CKAN2D0BWP g540(.A1 (a[5]), .A2 (b[0]), .Z (\r0[5] ));
  CKAN2D0BWP g541(.A1 (a[1]), .A2 (b[5]), .Z (r5[1]));
  CKAN2D0BWP g542(.A1 (a[6]), .A2 (b[3]), .Z (r3[6]));
  CKAN2D0BWP g543(.A1 (a[0]), .A2 (b[5]), .Z (r5[0]));
  CKAN2D0BWP g544(.A1 (a[7]), .A2 (b[3]), .Z (r3[7]));
  CKAN2D0BWP g545(.A1 (a[3]), .A2 (b[0]), .Z (\r0[3] ));
  CKAN2D0BWP g546(.A1 (a[6]), .A2 (b[4]), .Z (r4[6]));
  CKAN2D0BWP g547(.A1 (a[5]), .A2 (b[4]), .Z (r4[5]));
  CKAN2D0BWP g548(.A1 (a[6]), .A2 (b[7]), .Z (r7[6]));
  CKAN2D0BWP g549(.A1 (a[3]), .A2 (b[4]), .Z (r4[3]));
  CKAN2D0BWP g550(.A1 (a[0]), .A2 (b[4]), .Z (r4[0]));
  CKAN2D0BWP g551(.A1 (a[4]), .A2 (b[1]), .Z (r1[4]));
  CKAN2D0BWP g552(.A1 (a[1]), .A2 (b[2]), .Z (r2[1]));
  CKAN2D0BWP g553(.A1 (a[1]), .A2 (b[4]), .Z (r4[1]));
  CKAN2D0BWP g554(.A1 (a[0]), .A2 (b[1]), .Z (r1[0]));
  CKAN2D0BWP g555(.A1 (a[2]), .A2 (b[4]), .Z (r4[2]));
  CKAN2D0BWP g556(.A1 (a[2]), .A2 (b[2]), .Z (r2[2]));
  CKAN2D0BWP g557(.A1 (a[4]), .A2 (b[4]), .Z (r4[4]));
  CKAN2D0BWP g558(.A1 (a[1]), .A2 (b[0]), .Z (\r0[1] ));
  CKAN2D0BWP g559(.A1 (a[2]), .A2 (b[1]), .Z (r1[2]));
  CKAN2D0BWP g560(.A1 (a[5]), .A2 (b[1]), .Z (r1[5]));
  CKAN2D0BWP g561(.A1 (a[2]), .A2 (b[6]), .Z (r6[2]));
  CKAN2D0BWP g562(.A1 (a[4]), .A2 (b[0]), .Z (\r0[4] ));
  CKAN2D0BWP g563(.A1 (a[0]), .A2 (b[3]), .Z (t1[0]));
  CKAN2D0BWP g564(.A1 (a[6]), .A2 (b[5]), .Z (r5[6]));
  CKAN2D0BWP g565(.A1 (a[6]), .A2 (b[2]), .Z (r2[6]));
  CKAN2D0BWP g566(.A1 (a[2]), .A2 (b[5]), .Z (r5[2]));
  CKAN2D0BWP g567(.A1 (a[3]), .A2 (b[2]), .Z (r2[3]));
  CKAN2D0BWP g568(.A1 (a[7]), .A2 (b[4]), .Z (r4[7]));
  CKAN2D0BWP g569(.A1 (a[4]), .A2 (b[2]), .Z (r2[4]));
  CKAN2D0BWP g570(.A1 (a[5]), .A2 (b[2]), .Z (r2[5]));
  CKAN2D0BWP g571(.A1 (a[6]), .A2 (b[1]), .Z (r1[6]));
  CKAN2D0BWP g572(.A1 (a[7]), .A2 (b[2]), .Z (t0[9]));
  CKAN2D0BWP g573(.A1 (a[1]), .A2 (b[3]), .Z (r3[1]));
endmodule

