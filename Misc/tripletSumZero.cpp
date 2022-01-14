// Given an array nums of n integers, are there elements a, b, c in nums 
// such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

#include <iostream>
#include <vector>
using namespace std;

// Cost = Sort + O(n ^ 2)
bool tripletSum(int arr[], int n) {
	sort(arr, arr + n);
	// basic intuition is the valid arr[i] is definitely negative
	for (int i = 0; i < n - 2; i++) {
		int target = 0 - arr[i], low = i + 1, high = n - 1; // target is definitely positive
		while (low < high) {
			if (arr[low] + arr[high] == target)
				return true;
			else if (arr[low] + arr[high] <= target)
				low++;
			else if (arr[low] + arr[high] >= target)
				high--;
		}
	}
	return false;
}

// Efficient approach: O(n^2)
// It uses two pointers
vector<vector<int>> tripletSum2(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<vector<int>> result;
	int n = nums.size();
	for (int i = 0; i < n - 2; i++) {
		int target = 0 - nums[i], low = i + 1, high = n - 1;
		while (low < high) {
			if (nums[low] + nums[high] == target)
				result.push_back({nums[i], nums[low], nums[high]});
			else if (nums[low] + nums[high] <= target)
				low++;
			else if (nums[low] + nums[high] >= target)
				high--;
		}
	}
	return result;
}

// Naive approach: O(n^3)
// Efficient approach to calculate closest sum: O(n^2) 
int tripletSumClosest(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
    int n = nums.size(), result = INT_MAX;
    for (int i = 0; i < n - 2; i++) {
        int target_mod = target - nums[i], low = i + 1, high = n - 1;
        while (low < high)
            result = (abs(nums[i] + nums[low] + nums[high] - target) < abs(result - target)) ? (nums[i] + nums[low] + nums[high]) : result;
    }
    return result;
}


int main () {
	int arr[] = {1, -2, -3, 4, -2};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << boolalpha << tripletSum(arr, n) << endl;
	vector<int> nums{1, -2, -3, 4, -2}; // tripletSum2(nums);
	tripletSumClosest(nums, 5);
//	for (int i = 0; i < tripletSum(nums).size(); i++)
//		cout << tripletSum(nums)[i][0] << tripletSum(nums)[i][1] << tripletSum(nums)[i][2] << endl;
	return 0;
}