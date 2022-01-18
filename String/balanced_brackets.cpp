/*
Balance Brackets

A bracket is any of the following characters: (, ), {, }, [, or ].

We consider two brackets to be matching if the first bracket is an open-bracket, 
e.g., (, {, or [, and the second bracket is a close-bracket of the same type. 
That means ( and ), [ and ], and { and } are the only pairs of matching brackets.
Furthermore, a sequence of brackets is said to be balanced if the following 
conditions are met:
	The sequence is empty, or
	The sequence is composed of two or more non-empty sequences, 
	all of which are balanced, or
	The first and last brackets of the sequence are matching, 
	and the portion of the sequence without the first and last elements is balanced.

You are given a string of brackets. Your task is to determine whether 
each sequence of brackets is balanced. If a string is balanced, return true, 
otherwise, return false.

Example 1
s = {[()]}
output: true
Example 2
s = {}()
output: true
Example 3
s = {(})
output: false
Example 4
s = )
output: false
Example 5
s = {[(])}
output: false
Example 6
s = {{[[(())]]}}
output: true
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isBalanced(string s) {
  if (s.length() % 2 != 0)
    return false;
  stack<char> st;
  for (int i = 0; i < s.length(); i++)
    st.push(s[i]);
  for (int i = 0; i < s.length() / 2; i++) {
    if (s[i] == '(' && st.top() == ')')
      st.pop();
    else if (s[i] == '{' && st.top() == '}')
      st.pop();
    else if (s[i] == '[' && st.top() == ']')
      st.pop();
    else
      return false;
  }
  return true;
}


// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

void printString(string& str) {
  cout << "[\"" << str << "\"]";
}

int test_case_number = 1;

void check(bool expected, bool output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printf("%s", expected ? "true" : "false");
    cout << " Your output: ";
    printf("%s", output ? "true" : "false");
    cout << endl; 
  }
  test_case_number++;
}

// (())
//(0001
//( 010
//)  00
//)   0
int longestValidParentheses (string s) {
  bool dp[s.length()][s.length()];
  int max_length = 0, j = 0;
  for (int i = 0; i < s.length(); i++) {
    while (j <= i) {
      dp[i][j] = false; j++;
    }

    if ((j = i + 1) && (j < s.length()) && (s[i] == '(') && (s[j] == ')')) {
      dp[i][j] = true;
      max_length = max(2, max_length);
    }
  }

  for (int i = s.length() - 3; i >= 0; i--) {
    for (j = 0; j < s.length(); j++) {
      if (s[i] == '(' && s[j] == ')') {
        dp[i][j] = true;
        max_length = max(max_length, j - i + 1);
      }
    }
  }
  return max_length;
}


vector<string> removeInvalidParentheses (string s) {
  int left = 0, right = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(')
      left++;
    else if (s[i] == ')' && left != 0)
      left--;
    else if (s[i] == ')' && left == 0)
      right++;
  }
}



int main() {

  string s_1 = "{[(])}";
  bool expected_1 = false;
  bool output_1 = isBalanced(s_1);
  check(expected_1, output_1);

  string s_2 = "{{[[(())]]}}";
  bool expected_2 = true;
  bool output_2 = isBalanced(s_2);
  check(expected_2, output_2);

  string s_3 = "{}()";
  bool expected_3 = true;
  bool output_3 = isBalanced(s_3);
  check(expected_3, output_3);
  
  string s = "(()"; cout << longestValidParentheses(s) << endl;
  return 0;
  
}