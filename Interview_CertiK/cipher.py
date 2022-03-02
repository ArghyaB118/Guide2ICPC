# Given String = "abcccdddee"
# Return "a1b1c3d3e2"


def cipher (mess):
	curr = mess[0]
	count = 0
	result = ""
	for i in mess:
	    if (curr == i):
	        count = count + 1
	    else:
	        result = result + curr + str(count)
	        curr = i
	        count = 1
	return (result + curr + str(count))

mess = "abcccdddee"
print(cipher(mess))