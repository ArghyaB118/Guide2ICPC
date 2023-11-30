/*Given an integer array nums, return the length of the longest strictly increasing subsequence.
 
 A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].*/

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
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
    vector<int> nums = {1,3,6,7,9,4,10,5,6}; // {0,3,1,6,2,2,7};
    cout << lengthOfLIS(nums) << endl;
    return 0;
}
