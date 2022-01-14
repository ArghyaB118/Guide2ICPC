/*
Given a string s, find the length of the longest substring without repeating characters.

Input: s = "abcabcbb"
Output: 3
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;


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

int main () {
	string s = "abcabcbb";
	cout << "Length of the longest non-reapeating substring: " << lns(s) << endl;
	return 0;
}