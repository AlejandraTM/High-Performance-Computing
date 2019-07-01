
#This program plot the Henon Map. First, it makes a plot from a sequence of a initial conditions, and in the seond part, the Henon Map is evaluated over a grid, and make the plot of the resulting grid.


from pylab import *
import numpy as np
import sympy as sy
import matplotlib.pyplot as plt
from memory_profiler import profile


def HenonMap(x,y,a,b,alpha,beta): #Function of the Henon Map
    return a- alpha*x**2+b*y, beta*x
@profile
def main1():#Sequences of initial conditions of the HenonMap
    # Map dependent parameters
    a = 1.4
    b = 0.3
    alpha=1
    beta=1

    iterates = 1000
    # Initial Condition
    xtemp = 0.1
    ytemp = 0.1

    x = [xtemp]
    y = [ytemp]

    for n in range(0,iterates):
        xtemp, ytemp = HenonMap(xtemp,ytemp,a,b,alpha,beta)
        x.append( xtemp )
        y.append( ytemp )
    return x,y
x=[]
y=[]
x,y=main1()
# Plot the Henon map of the initial condition sequences
plt.plot(x,y,'k.')
plt.savefig("Solucion.png",dpi=300)
show()

@profile
def main2():#Henon map application to the initial condition grid.
    a = 1
    b = 1
    alpha=0.2
    beta=1.01

    R=100
    p=4
    q=4
    npoints=100

    pgrid=np.linspace(0,4,npoints)
    qgrid=np.linspace(-4,0,npoints)

    values=np.zeros([npoints,npoints])

    for i in range(npoints):
        for j in range(npoints):
            xtemp = pgrid[i]
            ytemp = qgrid[j]
            aux=0
            while (xtemp**2+ytemp**2)<R:
                xtemp, ytemp = HenonMap(xtemp,ytemp,a,b,alpha,beta)
                if aux>1000:
                    break
                aux+=1
            values[i,j]=aux
    return values
#Plot of resulting grid
values=main2()            
plt.imshow(values, interpolation='nearest', cmap=cm.hot)
plt.savefig("HenonMap.png",dpi=300)
show()
