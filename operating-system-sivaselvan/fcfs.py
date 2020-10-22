import os
# calculating arrival_time
first=int(os.path.getctime("1.txt")%100000)
second=int(os.path.getctime("2.txt")%100000)
third=int(os.path.getctime("3.txt")%100000)
fourth=int(os.path.getctime("4.txt")%100000)
fifth=int(os.path.getctime("5.txt")%100000)
arrival_time=[first,second,third,fourth,fifth]
# calculating burst_time
with open("1.txt",'r') as f1,open("2.txt",'r') as f2,open("3.txt",'r') as f3,open("4.txt",'r') as f4,open("5.txt",'r') as f5:
    for l1 in f1:
        len1=len(l1.split())
    for l2 in f2:
        len2=len(l2.split())
    for l3 in f3:
        len3=len(l3.split())
    for l4 in f4:
        len4=len(l4.split())
    for l5 in f5:
        len5=len(l5.split())
burst_time=[len1,len2,len3,len4,len5]
# zipping arrival_time and burst_time a/c arrival_time
a_b=sorted(dict(zip(arrival_time,burst_time)).items())
# putting arrival_time and burst_time in temp1(list)
temp1=[]
for i in range(5):
    temp1.append([a_b[i][0],a_b[i][1]])
# completion_time of first arrived element
temp1[0].append(a_b[0][0]+a_b[0][1])
# Completion_time of all
for i in range(4):
    if(temp1[i][2]>a_b[i+1][0]):
        temp1[i+1].append(temp1[i][2]+temp[i+1][1])
    else:
        temp1[i+1].append(temp1[i+1][0]+temp1[i+1][1])
# turn_around_time and wait_time respectively
for i in range(5):
    temp1[i].append(temp1[i][2]-temp1[i][0])
    temp1[i].append(temp1[i][3]-temp1[i][1])
print("[arrival_time, burst_time, completion_time, turn_around_time, wait_time]")
print(temp1)
