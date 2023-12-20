// Count the number of Islands
// 0 0 0 1
// 0 0 1 1
// 1 0 0 1
// 1 0 0 1


#include <iostream>
#include <queue>
using namespace std;
#define n 4
typedef pair<int, int> pos;

void bfs (int grid[n][n], bool visited[n][n], pos p) {
	visited[p.first][p.second] = true;
	queue<pos> q; q.push(p);
	while (!q.empty()) {
		pos p = q.front();
		visited[p.first][p.second] = true;
		q.pop();
		if (p.first + 1 < n && grid[p.first + 1][p.second] == 1 && visited[p.first + 1][p.second] == false)
			q.push(make_pair(p.first + 1, p.second));
		if (p.first - 1 > 0 && grid[p.first - 1][p.second] == 1 && visited[p.first - 1][p.second] == false)
			q.push(make_pair(p.first + 1, p.second));
		if (p.second + 1 < n && grid[p.first][p.second + 1] == 1 && visited[p.first][p.second + 1] == false)
			q.push(make_pair(p.first, p.second + 1));
		if (p.second - 1 > 0 && grid[p.first][p.second - 1] == 1 && visited[p.first][p.second - 1] == false)
			q.push(make_pair(p.first, p.second - 1));
	}
}

int numberOfIslands (int grid[n][n]) {
	bool visited[n][n];
	memset(visited, false, sizeof(visited));
	int numberOfIslands = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 1 && visited[i][j] != true) {
				bfs(grid, visited, make_pair(i, j));
				numberOfIslands++;
			}
		}
	}
	return numberOfIslands;
}


/* 
You are given an n x n binary matrix grid. 
You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.
*/
int bfs_size (int grid[n][n], bool visited[n][n], pos p) {
	int count = 0;
	visited[p.first][p.second] = true;
	queue<pos> q; q.push(p);
	while (!q.empty()) {
		pos p = q.front(); count++;
		visited[p.first][p.second] = true;
		q.pop();
		if (p.first + 1 < n && grid[p.first + 1][p.second] == 1 && visited[p.first + 1][p.second] == false)
			q.push(make_pair(p.first + 1, p.second));
		if (p.first - 1 > 0 && grid[p.first - 1][p.second] == 1 && visited[p.first - 1][p.second] == false)
			q.push(make_pair(p.first + 1, p.second));
		if (p.second + 1 < n && grid[p.first][p.second + 1] == 1 && visited[p.first][p.second + 1] == false)
			q.push(make_pair(p.first, p.second + 1));
		if (p.second - 1 > 0 && grid[p.first][p.second - 1] == 1 && visited[p.first][p.second - 1] == false)
			q.push(make_pair(p.first, p.second - 1));
	}
	return count;
}


int largestIsland (int grid[n][n]) {
	int largestIsland = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 0) {
				bool visited[n][n];
				memset(visited, false, sizeof(visited));
				grid[i][j] = 1;
				largestIsland = max(largestIsland, bfs_size(grid, visited, make_pair(i, j)));
			}
		}
	}
	return largestIsland;
}

int main () {
	int grid[n][n] = {{0,0,0,1}, {0,0,1,1}, {1,0,0,1}, {1,0,0,1}};
	cout << "The number of islands: " << numberOfIslands(grid) << endl;
	cout << "The largest island: " << largestIsland(grid) << endl;
	return 0;
}