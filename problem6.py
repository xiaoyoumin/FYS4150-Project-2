import matplotlib.pyplot as plt
import numpy as np
import os

if not os.path.isdir("./figures"):
    os.mkdir("./figures")

for n in (10,100):
    with open(f"output/eigenvectors_{n}.txt") as file:
        n_vectors, n_values = [int(s) for s in file.readline().split("\t")]
        vectors = np.zeros((n_vectors, n_values+2))
        for i in range(1,n_values+1):
            vectors[:, i] = [float(s) for s in file.readline().split("\t")]
    
    x = np.linspace(0,1,n+1,True)
    refs = np.zeros((3,len(x)))
    for i in range(3):
        refs[i] = np.sin(((i+1)*np.arange(len(x))*np.pi)/(len(x)-1))
    
    plt.figure(figsize = (10,7))
    colors = ("b", "r", "g")
    for i in range(3):
        plt.plot(x,refs[i],"-"+colors[i], label = f"theoretical solution for i = {i}")
        plt.plot(x,vectors[i],"--"+colors[i], label = f"numerical solution for i = {i}")
    plt.xlim(0,1)
    plt.xlabel = "x(L)"
    plt.ylabel = "v(AU)"
    plt.title(f"First three eigenvectors compared to theory with {n} steps")
    plt.legend()
    plt.savefig(f"figures/problem_6_{n}.pdf")