/*You are given an m x n integer matrix points (0-indexed). Starting with 0 points, you want to maximize the number of points you can get from the matrix.
 
 To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.

 However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.

 Return the maximum number of points you can achieve.

 abs(x) is defined as:

 x for x >= 0.
 -x for x < 0.*/

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

// Cost: O (m n^2)
long long maxPoints (vector<vector<int>>& points) {
    int m = points.size(), n = points[0].size();
    long long result = 0;
    vector<vector<long long>> dp (m, vector<long long> (n, 0));
    for (int i = 0; i < n; i++)
        dp[0][i] = points[0][i];
    if (m == 1) {
        for (int j = 0; j < n; j++) {
            result = (result > dp[0][j]) ? result : dp[0][j];
        }
        return result;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int tmp = 0;
            for (int k = 0; k < n; k++) {
                tmp = (tmp > dp[i - 1][k] - abs(k - j)) ? tmp : dp[i - 1][k] - abs(k - j);
            }
            dp[i][j] = points[i][j] + tmp;
        }
    }
    for (int j = 0; j < n; j++) {
        result = (result > dp[m - 1][j]) ? result : dp[m - 1][j];
    }
    return result;
}

int main () {
    vector<vector<int>> points = {{1,2,3},{1,5,1},{3,1,1}};
    cout << maxPoints(points) << endl;
    return 0;
}
