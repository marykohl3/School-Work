#Mary Kohl
#CISC/MATH 2011
#Lab 3 - 24 Feb 2019

import math

    
def sum (x, y): return [elemX+elemY for elemX, elemY in zip(x,y)]
"""Returns the sum of two vectors x and y are lists of floats representing vectos of the same length"""


def diff(x, y): return [elemX-elemY for elemX, elemY in zip(x,y)]
"""Returns the difference of two vectors x and y that are lists of floats representing vectors of the same length"""

def scale(c, x): return [c*elemX for elemX in x]
"""Returns a vector x that has been scaled by a constant c"""

def dot(x, y):
    """returns the dot product, z, from two vectors x and y"""
    z = 0
    for i in range(len(x)):
        z += (x[i].real * y[i].real) + (x[i].imag * y[i].imag)
    return z

def proj(x, y):
    """returns a projection vector, z: the projection of x on y"""
    z = dot(x,y)
    y_length = 0.0
    for elemY in y:
        y_length += elemY**2
    return scale((z/y_length), y)

def perp(x, y):
    """returns the perpendicular part of x to y"""
    z = []
    z = proj(y, x)
    return diff(x, z)

def refl(x,y):
    """returns the reflection,z, of x across the line or plane perpendicular to y"""
    z = []
    z = proj(x, y)
    u = []
    for elemX in x:
        u.append(2*elemX)
    z = diff(x, z)
    return z

def angle(x, y, s): 
    """returns the angle between the vectors x and y"""
    x_length = math.sqrt(dot(x,x))
    y_length = math.sqrt(dot(y,y))
    if s == 'd':
        return ((math.acos(dot(x,y) / (x_length*y_length))) * (180/3.1415))
    elif s == 'r':
        return (math.acos(dot(x,y) / (x_length*y_length)))
    else:
        return 0

def spPrint(*args):
    """function that takes in an unlimited amount of parameters to be used for lincomb"""
    for x in args: print(x)

def lincomb(*args):
    """the linear combination of the n vectors"""
    z = []
    answer = 0
    vecList = args[:int(len(args)/2)]
    scaleList = args[int(len(args)/2):]
    if (len(vecList) != len(scaleList)):
        print('Uneven amount of parameters')
    else:
        for i in range(len(vecList)):
            for j in range(len(vecList)):
                z.append(vecList[i][j]*scaleList[i])
        for i in range(len(z)):
            answer += z[i]   
        print answer