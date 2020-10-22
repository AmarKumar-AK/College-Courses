a_t=[0,3,4,8,10,11]
b_t=[1,5,2,8,3,4]
time_quantum=2
ready_queue=[]
# copying b_t in burst_time 
burst_time=b_t[:]
temp1=[]
for i in range(6):
    temp1.append([i,a_t[i],b_t[i]])
# print(temp1)
temp2=temp1[:]
temp3=temp1[:]
time=0
count=len(a_t)
# print(count)
time=time+temp1[0][1]
ready_queue.append(temp1[0])
# print(ready_queue,time)
popped=[]
while(count!=0):
    if(ready_queue[0][2]<=time_quantum):
        print("hello ={}".format(count))
        time=time+ready_queue[0][2]
        print("hello time ={}".format(time))
        index=ready_queue[0][0]
        temp2[index].append(time)
        b_t[index]=0
        temp3[index][2]=0
        temp1.remove(ready_queue.pop(0))
        print(ready_queue)
        count=count-1
    else:
        print("hello1")
        time=time+time_quantum
        print("hello1 time = {}".format(time))
        ready_queue[0][2]=ready_queue[0][2]-time_quantum
        index=ready_queue[0][0]
        b_t[index]=b_t[index]-time_quantum
        temp3[index][2]=temp3[index][2]-time_quantum
        temp1[index][2]=temp1[index][2]-time_quantum
        # popped=ready_queue.pop(0)
    temp=[]
    if(ready_queue!=[]):
        print("hello2")
        for i in range(len(temp1)):
            if(time>=a_t[i] and b_t[i]!=0):
                temp.append(temp1[i])
        if(temp!=[]):
            for item in temp:
                if(item not in ready_queue):
                    ready_queue.append(item)
            ready_queue.append(ready_queue.pop(0))

    while(ready_queue==[]):
        print("hello3")
        print(len(temp1))
        print("hello3 time = {}".format(time))
        for i in range(len(temp1)):
            if(time>=a_t[i] and b_t[i]!=0):
                temp.append(temp3[i])
        if(temp==[]):
            time=time+1
        else:
            for item in temp:
                ready_queue.append(item)
        print("ready_queue = {}".format(ready_queue))
      