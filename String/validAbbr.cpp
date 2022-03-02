#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool validAbbreviation (string word, string abbr) {
//	cout << word << " " << abbr << endl;
	if (abbr.length() == 0 && word.length() == 0)
		return true;
	else if (abbr.length() != 0 && word.length() == 0)
		return false;
	else if (abbr.length() == 0 && word.length() != 0)
		return false;

	int i = 0;
	string tmp;
	while (i < abbr.length()) {
//		cout << i << endl;
		if (i == word.length())
			return false;
		if (isalpha(abbr[i]) && abbr[i] != word[i])
			return false;
		else if (isdigit(abbr[i])) {
			tmp.clear();
			tmp.push_back(abbr[i]);
			if (stoi(tmp) == 0)
				return false;
			i++;
			while (isdigit(abbr[i]) == true) {
				tmp.push_back(abbr[i]); i++;
			}
//			cout << tmp << endl;
			if (word.length() < stoi(tmp))
				return false;
			return validAbbreviation(word.substr(i + stoi(tmp) - tmp.length(),word.length()), abbr.substr(i,abbr.length()));
		}
		i++;
	}
	return true;
}

typedef pair<string, string> testPair;

int main () {
	vector<testPair> test = {make_pair("substitution", "s10n"), make_pair("a", "01")};
	test.push_back(make_pair("hi", "hi1"));
	for (testPair & t : test)
		cout << boolalpha << validAbbreviation(t.first, t.second) << endl;
}