import math
H1 = [ 0.24, 0.2, 0.16, 0.12, 0.08, 0.04, 0.12, 0.04]
H2 = [0.22, 0.19, 0.16, 0.13, 0.11, 0.08, 0.05, 0.06]

KL_distance = 0
Bhatt_coeff = 0
for i in range(0,len(H1)):
    KL_distance += H1[i]*math.log((H1[i]/H2[i]))
    Bhatt_coeff += (H1[i]*H2[i])**(1/2) 
print(f"KL distance is {KL_distance}")
Bhatt_dist = -math.log(Bhatt_coeff)
print(f"Bhattacharya distance is {Bhatt_dist}")