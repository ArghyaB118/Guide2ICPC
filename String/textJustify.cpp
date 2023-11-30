/* LC#68
 
 Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.
 
 You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

 Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

 For the last line of text, it should be left-justified, and no extra space is inserted between words.

 Note:

 A word is defined as a character sequence consisting of non-space characters only.
 Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
 The input array words contains at least one word.
 
 Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string lastlinejustify (vector<string>& tmp, int maxWidth) {
    string result = "";
    for (auto i : tmp)
        result = result + i + " ";
    return result;
}

string justify (vector<string>& tmp, int maxWidth) {
    // cout << "here" << endl;
    int wordCount = 0, letterCount = 0;
    for (auto i : tmp) {
        wordCount++;
        letterCount += i.length();
    }
    vector<int> gaps (wordCount - 1, (maxWidth - letterCount) / (wordCount - 1));
    for (int i = 0; i < (maxWidth - letterCount) % (wordCount - 1); i++)
        gaps[i]++;
    gaps.push_back(0);
    /*for (int i : gaps)
        cout << i << endl;
    for (auto i : tmp)
        cout << i << endl;*/
    string result = "";
    for (int i = 0; i < tmp.size(); i++) {
        string gap (gaps[i], ' ');
        result = result + tmp[i] + gap;
    }
    return result;
}

vector<string> fullJustify (vector<string>& words, int maxWidth) {
    int i = 0, budget = maxWidth;
    vector<string> result = {}, tmp = {};
    while (i < words.size()) {
        if (budget > 0 && words[i].length() <= budget) {
            tmp.push_back(words[i]);
            budget = budget - words[i].length() - 1;
            i++;
        }
        else {
            result.push_back(justify (tmp, maxWidth));
            budget = maxWidth;
            tmp.clear();
        }
    }
    if (!tmp.empty())
        result.push_back(lastlinejustify (tmp, maxWidth));
    return result;
}

int main () {
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    vector<string> result = fullJustify (words, maxWidth);
    for (auto i : result)
        cout << i << endl;
    return 0;
}
