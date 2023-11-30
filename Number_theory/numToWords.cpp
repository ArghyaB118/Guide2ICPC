//
//  numToWords.cpp
//  
//
//  Created by Arghya Bhattacharya on 10/8/22.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, string> wordmap;

void make_words () {
    wordmap[0] = "";
    wordmap[00] = "";
    wordmap[000] = "";
    wordmap[1] = "One";
    wordmap[2] = "Two";
    wordmap[3] = "Three";
    wordmap[4] = "Four";
    wordmap[5] = "Five";
    wordmap[6] = "Six";
    wordmap[7] = "Seven";
    wordmap[8] = "Eight";
    wordmap[9] = "Nine";
    wordmap[10] = "Ten";
    wordmap[11] = "Eleven";
    wordmap[12] = "Twelve";
    wordmap[13] = "Thirteen";
    wordmap[14] = "Fourteen";
    wordmap[15] = "Fifteen";
    wordmap[16] = "Sixteen";
    wordmap[17] = "Seventeen";
    wordmap[18] = "Eighteen";
    wordmap[19] = "Nineteen";
    wordmap[20] = "Twenty";
    wordmap[30] = "Thirty";
    wordmap[40] = "Forty";
    wordmap[50] = "Fifty";
    wordmap[60] = "Sixty";
    wordmap[70] = "Seventy";
    wordmap[80] = "Eighty";
    wordmap[90] = "Ninety";
}

string make_hundreds (int n) {
    string s = "";
    if (n % 100 < 20)
        s = wordmap[n % 100];
    else {
        s = wordmap[n % 10];
        n -= n % 10;
        if (s.empty())
            s = wordmap[n % 100];
        else
            s = wordmap[n % 100] + " " + s;
    }
    n -= n % 100;
    n /= 100;
    if (n != 0) {
        if (s.empty())
            s = wordmap[n] + " Hundred";
        else
            s = wordmap[n] + " Hundred " + s;
    }
    return s;
}

string numberToWords (int n) {
    if (n == 0)
        return "Zero";
    make_words();
    vector<int> num;
    vector<string> words;
    string result = "";
    while (n != 0) {
        num.push_back(n % 1000);
        n /= 1000;
    }
    for (int i = 0; i < num.size(); i++) {
        words.push_back(make_hundreds(num[i]));
    }
    for (int i = 0; i < words.size(); i++) {
        if (!words[i].empty()) {
            if (result.empty()) {
                if (i == 0)
                    result = words[i];
                else if (i == 1)
                    result = words[i] + " Thousand";
                else if (i == 2)
                    result = words[i] + " Million";
                else if (i == 3)
                    result = words[i] + " Billion";
            }
            else {
                if (i == 0)
                    result = words[i] + " " + result;
                else if (i == 1)
                    result = words[i] + " Thousand " + result;
                else if (i == 2)
                    result = words[i] + " Million " + result;
                else if (i == 3)
                    result = words[i] + " Billion " + result;
            }
        }
    }
    return result;
}

int main () {
    int num = 1000000; // 2147483600; // 2147483647
    cout << num << " = " << numberToWords(num) << endl;
    return 0;
}
