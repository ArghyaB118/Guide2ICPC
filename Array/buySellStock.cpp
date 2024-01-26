/* LC#121

You are given an array prices where prices[i] is the price 
of a given stock on the ith day.

You want to maximize your profit by choosing a single day 
to buy one stock and choosing a different day in the future 
to sell that stock.

Return the maximum profit you can achieve from this transaction. 
If you cannot achieve any profit, return 0.

Clarification: number of transaction = 1
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

int maxProfit2b (vector<int>& prices) {
    if (prices.empty() || prices.size() == 1) return 0;
    int least = prices[0], max_diff = 0;

    for (int & price : prices) {
        least = min(least, price);
        max_diff = max(max_diff, price - least);
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

/* LC#122
Problem statement: 
You are given an integer array prices where prices[i] 
is the price of a given stock on the day i. 
On each day, you may decide to buy and/or sell the stock. 
Note that you can only hold at most one share 
of the stock at any time but you are allowed 
to perform as many transactions as you please. 
Day trading is allowed, i.e., you can buy it 
then immediately sell it on the same day, 
however, there will be no profit in that case 
the price is fixed on a day. 
Find and return the maximum profit you can achieve.
*/

int maxProfitManyTransactions (vector<int>& prices) {
    if (prices.empty()) return 0;
    int max_profit = 0, n = prices.size(); 
    int local_maxima = prices[0], local_minima = prices[0];
    bool on_positive_slope = true;
    for (int i = 1; i < n; i++) {
        cout << local_minima << " " << local_maxima << endl;
        if (!on_positive_slope && prices[i] < prices[i - 1])
            local_minima = prices[i];
        else if (!on_positive_slope && prices[i] >= prices[i - 1]) {
            local_minima = prices[i - 1];
            local_maxima = prices[i];
            on_positive_slope = true;
        }
        else if (on_positive_slope && prices[i] < prices[i - 1]) {
            max_profit += local_maxima - local_minima;
            on_positive_slope = false;
            local_minima = prices[i];
        }
        else if (on_positive_slope && prices[i] >= prices[i - 1]) {
            local_maxima = prices[i];
        }            
    }
    if (on_positive_slope)
        max_profit += local_maxima - local_minima;
    return max_profit;
}

int maxProfitManyTransactions2 (vector<int>& prices) {
    if (prices.empty()) return 0;
    int max_profit = 0, n = prices.size(); 
    int local_minima = prices[0];
    bool on_positive_slope = true;
    for (int i = 1; i < n; i++) {
        if (!on_positive_slope && prices[i] < prices[i - 1])
            local_minima = prices[i];
        else if (!on_positive_slope && prices[i] >= prices[i - 1]) {
            local_minima = prices[i - 1];
            on_positive_slope = true;
        }
        else if (on_positive_slope && prices[i] < prices[i - 1]) {
            max_profit += prices[i - 1] - local_minima;
            on_positive_slope = false;
            local_minima = prices[i];
        }            
    }
    if (on_positive_slope)
        max_profit += prices[n - 1] - local_minima;
    return max_profit;
}

/* LC#123

You are given an array prices where prices[i] 
is the price of a given stock on the day i. 
Find the maximum profit you can achieve. 
You may complete at most two transactions. 
Note: You may not engage in multiple transactions simultaneously 
(i.e., you must sell the stock before you buy again).
*/

/* Interestingly, this is wrong
 Counter example: prices = [1,2,4,2,5,7,2,4,9,0]
 three slopes: index 0-2, 3-5, 6-8 => best two of 3, 5, 7 => 12
 actual answer: index 0-5, 6-8 => 6 + 7 = 13
*/

int maxProfitTwoTransactionsIncorrect (vector<int>& prices) {
    if (prices.empty()) return 0;
    int max_slope = 0, second_max_slope = 0;
    int local_minima = prices[0];
    bool on_positive_slope = true;
    for (int i = 1; i < prices.size(); i++) {
        if (!on_positive_slope && prices[i] < prices[i - 1])
            local_minima = prices[i];
        else if (!on_positive_slope && prices[i] >= prices[i - 1]) {
            local_minima = prices[i - 1];
            on_positive_slope = true;
        }
        else if (on_positive_slope && prices[i] < prices[i - 1]) {
            int tmp = prices[i - 1] - local_minima;
            if (tmp >= max_slope) {
                second_max_slope = max_slope;
                max_slope = tmp;
            }
            else {
                second_max_slope = max(second_max_slope, tmp);
            }
            on_positive_slope = false;
            local_minima = prices[i];
        }            
    }
    if (on_positive_slope) {
        int tmp = prices[prices.size() - 1] - local_minima;
        if (tmp >= max_slope) {
            second_max_slope = max_slope;
            max_slope = tmp;
        }
        else {
            second_max_slope = max(second_max_slope, tmp);
        }
    }
    return max_slope + second_max_slope;
}

