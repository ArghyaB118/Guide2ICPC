#include <iostream>
#include <vector>
#include <string>
using namespace std;

void nQueens (vector<int>& v, int n) {
	if (v.size() == n)
		return v;
	int x = v.size();
	for (int i = 0; i < n; i++) {
		
	}
}

vector<vector<string>> solveNQueens(int n) {
	for (int i = 0; i < n; i++)
		nQueens({i}, n);
	return {{}};
}

int main () {
	int n = 4;
}