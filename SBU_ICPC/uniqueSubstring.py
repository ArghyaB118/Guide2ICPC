str = """3
aababab
3
ababab
3
abcabcdab
1"""

verbose = False
if (verbose): print(str)

lines = str.strip().split('\n')
if (verbose): print(lines)

test_case = int(lines[0])
for i in range(test_case):
	# This is O(n^2) solution.
	string = lines[2*i + 1]
	sublength = int(lines[2*i + 2])
	length = len(string)
	if (verbose): print(length, sublength)
	reject_list = []; unique_list = []
	for i in range(length - sublength + 1):
		substring = string[i:i+sublength]
		if (verbose): print(substring)
		if substring in unique_list:
			unique_list.remove(substring)
			reject_list.append(substring)
		else:
			if substring not in reject_list:
				unique_list.append(substring)
	if (verbose): print(unique_list)
	if (len(unique_list) == 0):
		print("BADSTRING")
	else:
		for i in range(length - sublength + 1):
			substring = string[i:i+sublength]
			if (substring == unique_list[0]):
				print(i + 1)