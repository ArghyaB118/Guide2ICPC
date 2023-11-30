/*Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 
 A subarray is a contiguous part of an array.*/


#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
        return nums[0];
    int ans = INT_MIN, sum = 0; // kadane's algorithm
    // as I don't use an int to iterate, it's better
    for (std::vector<int>::iterator i = nums.begin() ; i != nums.end(); ++i) {
        sum += *i; // pointer to variable
        if (sum > ans)
            ans = sum;
        if (sum < 0)
            sum = 0;
    }
    return ans;
}

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums) << endl;
    return 0;
}
