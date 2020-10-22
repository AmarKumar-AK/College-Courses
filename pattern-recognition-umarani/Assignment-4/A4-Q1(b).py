import math

class PR:
    
    i0 = 1
    i1 = 0.1
    i2 = 0.2
    h0 = 1

    neu = 0.1

    target_o1 = 0.4
    target_o2 = 0.3

    w1 = 0.1
    w2 = 0.1
    w3 = 0.2
    w4 = 0.2
    w5 = 0.1
    w6 = 0.1
    w7 = 0.2
    w8 = 0.2

    old_w1 = 0.1
    old_w2 = 0.1
    old_w3 = 0.2
    old_w4 = 0.2
    old_w5 = 0.1
    old_w6 = 0.1
    old_w7 = 0.2
    old_w8 = 0.2

    # net_h1 = (0.3 * i0 + w1 * i1 + w3 * i2)
    def net_h1(self):
        return (0.3 * self.i0 + self.w1 * self.i1 + self.w3*self.i2)

    # net_h2 = 0.2 * i0 + self.w2*self.i1 + self.w4*self.i2)
    def net_h2(self):
        return (0.2*self.i0 + self.w2*self.i1 + self.w4*self.i2)

    # activation function
    # tanh = (e^x - e^-x)/(e^x + e^-x)
    def out_h1(self):
        val1 = math.exp(self.net_h1()) # e^x
        val2 = 1/math.exp(self.net_h1()) # e^-x
        return ( (val1 - val2)/(val1 + val2) )

    # activation function
    # tanh = (e^x - e^-x)/(e^x + e^-x)
    def out_h2(self):
        val1 = math.exp(self.net_h2()) # e^x
        val2 = 1/math.exp(self.net_h2()) # e^-x
        return ( (val1 - val2)/(val1 + val2) )
##########################################################################
    # net_o1 =  (0.5 * h0) + (w5 * out_h1()) + (w7 * out_h2()) 
    def net_o1(self):
        return ( 0.5 * self.h0 + self.w5 * self.out_h1() + self.w7 * self.out_h2() )

    # net_o2 =  (0.5 * h0) + (w6 * out_h1()) + (w8 * out_h2()) 
    def net_o2(self):
        return 0.4*self.h0 + self.w6*self.out_h1() + self.w8*self.out_h2()

    # activation function
    # tanh = (e^x - e^-x)/(e^x + e^-x)
    def out_o1(self):
        val1 = math.exp(self.net_o1()) # e^x
        val2 = 1/math.exp(self.net_o1()) # e^-x
        return ( (val1 - val2)/(val1 + val2) )

    # activation function
    # tanh = (e^x - e^-x)/(e^x + e^-x)
    def out_o2(self):
        val1 = math.exp(self.net_o2()) # e^x
        val2 = 1/math.exp(self.net_o2()) # e^-x
        return ( (val1 - val2)/(val1 + val2) )
#################################################################
    # E_o1 = ((target_o1 - out_o1)^2)/2
    def E_o1(self):
        return ((self.target_o1 - self.out_o1())**2)/2

    # E_o2 = ((target_o2 - out_o2)^2)/2
    def E_o2(self):
        return ((self.target_o2 - self.out_o2())**2)/2

    # E_total = E_o1 + E_o2
    def E_total(self):
        return (self.E_o1() + self.E_o2())
