/*  LC#2484
 
 Given a string of digits s, return the number of palindromic subsequences of s having length 5. Since the answer may be very large, return it modulo 109 + 7.
 
 Note:

 A string is palindromic if it reads the same forward and backward.
 A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
 
 Input: s = "103301"
 Output: 2
 Explanation:
 There are 6 possible subsequences of length 5: "10330","10331","10301","10301","13301","03301".
 Two of them (both equal to "10301") are palindromic.*/

#include <iostream>
#include <string>
using namespace std;

int countPalindromes (string s) {
    if (s.length() < 5)
        return 0;
    else if (s.length() == 5) {
        if (s[0] == s[4] && s[1] == s[3])
            return 1;
        return 0;
    }
    int count = 0;
    for (int i = 0; i < s.length() - 4; i++) {
        for (int j = i + 1; j < s.length() - 3; j++) {
            for (int k = s.length() - 1; k >= j + 3; k--) {
                for (int l = k - 1; l >= j + 2; l--) {
                    if (s[i] == s[k] && s[j] == s[l])
                        count += (l - j - 1);
                }
            }
        }
    }
    return count % 1000000007;
}

int main () {
    string s  = "103301";
    cout << countPalindromes (s) << endl;
    return 0;
}
