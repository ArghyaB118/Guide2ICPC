'''
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
'''


#include <iostream>
#include <vector>
using namespace std;

// Two sums problems after sorting the array
// O(sorting) + O(n) = O(n log n)
bool twoSum(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end()); // Sorting: O(n log n)
	int i = 0, j = nums.size() - 1;
	// Traverese the array with two pointers: O(n)
	while (i < j) { 
		if (nums[i] + nums[j] == target) {
			cout << "The indices are: " << i << ", " << j << endl;
			return true;
		}
		else if (nums[i] + nums[j] >= target)
			j--;
		else if (nums[i] + nums[j] <= target)
			i++;
	}
	return false;
} 

int main() {
	std::vector<int> nums{2, 7, 15, 11};
	int target = 18;
	cout << "The two sum problem could be solved: " << boolalpha << twoSum(nums, target) << endl;
}