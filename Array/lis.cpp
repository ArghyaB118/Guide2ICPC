/* LC#300

Given an integer array nums, 
return the length of the longest strictly increasing subsequence.
 
A subsequence is a sequence that can be derived 
from an array by deleting some or no elements 
without changing the order of the remaining elements. 

For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
*/

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int lengthOfLIS2 (vector<int>& nums) {
    if (nums.size() == 1)
        return 1;
    vector<int> dp(nums.size(), 1);
    for (int i = 1; i < nums.size(); i++) {
        int tmp = dp[i];
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                tmp = max(tmp, dp[j] + 1);
            }
        }
        dp[i] = tmp;
    }
    for (auto &j : dp)
        cout << j << " ";
    cout << endl;
    return *max_element(dp.begin(), dp.end());
}

int lengthOfLIS (vector<int>& nums) {
    vector<int> dp(nums.size(), 1);
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    auto it = max_element(std::begin(dp), std::end(dp));
    return *it;
}

int main () {
    vector<int> nums = 
    // {10, 9, 2, 5, 3, 7, 101, 18}; 
    {1,3,6,7,9,4,10,5,6}; 
    // {0,3,1,6,2,2,7};
    cout << lengthOfLIS(nums) << " " << lengthOfLIS2(nums) << endl;
    return 0;
}
