#include<iostream>
#include <string>
using namespace std;

bool validAbbreviation (string word, string abbr) {
	for (int i = 0; i < abbr.length(); i++) {
		if (isalpha(abbr[i]) && abbr[i] != word[i])
			return false;
		else if (isinteger(abbr[i]))
			return validAbbreviation(word.substr(i,word.length()), word.substr(i,word.length()));
	}
	return ;
}

int main () {
	string s = "substitution", t = "s10n";
	cout << boolalpha << validAbbreviation(s, t) << endl;
}