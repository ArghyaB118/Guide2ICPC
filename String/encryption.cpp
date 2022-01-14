/*
Encrypted Words

You've devised a simple encryption method for alphabetic strings that shuffles the characters in such a way that the resulting string is hard to quickly read, but is easy to convert back into the original string.
When you encrypt a string S, you start with an initially-empty resulting string R and append characters to it as follows:
Append the middle character of S (if S has even length, then we define the middle character as the left-most of the two central characters)
Append the encrypted version of the substring of S that's to the left of the middle character (if non-empty)
Append the encrypted version of the substring of S that's to the right of the middle character (if non-empty)
For example, to encrypt the string "abc", we first take "b", and then append the encrypted version of "a" (which is just "a") and the encrypted version of "c" (which is just "c") to get "bac".
If we encrypt "abcxcba" we'll get "xbacbca". That is, we take "x" and then append the encrypted version "abc" and then append the encrypted version of "cba".
*/

#include <iostream>
#include <string>
#include <vector>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here
string encryptionRecur(string s, string c) {
//  cout << s << " " << c << endl;
  if (s.length() == 0)
    return c;
  else if (s.length() == 1) {
    c.push_back(s[0]);
    return c;
  }
  else if (s.length() == 2) {
    c.push_back(s[0]);
    c = encryptionRecur(s.substr(1,1), c);
    return c;
  }
  else if (s.length() > 2 && s.length() % 2 == 0) {
    c.push_back(s[s.length() / 2 - 1]);
    c = encryptionRecur(s.substr(0, s.length() / 2 - 1),c);
    c = encryptionRecur(s.substr(s.length() / 2, s.length()),c);
    return c;
  }
  else if (s.length() > 1 && s.length() % 2 != 0) {
    c.push_back(s[s.length() / 2]);
    c = encryptionRecur(s.substr(0, s.length() / 2),c);
    c = encryptionRecur(s.substr(s.length() / 2 + 1, s.length()),c);
    return c;
  }
  return c;
}

string findEncryptedWord(string s) {
  // Write your code here
  string c; 
  c = encryptionRecur(s, c);
  return c;
}


/*
To decode an encoded message, all the digits must be grouped then mapped 
back into letters using the reverse of the mapping above (there may be multiple ways). 
For example, "11106" can be mapped into:
'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped 
into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.
*/

// KJF -> 11 10 6 -> 2 
int numDecodings(string s) {
  vector<int> encrypted;
  for (int i = 0; i < s.length(); i++) {
    encrypted.push_back(int(s[i]) - 64);
  }
  int dp[encrypted.size()];
  dp[0] = (encrypted[0] > 10) ? 2 : 1;
  if (encrypted.size() == 1)
    return dp[0];
  else {
    for (int i = 1; i < encrypted.size(); i++) {
      if (encrypted[i] <= 10)
        dp[i] = dp[i - 1];
      else {
        if (encrypted[i - 1] < 10)
          dp[i] = dp[i - 1] + 2;
        else if (encrypted[i - 1] == 10)
          dp[i] = dp[i - 1] + 1;
        else
          dp[i] = dp[i - 1] + 2;
      }
    }
  }  
  return dp[encrypted.size() - 1];
}

// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

void printString(string& str) {
  cout << "[\"" << str << "\"]";
}

int test_case_number = 1;

void check(string& expected, string& output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << " Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << " Test #" << test_case_number << ": Expected ";
    printString(expected); 
    cout << " Your output: ";
    printString(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {

  string s_1 = "abc";
  string expected_1 = "bac";
  string output_1 = findEncryptedWord(s_1);
  check(expected_1, output_1);

  string s_2 = "abcd";
  string expected_2 = "bacd";
  string output_2 = findEncryptedWord(s_2);
  check(expected_2, output_2);

  // Add your own test cases here
  cout << numDecodings("KJF") << endl;
}