# ####################################################################

#  Created by Encounter(R) RTL Compiler v14.10-s022_1 on Wed Aug 10 22:11:42 +0530 2016

# ####################################################################

set sdc_version 1.7

set_units -capacitance 1000.0fF
set_units -time 1000.0ps

# Set the current design
current_design RCA64bit

create_clock -name "clk" -period 5.0 -waveform {0.0 2.5} 
set_clock_gating_check -setup 0.0 
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports cin]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[0]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[1]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[2]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[3]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[4]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[5]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[6]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[7]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[8]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[9]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[10]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[11]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[12]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[13]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[14]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[15]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[16]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[17]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[18]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[19]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[20]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[21]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[22]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[23]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[24]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[25]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[26]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[27]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[28]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[29]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[30]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[31]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[32]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[33]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[34]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[35]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[36]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[37]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[38]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[39]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[40]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[41]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[42]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[43]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[44]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[45]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[46]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[47]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[48]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[49]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[50]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[51]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[52]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[53]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[54]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[55]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[56]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[57]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[58]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[59]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[60]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[61]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[62]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {b[63]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[0]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[1]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[2]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[3]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[4]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[5]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[6]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[7]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[8]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[9]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[10]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[11]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[12]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[13]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[14]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[15]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[16]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[17]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[18]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[19]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[20]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[21]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[22]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[23]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[24]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[25]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[26]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[27]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[28]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[29]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[30]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[31]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[32]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[33]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[34]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[35]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[36]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[37]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[38]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[39]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[40]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[41]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[42]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[43]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[44]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[45]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[46]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[47]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[48]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[49]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[50]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[51]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[52]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[53]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[54]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[55]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[56]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[57]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[58]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[59]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[60]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[61]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[62]}]
set_input_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {a[63]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports cout]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[0]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[1]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[2]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[3]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[4]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[5]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[6]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[7]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[8]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[9]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[10]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[11]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[12]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[13]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[14]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[15]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[16]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[17]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[18]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[19]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[20]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[21]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[22]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[23]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[24]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[25]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[26]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[27]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[28]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[29]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[30]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[31]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[32]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[33]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[34]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[35]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[36]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[37]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[38]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[39]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[40]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[41]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[42]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[43]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[44]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[45]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[46]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[47]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[48]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[49]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[50]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[51]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[52]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[53]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[54]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[55]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[56]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[57]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[58]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[59]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[60]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[61]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[62]}]
set_output_delay -clock [get_clocks clk] -add_delay 1.7 [get_ports {sum[63]}]
set_wire_load_mode "segmented"
set_wire_load_selection_group "WireAreaForZero" -library "tcbn45gsbwpbc0d88_ccs"
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/BHDBWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/BUFFD20BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/BUFFD24BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/BUFTD20BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/BUFTD24BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/CKBD20BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/CKBD24BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/CKLHQD20BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/CKLHQD24BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/CKLNQD20BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/CKLNQD24BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/CKND20BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/CKND24BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/DCCKBD20BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/DCCKND20BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GAN2D1BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GAN2D2BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GAOI21D1BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GAOI21D2BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GAOI22D1BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GBUFFD1BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GBUFFD2BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GBUFFD3BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GBUFFD4BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GBUFFD8BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GDCAP10BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GDCAP2BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GDCAP3BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GDCAP4BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GDCAPBWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GDFCNQD1BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GDFQD1BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GFILL10BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GFILL2BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GFILL3BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GFILL4BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GFILLBWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GINVD1BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GINVD2BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GINVD3BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GINVD4BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GINVD8BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GMUX2D1BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GMUX2D2BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GMUX2ND1BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GMUX2ND2BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GND2D1BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GND2D2BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GND2D3BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GND2D4BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GND3D1BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GND3D2BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GNR2D1BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GNR2D2BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GNR3D1BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GNR3D2BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GOAI21D1BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GOAI21D2BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GOR2D1BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GOR2D2BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GSDFCNQD1BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GTIEHBWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GTIELBWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GXNR2D1BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GXNR2D2BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GXOR2D1BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/GXOR2D2BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/INVD20BWP]
set_dont_use [get_lib_cells tcbn45gsbwpbc0d88_ccs/INVD24BWP]
