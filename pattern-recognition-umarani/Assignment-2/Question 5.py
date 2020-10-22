# -*- coding: utf-8 -*-
from sympy import symbols
"""
Created on Sun Mar  1 20:16:55 2020

@author: jason
"""
import numpy as np
from sklearn import datasets
import math
from sympy import plot_implicit as plt_eq
from sympy import lambdify
import matplotlib.pyplot as plt 

#apriori probabilities -
P_setosa = 1/3
P_virginica = 1/3
P_versicolor = 1/3

iris = datasets.load_iris()

X_setosa = iris.data[:50,2:]

X_versicolor = iris.data[50:100,2:]

X_virginica = iris.data[100:150,2:]



#mean calculated
mean_X_setosa = np.mean(X_setosa,axis = 0)
mean_X_versicolor = np.mean(X_versicolor,axis = 0)
mean_X_virginica = np.mean(X_virginica,axis = 0)

#calculate covariance matrices
covariance_X_setosa = np.cov(X_setosa.T)
covariance_X_versicolor = np.cov(X_versicolor.T)
covariance_X_virginica = np.cov(X_virginica.T)

#inverses calcualtion
inv_covariance_X_setosa = np.linalg.inv(covariance_X_setosa)        
inv_covariance_X_versicolor = np.linalg.inv(covariance_X_versicolor)
inv_covariance_X_virginica =np.linalg.inv(covariance_X_virginica)
#determinant calculation
det_covariance_X_setosa = np.linalg.det(covariance_X_setosa)        
det_covariance_X_versicolor = np.linalg.det(covariance_X_versicolor)
det_covariance_X_virginica =np.linalg.det(covariance_X_virginica)

x1,x2 = symbols("x1 x2")

X_new_point = np.array([[x1],[x2]])
A_setosa=-(.5)*inv_covariance_X_setosa
B_setosa=np.matmul(inv_covariance_X_setosa,mean_X_setosa)
C_setosa= math.log(P_setosa) - (.5*math.log(det_covariance_X_setosa))- (.5*(np.matmul(mean_X_setosa.T,np.matmul(inv_covariance_X_setosa,mean_X_setosa))))

A_versicolor=-(.5)*inv_covariance_X_versicolor
B_versicolor=np.matmul(inv_covariance_X_versicolor,mean_X_versicolor)
C_versicolor=math.log(P_versicolor) - (.5*math.log(det_covariance_X_versicolor))- (.5*(np.matmul(mean_X_versicolor.T,np.matmul(inv_covariance_X_versicolor,mean_X_versicolor))))

A_virginica=-(.5)*inv_covariance_X_virginica
B_virginica=np.matmul(inv_covariance_X_virginica,mean_X_virginica)
C_virginica=math.log(P_virginica) - .5*math.log(det_covariance_X_virginica)- .5*(np.matmul(mean_X_virginica.T,np.matmul(inv_covariance_X_virginica,mean_X_virginica)))

#curve g1 g2
#curve g1 g3
#curve g2 g3
#Generating Discriminant Function
G1 = np.matmul(X_new_point.T,np.matmul(A_setosa,X_new_point)) + np.matmul(B_setosa,X_new_point)+C_setosa
G2 = np.matmul(X_new_point.T,np.matmul(A_versicolor,X_new_point)) + np.matmul(B_versicolor,X_new_point)+C_versicolor
G3 = np.matmul(X_new_point.T,np.matmul(A_virginica,X_new_point)) + np.matmul(B_virginica,X_new_point)+C_virginica

G1 = G1[0][0]
G2 = G2[0][0]
G3 = G3[0][0]

#Decision Boundary
Curve_1 = G1-G2
Curve_2 = G1-G3
Curve_3 = G2-G3
h=5.5
#Plotting Decision Boundary
c1_plt =plt_eq(Curve_1, (X_new_point[0][0], -h, h),(X_new_point[1][0], -h, h),show=False,depth=3)
c2_plt =plt_eq(Curve_2, (X_new_point[0][0], -h, h),(X_new_point[1][0], -h, h),show=False,line_color="red",depth=3)
c3_plt =plt_eq(Curve_3, (X_new_point[0][0], -h, h),(X_new_point[1][0], -h, h),show=False,line_color="green",depth=3) 

c1_plt.extend(c2_plt)
c1_plt.extend(c3_plt)
c1_plt.show()
plt.scatter(iris.data[:50,2:3],iris.data[:50,3:4],c="blue",s=10,label="Class W1")
plt.scatter(iris.data[50:100,2:3],iris.data[50:100,3:4],c="purple",s=10,label="Class W2")  
plt.scatter(iris.data[100:150,2:3],iris.data[100:150,3:4],c="black",s=10,label="Class W3")
plt.legend()      
