#Mary Kohl
#Lab5
#6 April 2019

import numpy as np
import math
import timeit

def Augment(A, b):
    """Augments martix so that every row has an 'output value' of b, returns augmented matrix"""
    Ab = np.hstack([A.reshape(b.size, A.size/b.size), b.reshape(-1,1)])
    return (Ab)

def BackSub(U, b):
    """Solve equation Ax=b for an upper triangular matrix A and returns solution matrix"""
    x = [0 for i in range(len(b))] #initalize x before adding values
    n = len(b)

    x[n-1] = b[n-1]/U[n-1][n-1] #find Xn-1 value to subsitute

    for i in range(n-2, -1, -1): #n-2 since Xn-1 was already solved
        num = b[i]
        for j in range (i-1, n):
            num -= U[i][j] * x[j] 
        x[i] = num / U[i][i]
    
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
    """Gaussian Elimination function that forms an upper triangular matrix"""
    # Augment Matrix
    Ab = Augment(A, b)
    n = len(Ab)
    
    for i in range(0, n):
        maxLE = abs(Ab[i][i]) #max Leading Entry
        maxRow = i #the location in which the max LE is found
        
        #find the max value
        for j in range(i+1, n):
            if abs(Ab[j][i]) > maxLE: #absolute value incase of negative numbers
                maxLE = abs(Ab[j][i])
                maxRow = j
        
        #swap max value
        for j in range(i, n+1):
            temp = Ab[maxRow][j]
            Ab[maxRow][j] = Ab[i][j]
            Ab[i][j] = temp
        
        #checked: Ab correct after swap

        #row reduce
        for j in range(i+1, n):
            c = -Ab[j][i]/Ab[i][i]
            for k in range(i, n+1):
                if i == j:
                    Ab[j][k] = 0
                else:
                    Ab[j][k] += c * Ab[i][k]

            #make leading entries == 1, results in error if anyplace else in loops
                if Ab[i][i] != 0: 
                    Ab[i] = Ab[i]/Ab[i][i]  
    
    #split Ab into an uppertrianglar matrix and b
    A = Ab[:, :-1]
    b = Ab[:, -1]
    return (A,b) # function checked: yes

def Absolute(A, b, x): 
    """Absolute matrix to calculate |b-Ax|"""
    absolute = [0 for i in range(len(A))]
    for i in range(0, len(A)):
        for j in range(0, len(A)):
            absolute[i] += A[i][j] * x[j]
        #took floor value so 0.0000x16 values would be negligable 
        absolute[i] = math.floor(abs(b[i] - absolute[i]))
    return absolute

def Relative(r, b):
    """Uses Check to see error value"""

    error = [0 for i in range(len(b))]
    for i in range(0, len(b)):
        if b[i] != 0:
            error[i] = abs(r[i]/b[i])
        else:
            error[i] = abs(r[i])
    return error
        

def Solve(A, b, options):
    """Main solve function"""
    U = [0 for i in range(len(A))]

    if options == 'absolute':
        (U, b) = RowReduce(A, b)
        if Rank(A, b) != True:
            print "Impossible Solution"
            exit()
        solution = BackSub(U, b)
        print Absolute(U, b, solution)
    
    if options == 'relative':
        (U, b) = RowReduce(A, b)
        if Rank(A, b) != True:
            print "Impossible Solution"
            exit()
        solution = BackSub(U, b)
        print Relative(Absolute(U, b, solution), b)

    if options == 'timing':
        t0 = timeit.default_timer()
        (U, b) = RowReduce(A, b)
        if Rank(A, b) != True:
            print "Impossible Solution"
            exit()
        t1 = timeit.default_timer() - t0
        solution = BackSub(U, b)
        t2 = timeit.default_timer() - t1
        print "Gaussian Elimiation:"
        print t1
        print "BackSub:"
        print t2
    
    if options == 'files':
        A = np.loadtxt('A.txt')
        b = np.loadtxt('b.txt')
        A = A.reshape(b.size, A.size/b.size)
        (U, b) = RowReduce(A, b)
        if Rank(U, b) != True:
            print "Impossible Solution"
            exit()
        solution = BackSub(U, b)

        with open('output.txt', 'w') as f:  #adapted from: https://stackoverflow.com/questions/899103/writing-a-list-to-a-file-with-python
            for i in range(0, len(solution)):
                f.write("%s\n" % solution[i])
    
    if options == 'FilesAndTime':
        A = np.loadtxt('A.txt')
        b = np.loadtxt('b.txt')
        A = A.reshape(b.size, A.size/b.size)
        t0 = timeit.default_timer()
        (U, b) = RowReduce(A, b)
        t1 = timeit.default_timer() - t0
        if Rank(U, b) != True:
            print "Impossible Solution"
            exit()
        solution = BackSub(U, b)
        t2 = timeit.default_timer() - t1

        with open('output.txt', 'w') as f:  #adapted from: https://stackoverflow.com/questions/899103/writing-a-list-to-a-file-with-python
            for i in range(0, len(solution)):
                f.write("%s\n" % solution[i])
        t3 = timeit.default_timer() - t2
        print "Gaussian Elimiation:"
        print t1
        print "BackSub:"
        print t2
        print "Write file:"
        print t3
    
    else:
        (U, b) = RowReduce(A, b)
        if Rank(U, b) != True:
            print "Impossible Solution"
            exit()
        solution = BackSub(U, b)


A = np.array([[-6, 3, -15], [2, -8, -8], [1, -3, 1]], dtype='float')
b = np.array([9, -2, 4], dtype='float')

print "Solve Afile, solution stored in output.txt"
Solve(A, b, 'files')

A = np.array([[-6, 3, -15], [2, -8, -8], [1, -3, 1]], dtype='float')
b = np.array([9, -2, 4], dtype='float')
print "Option: 'relative'"
Solve(A, b, 'relative')

print"Option: 'absolute'"
A = np.array([[-6, 3, -15], [2, -8, -8], [1, -3, 1]], dtype='float')
b = np.array([9, -2, 4], dtype='float')
Solve(A, b, 'absolute')

print"Option: 'timing'"
print"Time for 3x4 "
A = np.array([[-6, 3, -15], [2, -8, -8], [1, -3, 1]], dtype='float')
b = np.array([9, -2, 4], dtype='float')
Solve(A, b, 'timing')
print"Timing and A.txt:"
Solve(A, b, 'FilesAndTime')
print"Gaussian Elimination grows exponentally when n increased for an nxn matrix O(n^2). BackSub is almost constant O(1)"


A = np.array([[3, -6, -1, 1], [-1, 2, 2, 3], [3, -6, -1, 1]], dtype='float')
b = np.array([6, 3, 3], dtype='float')

print "Check for Row of Zeros with:"
print A 
print b
Solve(A, b, 1)