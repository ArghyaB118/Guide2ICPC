/*
Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.

A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.
*/

#include <iostream>
#include <vector>
using namespace std;

bool isToeplitz (vector<vector<int>>& matrix) {
	if (matrix.size() == 1 || matrix[0].size() == 1)
		return true;
	// go through the first row
	for (int i = 0; i < matrix[0].size(); i++) {
		while (j < )
		for (int j = 0; j < matrix[0].size(); j++) {

		}
	}
	// go through the first column

}


vector<int> diagonalTraversal (vector<vector<int>>& matrix) {
	vector<int> diag; diag.push_back(matrix[0][0]);
	int m = matrix.size(), n = matrix[0].size(), i = 0, j = 0;
	while (diag.size() < m * n) {
		if (i == 0 && j == 0) {
			j++; diag.push_back(matrix[i][j]);
		}
		else if (i == 0) {
			i++; j--; diag.push_back(matrix[i][j]);
		}
		else if (j == 0) {
			i++; 
		}
	}
}

int main () {
	vector<vector<int>> matrix = {{1,2,3,4},{5,1,2,3},{9,5,1,2}};
	cout << boolalpha << isToeplitz(matrix) << endl;
	return 0;
}