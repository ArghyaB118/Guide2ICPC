/*Given an array of strings strs, group the anagrams together.
You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters
 of a different word or phrase, typically using all the original
 letters exactly once.
*/
#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

vector<vector<string>> groupAnagrams (vector<string>& strs) {
    if (strs.empty())
        return {{}};
    vector<vector<string>> result;
    if (strs.size() == 1) {
        result.push_back(strs); return result;
    }
    unordered_map<string, vector<string>> hashmap;
    vector<string> tmpVec = {};
    for (int i = 0; i < strs.size(); i++) {
        string tmpStr = strs[i];
        sort(tmpStr.begin(), tmpStr.end());
        tmpVec.clear();
        if (hashmap.find(tmpStr) == hashmap.end()) {
            tmpVec.push_back(strs[i]);
            hashmap[tmpStr] = tmpVec;
        }
        else {
            hashmap[tmpStr].push_back(strs[i]);
        }
    }
    for (auto i : hashmap) {
        tmpVec.clear();
        for (int j = 0; j < i.second.size(); j++) {
            tmpVec.push_back(i.second[j]);
        }
        result.push_back(tmpVec);
    }
    return result;
}

void printResult (vector<vector<string>>& result) {
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main () {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result = groupAnagrams (strs);
    printResult(result);
}
