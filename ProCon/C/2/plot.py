import numpy as np
import matplotlib.pyplot as plt
import matplotlib as mpl

with open('./in1.txt') as f:
    x=[]
    for _ in range(6): x.append(int(f.readline()))
with open("./out1.txt") as f:
    y=[]
    for _ in range(6):
        y.append(list(map(int,f.readline().split())))
#print(x)
#print(y)
     
plt.xscale('log')
plt.yscale('log')
for z in y:
    plt.plot(x, z)
plt.savefig("a.png")
