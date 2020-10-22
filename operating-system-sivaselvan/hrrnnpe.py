a_t=[0,3,4,8,10,11]
b_t=[1,5,2,8,3,4]
# temp1[pid,at,bt,hrr]
temp1=[]
for i in range(6):
    temp1.append([i,a_t[i],b_t[i]])
# print(temp1)
time=0
count=0
# temp2[pid,at,bt,ct]
temp2=[]
temp2.append([temp1[0][0],temp1[0][1],temp1[0][2],temp1[0][1]+temp1[0][2]])
temp1.pop(0)
# print(temp2)
# print(temp1)
for i in range(5):
    temp=[]
    for j in range(5-i):
        if(temp2[i][3]>=temp1[j][1]):
            temp.append(temp1[j])

    if(temp==[]):
        temp2.append(temp1.pop(0))
        temp2[i+1].append(temp2[i+1][1]+temp2[i+1][2])
    else:
        for j in range(len(temp)):
            temp[j].append( (temp2[i][3] - temp[j][1] + temp[j][2]) / temp[j][2] )
            # print("temp = {}".format(temp[j]))
        temp.sort(key=lambda val:val[3], reverse=True)
        # removing hrr
        for j in range(len(temp)):
            temp[j].remove(temp[j][3])
        # print(temp)
        temp2.append(temp[0])
        temp1.remove(temp[0])
        del temp
        temp2[i+1].append(temp2[i+1][2]+temp2[i][3])
# turn_around_time and wait_time respectively
sum=0
for i in range(6):
    temp2[i].append(temp2[i][3]-temp2[i][1])
    temp2[i].append(temp2[i][4]-temp2[i][2])
    sum+=temp2[i][5]
print("[pid, arrival_time, burst_time, completion_time, turn_around_time, wait_time]")
for item in temp2:
    print(item)
print("average wait time ={}".format(sum/6))