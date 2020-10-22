a_t=[0,3,4,8,10,11]
b_t=[1,5,2,8,3,4]
pr=[4,5,7,2,1,6]
# copying b_t in burst_time 
burst_time=b_t[:]
temp1=[]
for i in range(6):
    temp1.append([i,a_t[i],b_t[i],pr[i]])
# print(temp1)
time=0
count=0
# c stands for burst_time in temp1
# for a,b,c in temp1:
#     if(c==0):
#         count=count+1
# count=0
# print(count)
while(count != 6):
    temp=[]
    for i in range(6):
        if(time>=a_t[i] and b_t[i]!=0):
            temp.append(temp1[i])

    if(temp==[]):
        time=time+1
    else:
        # temp sorted according to priority
        temp.sort(key=lambda val: val[3], reverse=True)
        # finding index of b_t which need to be reduced
        index=temp[0][0]
        b_t[index]=b_t[index]-1
        # print("b_t = {}".format(b_t))
        temp1[index][2]=temp1[index][2]-1
        time=time+1
        if(b_t[index]==0):
            temp1[index].append(time)
            count=count+1
        # print("temp1 = {}".format(temp1))
else:
    print("done")
    for i in range(6):
        temp1[i][2]=burst_time[i]
    for i in range(6):
        temp1[i].append(temp1[i][4]-temp1[i][1])
        temp1[i].append(temp1[i][5]-temp1[i][2])
    # print(temp1)
    print("[pid, AT, BT, PR, CT, TAT, WT]")
    for i in range(6):
        print(temp1[i])
    sum=0
    for i in range(6):
        sum=sum+temp1[i][6]
    print("avg_wait_time = {:.2f}".format(sum/6))