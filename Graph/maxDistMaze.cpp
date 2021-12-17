#include <iostream>
using namespace std;
#define N 4

// For this problem it is not possible to allow
// the degree of freedom to be 4. Only down and rightward
// movement is allowed.
// 1 2 3 4
// 5 6 7 8
// 9 8 7 6
// 5 4 3 2
// Source = (0, 0)
// Destination = (N - 1, N - 1)

int maxPath (int mat[N][N]) {
	int dp[N][N]; memset(dp, 0, sizeof(dp));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i > 0 && j > 0)
				dp[i][j] = mat[i][j] + max(dp[i-1][j], dp[i][j-1]);
			else if (j == 0 && i != 0)
				dp[i][j] = mat[i][j] + dp[i-1][j];
			else if (i == 0 && j != 0)
				dp[i][j] = mat[i][j] + dp[i][j-1];
			else
				dp[i][j] = mat[i][j];
		}
	}
	return dp[N - 1][N -1];
}

int main () {
	int mat[N][N] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 8, 7, 6}, {5, 4, 3, 2}};
	cout << "The maximum path is: " << maxPath(mat) << endl;
	return 0;
}