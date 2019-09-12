#Mary Kohl 
#CISC/MATH 2011
#Lab 3 - 24 Feb 2019

#imports
import KohlMary_Lab3mod as vec
import matplotlib.pyplot as plt

#graph set up
plt.axhline(0.0, color = 'k')                                                                                                                                                                                     
plt.axvline(0.0, color = 'k') #vertical axis 

#starting vectors 
x = [2+3j, 4+7j, 3+1j]
y = [6+4j, 1+3j, 4+2j]

#sum and diff test
print 'x = ', x
print 'y = ', y
print 'sum x + y = ', vec.sum(x,y)
print 'diff x - y = ', vec.diff(x, y)

#scale test
c = 0.75
print 'scale x by ',c,' = '
print(vec.scale(c,x))

#proj, per, and refl test for 3d complex vectors
print 'proj x and y: ', vec.proj(x, y)
print 'perp x and y: ', vec.perp(x, y)
print 'refl x and y: ', vec.refl(x, y)

#get a third vector from the other vectors and test lincomb
u = []
for i in range(len(x)):
    u.append(x[i].real)
    x[i] = x[i].imag
    y[i] = y[i].imag

print 'linear combination of ', x, y, u,' by (', c, c*2, c*4, ') = ', vec.lincomb(x,y,u, c, (c*2), (c*4))

#angle test in degrees and radians
print 'angle(x,y), in degrees: ', vec.angle(x, y, 'd')
print 'angle(x,y), in radians: ', vec.angle(x,y, 'r')

#testing for a graph - imaginary numbers were discarded and this example is easier to follow 
a = []
b = []

for i in range(len(x)-1):
    a.append(x[i])
    b.append(y[i])

print a, b
plt.plot([0,a[0]], [0, a[1]], 'r', linewidth = 2)
plt.plot([0, b[0]], [0, b[1]], 'blue', linewidth = 2)

proj_g = vec.proj(a, b)
print(proj_g)
plt.plot([0, proj_g[0]], [0, proj_g[1]], 'y', linewidth = 2)

perp_g = vec.perp(a, b)
print(perp_g)
plt.plot([0, perp_g[0]], [0, perp_g[1]], 'k', linewidth = 2)

refl_g = vec.refl(a, b)
print(refl_g)
plt.plot([0, refl_g[0]], [0, refl_g[1]], 'g', linewidth = 2) 

#my scaling for my graph is incorrect yet the functions still work properly
plt.show()
