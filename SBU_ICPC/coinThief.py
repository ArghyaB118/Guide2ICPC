import numpy as np
import math

verbose = False
with open('coinThief.txt') as f:
    lines = f.readlines()

test_case = int(lines[0])
j = 1
for i in range(test_case):
	temp = lines[j].split(' ')
	n = int(temp[0])
	m = int(temp[1])
	k = int(temp[2])
	if (verbose):
		print(n, m, k)
	if (m == 0):
		steal = (pow(k,n) - 1) / (k - 1); print(steal)
	else:
		connected = np.ones((n,n))
		for l in range(m):
			temp = lines[j+l+1].split(' ')
			if (verbose):
				print(lines[j+l+1], int(temp[0]), int(temp[1]))
			connected[int(temp[0])-1][int(temp[1])-1] = 0
			connected[int(temp[1])-1][int(temp[0])-1] = 0
		if (verbose):
			print(connected)
		dp = []; dp.append(1.0)
		for l in range(1,n):
			temp = 0
			for p in range(l+1):
				temp += connected[l][p] * pow(k, p)
			dp.append(temp)
		if (verbose):
			print(dp)
		steal = max(dp); print(steal)
	j += (m + 1)
