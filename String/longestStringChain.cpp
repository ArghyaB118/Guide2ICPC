/* LC#1048
 
 You are given an array of words where each word consists of lowercase English letters.
 
 wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

 For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
 A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

 Return the length of the longest possible word chain with words chosen from the given list of words.

 Input: words = ["a","b","ba","bca","bda","bdca"]
 Output: 4
 Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
 
 Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
 Output: 5
 Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
 
 Input: words = ["abcd","dbqca"]
 Output: 1
 Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
 ["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

// if s = "ab" and t = "adb" or "dab" or "abd", return true
// if s = "ab" and t = "bad", return false
bool isPredecessor (string s, string t) {
    return true;
}

int DFS (string s, vector<vector<string>>& wordvec) {
    if (s.length() == 16)
        return 1;
    int tmp = 0;
    queue<string> q; q.push(s);
    while (!q.empty()) {
        string t = q.front(); q.pop(); tmp = (tmp > t.length()) ? tmp : t.length();
        if (wordvec[t.length()].size() > 0) {
            for (auto j : wordvec[t.length()]) {
                if (isPredecessor(t, j))
                    q.push(j);
            }
        }
    }
    return tmp;
}


int longestStrChain (vector<string>& words) {
    vector<vector<string>> wordvec (16, vector<string> {});
    for (auto s : words)
        wordvec[s.length() - 1].push_back(s);
    int num = 0;
    for (int i = 0; i < 16; i++) {
        for (auto j : wordvec[i]) {
            num = max(num, DFS(j, wordvec));
        }
    }
    return 0;
}

int main () {
    vector<string> words = {"a","b","ba","bca","bda","bdca"};
    cout << longestStrChain(words) << endl;
    return 0;
}
