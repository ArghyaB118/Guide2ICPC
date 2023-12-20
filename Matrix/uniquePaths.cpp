/* LC#66
There is a robot on an m x n grid. 
The robot is initially located at the top-left corner 
(i.e., grid[0][0]). The robot tries to move to the 
bottom-right corner (i.e., grid[m - 1][n - 1]). 
The robot can only move either down or right at any point in time.

Given the two integers m and n, return 
the number of possible unique paths that the robot 
can take to reach the bottom-right corner.

The test cases are generated so that the answer 
will be less than or equal to 2 * 109.
*/

#include <iostream>
#include <vector>
using namespace std;

int uniquePathsUtil (int m, int n, int x, int y) {
	if (x > m - 1 || y > n - 1)
		return 0;
	else if (x == m - 1 && y == n - 1)
		return 1;
	else {
		return uniquePathsUtil(m, n, x + 1, y) 
			+ uniquePathsUtil(m, n, x, y + 1);
	}
}

int uniquePaths (int m, int n) {
	return uniquePathsUtil (m, n, 0, 0);
}

int uniquePaths2 (int m, int n) {
	if (m == 1 || n == 1)
		return 1;
	vector<vector<int>> maze(m, vector<int> (n, 0));
	for (int i = 0; i < m; i++)
		maze[i][0] = 1;
	for (int i = 0; i < n; i++)
		maze[0][i] = 1;
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			maze[i][j] = maze[i - 1][j] + maze[i][j - 1];
		}
	}
	return maze[m - 1][n - 1];
}

int main () {
	int m = 3, n = 7;
	cout << uniquePaths(m, n) << " " << uniquePaths2(m, n) << endl;
	return 0;
}