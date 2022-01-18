/*
You are given an m x n grid grid of values 0, 1, or 2, where:

each 0 marks an empty land that you can pass by freely,
each 1 marks a building that you cannot pass through, and
each 2 marks an obstacle that you cannot pass through.
You want to build a house on an empty land that reaches all 
buildings in the shortest total travel distance. 
You can only move up, down, left, and right.

Return the shortest travel distance for such a house. 
If it is not possible to build such a house according to the above rules, return -1.

The total travel distance is the sum of the distances between 
the houses of the friends and the meeting point.

The distance is calculated using Manhattan Distance, 
where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

Input: grid = [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]
Output: 7
Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2).
The point (1,2) is an ideal empty land to build a house, 
as the total travel distance of 3+3+1=7 is minimal.
So return 7.

Input: grid = [[1,0]]
Output: 1

Input: grid = [[1]]
Output: -1
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> Pair;
typedef pair<int, Pair> Pos;

int bfs(Pair source, vector<Pair>& houses) {
	int total_distance = 0, count = 0;
	bool visited[grid.size()][grid.size()];
	memset(visited, false, sizeof(visited)); 
	visited[source.first][source.second] = true;
	queue<Pos> q; q.push(make_pair(0,source));
	while (!q.empty() && count < houses.size()) {
		Pos pos = q.front(); q.pop();
		if (grid[pos.second.first][pos.second.second] == 1) {
			count++; total_distance += pos.first;
		}
		if (pos.second.first + 1 < grid.size())
			if (grid[pos.second.first + 1][pos.second.second] != 2)
				if (!visited[pos.second.first + 1][pos.second.second])
					q.push(make_pair(pos.first + 1, make_pair(pos.second.first + 1, pos.second.second));
		if (pos.second.first - 1 >= 0)
			if (grid[pos.second.first - 1][pos.second.second] != 2)
				if (!visited[pos.second.first - 1][pos.second.second])
					q.push(make_pair(pos.first + 1, make_pair(pos.second.first - 1, pos.second.second));
		if (pos.second.second + 1 < grid.size())
			if (grid[pos.second.first][pos.second.second + 1] != 2)
				if (!visited[pos.second.first][pos.second.second + 1])
					q.push(make_pair(pos.first + 1, make_pair(pos.second.first, pos.second.second + 1));
		if (pos.second.second - 1 >= 0)
			if (grid[pos.second.first][pos.second.second - 1] != 2)
				if (!visited[pos.second.first][pos.second.second - 1])
					q.push(make_pair(pos.first + 1, make_pair(pos.second.first, pos.second.second - 1));	
	}
	return total_distance;
}


int shortestDistance(vector<vector<int>>& grid) {
	vector<Pair> houses, empty_lands;
	vector<int> distances;
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (grid[i][j] == 0)
				empty_lands.push_back(make_pair(i, j));
			else if (grid[i][j] == 1)
				houses.push_back(make_pair(i, j));
		}
	}
	if (empty_lands.empty())
		return -1;
	for (int i = 0; i < empty_lands.size(); i++) {
		distances.push_back(bfs(empty_lands[i], houses));
	}
	return *min_element(distances.begin(), distances.end());
}

int main () {
	vector<vector<int>> grid{{1,0,2,0,1},{0,0,0,0,0},{0,0,1,0,0}}; 
	cout << shortestDistance(grid) << endl;
	return 0;
}