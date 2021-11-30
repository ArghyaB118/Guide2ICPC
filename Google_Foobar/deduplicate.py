'''
1 print items that do not have duplicates from the longer list
'''

def deduplicate(x, y):
	if (len(x) > len(y)):
		temp = [z for z in x if z not in y]
	else:
		temp = [z for z in y if z not in x]
	return temp


x = [14, 27, 1, 4, 2, 50, 3, 1]
y = [2, 4, -4, 3, 1, 1, 14, 27, 50]
print(deduplicate(x, y))