# a string container
# with manipulation to input

data = [["s.t.u.v", 1], ["a.b.c", 2], ["d.e", 3]]

Dict = {}

for each_data in data:
	tmp = each_data[0].split('.')
	val = each_data[1]

	if len(tmp) == 4:
		Dict[tmp[0]] = {tmp[1] : {tmp[2] : {tmp[3] : val}}}
	elif len(tmp) == 3:
		Dict[tmp[0]] = {tmp[1] : {tmp[2] : val}}
	elif len(tmp) == 2:
		Dict[tmp[0]] = {tmp[1] : val}
	elif len(tmp) == 1:
		Dict[tmp[0]] = val

for i in Dict:	
	print(i)
	#print(len(tmp), Dict[tmp[0]])
