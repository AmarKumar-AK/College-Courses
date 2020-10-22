import os
import sys

# def func():
#     print("hello")

def Add(a,b):
    a=str(a)
    b=str(b)
    f=open("fullAdder/fullAdder64_tb.v","w")
    # header
    f.write('`include "fullAdder/fullAdder64.v"\n`include "fullAdder/fullAdder32.v"\n`include "fullAdder/fullAdder16.v"\n`include "fullAdder/fullAdder8.v"\n`include "fullAdder/fullAdder4.v"\n`include "fullAdder/fullAdder.v"\n')
    # input output
    f.write('module top;\nreg [63:0]a, b;\nreg cin;\nwire [63:0]sum;\nwire ca;\n\tfullAdder64 FA_0(a,b,cin,sum,ca);\ninitial\nbegin\n')
    # appending value of a and b
    f.write("\t#0 a="+a+"; b="+b+" ; cin=0;\n")
    f.write('end\ninitial\nbegin\n\t$monitor("%d",sum);\nend\nendmodule')
    f.close()
    os.system("iverilog fullAdder/fullAdder64_tb.v -o fullAdder64")
    os.system("./fullAdder64>temp.txt")
    fp=open("temp.txt","r")
    l=[]
    for data in fp.readlines():
        l=data.split()
    fp.close()
    os.system("rm temp.txt")
    os.system("rm fullAdder64")
    return int(l[0])

# res=Add(100,200)
# print(res)   

def mac(x,n):
    # a=[]
    # b=[]
    # for i in range(0,n):
    #     a.append(str(x[i][0]))
    #     b.append(str(x[i][1]))
    f=open("mac/mac_tb.v","w")
    # header
    f.write('`include "mac/mac.v"\n')
    # input output
    f.write("module top;\nreg [15:0]a,b;\nreg clk,reset;\nwire [35:0]c;\nmac m1(a,b,c,clk,reset);\ninitial\nbegin\n")
    f.write("#0 clk=1; reset=1; a=0; b=0;\n")
    f.write("#5 reset=0;\nend\nalways\nbegin\n#5 clk=~clk;\nend\nalways\nbegin\n")
    for i in range(0,n):
        f.write("#10 a="+str(x[i][0])+"; b="+str(x[i][1])+";\n")
    f.write("end\n")
    f.write('initial begin\n\t#'+str(10*n+1)+ '$display("%d",c);\n\t#'+str(10*n)+' $finish;\nend\nendmodule\n')
    f.close()
    os.system("iverilog mac/mac_tb.v -o mac16")
    os.system("./mac16>temp.txt")
    fp=open("temp.txt","r")
    l=[]
    for data in fp.readlines():
        l=data.split()
    fp.close()
    os.system("rm temp.txt")
    os.system("rm mac16")
    return int(l[0])

# x=[[1,2],[2,3],[3,4]]
# res=mac_tb_gen_16bit(x,len(x))
# print(res)

def mul(a,b):
    a=str(a)
    b=str(b)
    f=open("multiplier/multi16_tb.v","w")
    # header
    f.write('`include "multiplier/multi16.v"\n')
    # input output
    f.write('module top;\nreg [15:0]a, b;\nwire [31:0]mul;\n\tmulti16 FA_0(a,b,mul);\ninitial\nbegin\n')
    # appending value of a and b
    f.write("\t#0 a="+a+"; b="+b+" ;\n")
    f.write('end\ninitial\nbegin\n\t$monitor("%d",mul);\nend\nendmodule')
    f.close()
    os.system("iverilog multiplier/multi16_tb.v -o multi16")
    os.system("./multi16>temp.txt")
    fp=open("temp.txt","r")
    l=[]
    for data in fp.readlines():
        l=data.split()
    fp.close()
    os.system("rm temp.txt")
    os.system("rm multi16")
    return int(l[0])

# res=multi16_tb_gen_16bit(10,20)
# print(res)

def subt(a,b):
    a=str(a)
    b=str(b)
    f=open("subtracter/sub64_tb.v","w")
    # header
    f.write('`include "subtracter/sub64.v"\n')
    # input output
    f.write('module top;\nreg [63:0]a, b;\nreg cin;\nwire [63:0]d;\nwire br;\n\tsub64 S1(a,b,cin,d,br);\ninitial\nbegin\n')
    # appending value of a and b
    f.write("\t#0 a="+a+"; b="+b+" ; cin=0;\n")
    f.write('end\ninitial\nbegin\n\t$monitor("%d",d);\nend\nendmodule')
    f.close()
    os.system("iverilog subtracter/sub64_tb.v -o sub64")
    os.system("./sub64>temp.txt")
    fp=open("temp.txt","r")
    l=[]
    for data in fp.readlines():
        l=data.split()
    fp.close()
    os.system("rm temp.txt")
    os.system("rm sub64")
    return int(l[0])

# res=subt(50,25)
# print(res)

def div(a,b):
    count=0
    while(a>=b):
        a=subt(a,b)
        count=Add(count,1)
    return (count+a/b)

# res=div(16,3)
# print(res)

def rec_doub(a,b):
    a=str(a)
    b=str(b)
    f=open("recursive_doubling/doub64_tb.v","w")
    # header
    f.write('`include "recursive_doubling/doub64.v"\n')
    # input output
    f.write('module top;\nreg [63:0]a, b;\nreg cin;\nwire [63:0]sum;\nwire ca;\n\tdoub64 d1(a,b,cin,sum,ca);\ninitial\nbegin\n')
    # appending value of a and b
    f.write("\t#0 a="+a+"; b="+b+" ; cin=0;\n")
    f.write('end\ninitial\nbegin\n\t$monitor("%d",sum);\nend\nendmodule')
    f.close()
    os.system("iverilog recursive_doubling/doub64_tb.v -o doub64")
    os.system("./doub64>temp.txt")
    fp=open("temp.txt","r")
    l=[]
    for data in fp.readlines():
        l=data.split()
    fp.close()
    os.system("rm temp.txt")
    os.system("rm doub64")
    return int(l[0])

# res=rec_doub(200,300)
# print(res)