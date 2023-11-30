/* LC#329
 
 Given an m x n integers matrix, return the length of the longest increasing path in matrix.
 
 From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cell {
    int row, col, dist;
};

int longestIncreasingPathUtil (vector<vector<int>>& matrix, cell c) {
    cout << c.row << c.col << c.dist << endl;
    queue<cell> q; q.push(c);
    int num = c.dist;
    while (!q.empty()) {
        cell tmp = q.front();
        q.pop();
        num = max(num, tmp.dist);
        if (tmp.row < matrix.size() - 1 && matrix[tmp.row + 1][tmp.col] > matrix[tmp.row][tmp.col])
            q.push({tmp.row + 1, tmp.col, tmp.dist + matrix[tmp.row + 1][tmp.col]});
        if (tmp.row > 0 && matrix[tmp.row - 1][tmp.col] > matrix[tmp.row][tmp.col])
            q.push({tmp.row - 1, tmp.col, tmp.dist + matrix[tmp.row - 1][tmp.col]});
        if (tmp.col < matrix[0].size() - 1 && matrix[tmp.row][tmp.col + 1] > matrix[tmp.row][tmp.col])
            q.push({tmp.row, tmp.col + 1, tmp.dist + matrix[tmp.row][tmp.col + 1]});
        if (tmp.col > 0 && matrix[tmp.row][tmp.col - 1] > matrix[tmp.row][tmp.col])
            q.push({tmp.row, tmp.col - 1, tmp.dist + matrix[tmp.row][tmp.col - 1]});
    }
    cout << num << endl;
    return num;
}

int longestIncreasingPath (vector<vector<int>>& matrix) {
    int longest = 0;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            longest = max(longest, longestIncreasingPathUtil(matrix, {i, j, matrix[i][j]}));
        }
    }
    return longest;
}


// The following utility is to determine the length of the path.
 
int longestIncreasingPathUtil2 (vector<vector<int>>& matrix, cell c, vector<vector<bool>>& visited) {
    queue<cell> q; q.push(c);
    int num = c.dist;
    while (!q.empty()) {
        cell tmp = q.front();
        q.pop();
        num = max(num, tmp.dist);
        visited[tmp.row][tmp.col] = true;
        if (tmp.row < matrix.size() - 1 && matrix[tmp.row + 1][tmp.col] > matrix[tmp.row][tmp.col])
            q.push({tmp.row + 1, tmp.col, tmp.dist + 1});
        if (tmp.row > 0 && matrix[tmp.row - 1][tmp.col] > matrix[tmp.row][tmp.col])
            q.push({tmp.row - 1, tmp.col, tmp.dist + 1});
        if (tmp.col < matrix[0].size() - 1 && matrix[tmp.row][tmp.col + 1] > matrix[tmp.row][tmp.col])
            q.push({tmp.row, tmp.col + 1, tmp.dist + 1});
        if (tmp.col > 0 && matrix[tmp.row][tmp.col - 1] > matrix[tmp.row][tmp.col])
            q.push({tmp.row, tmp.col - 1, tmp.dist + 1});
    }
    return num;
}

int longestIncreasingPath2 (vector<vector<int>>& matrix) {
    int longest = 0;
    vector<vector<bool>> visited (matrix.size(), vector<bool> (matrix[0].size(), false));
    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[0].size(); j++)
            if (!visited[i][j])
                longest = max(longest, longestIncreasingPathUtil2 (matrix, {i, j, 1}, visited));
    return longest;
}


int main () {
    vector<vector<int>> matrix = {{9,9,4},{6,6,8},{2,1,1}};
    cout << longestIncreasingPath (matrix) << endl;
    cout << longestIncreasingPath2 (matrix) << endl;
    return 0;
}