#####################################################################
    def E_total_by_w(self,wx):
        # E_total/w5 = E_total/out_o1 * out_o1/net_o1 * net_o1/w5 
        if(wx == 5):
            temp1 = self.E_total_by_out_ox(1)
            temp2 = self.out_by_net_ox(1,1)
            temp3 = self.net_by_w(1,5)
            return (temp1*temp2*temp3)

        # E_total/w6 = E_total/out_o2 * out_o2/net_o2 * net_o2/w6
        elif(wx == 6):
            temp1 = self.E_total_by_out_ox(2)
            temp2 = self.out_by_net_ox(2,2)
            temp3 = self.net_by_w(2,6)
            return (temp1*temp2*temp3)

        # E_total/w7 = E_total/out_o1 * out_o1/net_o1 * net_o1/w7
        elif(wx == 7):
            temp1 = self.E_total_by_out_ox(1)
            temp2 = self.out_by_net_ox(1,1)
            temp3 = self.net_by_w(1,7)
            return (temp1*temp2*temp3)

        # E_total/w8 = E_total/out_o2 * out_o2/net_o2 * net_o2/w8 
        elif(wx == 8):
            temp1 = self.E_total_by_out_ox(2)
            temp2 = self.out_by_net_ox(2,2)
            temp3 = self.net_by_w(2,8)
            return (temp1*temp2*temp3)

        # E_total/w1 = E_total/out_h1 * out_h1/net_h1 * net_h1/w1
        elif(wx == 1):
            temp1 = self.E_total_by_out_hx(1)
            temp2 = self.out_by_net_hx(1,1)
            temp3 = self.net_by_w(1,1)
            return (temp1*temp2*temp3)

        # E_total/w2 = E_total/out_h2 * out_h2/net_h2 * net_h2/w2
        elif(wx == 2):
            temp1 = self.E_total_by_out_hx(2)
            temp2 = self.out_by_net_hx(2,2)
            temp3 = self.net_by_w(2,2)
            return (temp1*temp2*temp3)

        # E_total/w3 = E_total/out_h1 * out_h1/net_h1 * net_h1/w3
        elif(wx == 3):
            temp1 = self.E_total_by_out_hx(1)
            temp2 = self.out_by_net_hx(1,1)
            temp3 = self.net_by_w(1,3)
            return (temp1*temp2*temp3)

        # E_total/w4 = E_total/out_h2 * out_h2/net_h2 * net_h2/w4
        elif(wx == 4):
            temp1 = self.E_total_by_out_hx(2)
            temp2 = self.out_by_net_hx(2,2)
            temp3 = self.net_by_w(2,4)
            return (temp1*temp2*temp3)

    # E_total_by_out = out_ox - target_ox (after differentitation of E_total w.r.t out )
    # temp1 for 5,6,7,8
    # tmp1 for 1,2,3,4
    def E_total_by_out_ox(self, outx):
        if(outx == 1):
            return (self.out_o1() -self.target_o1)
        elif(outx == 2):
            return (self.out_o2() -self.target_o2)

    # out_by_net_ox = 4/(e^x + e^-x)^2
    # out_by_net_ox is differentiation of activation function
    # x belongs to net_ox
    # temp2 for 5,6,7,8
    # tmp2 for 1,2,3,4
    def out_by_net_ox(self, outx, netx):
        val1 = math.exp(self.net_o1())
        val2 = 1/math.exp(self.net_o1())
        val3 = math.exp(self.net_o2())
        val4 = 1/math.exp(self.net_o2())

        if(outx == 1 and netx == 1):
            return 4/((val1+val2)**2)
        elif(outx == 2 and netx == 2):
            return 4/((val3+val4)**2)

    # temp3
    def net_by_w(self, ox, wx):
        # differentiaion of net_ox w.r.t wx
        # for 5,6,7,8
        if(ox == 1 and wx == 5):
            return self.out_h1()
        elif(ox == 2 and wx == 6):
            return self.out_h1()
        elif(ox == 1 and wx == 7):
            return self.out_h2()
        elif(ox == 2 and wx == 8):
            return self.out_h2()

        # differentiaion of net_hx w.r.t wx
        # for 1,2,3,4
        elif(ox == 1 and wx == 1):
            return self.i1
        elif(ox == 2 and wx == 2):
            return self.i1
        elif(ox == 1 and wx == 3):
            return self.i2
        elif(ox == 2 and wx == 4):
            return self.i2
    
