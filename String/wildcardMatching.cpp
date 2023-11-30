/*Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
 
 '?' Matches any single character.
 '*' Matches any sequence of characters (including the empty sequence).
 The matching should cover the entire input string (not partial).*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

bool isMatch (string s, string p) {
    int n = s.length(), m = p.length(), i = 0, j = 0;
    while (i < n && j < m) {
        if (s[i] != p[j] && s[i] != '?' && p[j] != '?')
            return false;
        else if (s[i] == p[j] && s[i] != '*' && p[j] != '*') {
            i++; j++;
        }
        else if (s[i] == '*' || p[j] == '*')
            return true;
    }
    if (i == n - 1 && j == m - 1)
        return true;
    return false;
}

int main () {
    cout << boolalpha << isMatch ("*", "cp") << endl;
    return 0;
}
