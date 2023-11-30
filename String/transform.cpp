/* Problem 1: Transform A to B
 operation allowed: stream through A, insert it at the front if need be*/

#include <iostream>
#include <string.h>
#include <vector>
#include <unordered_map>
using namespace std;

bool transformable (string& A, string& B) {
	if (A.length() != B.length())
		return false;
	int count1[256], count2[256];
	memset(count1, 0, sizeof(count1));
	memset(count2, 0, sizeof(count2));
	for (int i = 0; i < A.length(); i++)
		count1[A[i]]++;
	for (int i = 0; i < B.length(); i++)
		count2[B[i]]++;
	for (int i = 0; i < 256; i++)
		if (count1[i] != count2[i])
			return false;
	return true;
}

int minOps (string& A, string& B) {
	if (A == B)
		return 0;
	int count = 0;
	while (A != B) {
		int len = A.length();
		for (int i = len - 1; i >= 0; i--) {
			while (A[i] != B[i]) {
				char c = B[i]; 
				// to do the only operation that is allowed
				B.erase(B.begin() + i); 
				B.insert(B.begin(), c);
				// to increase the count as we do the operation
				count++;
			}
		}
	}
	return count;
}

/* LC#2135
 You are given two 0-indexed arrays of strings startWords and targetWords. Each string consists of lowercase English letters only.
 
 For each string in targetWords, check if it is possible to choose a string from startWords and perform a conversion operation on it to be equal to that from targetWords.

 The conversion operation is described in the following two steps:

 Append any lowercase letter that is not present in the string to its end.
 For example, if the string is "abc", the letters 'd', 'e', or 'y' can be added to it, but not 'a'. If 'd' is added, the resulting string will be "abcd".
 Rearrange the letters of the new string in any arbitrary order.
 For example, "abcd" can be rearranged to "acbd", "bacd", "cbda", and so on. Note that it can also be rearranged to "abcd" itself.
 Return the number of strings in targetWords that can be obtained by performing the operations on any string of startWords.

 Note that you will only be verifying if the string in targetWords can be obtained from a string in startWords by performing the operations. The strings in startWords do not actually change during this process.
 
 Constraints:

 1 <= startWords.length, targetWords.length <= 5 * 104
 1 <= startWords[i].length, targetWords[j].length <= 26
 Each string of startWords and targetWords consists of lowercase English letters only.
 No letter occurs more than once in any string of startWords or targetWords.
 */

int wordCount (vector<string>& startWords, vector<string>& targetWords) {
    vector<string> result = {};
    vector<unordered_map<char, int>> targetWordMaps = {};
    for (auto i : targetWords) {
        unordered_map<char, int> tmp;
        for (auto j : i)
            tmp[j]++;
        targetWordMaps.push_back(tmp);
    }
    for (auto i : targetWordMaps)
        for (auto it = i.begin(); it != i.end(); it++)
            cout << it->first << " " << it->second << endl;
    
    for (auto i : startWords) {
        for (int j = 0; j < targetWords.size(); j++) {
            if (find(result.begin(), result.end(), i) == result.end()) {
                if (targetWords[j].length() == i.length() + 1) {
                    unordered_map<char, int> tmp = targetWordMaps[j];
                    // int count = 0;
                    bool b = true;
                    for (auto k : i) // {
                        if (tmp.find(k) == tmp.end())
                            b = false;
                            // count++;
                    // }
                    //if (count <= 1)
                    if (b)
                        result.push_back(i);
                }
            }
        }
    }
    for (auto i : result)
        cout << i << endl;
    return result.size();
}

int main () {
	string A = "EACBD";
	string B = "EBACD";
	cout << boolalpha << transformable(A, B) << endl;
	if (transformable(A, B))
		cout << minOps(A, B) << endl;
    
    vector<string> startWords = {"ant","act","tack"}, targetWords = {"tack","act","acti"};
    // startWords = {"lhum","bim","cyjhm","h","a","ljxd","run","zrl","dmf","y"}, targetWords = {"da","lzkr","uzc","jdxlz","yt","emdf"};
    cout << wordCount (startWords, targetWords) << endl;
	return 0;
}
