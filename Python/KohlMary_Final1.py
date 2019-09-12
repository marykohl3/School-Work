#Mary Kohl
#Final 1
#13 May 2019
#CISC 2011

import math
import numpy as np
import sys

class Zp:
    """Create a class Zp that represents elements in the field of modular 
    integers Zp ={0,1,...,p−1} for a prime number p 
    all parameters and functions are self explanatory or comments will be provided. 
    Exception case catch if the modulos do not match"""

    def __init__(self, f, dim):
        """ a mod b = c"""
        self.d = dim #b
        self.f = f #a
        self.mod = f%dim #c
    
    def atab(self):
        """Print out addition table for Zp"""
        print('+' , end = '  ')
        for i in range(0, self.d):
            print (str(i), end ='  ')

        for i in range(0, self.d):
            print('\n')
            print (str(i), end = '  ')
            for j in range (0, self.d):
                print((i+j)%self.d, end = '  ')
        print('\n')

    def mtab(self):
        """Print out multiplication table for Zp"""
        print('*' , end = "  ")
        for i in range(0, self.d):
            print (str(i), end ='  ')

        for i in range(0, self.d):
            print('\n')
            print (str(i), end = '  ')
            for j in range (0, self.d):
                print((i*j)%self.d, end = '  ')
        print('\n')
    
    def __add__(self, other):
        if(other.d != self.d):
            raise Exception('Error: Modulos do not match')
            sys.exit()
        else:
            summ = self.f + other.f
            mod = summ%self.d
            return(mod)

    def __sub__(self, other):
        if(other.d != self.d):
            raise Exception('Error: Modulos do not match')
            sys.exit()
        else:
            subtract = self.f - other.f
            mod = subtract%self.d
            return(mod)

    def __mul__(self, other): 
        if(other.d != self.d):
            raise Exception('Error: Modulos do not match')
            sys.exit()
        else:
            mult = self.f * other.f
            mod = mult%self.d
            return(mod)

    def __truediv__(self, other): 
        """uses '//' to solve as an int, whe using '/' it solves as a double"""
        if(other.d != self.d):
            raise Exception('Error: Modulos do not match')
            sys.exit()
        else:
            divide= self.f//other.f
            mod = divide%self.d
            return(mod)

    def __pow__(self, other):
        if(other.d != self.d):
            raise Exception('Error: Modulos do not match')
            sys.exit()
        else:
            power = self.f**other.f
            mod = power%self.d
            return (mod)

    def __str__(self):
        string1 = str(self.f)
        string2 = str(self.d)
        return string1 + ' (mod ' + string2 + ')'

#Print
a = Zp(3,7)
b = Zp(6,5)
print(a,b)

#atab and mtab
print(a)
a.atab()
print('\n')
a.mtab()

#Multiplication
b = Zp(6,7)
print ("Multiplication: a*b:", end = ' ')
print (a, end = ' * ')
print(b, end = ' = ')
print(a*b)

#Addition
print ("Addition: a+b:", end = ' ')
print (a, end = ' + ')
print(b, end = ' = ')
print(a+b)

#Subtraction
print ("Subtraction: a-b:", end = ' ')
print (a, end = ' - ')
print(b, end = ' = ')
print(a-b)

#Power
a = Zp(5,2)
b = Zp(15,2)
print ("Power: a**b:", end = ' ')
print (a, end = ' ** ')
print(b, end = ' = ')
print(a**b)

#Division
a = Zp(9,3)
b = Zp(3,3)
print ("Division: a/b:", end = ' ')
print (a, end = '//')
print(b, end = ' = ')
print(a/b) #call '/' for truediv and use '//' to solve as an int

#Test Exception Case
print("Test Exception Case: ", end = ' ')
a = Zp(4,2)
print (a, end = ' // ')
print(b, end = ' = ')
print(a/b) 