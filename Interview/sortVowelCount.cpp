/* Input: a text in string format
 Task:
 1. get the words separated by space as delimiter.
 2. for each word, count abs(#vowels - #consonants)
 3. sort the words by this count in ascending order
 4. tie break alphabetically.
 
 max length of the input text = 1000*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int countVowels (string tmp) {
    int a = 0, b = 0;
    for (auto i : tmp) {
        if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u')
            a++;
        else
            b++;
    }
    return (a >= b) ? (a - b) : (b - a);
}

vector<string> sortByVowel (string text) {
    string tmp = "";
    vector<vector<string>> v (1000, vector<string> {});
    vector<string> result = {};
    for (int i = 0; i < text.length(); i++) {
        if (text[i] != ' ')
            tmp.push_back(text[i]);
        else if (text[i] == ' ') {
            int count = countVowels (tmp);
            v[count].push_back(tmp);
            tmp = "";
        }
    }
    if (tmp != "") {
        int count = countVowels (tmp);
        v[count].push_back(tmp);
    }
    
    /*for (auto i : v) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }*/
    
    for (auto i : v) {
        sort (i.begin(), i.end());
        for (auto j : i)
            result.push_back(j);
    }
    return result;

}

int main () {
    string text = "i am a bad boy";
    vector<string> res = sortByVowel (text);
    for (auto i : res)
        cout << i << " ";
    cout << endl;
    
    // test
    vector<string> a {"a", "i", "aa", "bb"};
    sort (a.begin(), a.end());
    for (auto i : a)
        cout << i << " ";
    cout << endl;
    return 0;
}
