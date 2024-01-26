/*
You've found yourself in a grid of cells with R rows 
and C columns. 
G_ij = . means emmopty cell
= # means wall
= 'S' means starting position
= 'E' means ending position
= otherwise, any lowrcase letter

start at 'S, go to any 'E
as soon as possible
by moving 4-way
or teleporting to a cell
with the same letter.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> coordinate;
typedef pair<coordinate, int> pos;

int getSecondsRequired(int R, int C, vector<vector<char>> G) {
	queue<pos> q;
	vector<vector<bool>> isVisited(R, vector<bool>(C, false));
	vector<vector<coordinate>> Gbar(28, vector<coordinate>{});
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (G[i][j] == 'S')
				Gbar[26].push_back({i, j});
			else if (G[i][j] == 'E')
				Gbar[27].push_back({i, j});
			else if (isalpha(G[i][j]))
				Gbar[(int)G[i][j] - (int)'a'].push_back({i, j});
		}
	}
	coordinate start = Gbar[26][0];
	q.push(make_pair(start, 0));
	isVisited[start.first][start.second] = true;
	while (!q.empty()) {
		pos tmp = q.front();
		q.pop();
		coordinate c = tmp.first;
		if (G[c.first][c.second] == 'E')
			return tmp.second;
		/*if (G[c.first][c.second] == 'a') {
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
		}*/
		if (isalpha(G[c.first][c.second]) && G[c.first][c.second] != 'S') {
			for (auto &i : Gbar[(int)G[c.first][c.second] - (int)'a']) {
				if (i != c) {
					q.push(make_pair(make_pair(i.first, i.second), tmp.second + 1));
					isVisited[i.first][i.second] = true;
				}
			}
		}
		if (c.second + 1 < C && G[c.first][c.second + 1] != '#' && !isVisited[c.first][c.second + 1]) {
			q.push(make_pair(make_pair(c.first, c.second + 1), tmp.second + 1));
			isVisited[c.first][c.second + 1] = true;
		}
		if (c.second - 1 >= 0 && G[c.first][c.second - 1] != '#' && !isVisited[c.first][c.second - 1]) {
			q.push(make_pair(make_pair(c.first, c.second - 1), tmp.second + 1));
			isVisited[c.first][c.second - 1] = true;
		}
		if (c.first + 1 < R && G[c.first + 1][c.second] != '#' && !isVisited[c.first + 1][c.second]) {
			q.push(make_pair(make_pair(c.first + 1, c.second), tmp.second + 1));
			isVisited[c.first + 1][c.second] = true;
		}
		if (c.first - 1 >= 0 && G[c.first - 1][c.second] != '#' && !isVisited[c.first - 1][c.second]) {
			q.push(make_pair(make_pair(c.first - 1, c.second), tmp.second + 1));
			isVisited[c.first - 1][c.second] = true;
		}
	}
	return -1;
}

int main () {
	return 0;
}