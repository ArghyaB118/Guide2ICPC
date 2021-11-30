str = """3
1 sbu
2 abc uubbs
3 bbb sss uuu"""

temp = str.split('\n')
for i in range(1, int(temp[0])+1):
	count = 0
	temp1 = temp[i].split(' ')
	for j in range(1, int(temp1[0])+1):
		if (temp1[j].find('s') != -1 and temp1[j].find('b') != -1 and temp1[j].find('u') != -1):
			count += 1
	print(count)