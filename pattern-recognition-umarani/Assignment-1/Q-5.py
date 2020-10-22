import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from statistics import mean

#Reading the dataset
data=pd.read_csv("iris.csv")

#Function for calculating mahalanobis distance.
def mahalanobis(a,b):
    a = a-[np.mean(b.T[0]),np.mean(b.T[1])]
    b = np.linalg.inv(np.cov(b.T))
    return np.dot(np.dot(a,b),a.T)

#Function to decide color according to the class, test cases belong
def col(x):
    if x=="Setosa":
        return "red"
    elif x=="Versicolor":
        return "blue"
    else:
        return "green"

#Separating dataset into three lists.
setosa_list = data[["petal.length","petal.width"]][1:50]
versicolor_list = data[["petal.length","petal.width"]][51:100]
virginica_list = data[["petal.length","petal.width"]][101:150]

#plotting the data-set
plt.scatter(setosa_list["petal.length"],setosa_list["petal.width"],color='red')
plt.scatter(versicolor_list["petal.length"],versicolor_list["petal.width"],color='blue')
plt.scatter(virginica_list["petal.length"],virginica_list["petal.width"],color='green')
plt.xlabel("Petal Length")
plt.ylabel("Petal Width")

#Test cases
test0 = data[["petal.length","petal.width"]].values[0]
test50 = data[["petal.length","petal.width"]].values[50]
test100 = data[["petal.length","petal.width"]].values[100]

#Creating Matrices of three classes [50 x 2] dimension.
setosa_matrix = np.array(setosa_list.values)
versicolor_matrix = np.array(versicolor_list.values)
virginica_matrix = np.array(virginica_list.values)

#Calculating mahalanobis distance for each testcase with every classes.
mahalanobis_test0 = {"Setosa":mahalanobis(test0,setosa_matrix),"Versicolor":mahalanobis(test0,versicolor_matrix),"Virginica":mahalanobis(test0,virginica_matrix)}
mahalanobis_test50 = {"Setosa":mahalanobis(test50,setosa_matrix),"Versicolor":mahalanobis(test50,versicolor_matrix),"Virginica":mahalanobis(test50,virginica_matrix)}
mahalanobis_test100 = {"Setosa":mahalanobis(test100,setosa_matrix),"Versicolor":mahalanobis(test100,versicolor_matrix),"Virginica":mahalanobis(test100,virginica_matrix)}

#Classifying the minimum distance for each testcase.
label_test0 = min(mahalanobis_test0,key=(lambda k:mahalanobis_test0[k]))
label_test50 = min(mahalanobis_test50,key=(lambda k:mahalanobis_test50[k]))
label_test100 = min(mahalanobis_test100,key=(lambda k:mahalanobis_test100[k]))

#plotting those testcases.
plt.scatter(test0.T[0],test0.T[1],s=200,marker="*",label=label_test0,color=col(label_test0))
plt.scatter(test50.T[0],test50.T[1],s=200,marker="*",label=label_test50,color=col(label_test50))
plt.scatter(test100.T[0],test100.T[1],s=200,marker="*",label=label_test100,color=col(label_test100))
plt.title("Classification Of Irisis")
plt.legend(loc="upper left")
plt.show()
