/*
Basic Calculator

Given a string s which represents an expression, 
evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. 
All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which 
evaluates strings as mathematical expressions, such as eval().

Input: s = "3+2*2"
Output: 7

Input: s = " 3/2 "
Output: 1

Input: s = " 3+5 / 2 "
Output: 5
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string removeSpaces (string s) {
	string t;
	for (int i = 0; i < s.length(); i++) {
		if (isdigit(s[i]) || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
			t.push_back(s[i]);
		}
	}
	return t;
}

int operations (vector<string> v) {
	int size = v.size();
	while (size > 1) {
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == "/") {
				int num = stoi(v[i - 1]) / stoi(v[i + 1]);
				v[i] = to_string(num);
				v.erase(v.begin() + i + 1);
				v.erase(v.begin() + i - 1);
			}
		}
		size = 1;
	}
	for (string & sv : v)
		cout << sv;
	cout << endl;
	return 0;
}


vector<string> split (string s) {
	string tmp;
	vector<string> v;
	for (int i = 0; i < s.length(); i++) {
		if (isdigit(s[i]))
			tmp.push_back(s[i]);
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
			v.push_back(tmp); tmp.clear(); 
			tmp.push_back(s[i]); v.push_back(tmp); tmp.clear();
		}
	}
	v.push_back(tmp);
	return v;
}

int calculate (string s) {
	s = removeSpaces(s);
	vector<string> v = split(s);
	for (string & sv : v)
		cout << sv;
	cout << endl;
	operations(v);
/*	vector<string> v = operations(s);
	while (v.size() > 1) {
		for (int i = 0; i < v.size(); i++)
			if (s[i] == '/') {
				int num = stoi(s[i - 1]) / stoi(s[i + 1]);
				v.erase(v.begin() + )
			}
	}*/
	return 0;
}

int main () {
	string s = "3+5 / 2 ";
	cout << calculate(s) << endl;
	return 0;
}