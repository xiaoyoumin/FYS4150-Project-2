import matplotlib.pyplot as plt
import numpy as np
import os

if not os.path.isdir("./figures"):
    os.mkdir("./figures")

for n in (10,100):
    with open(f"output/eigenvectors_{n}.txt") as file:
        n_vectors, n_values = [int(s) for s in split(file.readline(), "\t")]
        vectors = np.zeros((n_vectors, n_values))
        for i in range(n_values):
            vectors[:, i] = [float(s) for s in split(file.readline(), "\t")]
    
    x = np.linspace(0,1,n_1,True)
    refs = np.zeros((3,len(x)))
    for i in range(3):
        refs[i] = np.sin(((i+1)*np.arange(len(x))*np.pi)/(len(x)+1))
    
    plt.figure((10,7))
    colors = ("b", "r", "g")
    for i in range(3):
        plt.plot(x,refs[i],"-"+colors[i], label = f"theoretical solution for i = {i}")
        plt.plot(x,vectors[i],"--"+colors[i], label = f"numerical solution for i = {i}")
    plt.xlims(0,1)
    plt.xlabel = "x(L)"
    plt.ylabel = "v(AU)"
    plt.savefig(f"figures/problem_6_{n}.pdf")