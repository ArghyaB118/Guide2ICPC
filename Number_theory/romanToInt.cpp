//
//  romanToInt.cpp
//  
//
//  Created by Arghya Bhattacharya on 10/8/22.
//

#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int romanToInt (string s) {
    unordered_map<char, int> numbers;
    numbers['I'] = 1;
    numbers['V'] = 5;
    numbers['X'] = 10;
    numbers['L'] = 50;
    numbers['C'] = 100;
    numbers['D'] = 500;
    numbers['M'] = 1000;
    int num = 0;
    for (int i = 0; i < s.length() - 1; i++) {
        if (numbers[s[i]] >= numbers[s[i + 1]])
            num += numbers[s[i]];
        else
            num -= numbers[s[i]];
    }
    num += numbers[s[s.length() - 1]];
    return num;
}

int main () {
    string s = "LVIII";
    cout << s << " = " << romanToInt(s) << endl;
    return 0;
}