// O (n ^ 2) -- timed out
int maxProfitTwoTransactions (vector<int>& prices) {
    if (prices.empty()) return 0;
    int least = prices[0], tmp_max_profit = 0, tmp_max_profit2 = 0, max_profit = 0;
    for (int i = 0; i < prices.size(); i++) {
        least = min(least, prices[i]);
        tmp_max_profit = prices[i] - least;
        if (i < prices.size() - 1) {
            tmp_max_profit2 = 0;
            int j = i + 1, curr_custom_min = prices[j];
            while (j < prices.size()) {
                curr_custom_min = min(curr_custom_min, prices[j]);
                tmp_max_profit2 = max(tmp_max_profit2, prices[j] - curr_custom_min);
                j++;
            }
        }
        max_profit = max(max_profit, tmp_max_profit + tmp_max_profit2);
    }
    return max_profit;
}

// {1,2,4,2,5,7,2,4,9,0}
// {1, 2, 2} {4, 7, 9}
int maxProfitTwoTransactions2 (vector<int>& prices) {
    if (prices.empty()) return 0;
    vector<int> local_minimas = {};
    vector<int> local_maximas = {};
    int local_maxima = prices[0], local_minima = prices[0];
    bool on_positive_slope = true;

    for (int i = 1; i < prices.size(); i++) {
        if (!on_positive_slope && prices[i] < prices[i - 1])
            local_minima = prices[i];
        else if (!on_positive_slope && prices[i] >= prices[i - 1]) {
            local_minima = prices[i - 1];
            local_maxima = prices[i];
            on_positive_slope = true;
        }
        else if (on_positive_slope && prices[i] < prices[i - 1]) {
            local_maximas.push_back(local_maxima);
            local_minimas.push_back(local_minima);
            on_positive_slope = false;
            local_minima = prices[i];
        }
        else if (on_positive_slope && prices[i] >= prices[i - 1]) {
            local_maxima = prices[i];
        }           
    }
    if (on_positive_slope) {
        local_maximas.push_back(local_maxima);
        local_minimas.push_back(local_minima);
    }
    
    // for (int i = 0; i < local_maximas.size(); i++)
    //    cout << local_maximas[i] << local_minimas[i] << endl;

    if (local_minimas.size() == 1)
        return local_maximas[0] - local_minimas[0];

    int max_profit = 0, tmp_max_profit = 0;
    int tmp_max_profit2 = 0;
    local_minima = local_minimas[0];
    for (int i = 0; i < local_maximas.size(); i++) {
        tmp_max_profit = 0; tmp_max_profit2 = 0;
        local_minima = min(local_minima, local_minimas[i]);
        tmp_max_profit = local_maximas[i] - local_minima;
        if (i < local_maximas.size() - 1) {
            int j = i + 1;
            int local_minima2 = local_minimas[j];
            while (j < local_maximas.size()) {
                local_minima2 = min(local_minima2, local_minimas[j]);
                tmp_max_profit2 = max(tmp_max_profit2, local_maximas[j] - local_minima2);
                j++;
            }
            // cout << tmp_max_profit << " " << tmp_max_profit2 << endl;
            max_profit = max(max_profit, tmp_max_profit + tmp_max_profit2);
        }
    }
    return max_profit;
}


