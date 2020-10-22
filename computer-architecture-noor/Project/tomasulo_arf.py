
# Tomasulo Integer and Floating Point Register File.
class ARFobject:
    int_registers = [] # 16 registers by DLX standard
    fp_registers = [] # 16 registers by DLX standard
    
    def reg_initialize(self):#
        # code to initialize memory
        self.int_registers = [0]*16
        self.fp_registers = [0]*16

    def reg_write(self, register, value):#
        # code to store value at addr
        # register, value are strings
        if register[0] == 'R':
            reg_num = int(register.split('R')[1])
            if reg_num < 16 and reg_num != 0:
                self.int_registers[reg_num] = int(value)
            else:
                print ("Invalid register!")
                exit(0)
        elif register[0] == 'F':
            reg_num = int(register.split('F')[1])
            if reg_num < 16:
                self.fp_registers[reg_num] = float(value)
            else:
                print ("Invalid register!")
                exit(0)
        else:
            print ("Invalid register!")
            exit(0)
        
    def reg_read(self, register):#
        # code to load from addr
        # register is string
        if register[0] == 'R':
            reg_num = int(register.split('R')[1])
            if reg_num < 16:
                return self.int_registers[reg_num]
            else:
                print ("Invalid register!")
                exit(0)
        elif register[0] == 'F':
            reg_num = int(register.split('F')[1])
            if reg_num < 16:
                return self.fp_registers[reg_num]
            else:
                print ("Invalid register!")
                exit(0)
        else:
            print ("Invalid register!")
            exit(0)

    def reg_print(self):
        print ("-----------------------------------------------------------------------------------------------------------------------------------------------")
        print("{:^159}".format("INTEGER REGISTER FILE"))
        print ("-----------------------------------------------------------------------------------------------------------------------------------------------")
        row_spaces ="{:^10}" * 16
        reg_names = ["R0", "R1", "R2", "R3", "R4", "R5", "R6", "R7", "R8", "R9", "R10", "R11", "R12", "R13", "R14", "R15"]
        print(row_spaces.format(*reg_names))
        print(row_spaces.format(*self.int_registers[0:16]))
        print("\n")
        print ("-----------------------------------------------------------------------------------------------------------------------------------------------")
        print ("{:^159}".format("FLOATING POINT REGISTER FILE"))
        print ("-----------------------------------------------------------------------------------------------------------------------------------------------")    
        reg_names = ["F0", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "F13", "F14", "F15"]
        print (row_spaces.format(*reg_names))
        print (row_spaces.format(*self.fp_registers[0:16]))
        print("\n")