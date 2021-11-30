import numpy as np
from scipy.sparse import csgraph
import math
verbose = False

with open('desertCities.txt') as f:
    lines = f.readlines()

# Parameters
temp = lines[1].split(" ")
n = int(temp[0])
m = int(temp[1])
q = int(temp[2])

if (verbose):
	print(n, m, q)


for i in range(q):
	refuel = int(lines[m+2+i])
	if (verbose):
		print(refuel)
	connected = np.zeros((n, n))
	for j in range(m):
		temp = lines[2+j].split(" ")
		city1 = int(temp[0])
		city2 = int(temp[1])
		distance = int(temp[2])
		if (distance <= refuel):
			connected[city1-1][city2-1] = 1
			connected[city2-1][city1-1] = 1
	n_components, labels = csgraph.connected_components(connected, directed=False)
	if (verbose):
		print(n_components, labels, connected)
	count = 0
	for j in range(n_components):
		temp = len(np.where(labels == j)[0])
		if (temp > 1):
			count += math.factorial(temp) / math.factorial(temp - 2)
	print(int(count))

