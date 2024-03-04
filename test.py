import numpy as np
import time
f = open("test4.inp","r")
b = []
for x in f: 
    b.append(x)
f.close()
f = open("test4.out","a")
start = time.time()
np.sort(b)
total = (time.time() - start) * 1000000
p = "py sort:   " + str(int(total)) + " microseconds"
#print(p)
f.write(p)

    