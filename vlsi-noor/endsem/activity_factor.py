# all comments are written for c17.v
import re
import sys

def delete_comment(vtext):
    vtext=re.sub('//.*',"",vtext)
    return vtext
    
fileName = input("enter file name\n")
#vfile is file opened to read
vfile = open(fileName,'r')
#vtext is read file that contains data of c17
vtext = vfile.read()
# calling function to delete comment
vtext=delete_comment(vtext)

# ipop contains input, output, wire list
# [('input', 'N1,N2,N3,N6,N7'), ('output', 'N22,N23'), ('wire', 'N10,N11,N16,N19')]
ipopwi = []
for i in re.findall('(input|output|wire)[\s]+([^;\)]+)[\s]*[;,]', vtext):
    ipopwi.append((i[0], re.sub(r"^reg[\s]*", "", i[1])))

# ip contains inputs - ['N1,N2,N3,N6,N7']
ip=[]
for i in ipopwi:
    if i[0]=="input":
        ip.append(i[1])
# onlyip contains - ['N1', 'N2', 'N3', 'N6', 'N7']
onlyip=[]
for i in ip[0].split(','):
    onlyip.append(i.strip())
# print(onlyip)

# op contains outputs - ['N22,N23']
op=[]
for i in ipopwi:
    if i[0]=="output":
        op.append(i[1])
# onlyop contains - ['N22', 'N23']
onlyop=[]
for i in op[0].split(','):
    onlyop.append(i.strip())
# print(onlyop)
# wi contains wire - ['N10,N11,N16,N19']
wi=[]
for i in ipopwi:
    if i[0]=="wire":
        wi.append(i[1])
# onlywire contains - ['N10', 'N11', 'N16', 'N19']
onlywi=[]
for i in wi[0].split(','):
    onlywi.append(i.strip())
# print(onlywi)
prob_dict={}
for x in onlyip:
    prob_dict[x]=0.5
# print(prob_dict)

alpha_dict={}

allgate=[]

for i in re.findall('(nand|and|or|xor|nor|not|buf)[\s](.*)(\((.*?)\))',vtext):
    allgate.append(i)

test=[]
tempand=[]
tempor=[]
tempnand=[]
tempnor=[]
tempxor=[]
tempnot=[]
tempbuf=[]
res=1
for data in allgate:
    if(data[0]=='and'):
        test.append([data[0],data[3]])
        for i in data[3].split(','):
            tempand.append(i.strip())
            for j in range(1,len(tempand)):
                res=res*prob_dict[tempand[j]]
            prob_dict[tempand[0]]=res
            res=1
        tempand.clear()
    elif(data[0]=='or'):
        test.append([data[0],data[3]])
        for i in data[3].split(','):
            tempor.append(i.strip())
            for j in range(1,len(tempor)):
                res=res*(1-prob_dict[tempor[j]])
            res=1-res
            prob_dict[tempor[0]]=res
            res=1
        tempor.clear()
    elif(data[0]=='nand'):
        test.append([data[0],data[3]])
        for i in data[3].split(','):
            tempnand.append(i.strip())
            for j in range(1,len(tempnand)):
                # print(tempnand[j])
                res=res*prob_dict[tempnand[j]]
            res=1-res
            prob_dict[tempnand[0]]=res
            res=1
        tempnand.clear()
    elif(data[0]=='nor'):
        test.append([data[0],data[3]])
        for i in data[3].split(','):
            tempnor.append(i.strip())
            for j in range(1,len(tempnor)):
                res=res*(1-prob_dict[tempnor[j]])
            prob_dict[tempnor[0]]=res
            res=1
        tempnor.clear()
    elif(data[0]=='xor'):
        test.append([data[0],data[3]])
        for i in data[3].split(','):
            tempxor.append(i.strip())
            # print(tempxor)
        res=prob_dict[tempxor[1]]*(1-prob_dict[tempxor[2]]) + prob_dict[tempxor[2]]*(1-prob_dict[tempxor[1]])
        prob_dict[tempxor[0]]=res
        res=1
        tempxor.clear()
    elif(data[0]=='not'):
        test.append([data[0],data[3]])
        for i in data[3].split(','):
            tempnot.append(i.strip())
            # print(tempnot)
        res=prob_dict[tempnot[1]];
        res=1-res
        prob_dict[tempnot[0]]=res
        res=1
        tempnot.clear()
    elif(data[0]=='buf'):
        test.append([data[0],data[3]])
        for i in data[3].split(','):
            tempbuf.append(i.strip())
            # print(tempnot)
        res=prob_dict[tempbuf[1]];
        prob_dict[tempbuf[0]]=res
        res=1
        tempbuf.clear()

# probability dictionary  
# print(prob_dict)
for i in prob_dict:
    if i not in onlyip:
        alpha_dict[i]=prob_dict[i]*(1-prob_dict[i])

# activity factor
print(alpha_dict)