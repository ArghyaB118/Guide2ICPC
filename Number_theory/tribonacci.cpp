/* LC#1137
N-th Tribonacci Number:
The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.
*/

#include <iostream>
#include <vector>
using namespace std;

int tribonacci(int n) {
	vector<int> dp = {0, 1, 1};
	if (n <= 2)
		return dp[n];
	for (int i = 3; i <= n; i++)
		dp.push_back(dp[i - 3] + dp[i - 2] + dp[i - 1]);
	return dp.back();
}

int main () {
	cout << tribonacci (5) << endl;
	return 0;
}