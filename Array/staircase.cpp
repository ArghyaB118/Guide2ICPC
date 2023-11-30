/* LC#70

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. 
In how many distinct ways can you climb to the top?

A program to show how recursion and dynamic programming are different
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int climbStairsDP (int n) {
	if (n == 0 || n == 1 || n == 2)
    	return n;
    vector<int> dp = {0, 1, 2};
    for (int i = 3; i <= n; i++) {
    	dp.push_back(dp[i - 1] + dp[i - 2]);
    }
    return dp.back();
}

int climbStairsDP2 (int n) {
	if (n == 0 || n == 1 || n == 2)
    	return n;
    queue<int> dp;
    dp.push(1); dp.push(2);
    for (int i = 3; i <= n; i++) {
    	dp.push(dp.front() + dp.back());
    	dp.pop();
    }
    return dp.back();
}

int climbStairsRecur (int n) {
	if (n == 0 || n == 1 || n == 2)
    	return n;
	return climbStairsRecur(n - 2) + climbStairsRecur (n - 1); 
}

/* LC#746

You are given an integer array cost where cost[i] 
is the cost of ith step on a staircase. 
Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

Constraints:
2 <= cost.length <= 1000
0 <= cost[i] <= 999
*/

int minCostClimbingStairsDP (vector<int>& cost) {
	int n = cost.size();
	if (n == 2)
		return min(cost[0], cost[1]);
	vector<int> dp;
	dp.push_back(min(cost[0], cost[1]));
	dp.push_back(min(cost[1], dp.back() + cost[2]));
	int start = 3;
	while (start < n) {
		dp.push_back(min(dp[start - 3] + cost[start - 1], dp[start - 2] + cost[start]));
		start++;
	}
	return dp.back();
}

int minCostClimbingStairsQueue (vector<int>& cost) {
	int n = cost.size();
	if (n == 2)
		return min(cost[0], cost[1]);
	queue<int> dp;
	dp.push(min(cost[0], cost[1]));
	dp.push(min(cost[1], dp.back() + cost[2]));
	int start = 3;
	while (start < n) {
		dp.push(min(dp.front() + cost[start - 1], dp.back() + cost[start]));
		dp.pop(); start++;
	}
	return dp.back();
}

int main () {
	cout << climbStairsRecur (5) << endl;
	vector<int> cost = {1,100,1,1,1,100,1,1,100,1}; // {10,15,20};
	cout << minCostClimbingStairsQueue (cost) << endl;
	return 0;
}