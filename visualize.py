import os
import sys
import random
from matplotlib import pyplot as plt
import numpy as np
from mpl_toolkits import mplot3d 
directory = 'data'

m = sys.argv[1]
global layer
layer = int(sys.argv[2])-1   # which layer you want to plot

filename = "t_profile_"+m+".csv"

f = open(directory+"/"+filename, 'r')
global T_t
T_t = np.loadtxt(f,skiprows = 1, delimiter = ",", dtype = float)
T_t = T_t[:,1:5]        # change accordingly if also plotting column 0
fr = open(directory+"/"+"r.csv", 'r')
r = np.loadtxt(fr, delimiter=",", dtype = float)

T_plot = np.ndarray((4,1))
for i in range(4):
    T_plot[i] = T_t[layer][i] 

u= np.linspace(0,2*np.pi, 24)  # if values change here 
v= np.linspace(0, np.pi, 12)

global x,y,z 

x= np.outer(np.cos(u), np.sin(v))
y= np.outer(np.sin(u), np.sin(v))
z= np.outer(np.ones(np.size(u)), np.cos(v))
x = x*r[layer]
y = y*r[layer]
z = z*r[layer]

PlotT = np.ndarray((24,12))   # then these parameters should change accordingly
for i in range(24):                  
    for j in range(12):
        if (i<=5 and j<=5) :
            PlotT[i][j] = T_plot[0]
        if (5<i<=11 and j<=5):
            PlotT[i][j] = T_plot[1]
        if(11<i<=17 and j<=5):
            PlotT[i][j] = T_plot[2]
        if(17<i<=23 and j<=5):
            PlotT[i][j] = T_plot[3]
        if (i<=5 and 5<j<=11) :
            PlotT[i][j] = T_plot[2]
        if (5<i<=11 and 5<j<=11):
            PlotT[i][j] = T_plot[3]
        if(11<i<=17 and 5<j<=11):
            PlotT[i][j] = T_plot[0]
        if(17<i<=23 and 5<j<=11):
            PlotT[i][j] = T_plot[1]          


def plotIntersection(R=8):

    Nr = T_t.shape[0]
    Ntheta = 40
    r = np.linspace(0,R,Nr)
    t1 = T_t[:,0]
    t2 = T_t[:,1]
    t3 = T_t[:,2]
    t4 = T_t[:,3]
    theta = np.linspace(0,2*np.pi,Ntheta)
    T1 = np.ndarray((Nr, Ntheta))
    T2 = np.ndarray((Nr, Ntheta))

    # Tried to map the colors of 2D and 3D plots to be the same
    for i in range(Ntheta):
        if i < Ntheta/4:
            T1[:,i] = t1
            T2[:,i] = t3
        if Ntheta/4 <= i < Ntheta/2:
            T1[:,i] = t2
            T2[:,i] = t4
        if Ntheta/2 <= i < 3*Ntheta/4:
            T1[:,i] = t1
            T2[:,i] = t3
        if 3*Ntheta/4 <= i < Ntheta:
            T1[:,i] = t2
            T2[:,i] = t4

    fig = plt.figure()
    ax = fig.add_subplot(121, polar = True)
    pc = ax.pcolormesh(theta, r, T1, cmap="plasma", shading='auto')
    fig.colorbar(pc)

    ax2 = fig.add_subplot(122, polar = True)
    pc2 = ax2.pcolormesh(theta, r, T2, cmap="plasma",  shading='auto')
    fig.colorbar(pc2)
    plt.show()    


def plotball(mapdata, plotdata, alpha=0.6,colormap='plasma'):
    
    mycolormap = plt.get_cmap(colormap)
    mapminvalue=mapdata.min()
    mapmaxvalue=mapdata.max()
 
    relativevalue=np.zeros((mapdata.shape[0],mapdata.shape[1]))
    for i in range(0,relativevalue.shape[0]):
        for j in range(0,relativevalue.shape[1]):
            relativevalue[i][j]=round(mapdata[i][j]/mapmaxvalue,1)
    
    global colorsvalues
    colorsvalues = np.empty(mapdata.shape, dtype=object)
    for i in range(0,relativevalue.shape[0]):
        for j in range(0,relativevalue.shape[1]):
            tempc=mycolormap(relativevalue[i][j])
   
            colorreal=(tempc[0],tempc[1],tempc[2],alpha)
            colorsvalues[i][j]=colorreal

    # now we have the global colorvalues mapping, we will construct actual colorvalues for the plotdata

    actual_color = np.ndarray(plotdata.shape, dtype=object)  # the same size as plotdata

    for i in range(24):                  
        for j in range(12):
            if (i<=5 and j<=5) :
                actual_color[i][j] = colorsvalues[layer][0]
            if (5<i<=11 and j<=5):
                actual_color[i][j] = colorsvalues[layer][1]
            if(11<i<=17 and j<=5):
                actual_color[i][j] = colorsvalues[layer][2]
            if(17<i<=23 and j<=5):
                actual_color[i][j] = colorsvalues[layer][3]
            if (i<=5 and 5<j<=11) :
                actual_color[i][j] = colorsvalues[layer][2]
            if (5<i<=11 and 5<j<=11):
                actual_color[i][j] = colorsvalues[layer][3]
            if(11<i<=17 and 5<j<=11):
                actual_color[i][j] = colorsvalues[layer][0]
            if(17<i<=23 and 5<j<=11):
                actual_color[i][j] = colorsvalues[layer][1]
    
    fig = plt.figure(num=1,figsize=(10,8))
    ax = mplot3d.Axes3D(fig)
   
    # u= np.linspace(0,2*np.pi, mapdata.shape[0])
    # v= np.linspace(0, np.pi, mapdata.shape[1])

    # x= np.outer(np.cos(u), np.sin(v))
    # y= np.outer(np.sin(u), np.sin(v))
    # z= np.outer(np.ones(np.size(u)), np.cos(v))
   
    figmap = ax.plot_surface(x, y, z, facecolors=actual_color, edgecolor=None, cmap=mycolormap, rstride=1, cstride=1)
    plt.colorbar(figmap,shrink=0.8)
    #plt.show()


if __name__=="__main__":
    
    plotball(T_t, PlotT)
    plotIntersection()

