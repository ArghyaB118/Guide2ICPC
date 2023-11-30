// Given a string columnTitle that represents the column title as
// appears in an Excel sheet, return its corresponding column number.

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int titleToNumber(string s) {
    int num = 0;
    for (char i : s) {
        num *= 26;
        num += ((int)i - 64);
    }
    return num;
}

int main () {
    string columnTitle = "ZY"; // "FXSHRXW";
    cout << columnTitle << " = " << titleToNumber(columnTitle) << endl;
    return 0;
}
