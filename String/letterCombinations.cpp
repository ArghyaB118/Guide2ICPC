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


vector<vector<int>> permute (vector<int>& nums) {
	vector<vector<int>> v;
	if (nums.empty()) { return v; }
	if (nums.size() == 1) { return {{nums[0]}}; }
	return v;       
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
	vector<vector<int>> v1; vector<int> v{1,2};
	v1 = permute(v);
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[i].size(); j++)
			cout << v1[i][j] << " ";
		cout << endl;
	}
	return 0;
}