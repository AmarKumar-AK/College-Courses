
# Tomasulo Register Alias Table (Register and fp registers status)

class RATobject:
    int_rat = [] # same size as ARF
    fp_rat = [] # same size as ARF
    
    def rat_initialize(self):#
        # initialize rat
        for i in range(0, 16):
            self.int_rat.append("R" + str(i))
            self.fp_rat.append("F" + str(i)) 

    def rat_get(self, reg):#
        if reg[0] == 'R':
            int_rat_update_index = int(reg.split("R")[1])
            return self.int_rat[int_rat_update_index]  
        elif reg[0] == 'F':
            fp_rat_update_index = int(reg.split("F")[1])
            return self.fp_rat[fp_rat_update_index]           
 
    def int_rat_get(self, int_reg):#
        # get current value in int_reg location
        int_rat_update_index = int(int_reg.split("R")[1])
        return self.int_rat[int_rat_update_index]
    
    def fp_rat_get(self, fp_reg):
        # get current value in int_reg location
        fp_rat_update_index = int(fp_reg.split("F")[1])
        return self.fp_rat[fp_rat_update_index]
    
    def rat_update(self, reg, value):#
        if reg[0] == 'R':
            int_rat_update_index = int(reg.split("R")[1])
            self.int_rat[int_rat_update_index] = value  
        elif reg[0] == 'F':
            fp_rat_update_index = int(reg.split("F")[1])
            self.fp_rat[fp_rat_update_index] = value
    
    def int_rat_update(self, int_reg, int_value):
        #update mapping for Integer RAT
        int_rat_update_index = int(int_reg.split("R")[1])
        self.int_rat[int_rat_update_index] = int_value  

    def fp_rat_update(self, fp_reg, fp_value):
        #update mapping for Floating Point RAT
        fp_rat_update_index = int(fp_reg.split("F")[1])
        self.fp_rat[fp_rat_update_index] = fp_value
        
    def rat_print(self):
        print ("-----------------------------------------------------------------------------------------------------------------------------------------------")
        print ("{:^159}".format("INTEGER RAT"))
        print ("-----------------------------------------------------------------------------------------------------------------------------------------------")
        row_format ="{:^10}" * 16
        reg_names = ["R0", "R1", "R2", "R3", "R4", "R5", "R6", "R7", "R8", "R9", "R10", "R11", "R12", "R13", "R14", "R15"]
        print (row_format.format(*reg_names))
        print (row_format.format(*self.int_rat[0:16]))
        print()
        print ("-----------------------------------------------------------------------------------------------------------------------------------------------")
        print ("{:^159}".format("FLOATING POINT RAT"))
        print ("-----------------------------------------------------------------------------------------------------------------------------------------------")
        reg_names = ["F0", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "F13", "F14", "F15"]
        print (row_format.format(*reg_names))
        print (row_format.format(*self.fp_rat[0:16]))
        print()