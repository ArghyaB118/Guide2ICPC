/*You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.
 
 Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.
 
 Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
 Output: 6*/

// Complexity: O(m * n * k)


#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> x;
// (x, y) (number of moves, unused fuel (k))
typedef pair<x, x> xx;

bool isSafe (vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int m, int n, int k) {
    if (x < 0 || y < 0 || x >= m || y >= n)
        return false;
    else if (visited[x][y] == true)
        return false;
    else if (grid[x][y] == 1 && k == 0)
        return false;
    return true;
}

int shortestPath (vector<vector<int>>& grid, int k) {
    queue<xx> q;
    int m = grid.size(), n = grid[0].size();
    // cout << m << " " << n << endl;
    q.push({{0, 0}, {0, k}});
    vector<vector<bool>> visited (grid.size(), vector<bool> (grid[0].size(), false));
    while (!q.empty()) {
        xx tmp = q.front(); q.pop();
        if (tmp.first.first == m - 1 && tmp.first.second == n - 1)
            return tmp.second.first;
        visited[tmp.first.first][tmp.first.second] = true;
        // try to move up
        if (isSafe(grid, visited, tmp.first.first - 1, tmp.first.second, m, n, tmp.second.second)) {
            if (grid[tmp.first.first - 1][tmp.first.second] == 0)
                q.push({{tmp.first.first - 1, tmp.first.second}, {tmp.second.first + 1, tmp.second.second}});
            else
                q.push({{tmp.first.first - 1, tmp.first.second}, {tmp.second.first + 1, tmp.second.second - 1}});
        }
        // try to move down
        if (isSafe(grid, visited, tmp.first.first + 1, tmp.first.second, m, n, tmp.second.second)) {
            if (grid[tmp.first.first + 1][tmp.first.second] == 0)
                q.push({{tmp.first.first + 1, tmp.first.second}, {tmp.second.first + 1, tmp.second.second}});
            else
                q.push({{tmp.first.first + 1, tmp.first.second}, {tmp.second.first + 1, tmp.second.second - 1}});
        }
        // try to move left
        if (isSafe(grid, visited, tmp.first.first, tmp.first.second - 1, m, n, tmp.second.second)) {
            if (grid[tmp.first.first][tmp.first.second - 1] == 0)
                q.push({{tmp.first.first, tmp.first.second - 1}, {tmp.second.first + 1, tmp.second.second}});
            else
                q.push({{tmp.first.first, tmp.first.second - 1}, {tmp.second.first + 1, tmp.second.second - 1}});
        }
        // try to move right
        if (isSafe(grid, visited, tmp.first.first, tmp.first.second + 1, m, n, tmp.second.second)) {
            if (grid[tmp.first.first][tmp.first.second + 1] == 0)
                q.push({{tmp.first.first, tmp.first.second + 1}, {tmp.second.first + 1, tmp.second.second}});
            else
                q.push({{tmp.first.first, tmp.first.second + 1}, {tmp.second.first + 1, tmp.second.second - 1}});
        }
    }
    return -1;
}

int main () {
    vector<vector<int>> grid = {{0,0,0},{1,1,0},{0,0,0},{0,1,1},{0,0,0}};
    int k = 1;
    cout << shortestPath (grid, k) << endl;
    return 0;
}
