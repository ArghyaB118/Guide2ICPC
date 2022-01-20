/*
A peak element is an element that is strictly greater than its neighbors.

Given an integer array nums, find a peak element, and return its index. 
If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞.

You must write an algorithm that runs in O(log n) time.

Input: nums = [1,2,3,1]
Output: 2

Input: nums = [1,2,1,3,5,6,4]
Output: 5 
*/

#include <iostream>
#include <vector>
using namespace std;

int findLocalMaxima (vector<int>& nums, int l, int r) {
	if (l == r)
		return 1;
	int mid = l + (r - l) / 2;
	if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
		return mid;
	if (nums[mid] > nums[mid + 1])
		return findLocalMaxima(nums, l, mid);
	return findLocalMaxima(nums, mid, r);
}

int main () {
	vector<int> nums{1,2,1,3,5,6,4};
	cout << findLocalMaxima(nums, 0, nums.size() - 1) << endl;
	return 0;
}