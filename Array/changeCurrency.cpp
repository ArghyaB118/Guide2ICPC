/*
Change in a Foreign Currency

You likely know that different currencies have coins and bills 
of different denominations. In some currencies, it's actually 
impossible to receive change for a given amount of money. 
For example, Canada has given up the 1-cent penny. 
If you're owed 94 cents in Canada, a shopkeeper will graciously 
supply you with 95 cents instead since there exists a 5-cent coin.

Given a list of the available denominations, determine if it's 
possible to receive exact change for an amount of money targetMoney. 
Both the denominations and target amount will be given in generic units of that currency.

Example 1:
denominations = [5, 10, 25, 100, 200]
targetMoney = 94
output = false
Every denomination is a multiple of 5, so you can't receive exactly 
94 units of money in this currency.

Example 2:
denominations = [4, 17, 29]
targetMoney = 75
output = true
You can make 75 units with the denominations [17, 29, 29].
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool canGetExactChange(int targetMoney, vector<int>& denominations){
	for(int i = 0; i < denominations.size(); i++) {
		if (denominations[i] == targetMoney)
			return true;
		else if (denominations[i] < targetMoney)
			if (canGetExactChange(targetMoney - denominations[i], denominations))
				return true;
	}
	return false;
}

/* LC#322
 
 You are given an integer array coins representing 
 coins of different denominations and an integer amount 
 representing a total amount of money.
 
 Return the fewest number of coins 
 that you need to make up that amount. 
 If that amount of money cannot be made up 
 by any combination of the coins, return -1.

 You may assume that you have an infinite number 
 of each kind of coin.
 
 Input: coins = [1,2,5], amount = 11
 Output: 3
 Explanation: 11 = 5 + 5 + 1
 
 Input: coins = [2], amount = 3
 Output: -1
 
 Input: coins = [1], amount = 0
 Output: 0

 This is a dp problem*/

// Approach 1: Brute Force / Backtracking / DFS
// Cost: O(amount ^ |coins|)

typedef pair<int, int> Pair;

int coinChangeBFS (vector<int>& coins, int amount) {
    queue<Pair> q;
    q.push({0, amount});
    while (!q.empty()) {
        Pair p = q.front(); q.pop();
        cout << p.first << " " << p.second << endl;
        if (p.second == 0)
            return p.first;
        for (auto & coin : coins) {
            if (coin <= p.second)
                q.push({p.first + 1, p.second - coin});
        }
    }
    return -1;
}

int coinChangeBFSReverse (vector<int>& coins, int amount) {
    sort(coins.begin(), coins.end(), greater<int>());
    queue<Pair> q;
    q.push({0, amount});
    while (!q.empty()) {
        Pair p = q.front(); q.pop();
        cout << p.first << " " << p.second << endl;
        if (p.second == 0)
            return p.first;
        for (auto & coin : coins) {
            if (coin <= p.second)
                q.push({p.first + 1, p.second - coin});
        }
    }
    return -1;
}

// Complexity: O(amount * |coins|)

int coinChangeDP (vector<int>& coins, int amount) {
    if (amount == 0)
        return 0;
    vector<int> dp (amount + 1, -1);
    dp[0] = 0;
    for (auto & coin : coins)
        if (coin <= amount)
            dp[coin] = 1;
    for (int i = 1; i <= amount; i++) {
        if (dp[i] == -1) {
            for (auto & coin : coins) {
                if (i - coin >= 0 && dp[i - coin] != -1) {
                    if (dp[i] == -1)
                        dp[i] = dp[i - coin] + 1;
                    else
                        dp[i] = min (dp[i], dp[i - coin] + 1);
                }
            }
        }
    }
    for (int i = 0; i <= amount; i++)
        cout << dp[i] << " ";
    cout << endl;
    return dp[amount];
}

/* LC#518
 
 You are given an integer array coins representing 
 coins of different denominations and an integer amount 
 representing a total amount of money.
 
 Return the number of combinations that make up that amount. 
 If that amount of money cannot be made up 
 by any combination of the coins, return 0.

 You may assume that you have an infinite number of each kind of coin.

 The answer is guaranteed to fit into a signed 32-bit integer.
 
 Input: amount = 5, coins = [1,2,5]
 Output: 4
 Explanation: there are four ways to make up the amount:
 5=5
 5=2+2+1
 5=2+1+1+1
 5=1+1+1+1+1
 

 
 Input: amount = 3, coins = [2]
 Output: 0
 Explanation: the amount of 3 cannot be made up just with coins of 2.
 
 Input: amount = 10, coins = [10]
 Output: 1*/

/* number of ways to make i is sum (number of ways to make i - coin) forall coin in coins
 2: 1 + 1, 2
 3: 1 + 1 + 1, 2 + 1, 1 + 2
 This is not correct, there's duplicacy, it's not permutation, it's cobination.
int change (int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    for (auto & coin : coins)
        if (coin <= amount)
            dp[coin] = 1;
    for (int i = 1; i <= amount; i++) {
        for (auto & coin : coins) {
            if (i - coin >= 0)
                dp[i] += dp[i - coin];
        }
    }
    for (int i = 0; i <= amount; i++)
        cout << dp[i] << " ";
    cout << endl;
    return dp[amount];
}*/

int change (int amount, vector<int>& coins) {
    if (amount == 0)
        return 1;
    if (coins.size() == 0)
        return 0;
    vector<vector<int>> dp (coins.size(), vector<int> (amount + 1, 0));
    for (int i = 0; i < coins.size(); i++)
        dp[i][0] = 1;

    for (int i = 1; i <= amount; i++) {
        if (i % coins[0] == 0)
            dp[0][i] = 1;
    }
    if (coins.size() == 1)
        return dp[0][amount];
    
    for (int i = 1; i < coins.size(); i++) {
        for (int j = 1; j <= amount; j++) {
            // if (j % coins[i] == 0)
            //    dp[i][j]++;
            
            int tmp = 0;
            while (j - tmp * coins[i] >= 0) {
                dp[i][j] += dp[i - 1][j - tmp * coins[i]];
                tmp++;
            }
        }
    }
    
    for (int i = 0; i < coins.size(); i++) {
        for (int j = 0; j <= amount; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    return dp[coins.size() - 1][amount];
}

int change2 (int amount, vector<int>& coins) {
    if (amount == 0)
        return 0;
    if (coins.size() == 0)
        return 0;

    vector<int> tmp = {};
    vector<vector<int>> dp(amount + 1, tmp);
    for (auto &coin : coins)
        dp[coin].push_back({coin});

    for (int i = 1; i <= amount; i++) {
        for (auto &coin : coins) {
            if (i - coin > 0) {
                for (auto &j : dp[i - coin]) {
                    tmp = j;
                    tmp.push_back(coin);
                    dp[i].push_back(tmp);
                }
            }
        }
    }

    return dp[amount].size();
}

int main () {
	vector<int> denominations{4, 17, 29};  //{5, 10, 25, 100, 200};
	sort(denominations.begin(), denominations.end());
	int targetMoney = 94;
	cout << boolalpha << canGetExactChange(targetMoney, denominations) << endl;
    
    vector<int> coins = {1,2,5}; int amount = 11;
    cout << coinChangeDP (coins, amount) << endl;
    
    amount = 5;
    cout << change (amount, coins) << endl;
	return 0;
}
