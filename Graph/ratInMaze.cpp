// The rat enters at (0, 0) and leaves from (n - 1, n - 1)
// The rat can only move rightwarrd and downward
// The rat can go to cells with 1 and cannot go to cells with 0
// Use Backtracking
// Maze size: n^2
// Time complexity: 2^{n^2}
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
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

int main() {
	int grid[n][n], sol[n][n]; memset(sol, 0, sizeof(sol));
	readGrid (grid); displayGrid (grid);
	pair<int, int> source; source = make_pair (0, 0);
	if (solveMaze(grid, sol, source) == false) {
		cout << "solution does not exist" << endl;
	}
	else
		displayGrid (sol);
	return 0;
}