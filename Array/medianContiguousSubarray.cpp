/* LC#2488
 
 You are given an array nums of size n consisting of distinct integers from 1 to n and a positive integer k.
 
 Return the number of non-empty subarrays in nums that have a median equal to k.

 Note:

 The median of an array is the middle element after sorting the array in ascending order. If the array is of even length, the median is the left middle element.
 For example, the median of [2,3,1,4] is 2, and the median of [8,4,3,5,1] is 4.
 A subarray is a contiguous part of an array.
 
 Input: nums = [3,2,1,4,5], k = 4
 Output: 3
 Explanation: The subarrays that have a median equal to 4 are: [4], [4,5] and [1,4,5].*/

#include <iostream>
#include <vector>
using namespace std;

int countSubarraysOpt (vector<int>& nums, int k) {
    int i = 0, count = 0;
    for (i = 0; i < nums.size(); i++)
        if (nums[i] == k)
            break;
    int left = 0, right = i;
    for (left = 0; left <= i; left++) {
        int countLeft = 0;
        if (left == right)
            count++;
        else {
            for (int j = left; j <= right; j++)
                if (nums[j] < k)
                    countLeft++;
            if (countLeft == (right - left) / 2)
                count++;
        }
        if (right != nums.size() - 1) {
            for (int j = right + 1; j < nums.size(); j++) {
                if (nums[j] < k)
                    countLeft++;
                if (countLeft == (right - left) / 2)
                    count++;
            }
        }
    }
    return count;
}

bool findMedian (vector<int>& nums, int k, int left, int right) {
    if (left == right) {
        if (nums[left] == k)
            return true;
        else
            return false;
    }
    int countLeft = 0;
    for (int i = left; i <= right; i++)
        if (nums[i] < k)
            countLeft++;
    cout << left << " " << right << " " << countLeft << endl;
    if (countLeft == (right - left) / 2)
        return true;
    return false;
}

int countSubarrays (vector<int>& nums, int k) {
    int i = 0, count = 0;
    for (i = 0; i < nums.size(); i++)
        if (nums[i] == k)
            break;
    for (int j = 0; j <= i; j++) {
        for (int l = i; l < nums.size(); l++) {
            if (findMedian (nums, k, j, l))
                count++;
        }
    }
    return count;
}

int main () {
    // vector<int> nums = {2,3,1};
    // int k = 3;
    vector<int> nums = {3,2,1,4,5};
    int k = 4;
    cout << countSubarraysOpt (nums, k) << endl;
    return 0;
}
