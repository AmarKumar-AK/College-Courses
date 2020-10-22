from sympy import symbols
import numpy as np
from sklearn import datasets
import math
from sympy import plot_implicit as plt_eq
from sympy import lambdify
import matplotlib.pyplot as plt

iris = datasets.load_iris()

P_setosa = 0.5
P_versicolor = 0.5


X_setosa = np.array([[2,6],[3,4],[3,8],[4,6]])
X_versicolor = np.array([[3,0],[1,-2],[3,-4],[5,-2]])


# 2 dims 3

#mean calculated
mean_X_setosa = np.mean(X_setosa,axis = 0)
mean_X_versicolor = np.mean(X_versicolor,axis = 0)

#calculate covariance matrices
covariance_X_setosa = np.cov(X_setosa.T)
covariance_X_versicolor = np.cov(X_versicolor.T)

#inverses calcualtion
inv_covariance_X_setosa = np.linalg.inv(covariance_X_setosa)        
inv_covariance_X_versicolor = np.linalg.inv(covariance_X_versicolor)

#dets calculation
det_covariance_X_setosa = np.linalg.det(covariance_X_setosa)        
det_covariance_X_versicolor = np.linalg.det(covariance_X_versicolor)

x1,x2 = symbols("x1 x2")

X_new_point = np.array([[x1],[x2]])

A_setosa=-(.5)*inv_covariance_X_setosa
B_setosa=np.matmul(inv_covariance_X_setosa,mean_X_setosa)
C_setosa= math.log(P_setosa) - (.5*math.log(det_covariance_X_setosa))- (.5*(np.matmul(mean_X_setosa.T,np.matmul(inv_covariance_X_setosa,mean_X_setosa))))

A_versicolor=-(.5)*inv_covariance_X_versicolor
B_versicolor=np.matmul(inv_covariance_X_versicolor,mean_X_versicolor)
C_versicolor=math.log(P_versicolor) - (.5*math.log(det_covariance_X_versicolor))- (.5*(np.matmul(mean_X_versicolor.T,np.matmul(inv_covariance_X_versicolor,mean_X_versicolor))))

#curve g1 g2
#curve g1 g3
#curve g2 g3
G1 = np.matmul(X_new_point.T,np.matmul(A_setosa,X_new_point)) + np.matmul(B_setosa,X_new_point)+C_setosa
G2 = np.matmul(X_new_point.T,np.matmul(A_versicolor,X_new_point)) + np.matmul(B_versicolor,X_new_point)+C_versicolor

G1 = G1[0][0]
G2 = G2[0][0]

des_bound = G1-G2    

h=7
c1_plt =plt_eq(des_bound, (X_new_point[0][0], -h, h),(X_new_point[1][0], -h, h))
