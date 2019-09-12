#Mary Kohl
#Lab 4 
#31-March-2019
#Programming for Math and Science 

from __future__ import division
import math 


class Vector:
    def __init__(self, dim, f):
        self.n = dim #dimensions of vector; R^n
        self.f = f #values in vector 
        self.f = {x:y for x,y in f.items() if y!=0}
    def __add__(self, other): #adapted from Midterm Solutions
        try:
            sumf = {}
            #initialize keys for the dictionary of the sum so that += does not access an unassigned key
            for i in self.f: 
                sumf[i] = 0.0
            for i in other.f: 
                sumf[i] = 0.0
            #find the sum for assigned keys
            for i in self.f:
                sumf[i] += self.f[i]
            for i in other.f:
                sumf[i] += other.f[i]
        except AttributeError:
            print 'Cannot add two different types'         
        return Vector(self.n, sumf)

    def __sub__(self, other):
        try:
            subf = {}
            #initialize keys for the dictionary of the difference so that it does not access an unassigned key
            for i in self.f: 
                subf[i] = 0.0
            for i in other.f: 
                subf[i] = 0.0
            #find the difference for assigned keys
            for i in self.f:
                subf[i] = self.f[i] - subf[i]
            for i in other.f:
                subf[i] = other.f[i] - subf[i]
        except AttributeError:
            print 'Cannot subtract two different types'  
        return Vector(self.n, subf)

    def __neg__(self):
        negation = {}
        #negate the values in self.f
        for i in self.f:
            negation[i] = (-1) * self.f[i]
        return Vector(self.n, negation) 

    def __mul__(self, other):
        try:    #see if both objects are vectors
            dot = 0
            for i in self.f:
                if i in other.f:
                    dot += self.f[i]*other.f[i]
            return (dot)

        except AttributeError: #if different types, multiply
            mult = {}
            for i in self.f:
                mult[i] = other * self.f[i]
            return (mult)

    def __rmul__(self, other): #reverse mulitplication so that c * vector is true
        rmult = {}
        for i in self.f:
            rmult[i] = other * self.f[i]
        return (rmult)
    
    def __truediv__(self, other): #solves for x/c
        try:
            div = {}
            for i in self.f:
                div[i] = 0.0
                div[i] = self.f[i]/other
        except ZeroDivisionError:
            print 'Zero Division Error'
        return Vector(self.n, div)
    
    def proj(self, other): #projection of x onto y
        projection = {}
        projection = ((self * other) / (other.norm()**2)) * other
        return Vector(self.n, projection)

    def norm (self): #returns the length of vector
        self.norm = 0.0
        for i in self.f:
            self.norm += self.f[i]**2
        self.norm = math.sqrt(self.norm)
        return (self.norm)   
    
    def __str__ (self): #prints vector
        dimenString = ' '
        valString = ''
        for key,val in sorted(self.f.items()):
            tempDimen = ' ' + str(key)
            tempVal = ' ' + str('{:>-0.5g}'.format(val))
            tempDimen = (len(tempVal) - len(tempDimen)) * ' ' + tempDimen
            dimenString += tempDimen
            valString += tempVal
        bar = len(dimenString)*'-'
        return dimenString + '\n' + bar + '\n' + valString  

            


f = {0:1.0, 1:0.0, 2:0.0, 3:-1.0, 4: 5.0}
d = {0:2.0, 1:1.0, 2:2.0, 3:2.0, 4: 3.0}
TestVec = Vector(5, {})
x = Vector(5, f)
y = Vector(5, d)

print 'Add: x + y'
TestVec = x + y
print TestVec


print 'Subtract: x - y'
TestVec = x - y
print TestVec

print 'Exception class: adding and subtracting strings and x'
x + 'hello'
x - 'hello '

print 'Negation of y'
print -y

print 'Multiply: x*y'
TestVec = x*y
print TestVec

print 'Multiply: x*4'
TestVec = x*4
print TestVec

print 'RMul: 3*x'
TestVec = 3*x
print TestVec

print 'TrueDiv: x/3'
TestVec = x/3
print TestVec

print 'Exception Class: x/0'
x/0

print 'Projection of x onto y'
TestVec = x.proj(y)
print TestVec

print 'Length of vector x:'
print x.norm()
