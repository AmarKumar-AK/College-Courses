import cv2
from matplotlib import pyplot as plt
import numpy as np
im = cv2.imread('lena.jpg')
img = cv2.cvtColor(im, cv2.COLOR_BGR2RGB)
plt.imshow(img)