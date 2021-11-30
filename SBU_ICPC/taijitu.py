taijitu = []

# Parameters
num_folds = 100
pos = 5
taijitu.append(1)

i = 0
while (i < num_folds and len(taijitu) < pos):
	length = len(taijitu)
	taijitu.append(1)
	for j in range(length):
		if (taijitu[length - j - 1] == 0):
			taijitu.append(1)
		elif (taijitu[length - j - 1] == 1):
			taijitu.append(0)
		else:
			print("invalid shape")
	i += 1
print(taijitu[pos-1], taijitu)