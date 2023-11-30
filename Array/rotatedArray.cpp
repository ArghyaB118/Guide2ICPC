/*Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
 
 [4,5,6,7,0,1,2] if it was rotated 4 times.
 [0,1,2,4,5,6,7] if it was rotated 7 times.
 Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

 Given the sorted rotated array nums of unique elements, return the minimum element of this array.

 You must write an algorithm that runs in O(log n) time.*/

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

// O(log n) cost
int findMinRecur (vector<int>& nums, int l, int r) {
    if (l == r)
        return nums[l];
    else if (l + 1 == r) {
        if (nums[l] > nums[r])
            return nums[r];
    }
    else {
        if (nums[(l + r) / 2] > nums[r])
            return findMinRecur (nums, (l + r) / 2, r);
        else if (nums[(l + r) / 2] < nums[l])
            return findMinRecur (nums, l, (l + r) / 2);
    }
    return nums[0];
}

int findMin (vector<int>& nums) {
    return findMinRecur (nums, 0, nums.size() - 1);
}

/*Follow up: This problem is similar to Find Minimum in Rotated Sorted Array, but nums may contain duplicates. Would this affect the runtime complexity? How and why?*/
// O(n) cost
int findMinRecurDuplicate (vector<int>& nums) {
    int tmp = nums[0];
    for (auto i : nums) {
        if (i < tmp)
            return i;
        tmp = i;
    }
    return nums[0];
}

/*There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.*/

int findMinIndexRecur (vector<int>& nums, int l, int r) {
    if (l == r)
        return l;
    else if (l + 1 == r) {
        if (nums[l] > nums[r])
            return r;
    }
    else {
        if (nums[(l + r) / 2] > nums[r])
            return findMinIndexRecur (nums, (l + r) / 2, r);
        else if (nums[(l + r) / 2] < nums[l])
            return findMinIndexRecur (nums, l, (l + r) / 2);
    }
    return 0;
}

int searchIndexRecur (vector<int>& nums, int l, int r, int target) {
    if (l == r) {
        if (nums[l] == target)
            return l;
        else
            return -1;
    }
    else if (l + 1 == r) {
        if (nums[l] == target)
            return l;
        else if (nums[r] == target)
            return r;
        else
            return -1;
    }
    else {
        if (target >= nums[(l + r) / 2] && target <= nums[r])
            return searchIndexRecur (nums, (l + r) / 2, r, target);
        else if (target <= nums[(l + r) / 2] && target >= nums[l])
            return searchIndexRecur (nums, l, (l + r) / 2, target);
    }
    return -1;
}

int search (vector<int>& nums, int target) {
    int minIndex = findMinIndexRecur (nums, 0, nums.size() - 1);
    if (target >= nums[minIndex] && target <= nums[nums.size() - 1])
        return searchIndexRecur (nums, minIndex, nums.size() - 1, target);
    else if (minIndex > 0 && target >= nums[0] && target <= nums[minIndex - 1])
        return searchIndexRecur (nums, 0, minIndex - 1, target);
    return -1;
}

int main () {
    vector<int> nums = {4,5,6,7,8,9,1,2};
    cout << findMin (nums) << " " << search (nums, 6) << endl;
    nums = {2,4,5,5,6,7,7,7,8,9,1,2,2};
    cout << findMinRecurDuplicate (nums) << endl;
    return 0;
}
