# variables
# matrrix - contains whole matrix
# sum - contains sum of all elements in matrix
# max - contains maximum elements in matrix
# array_of_matrix - contains all elements of matrix in sorted order
# list1 - contains only unique elements from matrix
# frequency_of_elements - contains frequency of all elements in the matrix
# sorted_by_frequency - frequency of elements of matrix in descending order
# sd - contains (x-u)^2 value where x is elements of matrix and u is the mean of all elements in the matrix
# average - contains average of all elements in the matrix
matrix = []
############### reading matrix
print("enter 5X5 matrix")
for i in range(0,5):
    data = list(map(int,input().split()))
    matrix.append(data)

################# sum
sum = 0
for i in range(5):
    for j in range(5):
        sum += matrix[i][j]
        
print(f"\nsum is {sum}")

################ finding maximum element
max = matrix[0][0]
for i in range(5):
    for j in range(5):
        if(max < matrix[i][j]):
            max = matrix[i][j]
print(f"max is {max}")

############## finding mean
print(f"mean is {sum/25}")

############ finding median
array_of_matrix = []
for i in range(5):
    for j in range(5):
        array_of_matrix.append(matrix[i][j])
array_of_matrix.sort()
print(f"median is {array_of_matrix[12]}")

################# finding mode
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

################## finding standard deviation
sd = []
average = sum/25
# (x-u)^2
for data in array_of_matrix:
    sd.append((data - average)**2)

sum = 0
# finding mean of (x-u)^2
for data in sd:
    sum += data
sum = sum/25
print(f"standard deviation is {sum**(1/2)}")

##################### frequency distribution
print(f"frequency distribution :\n{frequency_of_elements}")