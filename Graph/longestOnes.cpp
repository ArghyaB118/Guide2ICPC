/* LC#562
 Given an m x n binary matrix mat, return the length of the longest line of consecutive one in the matrix.
 
 The line could be horizontal, vertical, diagonal, or anti-diagonal.*/

#include <iostream>
#include <vector>
using namespace std;

/* Idea:
1. Find a starting point.
 - Only if the previous point is either invalid or zero (depends on the direction of the pointer throw as well).
2. Throw a pointer.
*/

int longestLine (vector<vector<int>>& mat) {
    int longest = 0;
    int m = mat.size(), n = mat[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1) {
                // In each direction: horizontal, vertical, diagonal, and anti-diagonal
                // We will check either left to right or top to down.
                // 1. Check if this is starting point
                // 2. Throw a point
                if (i - 1 < 0 || (i - 1 >= 0 && mat[i - 1][j] == 0)) {
                    // check vertical
                    int tmp = 0, i0 = i;
                    while (i0 < m && mat[i0][j] == 1) {
                        tmp++; i0++;
                    }
                    cout << tmp << i << j << endl;
                    longest = max(longest, tmp);
                }
                if (j - 1 < 0 || (j - 1 >= 0 && mat[i][j - 1] == 0)) {
                    // check vertical
                    int tmp = 0, j0 = j;
                    while (j0 < n && mat[i][j0] == 1) {
                        tmp++; j0++;
                    }
                    cout << tmp << i << j << endl;
                    longest = max(longest, tmp);
                }
                if ((i - 1 < 0 || j - 1 < 0) || (i - 1 >= 0 && j - 1 >= 0 && mat[i - 1][j - 1] == 0)) {
                    // check diagonal
                    int tmp = 0, i0 = i, j0 = j;
                    while (i0 < m && j0 < n && mat[i0][j0] == 1) {
                        tmp++; i0++; j0++;
                    }
                    cout << tmp << i << j << endl;
                    longest = max(longest, tmp);
                }
                if ((i + 1 >= n || j + 1 >= n) || (i + 1 < m && j + 1 < n && mat[i + 1][j + 1] == 0)) {
                    // check anti-diagonal
                    int tmp = 0, i0 = i, j0 = j;
                    while (i0 < m && j0 >= 0 && mat[i0][j0] == 1) {
                        tmp++; i0++; j0--;
                    }
                    cout << tmp << i << j << endl;
                    longest = max(longest, tmp);
                }
            }
        }
    }
    return longest;
}

int main () {
    vector<vector<int>> mat = {{0,1,1,0},{0,1,1,0},{0,0,0,1}};
    cout << longestLine(mat) << endl;
    return 0;
}
