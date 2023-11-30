/*An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:
 
 'A': Absent.
 'L': Late.
 'P': Present.
 Any student is eligible for an attendance award if they meet both of the following criteria:

 The student was absent ('A') for strictly fewer than 2 days total.
 The student was never late ('L') for 3 or more consecutive days.
 Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. The answer may be very large, so return it modulo 10^9 + 7.

*/

#include <iostream>
using namespace std;

int checkRecord (int n) {
    if (n == 0)
        return 1;
    int dp[max(5,n)];
    dp[0] = 1;
    dp[1] = 2; // L P
    dp[2] = 4; // LL LP PL PP
    dp[3] = 7; // LLP LPL LPP PLL PLP PPL PPP
    dp[4] = 2*7 - 1; // LLP(PL) LPL(PL) ... PLL(P)
    // Recursion: f(n) = 2 * f(n - 1) - f(n - 4)
    if (n <= 5)
        return dp[n] + n * dp[n - 1];
    for (int i = 5; i <= n; i++)
        dp[i] = (2 * dp[i - 1] - dp[i - 4]) % 1000000007;
    return (dp[n] + n * dp[n - 1]) % 1000000007;
}

int main () {
    cout << checkRecord(100) << endl;
    return 0;
}
