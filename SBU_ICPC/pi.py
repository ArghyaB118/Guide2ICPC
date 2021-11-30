import math
from decimal import *
getcontext().prec = 6

r = 10
x = [x for x in range(-r,r+1)]
points = [[(i,j) for j in x] for i in x]

for rows in points:
	for point in rows:
		distance = point[0]**2 + point[1]**2
		distance = math.sqrt(distance)
		if (distance > r):
			rows.remove(point)

count = 0
for rows in points:
	for point in rows:
		count += 1
pi = float(count / r**2)
print(format(pi, '.10f'))