// https://www.geeksforgeeks.org/determinant-n-x-n-matrix-using-multi-threading/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> mat = {{1, 2, 3}, {2, 3, 4}, {4, 5, 6}};

int cofactor (int a, int b) {
	int size = mat.size();
	int cofactor_size = size - a - 1;
	vector<vector<int>> tmp(cofactor_size, vector<int> (0, cofactor_size));
	if (cofactor_size == 2) {
		for (int i = 0; i != a && i < size; i++) {
			for (int j = 0; j != b && j < size; j++) {
				// tmp[i].push_back(mat[i][j]);
			}
		}
		return tmp[0][0] * tmp[1][1] - tmp[1][0] - tmp[0][1];
	}
	else {
		int result = 0;
		for (int i = 0; i < size && i != ; i++) {
			result += cofactor(a + 1, )
		}
	}
}

int determinant () {
	int size = mat.size();
	if (size == 1)
		return mat[0][0];
	else if (size == 2)
		return mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];
	else {
		int result = 0;
		int sign = 1;
		for (int i = 0; i < size; i++) {
			result += cofactor(0, i) * mat[0][i] * sign;
			sign *= -1;
		}
		return result;
	}
	return -1;
}

int main () {
	cout << determinant() << endl;	
	return 0;
}