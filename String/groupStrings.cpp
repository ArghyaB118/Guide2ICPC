/* LC#249

We can shift a string by shifting 
each of its letters to its successive letter.

For example, "abc" can be shifted to be "bcd".
We can keep shifting the string to form a sequence.

For example, we can keep shifting "abc" 
to form the sequence: "abc" -> "bcd" -> ... -> "xyz".
Given an array of strings strings, 
group all strings[i] that belong 
to the same shifting sequence. 
You may return the answer in any order.

Input: strings = ["abc","bcd","acef","xyz","az","ba","a","z"]
Output: [["acef"],["a","z"],["abc","bcd","xyz"],["az","ba"]]
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isShifted(string& s, string& t) {
	// cout << "here " << s << t << endl;
	if (s.length() != t.length())
		return false;
	if (s == t)
        return true;
	int dist = (int)t[0] - (int)s[0];
	for (int i = 0; i < s.length(); i++) {
		int shifted = (int)s[i] + dist;
		if (shifted >= 97 && shifted <= 122)
			s[i] = static_cast<char>(shifted);
		else if (shifted < 97)
			s[i] = static_cast<char>(shifted + 26);
		else if (shifted > 122)
			s[i] = static_cast<char>(shifted - 26);
		if (s[i] != t[i])
			return false;
	}
	// cout << "here " << s << endl;
	if (s == t) 
		return true;
	return false;
}

vector<vector<string>> groupStrings(vector<string>& strings) {
	vector<bool> included (strings.size(), false);
	vector<vector<string>> result;
	for (int i = 0; i < strings.size(); i++) {
		if (included[i])
			continue;
		vector<string> tmp = {strings[i]};
		included[i] = true;
		for (int j = 0; j < strings.size(); j++) {
			if (j == i || included[j])
				continue;
			if (isShifted(strings[i], strings[j])) {
				tmp.push_back(strings[j]); 
				included[j] = true;
			}
		}
		result.push_back(tmp);
	}
	return result;
}

int main () {
	vector<string> strings = 
	// {"fpbnsbrkbcyzdmmmoisaa","cpjtwqcdwbldwwrryuclcngw","a","fnuqwejouqzrif","js","qcpr","zghmdiaqmfelr","iedda","l","dgwlvcyubde","lpt","qzq","zkddvitlk","xbogegswmad","mkndeyrh","llofdjckor","lebzshcb","firomjjlidqpsdeqyn","dclpiqbypjpfafukqmjnjg","lbpabjpcmkyivbtgdwhzlxa","wmalmuanxvjtgmerohskwil","yxgkdlwtkekavapflheieb","oraxvssurmzybmnzhw","ohecvkfe","kknecibjnq","wuxnoibr","gkxpnpbfvjm","lwpphufxw","sbs","txb","ilbqahdzgij","i","zvuur","yfglchzpledkq","eqdf","nw","aiplrzejplumda","d","huoybvhibgqibbwwdzhqhslb","rbnzendwnoklpyyyauemm"};
	{"abc","bcd", "acef","xyz","az","ba","a","z","lpt","txb"};
	vector<vector<string>> result = groupStrings(strings);
	for (auto &i : result) {
		for (auto &j : i)
			cout << j << " ";
		cout << endl;
	}
	return 0;
}