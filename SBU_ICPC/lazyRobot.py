verbose = False


class robot:
	def __init__(self, x=0, y=0, dirn="N"):
		self.x = x; self.y = y; self.dirn = dirn

	def L(self):
		if (self.dirn == "N"):
			self.dirn = "W"
		elif (self.dirn == "W"):
			self.dirn = "S"
		elif (self.dirn == "S"):
			self.dirn = "E"
		elif (self.dirn == "E"):
			self.dirn = "N"
		else:
			print("invalid direction")

	def R(self):
		if (self.dirn == "N"):
			self.dirn = "E"
		elif (self.dirn == "W"):
			self.dirn = "N"
		elif (self.dirn == "S"):
			self.dirn = "W"
		elif (self.dirn == "E"):
			self.dirn = "S"
		else:
			print("invalid direction")

	def F(self):
		if (self.dirn == "N"):
			self.y += 1
		elif (self.dirn == "W"):
			self.x -= 1
		elif (self.dirn == "S"):
			self.y -= 1
		elif (self.dirn == "E"):
			self.x += 1
		else:
			print("invalid move")

	def B(self):
		if (self.dirn == "N"):
			self.y -= 1
		elif (self.dirn == "W"):
			self.x += 1
		elif (self.dirn == "S"):
			self.y += 1
		elif (self.dirn == "E"):
			self.x -= 1
		else:
			print("invalid move")

def moveRobot(i, f):
	r = robot()
	if (verbose): print(r.x, r.y)
	moves = []
	for j in range(i, f + 1):
		moves.append(lines[j].strip())
	if (verbose): print(moves, len(moves))
	for k in range(len(moves)):
		if (len(moves[k]) == 1):
			if (moves[k] == "L"):
				r.L()
			elif (moves[k] == "R"):
				r.R()
			elif (moves[k] == "F"):
				r.F()
			elif (moves[k] == "B"):
				r.B()
			else:
				print("invalid move")
		elif (len(moves[k]) == 5 and moves[k].split()[0] == "R"):
			p = int(moves[k].split()[1]); q = int(moves[k].split()[2])
			for s in range(p - 1, q):
				if (moves[s] == "L"):
					r.L()
				elif (moves[s] == "R"):
					r.R()
				elif (moves[s] == "F"):
					r.F()
				elif (moves[s] == "B"):
					r.B()
				else:
					print("invalid move")
		else:
			print("invalid request")
	pos = (r.x, r.y)
	return pos


with open("lazyRobot.txt") as f:
	lines = f.readlines()

test_case = int(lines[0])
j = 1
for i in range(test_case):
	n = int(lines[j])
	pos = moveRobot(j + 1, j + n)
	print(pos[0], pos[1])
	j += (n + 1)