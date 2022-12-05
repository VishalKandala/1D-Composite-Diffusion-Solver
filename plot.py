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
t = []
for filename in os.listdir(directory):
    #print(filename)
    if(filename != "r.csv"):
        templist = filename.split("_")
        templist = templist[-1].split(".")
        t.append(int(templist[0]))
        T_t = loadtxt("data/"+filename,skiprows = 1, delimiter = ",",dtype = float)
        T.append(T_t.T)
        if(remove == 1):
            os.remove("data/"+filename)

T = array(T)
#T = T.T
#print(T[1,1])
#print(T)
#print(len(T))
layup = int(sys.argv[2])
r = loadtxt("data/r.csv",delimiter=',');
r = r.T
if(remove == 1):
    os.remove("data/r.csv")
#print(shape(r))
for i in range(len(T)):
    #if(i%1):
    plot(r,T[i,layup],label=str(t[i]))
#savefig("timeseries.svg")
legend()
name = str(input("Title: "))
title(name)
ylabel("Temperature (K)")
xlabel("Distance (m)")
savefig(name, dpi=1000)
show()

