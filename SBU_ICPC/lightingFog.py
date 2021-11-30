import math
R = 1.0 # radius of fog

for i in range(-100000, 100000, 1):
	for j in range(-100000, 100000, 1):
		distance = math.sqrt(math.pow(i, 2) + math.pow(j, 2))
		if (distance <= R):
			distance2 = math.sqrt(math.pow(i - 10000, 2) + math.pow(j, 2))
			if (distance2 <= )


fog = math.pi * math.pow(R,2)
lighted = 
print(fog)