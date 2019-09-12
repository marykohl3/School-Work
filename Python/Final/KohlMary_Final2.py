#Mary Kohl
#Final 2
#13 May 2019
#CISC 2011

#imports
import numpy as np
import KohlMary_Final2mod as mk

A = np.loadtxt('A.txt') #loads A.txt into the vector A
n = 50 #amount of files

#read files like array 
bList = ['b' + str(i) + '.txt' for i in range(1,n+1)]
xList = ['x' + str(i) + '.txt' for i in range (1,n+1)]
errorReport = ['residual' + str(i) + '.txt' for i in range(1, n+1)]

#A was reshaped originally in the for loop
#to make the code more efficient, it is only reshaped 
# once since each b[i].txt size is the same 
b = np.loadtxt(bList[0])
A = A.reshape(b.size, A.size//b.size)

for i in range (0, n):
    #b = np.loadtxt(bList[i])
    np.savetxt(xList[i], mk.Solve(A,b)) #store solution from Solve into x[i].txt
    print("Solved for b" + str(i+1) + ".txt")
    x = np.loadtxt(xList[i])
    np.savetxt(errorReport[i], mk.ErrorReport(A, b, x)) #store solution from Solve into residual[i].txt
    print("residual" + str(i+1) + ".txt calculated")
print ("Done")
