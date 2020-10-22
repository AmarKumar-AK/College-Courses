**Tomasulo Algorithm implementation using python**

**how to run the code**
-> python3 tomasulo_main.py [input file name] ***([input file name] should be replaced with file name of input file)***

**Configuration set from input file**
number of ROB entries, number of RS for functional unit, number of cycle for Execution stage for each functional unit, number of cycles for memory access, register values, memory values, instructions

**processor components**
1 instruction buffer : instruction_buffer
1 integer Architectured Register File(ARF) : int_registers
1 floating point ARF : fp_registers
1 Register Alias Table(RAT) : rat
1 reservation station(RS) for adder : adder_rs
1 RS for mult/div : mult_div_rs
1 common data bus(CDB) : cdb
1 ReOrder Buffer(ROB) : rob
1 load/store queue (similar to reservation station for memory unit), contains address and value(not useful for load) : load_store_queue

**Results contains**
INTEGER ADDER PROPERTIES, FP ADDER PROPERTIES, FP MULTIPLIER PROPERTIES, LOAD STORE UNIT PROPERTIES, ROB PROPERTIES
ROB,
INTEGER ADDER RS , FLOATING POINT ADDER RS, FLOATING POINT MULTIPLIER RS, LOGIC UNIT RS,
LOAD STORE QUEUE
TIMING TABLE
INTEGER REGISTER FILE, FLOATING POINT REGISTER FILE, 
INTEGER RAT, FLOATING POINT RAT 
***These results are printed for each clock cycle***