int maxProfitTwoTransactions2a (vector<int>& prices) {
    if (prices.empty()) return 0;
    vector<int> local_minimas = {};
    vector<int> local_maximas = {};
    vector<int> current_mins = {};
    int local_maxima = prices[0], local_minima = prices[0], current_min = prices[0];
    bool on_positive_slope = true;

    for (int i = 1; i < prices.size(); i++) {
        if (!on_positive_slope && prices[i] < prices[i - 1])
            local_minima = prices[i];
        else if (!on_positive_slope && prices[i] >= prices[i - 1]) {
            local_minima = prices[i - 1];
            local_maxima = prices[i];
            on_positive_slope = true;
        }
        else if (on_positive_slope && prices[i] < prices[i - 1]) {
            local_maximas.push_back(local_maxima);
            local_minimas.push_back(local_minima);
            current_mins.push_back(current_min);
            on_positive_slope = false;
            local_minima = prices[i];
        }
        else if (on_positive_slope && prices[i] >= prices[i - 1]) {
            local_maxima = prices[i];
        }
        current_min = min(current_min, prices[i]);
    }
    if (on_positive_slope) {
        local_maximas.push_back(local_maxima);
        local_minimas.push_back(local_minima);
        current_mins.push_back(current_min);
    }
    
    for (int i = 0; i < local_maximas.size(); i++)
        cout << local_minimas[i] << " " << local_maximas[i] << " " << current_mins[i] << endl;

    if (local_minimas.size() == 1)
        return local_maximas[0] - local_minimas[0];

    int max_profit = 0, tmp_max_profit = 0;
    for (int i = 0; i < local_maximas.size(); i++) {
        tmp_max_profit = 0;
        if (i < local_maximas.size() - 1) {
            int j = i + 1;
            local_minima = local_minimas[j];
            while (j < local_maximas.size()) {
                local_minima = min(local_minima, local_minimas[j]);
                tmp_max_profit = max(tmp_max_profit, local_maximas[j] - local_minima);
                j++;
            }
        }
        cout << tmp_max_profit << " ";
        tmp_max_profit += local_maximas[i] - current_mins[i];
        cout << tmp_max_profit << endl;
        max_profit = max(max_profit, tmp_max_profit);
    }
    return max_profit;
}

