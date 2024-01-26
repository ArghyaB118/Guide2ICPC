#include <iostream>
#include <string>
using namespace std;

bool isSubsequence(string s, string t) {
	int i = 0, j = 0;
	while (i < s.length() && j < t.length()) {
		if (s[i] == t[j]) {
			i++; j++;
		}
		else
			j++;
	}
	if (i == s.length())
		return true;
	return false;
}

int main () {
	string s = "ace", t = "abcde";
	cout << boolalpha << isSubsequence(s, t) << endl;
	return 0;
}