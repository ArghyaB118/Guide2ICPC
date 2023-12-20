/*
Given a square grid of characters in the range ascii[a-z], 
rearrange elements of each row alphabetically, ascending. 
Determine if the columns are also in ascending alphabetical order, 
top to bottom. Return YES if they are or NO if they are not.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string gridChallenge (vector<string> grid) {
	for (auto &s : grid)
		sort(s.begin(), s.end());
	if (grid.size() == 1)
		return "YES";
	int n = grid[0].length();
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < grid.size(); j++) {
			if ((int)grid[j][i] < (int)grid[j - 1][i])
				return "NO";
		}
	}
	return "YES";
}

int main () {
	vector<string> v = {"cba", "ade", "efg"};
	cout << gridChallenge (v) << endl;
	return 0;
}