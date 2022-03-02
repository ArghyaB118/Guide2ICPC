/*
Matching Pairs

Given two strings s and t of length N, find the maximum number of possible 
matching pairs in strings s and t after swapping exactly two characters within s.

A swap is switching s[i] and s[j], where s[i] and s[j] denotes the character 
that is present at the ith and jth index of s, respectively. 
The matching pairs of the two strings are defined as the number of indices 
for which s[i] and t[i] are equal.

Note: This means you must swap two characters at different indices.

Example 1
s = "abcd"
t = "adcb"
output = 4

Example 2
s = "mno"
t = "mno"
output = 1
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

int matchingPairs(string s, string t) {
  if (s == t)
  	return s.length() - 2;
  string temp1, temp2;
  int count = 0;
  for (int i = 0; i < s.length(); i++) {
  	if (s[i] == t[i])
  		count++;
  	else {
  		temp1.push_back(s[i]);
  		temp2.push_back(t[i]);
  	}
  }
  sort(temp1.begin(), temp1.end());
  sort(temp2.begin(), temp2.end());
  int count2 = 0;
  for (int i = 0; i < temp1.length(); i++)
  	if (temp1[i] == temp2[i])
  		count2++;
  count = count + count2 % 3;
  return count;
}

/*
Making Anagrams:
You are given two strings of the same length s and t. 
In one step you can choose any character of t and replace it with another character.

Return the minimum number of steps to make t an anagram of s.

An Anagram of a string is a string that contains the same characters 
with a different (or the same) ordering.
*/

int minStepsAnagram(string s, string t) {
  map<char, int> m1, m2;
  for(int i = 0; i < 26; ++i) {
    m1.insert(make_pair(static_cast<char>('a' + i), i));
    m2.insert(make_pair(static_cast<char>('a' + i), i));
  }
  for (int i = 0; i < s.length(); i++) {
    m1[s[i]]++;
    m2[t[i]]++;
  }
  int minSteps = 0;
  for (int i = 0; i < 26; ++i)
    minSteps += abs(m1[static_cast<char>('a' + i)] - m2[static_cast<char>('a' + i)]);
  
  return minSteps / 2;
}


int main () {
	string s = "abcd", t = "adcb";
//	string s = "mno", t = "mno";
	cout << matchingPairs(s, t) << endl;
  cout << minStepsAnagram(s, t) << endl;
	return 0;
}