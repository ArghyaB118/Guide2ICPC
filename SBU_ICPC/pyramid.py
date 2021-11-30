import numpy as np

i = 100000
g_i = []
for j in range(1,i+1):
	temp = []
	if (len(g_i) < j):
		temp = [j] * j
#		print("x", temp)
		g_i.extend(temp)
	else:
		temp = [j] * g_i[j-1]
#		print("y", temp)
		g_i.extend(temp)
print(sum(g_i) % 1000000007)