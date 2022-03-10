/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock 
and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. 
If you cannot achieve any profit, return 0.

Clarification: number if transaction = 1
Input: prices = [7,1,5,3,6,4]
Output: 5

Input: prices = [7,6,4,3,1]
Output: 0
*/

#include <iostream>
#include <vector>
using namespace std;


int maxProfit (vector<int>& prices) {
	int dp[prices.size()];
	int current_min = prices[0];
	for (int i = 0; i < prices.size(); i++) {
		dp[i] = prices[i] - current_min;
		if (prices[i] < current_min)
			current_min = prices[i];
	}
	int maxProfit = 0;
	for (int i = 0; i < prices.size(); i++)
		maxProfit = max(maxProfit, dp[i]);
	return maxProfit;
}

int main () {
	vector<int> prices{7,6,4,3,1}; // {7,1,5,3,6,4};
	cout << "Max profit is: " << maxProfit(prices) << endl;
	return 0;
}