/* LC#72

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* recursion:
if (a[i] == b[j])
	dp[i][j] = dp[i - 1][j - 1]
else
	dp[i][j] = 1 + min(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1])
*/
int minDistance (string word1, string word2) {
	if (word1.length() == 0)
		return word2.length();
	if (word2.length() == 0)
		return word1.length();
	if (word1.length() == 1) {
		if (find(word2.begin(), word2.end(), word1[0]) != word2.end())
			return word2.length() - 1;
		else
			return word2.length();
	}
	if (word2.length() == 1) {
		if (find(word1.begin(), word1.end(), word2[0]) != word1.end())
			return word1.length() - 1;
		else
			return word1.length();
	}
	vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), 0));
	if (word1[0] != word2[0])
		dp[0][0] = 1;
	for (int i = 1; i < word2.length(); i++) {
		if (word2[i] == word1[0])
			dp[0][i] = dp[0][i - 1];
		else
			dp[0][i] = dp[0][i - 1] + 1;
	}
	for (int i = 1; i < word1.length(); i++) {
		if (word1[i] == word2[0])
			dp[i][0] = dp[i - 1][0];
		else
			dp[i][0] = dp[i - 1][0] + 1;
	}
	for (int i = 1; i < word1.length(); i++) {
		for (int j = 1; j < word2.length(); j++) {
			if (word1[i] == word2[j])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = 1 + min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]);
		}
	}
	return dp[word1.size() - 1][word2.length() - 1];
}

int main () {
	string word1 = "pneumonoultramicroscopicsilicovolcanoconiosis", word2 = "ultramicroscopically"; // word1 = "horse", word2 = "ros";
	cout << minDistance (word1, word2) << endl;
	return 0;
}
