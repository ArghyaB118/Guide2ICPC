/* LC#121

You are given an array prices where prices[i] is the price 
of a given stock on the ith day.

You want to maximize your profit by choosing a single day 
to buy one stock and choosing a different day in the future 
to sell that stock.

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

// Beats 23% and has more space
int maxProfit (vector<int>& prices) {
    if (prices.size() == 0 || prices.size() == 1)
        return 0;
    int maxRight = prices[prices.size() - 1];
    vector<int> maxRights = {};
    for (int i = prices.size() - 1; i > 0; i--) {
        maxRight = (prices[i] > maxRight) ? prices[i] : maxRight;
        maxRights.push_back(maxRight);
    }
    for (int i : maxRights)
        cout << i << endl;
    int maxProfit = 0;
    for (int i = 0; i < prices.size() - 1; i++) {
        if (maxRights[prices.size() - i - 2] - prices[i] > maxProfit)
            maxProfit = maxRights[prices.size() - i - 2] - prices[i];
    }
    return maxProfit;
}

// Beats only 5%
int maxProfit3 (vector<int>& prices) {
    if (prices.size() == 0 || prices.size() == 1)
        return 0;
    int current_min  = prices[0], result = 0;
    /*for (int i = 1; i < prices.size(); i++) {
        result = max(result, prices[i] - current_min);
        current_min = min(current_min, prices[i]);
    }*/
    // More Optimized
    for (int i : prices) {
        result = max(result, i - current_min);
        current_min = min(current_min, i);
    }
    return result;
}

// Beats 50%
int maxProfit2 (vector<int>& prices) {
    if (prices.empty()) return 0;
    int least = prices[0], max_diff = 0;
    for (int & price : prices) {
        if (price < least)
            least = price;
        if (price - least > max_diff)
            max_diff = price - least;
    }
    return max_diff;
}
//more concise form, beats only 20%
int maxProfit2a (vector<int>& prices) {
    if (prices.empty() || prices.size() == 1) return 0;
    int least = prices[0], max_diff = 0;
    for (int & price : prices) {
        least = (price < least) ? price : least;
        max_diff = (price - least > max_diff) ? price - least : max_diff;
    }
    return max_diff;
}

int maxProfit4 (vector<int>& prices) {
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
	vector<int> prices{2,1,4}; //{7,1,5,3,6,4}; // {7,6,4,3,1}; // 
	cout << "Max profit is: " << maxProfit(prices) << endl;
	return 0;
}