int maxProfitTwoTransactions2b (vector<int>& prices) {
    if (prices.empty() || prices.size() == 1) return 0;
    int n = prices.size();
    vector<int> local_maximas = {};
    vector<int> local_maxima_indices = {};
    vector<int> current_mins = {};
    int current_min = prices[0];

    for (int i = 1; i < n - 1; i++) {
        current_min = min(current_min, prices[i]);
        if (i == n - 2 && prices[i] <= prices[i + 1]) {
            local_maximas.push_back(prices[i + 1]);
            local_maxima_indices.push_back(n - 1);
            current_mins.push_back(current_min);
        }
        else if (prices[i] > prices[i + 1]) {
            local_maximas.push_back(prices[i]);
            local_maxima_indices.push_back(i);
            current_mins.push_back(current_min);
        }
    }

    int nn = local_maximas.size();
    for (int i = 0; i < nn; i++)
        cout << local_maximas[i] << " " << current_mins[i] << endl;
    
    if (local_maximas.empty())
        return 0;
    else if (nn == 1)
        return local_maximas[0] - current_mins[0];
    
    vector<vector<int>> dp(nn, vector<int>(nn, -1));
    for (int i = 0; i < nn - 1; i++) {
        int k = local_maxima_indices[i], l = local_maxima_indices[i + 1];
        int current_range_min = prices[k];
        while (k < l) {
            current_range_min = min(current_range_min, prices[k]);
            k++;
        }
        dp[i][i + 1] = current_range_min;
    }

    for (int i = 0; i < nn; i++) {
        for (int j = 0; j < nn; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < nn; i++) {
        for (int j = i + 1; j < nn; j++) {
            if (dp[i][j] == -1)
                dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]);
        }
    }

    for (int i = 0; i < nn; i++) {
        for (int j = 0; j < nn; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < nn; i++) {
        for (int j = i + 1; j < nn; j++) {
            int tmp = dp[i][j];
            dp[i][j] = local_maximas[j] - tmp;
        }
    }

    for (int i = 0; i < nn; i++) {
        for (int j = 0; j < nn; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
Algorithm:
for every index:
1. determine minimum till left, store max profit from left
2. determine maximum from right, store max profit made from right
take the max sum by iterating over all indices.
consider:
1. whether to sell on this index (for the best return) or skip.
2. whether to buy on this index (for the best return) or skip.
*/

int maxProfitTwoTransactions2c (vector<int>& prices) {
    if (prices.empty() || prices.size() == 1) return 0;
    int n = prices.size();
    int leftmin = prices[0], rightmax = prices[n - 1];
    vector<int> max_profit_left(n, 0);
    vector<int> max_profit_right(n, 0);
    for (int i = 1; i < prices.size(); i++) {
        leftmin = min(leftmin, prices[i]);
        max_profit_left[i] 
            = max(max_profit_left[i - 1], 
                prices[i] - leftmin);
        rightmax = max(rightmax, prices[n - 1 - i]);
        max_profit_right[n - 1 - i] 
            = max(max_profit_right[n - i], 
                rightmax - prices[n - i - 1]);
    }
    int max_profit = 0;
    for (int i = 0; i < n; i++)
        max_profit = max(max_profit, 
            max_profit_left[i] + max_profit_right[i]);
    return max_profit;
}

/* LC#188

You are given an integer array prices 
where prices[i] is the price of a given stock 
on the ith day, and an integer k.

Find the maximum profit you can achieve. 
You may complete at most k transactions: i.e. 
you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously 
(i.e., you must sell the stock before you buy again).
*/

#define max_diff 1000

int maxProfitkTransactions (int k, vector<int>& prices) {
    if (prices.empty() || prices.size() == 1) return 0;
    int n = prices.size();
    vector<int> local_maximas, local_minimas;
    bool on_increasing_slope;
    if (prices[1] >= prices[0]) {
        on_increasing_slope = true;
        local_minimas.push_back(prices[0]);
    }
    else
        on_increasing_slope = false;
    
    for (int i = 2; i < n; i++) {
        if (on_increasing_slope && prices[i] < prices[i - 1]) {
            local_maximas.push_back(prices[i - 1]);
            on_increasing_slope = false;
        }
        else if (!on_increasing_slope && prices[i] >= prices[i - 1]) {
            local_minimas.push_back(prices[i - 1]);
            on_increasing_slope = true;
        }
    }
    if (on_increasing_slope)
        local_maximas.push_back(prices[n - 1]);
    
    int max_profit = 0;
    if (k >= local_maximas.size()) {
        for (int i = 0; i < local_maximas.size(); i++)
            max_profit += local_maximas[i] - local_minimas[i];
        return max_profit;
    }
    if (k == 1) {
        int current_min = max_diff;
        for (int i = 0; i < local_maximas.size(); i++) {
            current_min = min(current_min, local_minimas[i]);
            max_profit = max(max_profit, local_maximas[i] - current_min);
        }
        return max_profit;
    }

    for (auto &i : local_maximas)
        cout << i << " ";
    cout << endl;
    for (auto &i : local_minimas)
        cout << i << " ";
    cout << endl;
    cout << local_maximas.size() << " " 
        << local_minimas.size() << endl;

    int l = local_maximas.size();
    while (l > k) {
        int loss = max_diff, idx = 0;
        for (int i = 1; i < l; i++) {
            int tmp = (local_maximas[i] - local_minimas[i]) 
                + (local_maximas[i - 1] - local_minimas[i - 1]) 
                - (local_maximas[i] 
                - min(local_minimas[i], local_minimas[i - 1]));
            if (tmp < loss) {
                loss = tmp;
                idx = i;
            }
        }
        if (local_maximas[l - 1] - local_minimas[l - 1] < loss) {
            local_maximas.pop_back();
            local_minimas.pop_back();
        }
        else {
            local_maximas.erase(local_maximas.begin() + idx - 1);
            local_minimas[idx] = min(local_minimas[idx - 1], local_minimas[idx]);
            local_minimas.erase(local_minimas.begin() + idx - 1);
        }
        l--;
    }
    for (int i = 0; i < k; i++)
        max_profit += local_maximas[i] - local_minimas[i];

    for (auto &i : local_maximas)
        cout << i << " ";
    cout << endl;
    for (auto &i : local_minimas)
        cout << i << " ";
    cout << endl;
    cout << local_maximas.size() << " " 
        << local_minimas.size() << endl;

    return max_profit;
}


int main () {
	vector<int> prices{2,1,4}; //{7,1,5,3,6,4}; // {7,6,4,3,1}; // 
	cout << "Max profit is: " << maxProfit(prices) << endl;

    vector<int> prices2{7,1,5,3,6,4};
    cout << "Max profit is: " << maxProfitManyTransactions2(prices2) << endl;
	
    vector<int> prices3{3,3,5,0,0,3,1,4}; // {1,2,4,2,5,7,2,4,9,0};
    cout << "Max profit is: " << maxProfitTwoTransactions2c(prices3) << endl;
    
    // vector<int> prices4{8,6,4,3,3,2,3,5,8,3,8,2,6}; // {1,2,4,2,5,7,2,4,9,0}; // {3,3,5,0,0,3,1,4}; // {3,2,6,5,0,3};
    vector<int> prices4{0,1,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000};
    cout << "Max profit is: " << maxProfitkTransactions(100, prices4) << endl;
    return 0;
}
