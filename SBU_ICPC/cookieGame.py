import numpy as np

str = """2
6 2
4 0"""

def eatCookie(board, n):
	modified = False
	for i in range(n):
		for j in range(n):
			if (board[i][j] != 0):
				for k in range(i, n):
					for l in range(j, n):
						if (board[k][l] > board[i][j] and board[k][l] != 0):
							board[k][l] -= board[i][j]; modified = True
							return(board, modified)
						elif (board[k][l] < board[i][j] and board[k][l] != 0):
							board[i][j] -= board[k][l]; modified = True
							return(board, modified)
	return(board, modified)


n = int(str.strip().split('\n')[0]); print(n)
board = np.zeros((n,n))

for i in range(n):
	for j in range(n):
		board[i][j] = str.strip().split('\n')[i + 1].split(' ')[j]

print(board)

modified = True; count = 0
while (modified):
	board, modified = eatCookie(board, n); print(board)
	if (modified):
		count += 1

print("Number of times the player eats the cookies: ", count)
