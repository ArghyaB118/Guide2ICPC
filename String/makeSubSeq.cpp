/* LC#2486
 
 You are given two strings s and t consisting of only lowercase English letters.
 
 Return the minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s.

 A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
 
 Input: s = "coaching", t = "coding"
 Output: 4
 Explanation: Append the characters "ding" to the end of s so that s = "coachingding".
 Now, t is a subsequence of s ("coachingding").
 It can be shown that appending any 3 characters to the end of s will never make t a subsequence.
 
 Input: s = "abcde", t = "a"
 Output: 0
 Explanation: t is already a subsequence of s ("abcde").
 
 Input: s = "z", t = "abcde"
 Output: 5
 Explanation: Append the characters "abcde" to the end of s so that s = "zabcde".
 Now, t is a subsequence of s ("zabcde").
 It can be shown that appending any 4 characters to the end of s will never make t a subsequence.*/

#include <iostream>
#include <string>
using namespace std;

int appendCharacters (string s, string t) {
    int i = 0, j = 0;
    while (i < s.length() && j < t.length()) {
        if (s[i] == t[j]) {
            i++; j++;
        }
        else {
            i++;
        }
    }
    return t.length() - j;
}

int main () {
    string s = "zbc", t = "abc";
    // string s = "coaching", t = "coding";
    cout << appendCharacters (s, t) << endl;
    return 0;
}
