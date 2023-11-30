/* LC#778
 You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).
 
 The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

 Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).
 
 Input: grid = [[0,2],[1,3]]
 Output: 3
 Explanation:
 At time 0, you are in grid location (0, 0).
 You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
 You cannot reach point (1, 1) until time 3.
 When the depth of water is 3, we can swim anywhere inside the grid.
 
 Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
 Output: 16
 Explanation: The final route is shown.
 We need to wait until time 16 so that (0, 0) and (4, 4) are connected.*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> coord;

// O(t * m * n)
int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    int t = 0;
    vector<vector<bool>> visited (n, vector<bool> (n, false));
    visited[0][0] = true;
    
    while (visited[n - 1][n - 1] == false) {
        queue<coord> q; q.push({0, 0});
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (visited[i][j])
                    q.push({i, j});
        
        while (!q.empty()) {
            coord p = q.front(); q.pop();
            visited[p.first][p.second] = true;
            if (p.first + 1 < n && visited[p.first + 1][p.second] == false)
                if (grid[p.first + 1][p.second] <= t && grid[p.first][p.second] <= t)
                    q.push({p.first + 1, p.second});
            if (p.first - 1 >= 0 && visited[p.first - 1][p.second] == false)
                if (grid[p.first - 1][p.second] <= t && grid[p.first][p.second] <= t)
                    q.push({p.first - 1, p.second});
            if (p.second + 1 < n && visited[p.first][p.second + 1] == false)
                if (grid[p.first][p.second + 1] <= t && grid[p.first][p.second] <= t)
                    q.push({p.first, p.second + 1});
            if (p.second - 1 >= 0 && visited[p.first][p.second - 1] == false)
                if (grid[p.first][p.second - 1] <= t && grid[p.first][p.second] <= t)
                    q.push({p.first, p.second - 1});
        }
        if (visited[n - 1][n - 1] == true)
            break;
        t++;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                grid[i][j] = max(grid[i][j], t);
        
        if (t == 5)
            break;
        for (auto i : grid) {
            for (int j : i)
                cout << boolalpha << j << " ";
            cout << endl;
        }
        for (auto i : visited) {
            for (bool j : i)
                cout << boolalpha << j << " ";
            cout << endl;
        }
    }
    return t;
}

int main () {
    vector<vector<int>> grid = {{3,2},{0,1}}; // {{0,2},{1,3}}; // {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
    cout << swimInWater(grid) << endl;
    return 0;
}

