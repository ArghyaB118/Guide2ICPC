// The rat enters at (0, 0) and leaves from (n - 1, n - 1)
// The rat can only move rightward and downward
// The rat can go to cells with 1 and cannot go to cells with 0
// Use Backtracking
// Maze size: n^2
// Time complexity: 2^{n^2}
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>

#include <vector>
#include <queue>
using namespace std;

#define n 4


void readGrid (int grid[n][n]) {
	ifstream file; file.open("ratInMaze.csv");
	string line;
	int i = 0;
	while (i < n) {
		getline(file, line);
		stringstream ss(line);
		int j = 0;
		while (ss.good() && j < n) {
			string substr;
			getline(ss, substr, ',');
			grid[i][j] = stoi(substr);
			j++;
		}
		i++;
	}
	file.close();
}


void displayGrid (int grid[n][n]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << grid[i][j] << " ";
		cout << endl;
	}
}

bool isSafe (int grid[n][n], pair<int, int> node) {
	if (node.first >= 0 && node.first < n && node.second >= 0 && node.second < n && grid[node.first][node.second] == 1)
		return true;
	return false;
}

bool solveMaze (int grid[n][n], int sol[n][n], pair<int, int> node) {
	if (node.first == n - 1 && node.second == n - 1 && grid[n - 1][n - 1] == 1) {
		sol[n - 1][n - 1] = 1; return true;
	}
	if (isSafe (grid, node) == true) {
		if (sol[node.first][node.second] == 1)
			return false;
		sol[node.first][node.second] = 1;
		if (solveMaze(grid, sol, make_pair(node.first + 1, node.second)) == true)
			return true;
		if (solveMaze(grid, sol, make_pair(node.first, node.second + 1)) == true)
			return true;
		if (solveMaze(grid, sol, make_pair(node.first - 1, node.second)) == true)
			return true;
		if (solveMaze(grid, sol, make_pair(node.first, node.second - 1)) == true)
			return true;
		sol[node.first][node.second] = 0;
		return false;
	}
	return false;
}

/*
Shortest Path in Binary Matrix

Given an n x n binary matrix grid, return the length of the 
shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell 
(i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected 
(i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

Input: grid = [[0,1],[1,0]]
Output: 2

Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1
*/

struct cell {
	int x, y, dist;
};

int shortestPathBinaryMatrix (vector<vector<int>>& grid) {
	int nn = grid.size();
	if (grid[0][0] == 1 || grid[nn - 1][nn - 1] == 1)
		return -1;
	bool visited[nn][nn]; memset(visited, false, sizeof(visited));
	queue<cell> q;
	q.push({0, 0, 1});
	while (!q.empty()) {
		struct cell tmp = q.front(); q.pop();
		if (tmp.x == nn - 1 && tmp.y == nn - 1)
			return tmp.dist;
		visited[tmp.x][tmp.y] = true;
		if (tmp.x + 1 < nn && visited[tmp.x + 1][tmp.y] != true && grid[tmp.x + 1][tmp.y] == 0)
			q.push({tmp.x + 1, tmp.y, tmp.dist + 1});
		if (tmp.x - 1 > 0 && visited[tmp.x - 1][tmp.y] != true && grid[tmp.x - 1][tmp.y] == 0)
			q.push({tmp.x - 1, tmp.y, tmp.dist + 1});
		if (tmp.y + 1 < nn && visited[tmp.x][tmp.y + 1] != true && grid[tmp.x][tmp.y + 1] == 0)
			q.push({tmp.x, tmp.y + 1, tmp.dist + 1});
		if (tmp.y - 1 > 0 && visited[tmp.x][tmp.y - 1] != true && grid[tmp.x][tmp.y - 1] == 0)
			q.push({tmp.x, tmp.y - 1, tmp.dist + 1});
		if (tmp.x + 1 < nn && tmp.y + 1 < nn && visited[tmp.x + 1][tmp.y + 1] != true && grid[tmp.x + 1][tmp.y + 1] == 0)
			q.push({tmp.x + 1, tmp.y + 1, tmp.dist + 1});
		if (tmp.x + 1 < nn && tmp.y - 1 > 0 && visited[tmp.x + 1][tmp.y - 1] != true && grid[tmp.x + 1][tmp.y - 1] == 0)
			q.push({tmp.x + 1, tmp.y - 1, tmp.dist + 1});
		if (tmp.x - 1 > 0 && tmp.y + 1 < nn && visited[tmp.x - 1][tmp.y + 1] != true && grid[tmp.x - 1][tmp.y + 1] == 0)
			q.push({tmp.x - 1, tmp.y + 1, tmp.dist + 1});
		if (tmp.x - 1 > 0 && tmp.y - 1 > 0 && visited[tmp.x - 1][tmp.y - 1] != true && grid[tmp.x - 1][tmp.y - 1] == 0)
			q.push({tmp.x - 1, tmp.y - 1, tmp.dist + 1});
	}
	return -1;
}

int main() {
	int grid[n][n], sol[n][n]; memset(sol, 0, sizeof(sol));
	readGrid (grid); displayGrid (grid);
	pair<int, int> source; source = make_pair (0, 0);
	if (solveMaze(grid, sol, source) == false) {
		cout << "solution does not exist" << endl;
	}
	else
		displayGrid (sol);


	vector<vector<int>> maze = {{0,0,0},{1,1,0},{1,1,0}};
	cout << "The shortest distance: " << shortestPathBinaryMatrix(maze) << endl;
	return 0;
}