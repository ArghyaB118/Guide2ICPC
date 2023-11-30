/*
 In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either replacing one occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR". Given the starting string start and the ending string end, return True if and only if there exists a sequence of moves to transform one string to the other.
 
 Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
 Output: true
 Explanation: We can transform start to end following these steps:
 RXXLRXRXL ->
 XRXLRXRXL ->
 XRLXRXRXL ->
 XRLXXRRXL ->
 XRLXXRRLX
 
 Input: start = "X", end = "L"
 Output: false
 
 Idea: The relative order matters!
 Allowed moves:
 XL -> LX
 RX -> XR
*/

#include <iostream>
#include <string>
using namespace std;

bool canTransformAllSwaps (string start, string end) {
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
    for (char c : start) {
        if (c == 'L')
            count1++;
        else if (c == 'R')
            count2++;
    }
    for (char c : end) {
        if (c == 'L')
            count3++;
        else if (c == 'R')
            count4++;
    }
    if (count1 != count3 || count2 != count4)
        return false;
    int i = 0, j = 0;
    while (i < start.length() && j < end.length()) {
        if (start[i] == 'X')
            i++;
        else if (end[j] == 'X')
            j++;
        else if ((start[i] == 'L' && end[j] == 'R') || (start[i] == 'R' && end[j] == 'L'))
            return false;
        else if ((start[i] == 'L' && end[j] == 'L') || (start[i] == 'R' && end[j] == 'R')) {
            i++; j++;
        }
    }
    if (i - j > 1 || j - i > 1)
        return false;
    return true;
}

bool canTransform (string start, string end) {
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
    for (char c : start) {
        if (c == 'L')
            count1++;
        else if (c == 'R')
            count2++;
    }
    for (char c : end) {
        if (c == 'L')
            count3++;
        else if (c == 'R')
            count4++;
    }
    if (count1 != count3 || count2 != count4)
        return false;
    int i = 0, j = 0;
    while (i < start.length() && j < end.length()) {
        if (start[i] == 'X')
            i++;
        else if (end[j] == 'X')
            j++;
        else if ((start[i] == 'L' && end[j] == 'R') || (start[i] == 'R' && end[j] == 'L'))
            return false;
        /*else if ((start[i] == 'L' && end[j] == 'L') || (start[i] == 'R' && end[j] == 'R')) {
            i++; j++;
        }*/
        // adding extra logic
        else if ((start[i] == 'L' && end[j] == 'L') && (i >= j)) {
            i++; j++;
        }
        else if ((start[i] == 'R' && end[j] == 'R') && (i > j)) {
            i++; j++;
        }
        else if ((start[i] == 'L' && end[j] == 'L') && (i < j))
            return false;
        else if ((start[i] == 'R' && end[j] == 'R') && (i > j))
            return false;
    }
    return true;
}

int main () {
    string start = "XXXLXXXXXX", end = "XXXLXXXXXX";
    // start = "LXXLXRLXXL", end = "XLLXRXLXLX";
    // start = "X", end = "L"; // start = "RXXLRXRXL", end = "XRLXXRRLX";
    cout << boolalpha << canTransform (start, end) << endl;
    return 0;
}
