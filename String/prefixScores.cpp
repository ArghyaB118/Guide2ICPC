/*You are given an array words of size n consisting of non-empty strings.
 
 We define the score of a string word as the number of strings words[i] such that word is a prefix of words[i].

 For example, if words = ["a", "ab", "abc", "cab"], then the score of "ab" is 2, since "ab" is a prefix of both "ab" and "abc".
 Return an array answer of size n where answer[i] is the sum of scores of every non-empty prefix of words[i].

 Note that a string is considered as a prefix of itself.
 
 Input: words = ["abc","ab","bc","b"]
 Output: [5,4,3,2]
 Explanation: The answer for each string is the following:
 - "abc" has 3 prefixes: "a", "ab", and "abc".
 - There are 2 strings with the prefix "a", 2 strings with the prefix "ab", and 1 string with the prefix "abc".
 The total is answer[0] = 2 + 2 + 1 = 5.
 - "ab" has 2 prefixes: "a" and "ab".
 - There are 2 strings with the prefix "a", and 2 strings with the prefix "ab".
 The total is answer[1] = 2 + 2 = 4.
 - "bc" has 2 prefixes: "b" and "bc".
 - There are 2 strings with the prefix "b", and 1 string with the prefix "bc".
 The total is answer[2] = 2 + 1 = 3.
 - "b" has 1 prefix: "b".
 - There are 2 strings with the prefix "b".
 The total is answer[3] = 2.
 
 Input: words = ["abcd"]
 Output: [4]
 Explanation:
 "abcd" has 4 prefixes: "a", "ab", "abc", and "abcd".
 Each prefix has a score of one, so the total is answer[0] = 1 + 1 + 1 + 1 = 4.*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;



bool prefix (string prefix, string word) {
    if (prefix.length() > word.length())
        return false;
    for (int i = 0; i < prefix.length(); i++)
        if (prefix[i] != word[i])
            return false;
    return true;
}

vector<int> sumPrefixScores (vector<string>& words) {
    unordered_map<string, int> scoreDict;
    vector<int> scores = {};
    for (int j = 0; j < words.size(); j++) {
        string word = words[j];
        vector<string> tmpVec = {};
        string tmp = "";
        for (int i = 0; i < word.length(); i++) {
            tmp.push_back(word[j]);
            tmpVec.push_back(tmp);
        }
        int num = tmpVec.size();
        for (string s : tmpVec) {
            if (scoreDict.find(s) != scoreDict.end())
                num += scoreDict[s];
            else {
                int tmpnum = 0;
                for (int i = 0; i != j && i < words.size(); i++)
                    if (prefix(s, words[i]))
                        tmpnum++;
                scoreDict[s] = tmpnum;
                num += tmpnum;
            }
            // cout << num << endl;
        }
        scores.push_back(num);
    }
    return scores;
}

int main () {
    vector<string> words = {"abc","ab","bc","b"};
    vector<int> scores = sumPrefixScores (words);
    for (int i : scores)
        cout << i << " ";
    cout << endl;
    return 0;
}
