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
time