/* LC#695
 
 You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
 
 The area of an island is the number of cells with a value 1 in the island.

 Return the maximum area of an island in grid. If there is no island, return 0.
 
 Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 Output: 6
 Explanation: The answer is not 11, because the island must be connected 4-directionally.
 
 Input: grid = [[0,0,0,0,0,0,0,0]]
 Output: 0
 
 11000
 11000
 00011
 00011*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> Pair;

// Idea: Do depth first search when see a 1 + maintain visited array
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxArea = 0;
    vector<vector<bool>> visited (grid.size(), vector<bool> (grid[0].size(), false));
    // cout << visited.size() << grid.size() << visited[0].size() << grid[0].size() << endl;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1) {
                int tmp = 0;
                queue<Pair> q; q.push({i, j}); visited[i][j] = true;
                while (!q.empty()) {
                    Pair p = q.front(); q.pop(); tmp++;
                    cout << p.first << p.second << endl;
                    // go left
                    if (p.second > 0 && grid[p.first][p.second - 1] == 1 && visited[p.first][p.second - 1] == false) {
                        q.push({p.first, p.second - 1});
                        visited[p.first][p.second - 1] = true;
                    }
                    // go right
                    if (p.second < grid[0].size() - 1 && grid[p.first][p.second + 1] == 1 && visited[p.first][p.second + 1] == false) {
                        q.push({p.first, p.second + 1});
                        visited[p.first][p.second + 1] = true;
                    }
                    // go top
                    if (p.first > 0 && grid[p.first - 1][p.second] == 1 && visited[p.first - 1][p.second] == false) {
                        q.push({p.first - 1, p.second});
                        visited[p.first - 1][p.second] = true;
                    }
                    // go down
                    if (p.first < grid.size() - 1 && grid[p.first + 1][p.second] == 1 && visited[p.first + 1][p.second] == false) {
                        q.push({p.first + 1, p.second});
                        visited[p.first + 1][p.second] = true;
                    }
                }
                maxArea = max(maxArea, tmp);
                // cout << i << j << maxArea << endl;
            }
        }
    }
    return maxArea;
}

int main () {
    vector<vector<int>> grid = {{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
    // {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    cout << maxAreaOfIsland (grid) << endl;
    return 0;
}
