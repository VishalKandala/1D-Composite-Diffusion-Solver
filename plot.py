#!/usr/bin/env python3
import os
import sys
from numpy import *
from matplotlib.pyplot import *
directory = 'data'
#count = len(os.listdir(directory))

#T0 = loadtxt('data/t_profile_0.csv',skiprows = 1,delimiter=',')
#length = len(T0)
#print(length)
remove = int(sys.argv[1])
T = []
for filename in os.listdir(directory):
    #print(filename)
    if(filename != "r.csv"):
        T_t = loadtxt("data/"+filename,skiprows = 1, delimiter = ",",dtype = float)
        T.append(T_t.T)
        if(remove == 1):
            os.remove("data/"+filename)

T = array(T)
#T = T.T
#print(T[1,1])
#print(T)
print(len(T))

r = loadtxt("data/r.csv",delimiter=',');
r = r.T
if(remove == 1):
    os.remove("data/r.csv")
#print(shape(r))
for i in range(len(T)):
    #if(i%1):
    plot(r,T[i,0])
#savefig("timeseries.svg")
show()

