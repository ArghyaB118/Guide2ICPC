#include <iostream>
#include <vector>
using namespace std;


// This problem is known as coin change problem
// This problem is the same as subset sum problem
// 


// This function uses a method of recursion
bool coin_change(vector<int> coins, int n, int sum) {
	if (sum == 0)
		return true;
	else if (sum < 0)
		return false;
	else if (sum > 0 && n == 0)
		return false;
	else
		return coin_change(coins, n - 1, sum) || coin_change(coins, n - 1, sum - coins[n - 1]);
}

// This method uses a method of dynamic programming
bool coin_change_dp(vector<int> coins, int n, int sum) {
	bool changes[n+1][sum+1]; 
	for (int i = 0; i < n + 1; i++) 
		changes[i][0] = true;
	for (int i = 1; i < sum + 1; i++) 
		changes[0][i] = false;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; i < sum + 1; j++) {
			if (j < coins[i - 1])
				changes[i][j] = changes[i - 1][j];
			if (j >= coins[i - 1])
				changes[i][j] = changes[i - 1][j] || changes[i - 1][j - coins[i - 1]];
		}
	}
	// for (int i = 0; i < n + 1; i++) {
	// 	for (int j = 0; i < sum + 1; j++) {
	// 		cout << changes[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	return changes[n + 1][sum + 1];
}


int main() {
	vector<int> coins, change; int sum = 15;
	for (int i = 1; i <= 10; i++)
		coins.push_back(i);
	if(coin_change(coins, coins.size(), sum) && coin_change_dp(coins, coins.size(), sum))
		cout << "subset sum is valid" << endl;
	else
		cout << "subset sum is not valid" << endl;
	return 0;
}