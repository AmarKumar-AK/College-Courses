from sympy import symbols
import numpy as np
from sklearn import datasets
import math
from sympy import plot_implicit as plt_eq
from sympy import lambdify
import matplotlib.pyplot as plt

#apriori probabilities - 
P_w1 = 0.8
P_w2 = 0.2

#Datapoints
X_w1 = np.array([[1,6],[3,4],[3,8],[5,6]])
X_w2 = np.array([[3,0],[1,-2],[3,-4],[5,-2]])

#mean calculated
mean_X_w1 = np.mean(X_w1,axis = 0)
mean_X_w2 = np.mean(X_w2,axis = 0)

#calculate covariance matrices
covariance_X_w1 = np.cov(X_w1.T)
covariance_X_w2 = np.cov(X_w2.T)

#inverses calcualtion
inv_covariance_X_w1 = np.linalg.inv(covariance_X_w1)        
inv_covariance_X_w2 = np.linalg.inv(covariance_X_w2)

#determinant calculation
det_covariance_X_w1 = np.linalg.det(covariance_X_w1)        
det_covariance_X_w2 = np.linalg.det(covariance_X_w2)

x1,x2 = symbols("x1 x2")

X_new_point = np.array([[x1],[x2]])


A_w1=-(.5)*inv_covariance_X_w1
B_w1=np.matmul(inv_covariance_X_w1,mean_X_w1)
C_w1= math.log(P_w1) - (.5*math.log(det_covariance_X_w1))- (.5*(np.matmul(mean_X_w1.T,np.matmul(inv_covariance_X_w1,mean_X_w1))))

A_w2=-(.5)*inv_covariance_X_w2
B_w2=np.matmul(inv_covariance_X_w2,mean_X_w2)
C_w2=math.log(P_w2) - (.5*math.log(det_covariance_X_w2))- (.5*(np.matmul(mean_X_w2.T,np.matmul(inv_covariance_X_w2,mean_X_w2))))

#curve g1 g2
#curve g1 g3
#curve g2 g3
#Generating Discriminant Function
G1 = np.matmul(X_new_point.T,np.matmul(A_w1,X_new_point)) + np.matmul(B_w1,X_new_point)+C_w1
G2 = np.matmul(X_new_point.T,np.matmul(A_w2,X_new_point)) + np.matmul(B_w2,X_new_point)+C_w2

G1 = G1[0][0]
G2 = G2[0][0]

#Decision Boundary
des_bound = G1-G2    

h=20

#Plotting Decision Boundary
c1_plt =plt_eq(des_bound, (X_new_point[0][0], -h, h),(X_new_point[1][0], -h, h))
  
#Plotting Datapoints
plt.scatter([a for a,b in X_w1],[b for a,b in X_w1],c="red",label="Class W1")
plt.scatter([a for a,b in X_w2],[b for a,b in X_w2],c="green",label="Class W2")
plt.legend()
