import numpy as np
from scipy.sparse import csgraph


with open('myFear.txt') as f:
    lines = f.readlines()

#read parameters
test_case = int(lines[0])
n = int(lines[1][0])
m = int(lines[1][2])
areas = np.zeros(n)
	
for i in range(n):
	areas[i] = int(lines[2][2*i])

connected = np.zeros((n,n))

for i in range(m):
	edge = lines[3+i]
	print(int(edge[0]), int(edge[2]))
	connected[int(edge[0]) - 1][int(edge[2]) - 1] = 1
	connected[int(edge[2]) - 1][int(edge[0]) - 1] = 1

single_door = []
for i in range(n):
	count = 0
	for j in range(n):
		if (connected[i][j] == 1):
			count = count + 1
	if (count == 1):
		single_door.append(i)

print(test_case, n, m, areas, connected)


n_components, labels = csgraph.connected_components(connected, directed=False)
print(n_components, labels)

count = []
for i in range(n_components):
	count.append(np.where(labels == i))
print(count)

result = 0
for i in range(n_components):
	if (len(count[i][0]) % 2 != 0):
		for k in range(len(count[i][0])):
			room = count[i][0][k]
			if (room not in single_door):
				result += areas[room]
print(result)