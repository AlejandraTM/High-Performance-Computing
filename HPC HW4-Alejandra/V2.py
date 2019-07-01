from pylab import *
import matplotlib.pyplot as plt
from numba import jit

def HenonMap(x,y,a,b,alpha,beta):
    return a- alpha*x**2+b*y, beta*x
@profile
def notnumpy(pgrid,qgrid,xsup,xinf,ysup,yinf,npoints):    
    #size of grid division
    xsize=(xsup-xinf)/npoints
    ysize=(ysup-yinf)/npoints
    for i in range(npoints):
        pgrid.append(xinf)
        xinf=xsize+xinf
        qgrid.append(yinf)
        yinf=ysize+yinf
    #Matriz of initial values
    values =[[0 for j in range(npoints)] for i in range(npoints)]
    return values
def main0():
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
def main():
    #Initial values of the Henon Map
    a = 1
    b = 1
    alpha=0.2
    beta=1.01
    #Grid limits
    xinf=0.
    xsup=4.
    yinf=-4.
    ysup=0.
    #Restriction and number of points on the plot
    R=100
    npoints=600
    #grid definition
    pgrid=[]
    qgrid=[]
    values=notnumpy(pgrid,qgrid,xsup,xinf,ysup,yinf,npoints)
    #HenonMap on the grid
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
            values[i][j]=aux
    return values
x=[]
y=[]
# Plot the time series
x,y=main0()
plt.plot(x,y,'k.')
plt.savefig("Solucion.png",dpi=300)
#Plot the Henon Map over the grid
values=main()
plt.imshow(values, interpolation='nearest', cmap=cm.hot)
plt.savefig("HenonMap.png",dpi=300)
	
