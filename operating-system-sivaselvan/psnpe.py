a_t=[0,3,4,8,10,11]
b_t=[1,5,2,8,3,4]
pr=[4,5,7,2,1,6]

temp1=[]
for i in range(6):
    temp1.append([i,a_t[i],b_t[i],pr[i]])
# print(temp1)
temp2=[]
temp2.append([temp1[0][0],temp1[0][1],temp1[0][2],temp1[0][3],temp1[0][1]+temp1[0][2]])
temp1.pop(0)

for i in range(5):
    temp=[]
    for j in range(5-i):
        if(temp2[i][4]>=temp1[j][1]):
            temp.append(temp1[j])
    if(temp==[]):
        temp2.append(temp1.pop(0))
        temp2[i+1].append(temp2[i+1][1]+temp2[i+1][2])
    else:
        temp.sort(key=lambda val:val[3], reverse=True)
        temp2.append(temp[0])
        temp1.remove(temp[0])
        del temp
        temp2[i+1].append(temp2[i][4]+temp2[i+1][2])

for i in range(6):
    temp2[i].append(temp2[i][4]-temp2[i][1])
    temp2[i].append(temp2[i][5]-temp2[i][2])
temp2.sort(key=lambda val:val[0])
print("[pid, AT, BT, PR, CT, TAT, WT]")
sum=0
for i in range(6):
    sum+=temp2[i][6]
for item in temp2:
    print(item)
print("average wait time = {:.2f} ".format(sum/6))