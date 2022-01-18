/*
Given a string containing digits from 2-9 inclusive, 
return all possible letter combinations that the number could represent. 
Return the answer in any order.

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Input: digits = ""
Output: []

Input: digits = "2"
Output: ["a","b","c"]
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<char> > keypad{{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};

vector<string> permutation (char c, vector<string> out) {
	if (out.empty()) {
		for (int i = 0; i < keypad[int(c) - 50].size(); i++) {
			string temp;
			temp.push_back(keypad[int(c) - 50][i]);
			out.push_back(temp);
		}
	}
	else {
		for (int i = 0; i < out.size(); i++) {
			string temp = out.front();
			out.pop_back();
			for (int j = 0; j < keypad[int(c) - 50].size(); j++) {
				string temp1 = temp;
				temp1.push_back(keypad[int(c) - 50][j]);
				out.push_back(temp1);
			}
		}
	}
	return out;
}

vector<string> letterCombinations(string digits) {
	if (digits.length() == 0)
		return {};
	vector<string> out;
	for (int i = 0; i < digits.length(); i++)
		out = permutation(digits[i], out);
	return out;
}


/*
Given an array nums of distinct integers, return all the possible permutations. 
You can return the answer in any order.
*/
void rotate (vector<int>& nums) {
	int num = nums.front();
	nums.pop_back();
	nums.push_back(num);
}

// Use Backtracking
void permute (vector<int>& nums, int start, vector<vector<int>>& v) {
	if (nums.empty()) { return; }
	if (nums.size() == 1) { 
		v.push_back({nums[0]});
		return; 
	}
	if (start == nums.size())
		return;
	for (int j = start; j < nums.size(); j++) {
		swap(nums[start], nums[j]);
		if (find(v.begin(), v.end(), nums) == v.end())
			v.push_back(nums);
		permute(nums, start + 1, v);
		swap(nums[start], nums[j]);
	}
}

int main () {
	/*
	vector<string> digits{"23", "", "2"};
	for (int i = 0; i < digits.size(); i++) {
		vector<string> v = letterCombinations(digits[i]);
		for (int j = 0; j < v.size(); j++)
			cout << v[j] << " ";
		cout << endl;
	}
	*/
	vector<vector<int>> v; vector<int> nums{1,2,3};
	permute(nums, 0, v);
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++)
			cout << v[i][j] << " ";
		cout << endl;
	}
	return 0;
}