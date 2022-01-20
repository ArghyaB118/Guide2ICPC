/*
In an alien language, surprisingly, they also use English lowercase letters, 
but possibly in a different order. The order of the alphabet is some 
permutation of lowercase letters.

Given a sequence of words written in the alien language, 
and the order of the alphabet, return true if and only if the 
given words are sorted lexicographically in this alien language.

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// Idea: Create a hashmap of chars and ranks from the dictionary.
// Compare each 2 contiguous words. 
// Compare the indexes of the correposnding chars in the 2 words.
// Return false for any mistake.
bool isAlienSorted(vector<string>& words, string order) {
	unordered_map<char, int> dict;
	for (int i = 0; i < order.length(); i++)
		dict.insert({order[i], i});
//	for (auto & m : dict)
//		cout << m.first << m.second << endl;
	for (int i = 1; i < words.size(); i++) {
		if (words[i].length() < words[i - 1].length())
			if (words[i - 1].substr(0, words[i].length()) == words[i])
				return false; 
		for (int j = 0; j < min(words[i].length(), words[i - 1].length()); j++)
			if (dict[words[i][j] < dict[words[i - 1][j]]])
				return false;
	}
	return true;
}

int main () {
	vector<string> words = {"word","world","row"}; //{"apple","app"};
	string order = "worldabcefghijkmnpqstuvxyz"; //"abcdefghijklmnopqrstuvwxyz";
	cout << boolalpha << isAlienSorted(words, order) << endl;
	return 0;
}