import numpy as np
xt = np.array([[0.5, 0.5, -0.5, -0.25, -0.25]])

# taking transpose
x = xt.T
A = np.array([[1, 0.135, 0.195, 0.137, 0.157],
    [0.135, 1, 0.2, 0.309, 0.143],
    [0.195, 0.2, 1, 0.157, 0.122],
    [0.137, 0.309, 0.157, 1, 0.195],
    [0.157, 0.143, 0.122, 0.195, 1]])

temp1 = np.matmul(A,x)
res = np.matmul(xt,temp1)
print(f"quadratic distance is {res}")
