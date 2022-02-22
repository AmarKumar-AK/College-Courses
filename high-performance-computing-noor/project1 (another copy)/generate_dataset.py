import random

width =1200
height = 600
offset = 10
for i in range(100):
    x = random.randint(1+offset,width/3-offset)
    y = random.randint(1+offset,height/3-offset)
    print(f"{x} {y}")

for i in range(100):
    x = random.randint(width/3+offset,2*width/3-offset)
    y = random.randint(2*height/3+offset,height-offset)
    print(f"{x} {y}")

for i in range(100):
    x = random.randint(2*width/3+offset,width-offset)
    y = random.randint(height/3+offset,2*height/3-offset)
    print(f"{x} {y}")


x1 = random.randint(1+offset,width/3-offset)
y1 = random.randint(1+offset,height/3-offset)
x2 = random.randint(width/3+offset,2*width/3-offset)
y2 = random.randint(2*height/3+offset,height-offset)
x3 = random.randint(2*width/3+offset,width-offset)
y3 = random.randint(height/3+offset,2*height/3-offset)
print(f"{x1} {y1}")
print(f"{x2} {y2}")
print(f"{x3} {y3}")