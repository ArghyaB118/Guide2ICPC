/* LC#77

Given two strings s and t of lengths m and n respectively, 
return the minimum window substring of s 
such that every character in t (including duplicates) 
is included in the window. 
If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

bool covers 
	(unordered_map<char, int> window_chars, 
		unordered_map<char, int> t_chars) {
	if (window_chars == t_chars)
		return true;
	for (auto &i : t_chars)
		if (window_chars[i.first] < i.second)
			return false;
	return true;
}

string minWindow(string s, string t) {
	string s_bar = "";
	vector<int> s_indices = {};
	unordered_map<char, int> t_chars;
	for (auto &ch: t) {
		if (t_chars.find(ch) == t_chars.end())
			t_chars[ch] = 1;
		else
			t_chars[ch]++;
	}
	for (int i = 0; i < s.length(); i++) {
		if (t_chars.find(s[i]) != t_chars.end()) {
			s_indices.push_back(i);
			s_bar.push_back(s[i]);
		}
	}
	int left_final = 0, right_final = s_bar.length() - 1;
	int left = 0, right = 0;
	unordered_map<char, int> window_chars;
	for (auto &i : t_chars)
		window_chars[i.first] = 0;
	while (right < s_bar.size()) {
		if (covers(window_chars, t_chars)) {
			window_chars[s_bar[right]]++;
			if (s_indices[right] - s_indices[left] 
				< s_indices[right_final] - s_indices[left_final]) {
				right_final = right;
				left_final = left;
			}
			left++;
		}
		else
			right++;
	}
	while (covers(window_chars, t_chars)) {
		left++;
		if (s_indices[right] - s_indices[left] 
			< s_indices[right_final] - s_indices[left_final]) {
			right_final = right;
			left_final = left;
		}
	}
	cout << left_final << "  " << right_final << endl;
	string result = "";
	for (int i = s_indices[left_final]; i <= s_indices[right_final]; i++)
		result.push_back(s[i]);
	return result;
}

int main () {
	string s = "ADOBECODEBANC", t = "ABC";
	cout << minWindow (s, t) << endl;
	return 0;
}