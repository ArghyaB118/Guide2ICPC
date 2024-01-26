/* LC#408

A string can be abbreviated by replacing 
any number of non-adjacent, 
non-empty substrings with their lengths. 
The lengths should not have leading zeros.

For example, a string such as "substitution" 
could be abbreviated as (but not limited to):

"s10n" ("s ubstitutio n")
"sub4u4" ("sub stit u tion")
"12" ("substitution")
"su3i1u2on" ("su bst i t u ti on")
"substitution" (no substrings replaced)

a string word and an abbreviation abbr, 
return whether the string matches the given abbreviation.

A substring is a contiguous non-empty sequence 
of characters within a string.
*/
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

// beats 100% LC users
bool validAbbreviationOptimized (string word, string abbr) {
//	cout << word << " " << abbr << endl;
	if (abbr.length() == 0 && word.length() == 0)
		return true;
	else if (abbr.length() == 0 || word.length() == 0)
		return false;
	else if (abbr.length() > word.length())
		return false;
	else if (word == abbr)
		return true;
	int word_index = 0, abbr_index = 0;
	string tmp;
	while (abbr_index < abbr.length()) {
		// cout << abbr_index << endl;
		//if (i == word.length())
		//	return false;
		if (isalpha(abbr[abbr_index]) && abbr[abbr_index] != word[word_index])
			return false;
		else if (isdigit(abbr[abbr_index])) {
			tmp.clear(); tmp.push_back(abbr[abbr_index]);
			if (stoi(tmp) == 0)
				return false;
			abbr_index++;
			while (isdigit(abbr[abbr_index]) == true && abbr_index < abbr.length()) {
				tmp.push_back(abbr[abbr_index]); abbr_index++;
			}
			// cout << tmp << endl;
			int tmpnum = stoi(tmp);
			if (word.length() < word_index + tmpnum)
				return false;
			else {
				word_index += tmpnum;
			}
			// return validAbbreviation(word.substr(i + stoi(tmp) - tmp.length(),word.length()), abbr.substr(i,abbr.length()));
		}
		else if (isalpha(abbr[abbr_index]) && abbr[abbr_index] == word[word_index]) {
			word_index++; abbr_index++;
		}
	}
	if (word_index == word.length())
		return true;
	return false;
}

typedef pair<string, string> testPair;

int main () {
	vector<testPair> test = {make_pair("substitution", "s10n"), make_pair("a", "01"), make_pair("sargdfg", "s3d2")};
	test.push_back(make_pair("hi", "hi1"));
	test.push_back(make_pair("hi", "1"));	
	for (testPair & t : test)
		cout << boolalpha << validAbbreviationOptimized(t.first, t.second) << endl;
}