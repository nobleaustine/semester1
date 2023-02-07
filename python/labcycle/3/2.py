
# 2.Implement Principle Component Analysis(PCA) of a matrix.

import numpy as np
import numpy.linalg as nl

# function to input a matrix
def input_matrix():

  matrix = []
  row = int(input("Enter the number of rows    : "))   # taking number of rows
  col = int(input("Enter the number of columns : "))   # taking number of columns
  print(" ")
  
  print("Enter the elements of the matrix : ")
  print(" ")
  
  for i in range(row):                     # nested loop to input a matrix
    m = []
    for j in range(col):
      print("Enter m[",i+1,j+1,"] ")
      m.append(float(input()))  
      print(" ")                          
    matrix.append(m)                       # returning the matrix, number of             
  return(matrix,row,col)                   # rows and columns               

# function to display the matrix
def output_matrix(matrix,row,col):
  print(" ")
  print("MATRIX : ")
  for i in range(row):
    for j in range(col):
      print(matrix[i][j],end="  ")
    print(" ")
  print(" ")

# function to calculate PCA
def calculate_PCA(matrix):
  Array = np.array(matrix)
  A = np.array([[1, 2], [3, 4], [5, 6]])
  print(A)
  M2 = np.mean(A, axis=0)
  print(M2)
  Mean = np.mean(Array.T, axis=1)
  print("Mean of each column : ")
  print(Mean)
  print(" ")
  
  Center = Array - Mean                    # centering columns by subtracting column means
  print("Centered matrix : ")
  print(Center)
  print(" ")

  Varience = np.cov(Center.T)               # calculate covariance matrix of centered matrix
  print("Covariance Matrix : ")
  print(Varience)
  print(" ")

  e_values, e_vectors = nl.eig(Varience)    # generating Eigen vectors
  print("Eigen vectors : ")
  print(e_vectors)
  print(" ")

  print("Eigen values  : ",e_values)        # generating Eigen values
  Proj = e_vectors.T.dot(Center.T)
  print(" ")

  print("Projection of original matrix : ") # printing projection of matrix
  print(Proj.T)
  print(" ")

# calling functions to perform PCA
print("Program to perform implement principle component analysis ")
print(" ")
matrix,row,col=input_matrix()
output_matrix(matrix,row,col)
calculate_PCA(matrix)