# Python code to reading an image using OpenCV 
import numpy as np 
import cv2 

img = cv2.imread('lena.png', 0)
l = []
m = []
for i in range(512):
    for j in range(512):
        l.append(img[i][j])
    m.append(l)
print(m)

# will show the image in a window 
# cv2.imshow('image', img) 
# k = cv2.waitKey(0) & 0xFF

# # wait for ESC key to exit 
# if k == 27: 
# 	cv2.destroyAllWindows() 
	
# # wait for 's' key to save and exit 
# elif k == ord('s'): 
# 	cv2.imwrite('messigray.png',img) 
# 	cv2.destroyAllWindows() 
