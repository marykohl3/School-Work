#Mary Kohl
#Final 2
#13 May 2019
#CISC 2011

import numpy as np
import math

def Augment(A, b):
    """Augments martix so that every row has an 'output value' of b, returns augmented matrix"""
    Ab = np.hstack([A.reshape(b.size, A.size//b.size), b.reshape(-1,1)])
    return (Ab)

def BackSub(U, b):
    """FROM https://storm.cis.fordham.edu/~ryham/CISCMATH2011Web/Lab5_Solutions_Basic.py
    My BackSub was incorrect for the lab submission so I altered it from the online solution 
    
    Solve equation Ax=b for an upper triangular matrix A and returns solution matrix"""
    
    n = len(b)
    x = np.zeros((n,1))

    for i in range(n-1, -1, -1): #n-2 since Xn-1 was already solved
        x[i] = (b[i] - U[i,i+1:n].dot(x[i+1:n]))/U[i,i]
    return x

def Rank(A, b):
    """determines if there is a row of zeros and returns boolean value"""
    rank = True

    for i in range(0, len(A)):
        check_row = 0
        for j in range(0, len(A)):
            if A[i][j] == 0:
                check_row += 1
        if check_row == len(A):
            rank = False
            break
    return rank #note: checked function


def RowReduce(A, b):
    """ADAPTED FROM https://storm.cis.fordham.edu/~ryham/CISCMATH2011Web/Lab5_Solutions_Basic.py
    
    My original Row Reduce Function ran slower than this one 
    using this version of RowReduce made my program run faster

    Performs Gaussian elimination with pivoting.
    Exception raised if all potential pivots are zero (rank(A) < n)
    
    Returns (U, c), the augmented matrix pair after row reductions
    and row swaps are performed on (A, b)"""

    n = len(b)

    for i in range(n):
        #find the row with the largest leading entry
        k = i
        M = abs(A[i,i])

        for j in range(i,n): #iterating over rows 
            m = abs(A[j,i]) #redefine m and k
            k = j*(m > M) + k*(m <= M)
            M = m*(m > M) + M*(m <= M)                        

        #k is the row with largest leading entry          
        b[[i,k]] = b[[k,i]] #for some strange reason, c[i], c[k] = c[k], c[i] does not work; but it does below
        for j in range(i,n): 
            A[i,j], A[k,j] = A[k,j], A[i,j]

        #elimination step 
        for j in range(i+1,n): 
            W = A[j,i]/A[i,i]  
            A[j,:] -= W*A[i,:] 
            b[j]   -= W*b[i]  
                             
    return (A,b) #returns A,b as U,b 

def Solve(A, b):
    """From main solve function of Lab 5 without options"""
    U = [0 for i in range(len(A))]
    (U, b) = RowReduce(A, b)
    if Rank(U, b) != True:
        print ("Impossible Solution")
        exit()
    return BackSub(U, b)

def ErrorReport(A, b, x):
    """Solves for the residual error"""
    error = {}
    error = abs(b - (A@x))
    return error
