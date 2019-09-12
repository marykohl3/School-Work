# Mary Kohl - Lab 2
# CISC / MATH 2011
# 2 - 14 - 19

import matplotlib.pyplot as plt
import math

#Problem 1
x = [ i / 100.0 for i in range (-200, 100)] #some x values between -1 and 1                                                                                                                                                                      
y1 = []

for i in range(len(x)):
    y1.append((x[i]**3)+(x[i]**2)+1) # y = x^3+x^2+1                                                                                                                                                                             

plt.axhline(0.0, color = 'k')                                                                                                                                                                                     
plt.axvline(0.0, color = 'k') #vertical axis   
plt.plot(x, y1, 'k') #a black curve                                                                                                                                                                                                           

    #Quadrilateral                                                                                                                                                                                                       
plt.plot([0,-0.66],[1,1.14], 'b-', linewidth = 2)
plt.plot([-0.66,-1.48],[1.14,0], 'b-', linewidth = 2)
plt.plot([-1.48,0],[0,0], 'b-', linewidth = 2)
plt.plot([0,0], [0,1], 'b', linewidth = 2)  

plt.show()

#Problem 2 
z = [(1+2j), (3+4j)]

def Real(z):
    real_num = []
    for i in range(len(z)):
        real_num.append(z[i].real)
    return real_num

def Imag(z):
    imaginary = [] 
    for i in range(len(z)):
        imaginary.append(z[i].imag)
    return imaginary

print(Real(z))
print(Imag(z))

#Problem 3
def GetBunnyCloudData():
   
   f    = open("bunny_cloud.dat", "r") 
   #assings f as bunny_cloud.dat as a read, 'r' file 
   
   DATA = f.readlines()           
   # list DATA is assinged the data points, each line of text is used as a new object

   N    = len(DATA)  
   #N will be the number of data points in the list DATA
   z = [] 
   #assign z as empty list

   for s in DATA: # for each item in the list DATA
     
      ss = s.split() 
      #splits the string of each line into a list of data members

      a = float(ss[0])
      #a is a floast that is assigned to the first item in the line of text

      b = float(ss[1])
      #b is a float that is assinged to second item in the line of text

      z.append( a + b*1j )
      #adds a complex number a (real) and complex component b (imag) to the end

   return z 
   #returns list z

zb = GetBunnyCloudData()    #points for the bunny
zh = [0+0j, 1+0j, 1+1j, 0.5+1.5j, 0+1j, 0+0j]   #points for the bunny house

plt.plot(Real(zb), Imag(zb), 'yo') # plot bunny with Real and Imag and yellow dots
plt.plot(Real(zh), Imag(zh), 'y-', linewidth = 2) #an attractive house for the bunny

#Problem 4
    #variables used to originally test functions
z0 = 1+2j
a = 3.14159*0.75 # 3pi/4

def Scale(z, c):
    scale = []
    if c.real:
        for i in range(len(z)):
            scale.append(c*z[i])
        return scale
    else:
        print(c, "is not real")

def Conju(z):
    conjugate = []
    for i in range(len(z)):
        conjugate.append(z[i].conjugate())
    return conjugate

def Rotate(z,a):
    rotated = []
    u = (math.cos(a)+(1j)*math.sin(a))
    for i in range(len(z)):
        rotated.append(z[i] * u)
    return rotated

def Trans(z, z0):
    translate = []
    for i in range(len(z)):
        translate.append(z[i] + z0)
    return translate

#Problem 5
plt.axhline(0, color = 'k')
plt.axvline(0, color = 'k')

    #scale c = 3 in red
c = 3
scale_b = Scale(zb, c) 
scale_h = Scale(zh, c)

plt.plot(Real(scale_b), Imag(scale_b), 'ro')
plt.plot(Real(scale_h), Imag(scale_h), 'r-')

    #translate z0 = 1 - 2j
z0 = 1 - 2j
trans_b = Trans(zb, z0)
trans_h = Trans(zh, z0)

plt.plot(Real(trans_b), Imag(trans_b), 'bo')
plt.plot(Real(trans_h), Imag(trans_h), 'b-')

    #conjuation in green
conju_b = Conju(zb)
conju_h = Conju(zh)

plt.plot(Real(conju_b), Imag(conju_b), 'go')
plt.plot(Real(conju_h), Imag(conju_h), 'g-')

    #rotation with a = 3pi/4 in black
rotate_b= Rotate(zb, a)
rotate_h = Rotate(zh, a)

plt.plot(Real(rotate_b), Imag(rotate_b), 'ko')
plt.plot(Real(rotate_h), Imag(rotate_h), 'k-')

plt.show() #show each transformation and original bunny

#Problem 6
rotatetrans = Rotate(Trans(zb ,z0), a)
transrotate = Trans(Rotate(zb, a), z0)

plt.plot(Real(rotatetrans), Imag(rotatetrans), 'bo')
plt.plot(Real(transrotate), Imag(transrotate), 'ko')

plt.show() # not communative transformations

#ExtraCredit - 7
a = 3.14159*0.33 # pi/3
z0 = 4+0j

trans_bunny = Trans(zb, z0)
reflection_bunny = Rotate(Conju(zb), a)

plt.plot(Real(trans_bunny), Imag(trans_bunny), 'yo')
plt.plot(Real(reflection_bunny), Imag(reflection_bunny), 'go')

plt.show()







