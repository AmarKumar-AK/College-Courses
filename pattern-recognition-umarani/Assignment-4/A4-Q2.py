import numpy as np
#sklearn dataset
np.random.seed(9)
from sklearn import datasets
iris = datasets.load_iris()
X = iris.data[:, :2] 
y = iris.target[:,]


def sigmoid(x):
    return 1/(1+np.exp(-x))

def sigmoid_derivative(x):
    return sigmoid(x)*(1-sigmoid(x))

X_test=iris.data[148:, :2]
b = np.zeros((y.size, y.max()+1))
b[np.arange(y.size),y] = 1
y=b

weights_1 = np.random.randn(2,2)
weights_2 = np.random.randn(2,3)
for i in range(0,800):
    l1_val = np.dot(X,weights_1) 
    act_l1 = sigmoid(l1_val)
    l2_val = np.dot(act_l1,weights_2)
    act_l2= sigmoid(l2_val)
    
    error = y - act_l2
    del_err = error * sigmoid_derivative(act_l2)
    dw_1 = np.dot(act_l1.T,del_err)
    dw_2 = np.dot(X.T,sigmoid_derivative(act_l1)*(np.dot(error*sigmoid_derivative(act_l2),weights_2.T)))
    lr  = 0.1
    weights_2=weights_2+lr*(dw_1)
    weights_1=weights_1+lr*(dw_2)
    
lx_val = np.dot(X[:5,],weights_1)
act_lx = sigmoid(lx_val)
lx2_val = np.dot(act_lx,weights_2)
act_lx2= sigmoid(lx2_val)

print("first 5 samples given to test" )
print("")
print ("predictions\n" + str(act_lx2))
print("")
print ("actual labels\n" + str(y[:5,]))