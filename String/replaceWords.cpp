/* LC#648
 
 In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word successor. For example, when the root "an" is followed by the successor word "other", we can form a new word "another".
 
 Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the successors in the sentence with the root forming it. If a successor can be replaced by more than one root, replace it with the root that has the shortest length.

 Return the sentence after the replacement.
 
 Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
 Output: "the cat was rat by the bat"
 
 Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
 Output: "a a b c"
 
 Constraints:

 1 <= dictionary.length <= 1000
 1 <= dictionary[i].length <= 100
 dictionary[i] consists of only lower-case letters.
 1 <= sentence.length <= 106
 sentence consists of only lower-case letters and spaces.
 The number of words in sentence is in the range [1, 1000]
 The length of each word in sentence is in the range [1, 1000]
 Every two consecutive words in sentence will be separated by exactly one space.
 sentence does not have leading or trailing spaces.*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

string replaceWords (vector<string>& dictionary, string sentence) {
    unordered_set<string> dict;
    for (string d : dictionary)
        dict.insert(d);
    
    string s = "", tmp = "";
    int i = 0;
    while (i < sentence.length()) {
        if (sentence[i] != ' ') {
            tmp.push_back(sentence[i]);
            if (dict.find(tmp) != dict.end()) {
                if (s.length() == 0)
                    s = s + tmp;
                else
                    s = s + " " + tmp;
                tmp.clear();
                while (sentence[i] != ' ' && i < sentence.length()) {
                    i++;
                }
                // else {
                   // i++; break;
                // }
            }
        }
        else if (sentence[i] == ' '){
            cout << i << endl;
            if (s.length() == 0)
                s = s + tmp;
            else
                s = s + " " + tmp;
            tmp.clear();
        }
        if (i == sentence.length() - 1)
            s = s + " " + tmp;
        i++;
    }
    return s;
}

int main () {
    vector<string> dictionary = {"cat","bat","rat"};
    string sentence = "the cattle was rattled by the battery";
    string s = replaceWords (dictionary, sentence);
    cout << s << endl;
    return 0;
}
