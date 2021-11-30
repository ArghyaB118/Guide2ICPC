"""
3.1 Prepare the Bunnies' Escape
===========================
You're awfully close to destroying the LAMBCHOP doomsday device and freeing Commander 
Lambda's bunny prisoners, but once they're free of the prison blocks, the bunnies are 
going to need to escape Lambda's space station via the escape pods as quickly as possible. 
Unfortunately, the halls of the space station are a maze of corridors and dead ends that will 
be a deathtrap for the escaping bunnies. Fortunately, Commander Lambda has put you in charge 
of a remodeling project that will give you the opportunity to make things a little easier for 
the bunnies. Unfortunately (again), you can't just remove all obstacles between the bunnies 
and the escape pods - at most you can remove one wall per escape pod path, both to maintain
structural integrity of the station and to avoid arousing Commander Lambda's suspicions. 
You have maps of parts of the space station, each starting at a prison exit and ending at the
door to an escape pod. The map is represented as a matrix of 0s and 1s, where 0s are passable
space and 1s are impassable walls. The door out of the prison is at the top left (0,0) and 
the door into an escape pod is at the bottom right (w-1,h-1). 
Write a function solution(map) that generates the length of the shortest path from the prison
door to the escape pod, where you are allowed to remove one wall as part of your remodeling 
plans. The path length is the total number of nodes you pass through, counting both the 
entrance and exit nodes. The starting and ending positions are always passable (0). 
The map will always be solvable, though you may or may not need to remove a wall. The height
and width of the map can be from 2 to 20. Moves can only be made in cardinal directions; 
no diagonal moves are allowed.
To rephrase:
Given: A matrix of m*n size with only 0s and 1s. 0s denote a passable path, 1s denote a wall / obstruction.
Problem: We want to design a robot that travels from top left corner to bottom right corner 
(it can only walk through 0s and 1s are obstructions). the robot has one (and only one) 
special bomb to burst down one obstruction (magic wand to convert a 1 to 0, hence transforming
an obstruction to walkable path). We define cost of the path that robot takes by total number of 
cell it visits (inclusive of starting point and finishing point). What is the algorithm to 
get the optimal path for the robot?
Constraints:
(1) The robot can only move in cardinal directions, not in diagonal directions.
(2) The starting and finishing positions (top left and bottom right) are always passable 
(there is 0 in these two positions in the matrix)
(3) The map is always solvable, you may or may not need to use the bomb.

Algorithm:
We will use DP! But not the simplest variant.
1. Start from top left moving forward and at the same time from bottom right moving backward.
2. Keep on moving through cells and store path length.
3. Keep on going in all directions from a cell (whichever is not already ventured). 
4. If there's 1, STOP! if 0, recursively move in all 4 directions
"""



def sht_pth(sx, sy, maze):
  w = len(maze[0])
  h = len(maze)
  board = [[None for i in range(0,w)] for i in range(0,h)]
  board[sx][sy] = 1
  arr = [(sx, sy)]
  while arr:
    x, y = arr.pop(0)
    for i in [[1,0],[-1,0],[0,-1],[0,1]]:
      nx = x + i[0]; ny = y + i[1]
      if 0 <= nx < h and 0 <= ny < w:
        if board[nx][ny] is None:
          board[nx][ny] = board[x][y] + 1
          if maze[nx][ny] == 0:
            arr.append((nx, ny))
  return board

def solution(map):
  w = len(map[0])
  h = len(map)
  tb = sht_pth(0, 0, map); print(tb)
  bt = sht_pth(h-1, w-1, map); print(bt)
  ans = 1000
  for i in range(h):
    for j in range(w):
      if tb[i][j] and bt[i][j]:
        ans = min(tb[i][j] + bt[i][j] - 1, ans)
  return ans

#map = [[0, 1, 1, 0], [0, 0, 0, 1], [1, 1, 0, 0], [1, 1, 1, 0]]
#map = [[0, 0, 0, 0, 0, 0], [1, 1, 1, 1, 1, 0], [0, 0, 0, 0, 0, 0], [0, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1], [0, 0, 0, 0, 0, 0]]
map = [[0, 0, 0, 0, 0, 0],[1, 1, 1, 1, 1, 0],[1, 1, 1, 1, 1, 1],[0, 0, 0, 0, 0, 0],[0, 1, 1, 1, 1, 1],[0, 0, 0, 0, 0, 0]]
print(solution(map))