/*
LC#3

Given a string s, find the length of the longest substring without repeating characters.

Input: s = "abcabcbb"
Output: 3
*/

#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

/*
// Time = O(n + d) n = string length, d = dictionary length
// Space = O(d)
int lnrs(string s) {
	if (s.length() == 0 || s.length() == 1)
		return s.length();
	map<char, int> seen;
	int max_length = 0, start = 0;
	for (int end = 0; end < s.length(); s++) {
		if (seen.find(s[end]) != seen.end())
			start = max(start, seen[s[end]] + 1);
		seen[s[end]] = end;
		max_length = max(max_length, end - start + 1);
	}
	return max_length;
}
*/

int lnrs2(string s) {
	if (s.length() == 0 || s.length() == 1)
		return s.length();
	unordered_map<char, int> seen;
	int max_length = 0, current = 0, index = 0;
	for (char& ch : s) {
		if (seen.find(ch) == seen.end()) {
			current += 1; 
			max_length = max(max_length, current);
			seen[ch] = index;
		}
		else {
			current = min(current - seen[ch], current + 1);
			max_length = max(max_length, current);
			seen[ch] = index;
		}
		cout << index << " " << current << " " << max_length << endl;
		index++;
	}
	return max_length;
}

/*Example: bbb dp[] = {1, 1 - 0, 2 - 1} 
bab dp[] = {1, 1 + 1, 2 - 0}*/

int lnrs3(string s) {
	if (s.length() == 0 || s.length() == 1)
		return s.length();
	int dp[s.length()];
	unordered_map<char, int> seen;
	dp[0] = 1; seen[s[0]] = 0;
	for (int i = 1; i < s.length(); i++) {
		if (seen.find(s[i]) == seen.end()) {
			dp[i] = dp[i - 1] + 1;
			seen[s[i]] = i;
		}
		else {
			dp[i] = min(i - seen[s[i]], dp[i - 1] + 1);
			seen[s[i]] = i;
		}
	}
	return *max_element(dp, dp + s.length());
}

int main () {
	string s = "abcabcbb"; // "nfpdmpi"; // "tmmzuxt"; // 
	cout << "Length of the longest non-reapeating substring: " << lnrs2(s) << endl;
	return 0;
}
