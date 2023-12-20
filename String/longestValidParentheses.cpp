/* LC#32

Given a string containing just the characters '(' and ')', 
return the length of the longest valid (well-formed) parentheses substring.
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int longestValidParentheses (string s) {
	stack<int> q;
	for (int i = 0; i < s.length(); i++) {
		char ch = s[i];
		if (ch == '(') {
			q.push(i); cout << i << endl;
		}
		else if (ch == ')' && q.empty()) {
			q.push(i); cout << i << endl;
		}
		else if (ch == ')' && s[q.top()] == '(') {
			cout << q.top() << endl; q.pop();
		}
		else if (ch == ')' && s[q.top()] != '(') {
			q.push(i); cout << i << endl;
		}
	}
	int right = s.length(), left = 0, max_length = 0;
	while (!q.empty()) {
		left = q.top(); cout << left << endl;
		max_length = max(max_length, right - left - 1);
		right = left;
		q.pop();
	}
	max_length = max(max_length, right);
	return max_length;
}

int main () {
	string s = "()(()"; // ")()())"; // "()(()"; // "()(())";
	cout << longestValidParentheses (s) << endl;
	return 0;
}