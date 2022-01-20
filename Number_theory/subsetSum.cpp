#include <iostream>
#include <vector>
#include <numeric>
using namespace std;


void print (vector<int> vec) {
	for (int i = 0; i < vec.size(); i++)
			cout << vec[i] << " ";
		cout << endl;
}

bool subsetSum (int arr[], int n, int sum, int x, vector<int> subset) {
	int sum_elts = accumulate(subset.begin(), subset.end(), 0);
	if (sum_elts == sum) {
		print(subset); return true;
	}
	if (sum_elts > sum)
		return false; 
	if (sum_elts < sum) {
		subset.push_back(arr[x]); print(subset);
		if (x < n - 1) {
			if (!subsetSum(arr, n, sum, x + 1, subset))
				return false;
		}
	}
}


/*
Given an integer array nums and an integer k, 
return true if nums has a continuous subarray of size 
at least two whose elements sum up to a multiple of k, or false otherwise.

Input: nums = [23,2,4,6,7], k = 6
Output: true

Input: nums = [23,2,6,4,7], k = 6
Output: true

Input: nums = [23,2,6,4,7], k = 13
Output: false
*/

// Naive approach: O(n ^ 2)
bool checkSubarraySum (vector<int>& nums, int k) {
	for (int i = 1; i < nums.size(); i++)
		for (int j = 0; j < i - 1; j++)
			if (accumulate(nums.begin() + j, nums.begin() + i, 0) % k == 0)
				return true;
	return false;
}

// O(n) algorithm
bool checksubarraySum2 (vector<int>& nums, int k) {
	if (nums.size() == 0)
		return false;
	int left = 0, right = 0, sum = nums[0];
	while (right < nums.size() - 1) {
		if (sum == k)
			return true;
		else if (sum < k) {
			right++; sum += nums[right];
		}
		else if (sum > k) {
			sum -= nums[left]; left++;
		}
	}
	return false;
}


/*
Subarray Sum Equals K

Given an array of integers nums and an integer k, 
return the total number of continuous subarrays whose sum equals to k.

Input: nums = [1,1,1], k = 2
Output: 2

Input: nums = [1,2,3], k = 3
Output: 2
*/

int subarraySum(vector<int>& nums, int k) {
	if (nums.size() == 0)
		return 0;
	int left = 0, right = 0, count = 0, sum = nums[0];
	while (left < nums.size() - 1 && right < nums.size() - 1 && left <= right) {
		if (sum == k) {
			count++; left++; right++;
		}
		else if (sum < k) {
			right++; sum += nums[right];
		}
		else if (sum > k) {
			sum -= nums[left]; left++;
		}
	}
	return count;
}

int main() {
	int arr[] = {10, 7, 5, 18, 12, 20, 15};
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 32;
	vector<int> subset;
	cout << boolalpha << subsetSum(arr, n, sum, 0, subset) << endl;

	vector<int> v{23,2,4,6,7}; int k = 6;
	cout << boolalpha << checkSubarraySum(v, k) << endl;

	vector<int> nums{1,1,1}; int target = 2;
	cout << subarraySum(nums, target) << endl;
	cout << boolalpha << checksubarraySum2(nums, target) << endl;
	return 0;
}