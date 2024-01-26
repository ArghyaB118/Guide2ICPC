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
	string s = "";
	for (int i = 0, i < n; i++)
		s.push_back('.');
	vector<string> ss(n, s);
	queue<vector<string>> q;
	q.push(ss);
	while (!q.empty()) {
		vector<string> tmp = q.front();
	}
	return {{}};
}

int main () {
	int n = 4;
}