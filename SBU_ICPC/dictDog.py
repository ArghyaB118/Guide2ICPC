with open("dictDog.txt") as f:
	lines = f.readlines()

j = 1
for i in range(int(lines[0])):
	num_words = int(lines[j])
	words = []
	for k in range(num_words):
		words.append(lines[j+1+k].split('\n')[0])
	words.sort()
	for w in words:
		print(w)
	j += (num_words + 1)