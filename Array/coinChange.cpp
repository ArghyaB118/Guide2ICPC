/* LC#322

You are given an integer array coins representing coins of 
different denominations and an integer amount representing
a total amount of money.

Return the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination 
of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.
*/

#include <iostream>
#include <vector>
using namespace std;

#define MAX 10000

int coinChange(vector<int>& coins, int amount) {
	if (amount == 0)
		return 0;
	if (coins.size() == 1)
		return (amount % coins[0] == 0) ? (amount / coins[0]) : -1;
	vector<int> dp(amount + 1, -1);
	dp[0] = 0;
	for (int &coin : coins) {
		if (amount >= coin) {
			dp[coin] = 1;
		}
	}
	for (int i = 1; i <= amount; i++) {
		if (dp[i] == -1) {
			int tmp = MAX;
			for (auto &coin: coins) {
				if (i - coin >= 1 && dp[i - coin] > 0) {
					tmp = min(tmp, dp[i - coin] + 1);
				}
			}
			dp[i] = (tmp != MAX) ? tmp : -1;
		}
	}
	for (auto &i : dp)
		cout << i << " ";
	cout << endl;
	return dp[amount];
}

int main () {
	vector<int> coins = {2}; // {1, 2, 5};
	int amount = 11;
	cout << coinChange(coins, amount) << endl;
	return 0;
}