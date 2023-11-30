#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> coordinate;
typedef pair<coordinate, int> pos;

int getSecondsRequired(int R, int C, vector<vector<char>> G) {
	// Write your code here
	queue<pos> q;
	vector<vector<bool>> isVisited(R, vector<bool>(C, false));
	coordinate start, end;
	vector<coordinate> as, zs;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (G[i][j] == 'S')
				start = {i, j};
			else if (G[i][j] == 'E')
				end = {i, j};
			else if (G[i][j] == 'a')
				as.push_back({i, j});
			else if (G[i][j] == 'z')
				zs.push_back({i, j});
		}
	}
	q.push(make_pair(start, 0));
	isVisited[start.first][start.second] = true;
	while (!q.empty()) {
		pos tmp = q.front();
		q.pop();
		coordinate c = tmp.first;
		if (G[c.first][c.second] == 'E')
			return tmp.second;
		if (G[c.first][c.second] == 'a') {
			for (auto a : as) {
				if (a != c & !isVisited[a.first][a.second]) {
					isVisited[a.first][a.second] = true;
					q.push(make_pair(a, tmp.second));
				}
			}
		}
		else if (G[c.first][c.second] == 'z') {
			for (auto z : zs) {
				if (z != c & !isVisited[z.first][z.second]) {
					isVisited[z.first][z.second] = true;
					q.push(make_pair(z, tmp.second));
				}
			}
		}
		if (c.second + 1 < C && G[c.first][c.second + 1] != '#' && !isVisited[c.first][c.second + 1])
			q.push(make_pair(make_pair(c.first, c.second + 1), tmp.second + 1));
		if (c.second - 1 >= 0 && G[c.first][c.second - 1] != '#' && !isVisited[c.first][c.second + 1])
			q.push(make_pair(make_pair(c.first, c.second - 1), tmp.second + 1));
		if (c.first + 1 < R && G[c.first + 1][c.second] != '#' && !isVisited[c.first][c.second + 1])
			q.push(make_pair(make_pair(c.first + 1, c.second), tmp.second + 1));
		if (c.first - 1 >= 0 && G[c.first - 1][c.second] != '#' && !isVisited[c.first][c.second + 1])
			q.push(make_pair(make_pair(c.first - 1, c.second), tmp.second + 1));
	}
	return -1;
}

int main () {
	return 0;
}