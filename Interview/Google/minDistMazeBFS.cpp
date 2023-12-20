// https://www.geeksforgeeks.org/shortest-distance-two-cells-matrix-grid/
// https://www.geeksforgeeks.org/shortest-path-in-a-binary-maze/
// BFS
// https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/

// How to find the shortest path between two cells of a binary matrix
// 0's represent a path to navigate, 1's represent a wall

// Algorithm: Use BFS to find shortest path in unweighted graph
// 0 1 1 0
// 0 1 1 0
// 0 0 0 0
// 0 0 0 0
// source: (0,0) and destination: (0,3)

#include <iostream>
#include <queue>
using namespace std;

struct Point {
	int x;
	int y;
};

struct PointNode {
	Point pt;
	int dist;
};

int minDist(int matrix[4][4], Point src, Point dest) {
	//if (!matrix[src.x][src.y] || !matrix[dest.x][dest.y])
	//	return -1;
	if (src.x < 0 || src.y < 0 || dest.x < 0 || dest.y < 0)
		return -1;
	if (src.x > 3 || src.y > 3 || dest.x > 3 || dest.y > 3)
		return -1;

	bool isVisited[4][4]; memset(isVisited, false, sizeof isVisited);
	//for (int i = 0; i < 4; i++)
	//	for (int j = 0; j < 4; j++)
	//		isVisited[i][j] = false;

	isVisited[src.x][src.y] = true;

	queue<PointNode> q;
	PointNode s = {src, 0};
	q.push(s);
	while(!q.empty()) {
		PointNode curr = q.front();
		Point pt = curr.pt;

		if (pt.x == dest.x && pt.y == dest.y)
			return curr.dist;
		q.pop();

		if (pt.x + 1 >= 0 && pt.x + 1 <= 3 && matrix[pt.x + 1][pt.y] == 0 && isVisited[pt.x + 1][pt.y] == false) {
			isVisited[pt.x + 1][pt.y] = true;
			Point ptt = {pt.x + 1, pt.y};
			PointNode ss = {ptt, curr.dist + 1};
			q.push(ss);
		}
		if (pt.x - 1 >= 0 && pt.x - 1 <= 3 && matrix[pt.x - 1][pt.y] == 0 && isVisited[pt.x - 1][pt.y] == false) {
			isVisited[pt.x - 1][pt.y] = true;
			Point ptt = {pt.x - 1, pt.y};
			PointNode ss = {ptt, curr.dist + 1};
			q.push(ss);
		}
		if (pt.y + 1 >= 0 && pt.y + 1 <= 3 && matrix[pt.x][pt.y + 1] == 0 && isVisited[pt.x][pt.y + 1] == false) {
			isVisited[pt.x][pt.y + 1] = true;
			Point ptt = {pt.x, pt.y + 1};
			PointNode ss = {ptt, curr.dist + 1};
			q.push(ss);
		}
		if (pt.y - 1 >= 0 && pt.y - 1 <= 3 && matrix[pt.x][pt.y - 1] == 0 && isVisited[pt.x][pt.y - 1] == false) {
			isVisited[pt.x][pt.y - 1] = true;
			Point ptt = {pt.x, pt.y - 1};
			PointNode ss = {ptt, curr.dist + 1};
			q.push(ss);
		}
	}

	return -1;
}


int main () {
	int matrix[4][4] = {{0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	Point source = {0, 0};
	Point destination = {1, 3};
	cout << "Minimum distance between the source and destination: " << minDist(matrix, source, destination) << endl;
	return 0;
}