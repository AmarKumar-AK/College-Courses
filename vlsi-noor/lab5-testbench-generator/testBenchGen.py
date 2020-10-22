import re
import sys
import itertools

def delete_comment(vtext):
    vtext=re.sub('//.*',"",vtext)
    return vtext
# function for generating inputs
def foo(l,size):
     yield from itertools.product(*([l] * size))
fname=""
oname=""
# inputting file name
fname = input("enter the name of file for which you want to generate testbench\n")

vfile = open(fname,'r')
vtext = vfile.read()
vtext=delete_comment(vtext)
ofile = open("output_tb.v",'w')
# getting module name
modname= (re.findall('module[\s]+(\S*)[\s]*\([^\)]*\)[\s\S]*',vtext))
print(modname)
ofile.write("`include \""+fname+"\"\n")
ofile.write("module top;\n")

# ipop contains input and output list
ipop = []
for i in re.findall('(input|output)[\s]+([^;\)]+)[\s]*[;,]', vtext):
    ipop.append((i[0], re.sub(r"^reg[\s]*", "", i[1])))

# ip contains inputs dictionary
# op contains outputs dictionary
ip=[]
op=[]

icount =0
for i in ipop:
    if i[0]=="input":
        ofile.write("reg "+i[1]+";\n")
        ip.append(i[1])

for i in ipop:
    if i[0]=="output":
        ofile.write("wire "+i[1]+";\n")
        op.append(i[1])

print (ip)
# ia contains input list
# oa contains output list
ia=[]
oa=[]
for i in ip:
    ia.append(re.findall('[^0-9\[:\s\],]\w*',i))
for i in op:
    oa.append(re.findall('[^0-9\[:\s\],]\w*',i))


st = ""
for i in ia:
    for j in i:
        st=st+j+","
ast=st
ast=ast[:-1]
for i in oa:
    for j in i:
        st=st+j+","
st=st[:-1]
print (st)
ofile.write(modname[0]+" "+modname[0]+"_0("+st+");\n")

ofile.write("initial\n\tbegin\n\n")
inputs=ast.split(",")

comb=[]
print("total no. of i/p:"+str(len(inputs)))
totalComb=int(input("enter no of test:"))
tc=totalComb
for x in foo('01',len(inputs)):
    comb.append(''.join(x))
    totalComb=totalComb-1
    if(totalComb==0):
        break;
print(comb)

t=0
line=""
# print(comb[2])
for i in range(0,tc):

    line=line+"\t\t#"+str(t)+" "
    for index,j in enumerate(inputs):
        line=line+j+"=1'b"+comb[i][index]+"; "
    line=line+"\n"
    t=t+5
    print(line)
    ofile.write(line)
    line=""

ofile.write("\tend\n\ninitial\n\tbegin\n")
line="$monitor($time, \" "
allVar=st.split(",")
# print(allVar)

for index,i in enumerate(allVar):
    if(index==len(allVar)-1):
        line+=i+"=%b\","
        break
    line = line +i+"=%b, "
for i,val in enumerate(allVar):
    if(i==len(allVar)-1):
        line+=val
        break
    line+=val+","
line+=");"
# print(line)
ofile.write("\t\t"+line)
ofile.write("\n\t\t$dumpfile(\""+modname[0]+".vcd\");\n\t\t$dumpvars;\n")
ofile.write("\tend\n\nendmodule")
ofile.close()
