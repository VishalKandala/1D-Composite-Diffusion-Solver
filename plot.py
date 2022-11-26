import os
from numpy import *
from matplotlib.pyplot import *

directory = 'data'
#count = len(os.listdir(directory))
T0 = loadtxt('data/t_profile_0.csv',skiprows = 1,delimiter=',')
length = len(T0)
T = []
for filename in os.listdir(directory):
    #print(filename)
    T_t = loadtxt("data/"+filename,skiprows = 1, delimiter = ",",dtype = float)
    T.append(T_t.T)

T = array(T)
#T = T.T
#print(T[1,1])
print(T[5,1])
#print(length)
r = linspace(0,4,length)
#print(r)
plot(r,T[5,1])
savefig("plot.png")
show()

