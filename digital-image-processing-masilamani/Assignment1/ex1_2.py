import math
import random
# variables
# matrrix - contains whole matrix
# m - contains number of rows in matrix
# n - contains number of column in matrix
# sum - contains sum of all elements in matrix
# max - contains maximum elements in matrix
# array_of_matrix - contains all elements of matrix in sorted order
# list1 - contains only unique elements from matrix
# frequency_of_elements - contains frequency of all elements in the matrix
# sorted_by_frequency - frequency of elements of matrix in descending order
# sd - contains (x-u)^2 value where x is elements of matrix and u is the mean of all elements in the matrix
# average - contains average of all elements in the matrix

matrix = []
m,n = map(int,input("enter number of rows and column : ").split())
# print(m,n)
data = []
# ############### reading matrix
print(f"enter {m} X {n} matrix")
for i in range(m):
    for j in range(n):
        data.append(random.randint(0,10))
    matrix.append(data)
# ################# sum
for i in range(m):
    for j in range(n):
        print(matrix[i][j])
sum = 0
for i in range(m):
    for j in range(n):
        sum += matrix[i][j]
        
print(f"\nsum is {sum}")

# ################ finding maximum element
max = matrix[0][0]
for i in range(m):
    for j in range(n):
        if(max < matrix[i][j]):
            max = matrix[i][j]
print(f"max is {max}")

# ############## finding mean
total_number_of_elements = m*n
print(f"mean is {sum/total_number_of_elements}")

# ############ finding median
array_of_matrix = []
for i in range(m):
    for j in range(n):
        array_of_matrix.append(matrix[i][j])
array_of_matrix.sort()
print(f"median is {array_of_matrix[int(total_number_of_elements/2)]}")

# ################# finding mode
list1 = []  #list1 contains unique numbers in it
for data in array_of_matrix:
    if data not in list1:
        list1.append(data)
# finding frequency of elements
frequency_of_elements = {}
for data in array_of_matrix:
    if data in frequency_of_elements:
        frequency_of_elements[data] += 1
    else:
        frequency_of_elements[data] = 1
# sorting frequency dictionary by value in descending order
sorted_by_frequency = dict(sorted(frequency_of_elements.items(), key = lambda x : x[1], reverse = True))
print(f"mode is {list(sorted_by_frequency.keys())[0]}")

# ################## finding standard deviation
sd = []
average = sum/total_number_of_elements
# (x-u)^2
for data in array_of_matrix:
    sd.append((data - average)**2)

sum = 0
# finding mean of (x-u)^2
for data in sd:
    sum += data
sum = sum/total_number_of_elements
print(f"standard deviation is {sum**(1/2)}")

# ##################### frequency distribution
print(f"frequency distribution :\n{frequency_of_elements}")