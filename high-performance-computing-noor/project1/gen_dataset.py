import random

width =1200
height = 600
k = 10
for i in range(1000+k):
    x = random.randint(1,width)
    y = random.randint(1,height)
    print(f"{x} {y}")