#Mary Kohl
#Final 4
#13 May 2019
#CISC 2011

import numpy as np
import matplotlib.pyplot as plt

def GramSchmidt(Q):
   """Function from 3d Animation: https://storm.cis.fordham.edu/~ryham/CISCMATH2011Web/3Drotation.py"""
   u = Q[:,0]
   v = Q[:,1]
   w = Q[:,2]

   x = Q[:,3] #4x4 matrix
   
   #Gram–Schmidt process from above function 
   u /= np.linalg.norm(u)

   v -= v.dot(u)*u
   v /= np.linalg.norm(v)

   w -= w.dot(u)*u + w.dot(v)*v
   w /= np.linalg.norm(w)

   #4x4
   x -= x.dot(u)*u + x.dot(v)*v + x.dot(w)*w
   x /= np.linalg.norm(x) 

   return (np.array([u, v, w, x]))

#Use Numpy to generate a random, 4 by 4, orthogonal matrix Q. Verify that the
# orthogonality property holds by exhibiting QT Q
Q = np.random.random((4,4))
print("Random Vector Q: ", end = ' ')
print (Q)

Q = GramSchmidt(Q)
print("GramSchmidt Q: ", end = ' ')
print (Q)

print("Verify Q.T@Q: ", end = ' ')
print (Q.T@Q)

#Form a 100 by 100 matrix A consisting of 2’s on the diagonal and -1’s on the off-diagonals:
n = 100
A = np.zeros((n, n))
b = np.ones(n-1)

np.fill_diagonal(A, 2) #fill diagonal with 2s 

np.fill_diagonal(A[1:], -b) #fill -1 with off diagonals
np.fill_diagonal(A[:,1:], -b)

print("Form a 100 by 100 matrix A consisting of 2’s on the diagonal and -1’s on the off-diagonals: ")
print(A)

#Find the smallest eigenvalue λmin of A and plot the corresponding eigenvector xmin.
(eigenVal, eigenVec) = np.linalg.eig(A)

X = np.argsort(eigenVal) #sorts increasing matrix 

#split matrix to respective values
eigenVal = eigenVal[X] #store eigenValue
eigenVec = eigenVec[:,X] #store eigenVector

#check np.argsort
#if (min(eigenVal) != eigenVal[0]):
   #print (min(eigenVal))
   #eigenVal[0] = min(eigenVal)

print("smallest eigenvalue λmin of A: " + str(eigenVal[0]))
print("corresponding eigenvector of " + str(eigenVal[0]) + ':\n' + str(eigenVec[0]))
plt.plot(eigenVec[0], 'mo')
plt.show()
