import re
import sys
def delete_comment(vtext):
    vtext=re.sub('//.*',"",vtext)
    return vtext
fileName = input("enter file name : ")
vfile = open(fileName,'r')
vtext = vfile.read()
vtext=delete_comment(vtext)
ipopwi = []
for i in re.findall('(input|output|wire)[\s]+([^;\)]+)[\s]*[;,]', vtext):
    ipopwi.append((i[0], re.sub(r"^reg[\s]*", "", i[1])))
ip=[]
for i in ipopwi:
    if i[0]=="input":
        ip.append(i[1])
onlyip=[]
for i in ip[0].split(','):
    onlyip.append(i.strip())
op=[]
for i in ipopwi:
    if i[0]=="output":
        op.append(i[1])
onlyop=[]
for i in op[0].split(','):
    onlyop.append(i.strip())
wi=[]
for i in ipopwi:
    if i[0]=="wire":
        wi.append(i[1])
onlywi=[]
for i in wi[0].split(','):
    onlywi.append(i.strip())
prob_dict={}
for x in onlyip:
    prob_dict[x]=0.5
alpha_dict={}
allgate=[]
for i in re.findall('(nand|and|or|xor|nor|not|buf)[\s](.*)(\((.*?)\))',vtext):
    allgate.append(i)
test=[]
res=1
for data in allgate:
    temp=[]
    if(data[0]=='and'):
        test.append([data[0],data[3]])
        for i in data[3].split(','):
            temp.append(i.strip())
            for j in range(1,len(temp)):
                res=res*prob_dict[temp[j]]
            prob_dict[temp[0]]=res
            res=1
    elif(data[0]=='or'):
        test.append([data[0],data[3]])
        for i in data[3].split(','):
            temp.append(i.strip())
            for j in range(1,len(temp)):
                res=res*(1-prob_dict[temp[j]])
            prob_dict[temp[0]]=1-res
            res=1
    elif(data[0]=='nand'):
        test.append([data[0],data[3]])
        for i in data[3].split(','):
            temp.append(i.strip())
            for j in range(1,len(temp)):
                res=res*prob_dict[temp[j]]
            prob_dict[temp[0]]=1-res
            res=1
    elif(data[0]=='nor'):
        test.append([data[0],data[3]])
        for i in data[3].split(','):
            temp.append(i.strip())
            for j in range(1,len(temp)):
                res=res*(1-prob_dict[temp[j]])
            prob_dict[temp[0]]=res
            res=1
    elif(data[0]=='xor'):
        test.append([data[0],data[3]])
        for i in data[3].split(','):
            temp.append(i.strip())
        res=prob_dict[temp[1]]*(1-prob_dict[temp[2]]) + prob_dict[temp[2]]*(1-prob_dict[temp[1]])
        prob_dict[temp[0]]=res
        res=1
    elif(data[0]=='not'):
        test.append([data[0],data[3]])
        for i in data[3].split(','):
            temp.append(i.strip())
        res=prob_dict[temp[1]];
        prob_dict[temp[0]]=1-res
        res=1
    elif(data[0]=='buf'):
        test.append([data[0],data[3]])
        for i in data[3].split(','):
            temp.append(i.strip())
        res=prob_dict[temp[1]];
        prob_dict[temp[0]]=res
        res=1
for i in prob_dict:
    if i not in onlyip:
        alpha_dict[i]=prob_dict[i]*(1-prob_dict[i])
print(alpha_dict)