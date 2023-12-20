/* LC#1143

Given two strings text1 and text2, 
return the length of their longest common subsequence. 
If there is no common subsequence, return 0.

A subsequence of a string is a new string generated 
from the original string with some characters (can be none) 
deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence 
that is common to both strings.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lcs (string a, string b) {
	if (a.length() == 0 || b.length() == 0)
		return 0;
	else if (a.length() == 1) {
		if (find(b.begin(), b.end(), a[0]) != b.end())
			return 1;
		return 0;
	}
	else if (b.length() == 1) {
		if (find(a.begin(), a.end(), b[0]) != a.end())
			return 1;
		return 0;
	}
	vector<vector<int>> dp(a.length(), vector<int>(b.length(), 0));
	for (int i = 0; i < b.length(); i++)
		if (a[0] == b[i])
			dp[0][i] = 1;
	for (int i = 0; i < a.length(); i++)
		if (b[0] == a[i])
			dp[i][0] = 1;
	for (int i = 1; i < a.length(); i++) {
		for (int j = 1; j < b.length(); j++) {
			if (a[i] == b[j])
				dp[i][j] = 1 + max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
			else
				dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
		}
	}

	for (auto &i : dp) {
		for (auto &j : i)
			cout << j << " ";
		cout << endl;
	}
	return dp[a.length() - 1][b.length() - 1];
}

int main () {
	string a = "adbce", b = "ace";
	cout << lcs(a, b) << endl;
	return 0;
}