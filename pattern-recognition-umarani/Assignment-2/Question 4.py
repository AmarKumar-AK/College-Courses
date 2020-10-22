from sympy import symbols
import numpy as np
from sklearn import datasets
import math
from sympy import plot_implicit as plt_eq
from sympy import lambdify
import matplotlib.pyplot as plt

#Reading Datasets
iris = datasets.load_iris()

#apriori probabilities
P_setosa = 1/3
P_virginica = 1/3
P_versicolor = 1/3

X_setosa_temp = iris.data[:50,:]
X_versicolor_temp = iris.data[50:100,:]
X_virginica_temp = iris.data[100:150,:]

np.random.shuffle(X_setosa_temp)
np.random.shuffle(X_versicolor_temp)
np.random.shuffle(X_virginica_temp)

X_setosa = X_setosa_temp[:40,:]
X_versicolor = X_versicolor_temp[:40,:]
X_virginica = X_virginica_temp[:40,:]


X_setosa_test = X_setosa_temp[40:,:]
X_versicolor_test = X_versicolor_temp[40:,:]
X_virginica_test = X_virginica_temp[40:,:]

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

x1,x2,x3,x4 = symbols("x1 x2 x3 x4")

X_new_point = np.array([[x1],[x2],[x3],[x4]])

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

#Generating Discriminant Functions
G1 = np.matmul(X_new_point.T,np.matmul(A_setosa,X_new_point)) + np.matmul(B_setosa,X_new_point)+C_setosa
G2 = np.matmul(X_new_point.T,np.matmul(A_versicolor,X_new_point)) + np.matmul(B_versicolor,X_new_point)+C_versicolor
G3 = np.matmul(X_new_point.T,np.matmul(A_virginica,X_new_point)) + np.matmul(B_virginica,X_new_point)+C_virginica

G1 = G1[0][0]
G2 = G2[0][0]
G3 = G3[0][0]


error_count = 0

print("\nGiving 10 Setosa inputs - \n")
for i,each in enumerate(X_setosa_test):
    r1,r2,r3,r4 = each
    g1_val=G1.subs([(x1, r1), (x2, r2), (x3, r3),(x4,r4)])
    g2_val=G2.subs([(x1, r1), (x2, r2), (x3, r3),(x4,r4)]) 
    g3_val=G3.subs([(x1, r1), (x2, r2), (x3, r3),(x4,r4)])
    if(g1_val>g2_val and g1_val>g3_val):
        print(i,"Setosa")
    if(g2_val>g1_val and g2_val>g3_val):
        print(i,"Versicolor")
        error_count+=1
    if(g3_val>g2_val and g3_val>g1_val):
        error_count+=1
        print(i,"Virginica")
        
print("\nGiving 10 Versicolor inputs - \n")
for i,each in enumerate(X_versicolor_test):
    r1,r2,r3,r4 = each
    g1_val=G1.subs([(x1, r1), (x2, r2), (x3, r3),(x4,r4)])
    g2_val=G2.subs([(x1, r1), (x2, r2), (x3, r3),(x4,r4)]) 
    g3_val=G3.subs([(x1, r1), (x2, r2), (x3, r3),(x4,r4)])
    if(g2_val>g1_val and g2_val>g3_val):
        print(i,"Versicolor")
    if(g1_val>g2_val and g1_val>g3_val):
        error_count+=1
        print(i,"Setosa")
    if(g3_val>g2_val and g3_val>g1_val):
        error_count+=1
        print(i,"Virginica")
        
print("\nGiving 10 Virginica inputs - \n")
for i,each in enumerate(X_virginica_test):
    r1,r2,r3,r4 = each
    g1_val=G1.subs([(x1, r1), (x2, r2), (x3, r3),(x4,r4)])
    g2_val=G2.subs([(x1, r1), (x2, r2), (x3, r3),(x4,r4)]) 
    g3_val=G3.subs([(x1, r1), (x2, r2), (x3, r3),(x4,r4)])
    if(g1_val>g2_val and g1_val>g3_val):
        error_count+=1
        print(i,"Setosa")
    if(g2_val>g1_val and g2_val>g3_val):
        error_count+=1
        print(i,"Versicolor")
    if(g3_val>g2_val and g3_val>g1_val):
        print(i,"Virginica")
        
#Accuracy Calculation
print("accuracy = "+str(1-(error_count/150)))
    