############################################################
    # temp1 for 1,2,3,4
    def E_total_by_out_hx(self,hx):
        # E_total/out_h1 = E_o1/out_h1 + E_o2/out_h1
        if(hx == 1):
            return (self.E_o1_by_h1() + self.E_o2_by_h1())
        # E_total/out_h2 = E_o1/out_h2 + E_o2/out_h2
        elif(hx == 2):
            return (self.E_o1_by_h2() + self.E_o2_by_h2())
        
    def E_o1_by_h1(self):
        # E_o1/out_h1 = E_o1/out_o1 * out_o1/net_o1 * net_o1/h1
        tmp1 = self.E_total_by_out_ox(1)
        tmp2 = self.out_by_net_ox(1,1)
        tmp3 = self.old_w5
        return (tmp1 * tmp2 * tmp3)

    def E_o2_by_h2(self):
        # E_o2/out_h2 = E_o2/out_o2 * out_o2/net_o2 * net_o2/h2
        tmp1 = self.E_total_by_out_ox(2)
        tmp2 = self.out_by_net_ox(2,2)
        tmp3 = self.old_w8
        return (tmp1 * tmp2 * tmp3)

    def E_o2_by_h1(self):
        # E_o2/out_h1 = E_o2/out_o2 * out_o2/net_o2 * net_o2/h1
        tmp1 = self.E_total_by_out_ox(2)
        tmp2 = self.out_by_net_ox(2,2)
        tmp3 = self.old_w6
        return (tmp1 * tmp2 * tmp3)

    def E_o1_by_h2(self):
        # E_o1/out_h2 = E_o1/out_o1 * out_o1/net_o1 * net_o1/h2
        tmp1 = self.E_total_by_out_ox(1)
        tmp2 = self.out_by_net_ox(1,1)
        tmp3 = self.old_w7
        return (tmp1 * tmp2 * tmp3)
    
########################################################################
    # temp2 for 1,2,3,4
    def out_by_net_hx(self,outx,netx):
        val1 = math.exp(self.net_h1())
        val2 = 1/math.exp(self.net_h1())
        val3 = math.exp(self.net_h2())
        val4 = 1/math.exp(self.net_h2())

        if(outx == 1 and netx == 1):
            return 4/((val1+val2)**2)
        elif(outx == 2 and netx == 2):
            return 4/((val3+val4)**2)

    def update_w(self,wx):
        # applying weight updatation formaula for each w
        if(wx == 5):
            self.old_w5 = self.w5
            self.w5 = self.old_w5 - self.neu * self.E_total_by_w(5)
            
        elif(wx == 6):
            self.old_w6 = self.w6
            self.w6 = self.old_w6 - self.neu * self.E_total_by_w(6)
            
        elif(wx == 7):
            self.old_w7 = self.w7
            self.w7 = self.old_w7 - self.neu * self.E_total_by_w(7)
            
        elif(wx == 8):
            self.old_w8 = self.w8
            self.w8 = self.old_w8 - self.neu * self.E_total_by_w(8)
            

        elif(wx == 1):
            self.old_w1 = self.w1
            self.w1 = self.old_w1 - self.neu * self.E_total_by_w(1)
            
        elif(wx == 2):
            self.old_w2 = self.w2
            self.w2 = self.old_w2 - self.neu * self.E_total_by_w(2)
            
        elif(wx == 3):
            self.old_w3 = self.w3
            self.w3 = self.old_w3 - self.neu * self.E_total_by_w(3)
            
        elif(wx == 4):
            self.old_w4 = self.w4
            self.w4 = self.old_w4 - self.neu * self.E_total_by_w(4)
            

############################################################################
iteration = int(input("Enter the number of iteration : ")) 
# print(iteration)
data = PR()
# print(data.net_h1())
for i in range(iteration):
    print("")
    print(f"################## iteration {i} ######################")
    print(f"out h1 = {data.out_h1()}    out h2 = {data.out_h2()}")
    print(f"out o1 = {data.out_o1()}    out o2 = {data.out_o2()}")
    print(f"w1 = {data.w1}  w2 = {data.w2}  w3 = {data.w3}  w4 = {data.w4}")
    print(f"w5 = {data.w5}  w6 = {data.w6}  w7 = {data.w7}  w8 = {data.w8}")
    print(f"old_w1 = {data.old_w1}  old_w2 = {data.old_w2}  old_w3 = {data.old_w3}  old_w4 = {data.old_w4}")
    print(f"old_w5 = {data.old_w5}  old_w6 = {data.old_w6}  old_w7 = {data.old_w7}  old_w8 = {data.old_w8}")

    print(f"E_total = {data.E_total()}")

    # print("hello")
    data.update_w(5)
    data.update_w(6)
    data.update_w(7)
    data.update_w(8)
    data.update_w(1)
    data.update_w(2)
    data.update_w(3)
    data.update_w(4)