#*#####################################################
# Script for Cadence RTL Compiler synthesis
# Erik Brunvand, 2008
# Use with rc -f <rtl-script>
# Updated by Eric MacDonald to avoid double output flops to avoid DRC errors in ICC
#*#####################################################

# Set the search paths to the libraries and the HDL files
# Remember that "." means your current directory

set dir /home/iiitdm/Desktop/log/Amar/mac_done
set myFiles [list mac.v] ;# All your HDL files
set basename mac;# name of top level module
set myClk clk ;# clock name
set myPeriod_ps 3000 ;# Clock period in ps - MHz
set myInDelay_ps  1500 ;# delay from clock to inputs valid - 0.1 ns
set myOutDelay_ps 1500 ;# delay from clock to output valid - 0.1 ns
set runname post_synth_tcbn45nm ;# name appended to output files

#*********************************************************
#* below here shouldn't need to be changed... *
#*********************************************************
set_attribute hdl_search_path ${dir} ;# Search path for Verilog files
set_attribute lib_search_path /home/cadence/cadence_tools/genus_lib ;# Search path for library files
set_attribute library [list tcbn45gsbwpbc0d88_ccs.lib] ;# Target Library
set_attribute information_level 6 ;# See a lot of warnings.

# Analyze and Elaborate the HDL files
read_hdl ${myFiles}

#*********************************************************
#* Avoid these flip-flops - two outputs not always using both causing DRCs in ICC 
#*********************************************************
#set_attribute avoid true [find / -libcell DCBX1]
#set_attribute avoid true [find / -libcell DCBNX1]

elaborate ${basename}

# Apply Constraints and generate clocks
set clock [define_clock -period ${myPeriod_ps} -name ${myClk} [clock_ports]]
external_delay -input $myInDelay_ps -clock ${myClk} [find / -port ports_in/*]
external_delay -output $myOutDelay_ps -clock ${myClk} [find / -port ports_out/*]

# Sets transition to default values for Synopsys SDC format,
# fall/rise 400ps
#*########################################################################
#dc::set_clock_transition .4 $myClk

# check that the design is OK so far
check_design -unresolved
report timing -lint

# Synthesize the design to the target library
synthesize -to_mapped -effort low
#synthesize -to_mapped -effort medium
#synthesize -to_mapped -effort high
#synthesize -to_generic -no_incremental
#synthesize -to_generic 



# Write out the reports
report timing > ${dir}/report/${basename}_${runname}_timing.rep
report gates > ${dir}/report/${basename}_${runname}_cell.rep
report power > ${dir}/report/${basename}_${runname}_power.rep

# Write out the structural Verilog and sdc files
write_hdl -mapped > ${dir}/netlist/${basename}_${runname}.v
write_sdc > ${dir}/sdc/${basename}_${runname}.sdc
gui_show
