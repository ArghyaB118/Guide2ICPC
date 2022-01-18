/*
Implement next permutation, which rearranges numbers into the 
lexicographically next greater permutation of numbers.

If such an arrangement is impossible, it must rearrange it to the 
lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

Input: nums = [1,2,3]
Output: [1,3,2]
Input: nums = [3,2,1]
Output: [1,2,3]
*/

#include<iostream>
#include<vector>
using namespace std;


bool isReverseSorted (vector<int>& nums) {
	int n = nums.size();
	for (int i = 1; i < n; i++)
		if (nums[i] > nums[i - 1])
			return false;
	return true;
}


void next_perm (vector<int>& nums) {
	int n = nums.size(), i = n - 1;
	for (i = n - 1; i >= 1; i--) {
		if (nums[i] > nums[i - 1]) {
			// now we have to swap nums[i - 1].
			// swap with the ``smallest greater'' number from the right side
			int smallest_greater = nums[i], smallest_greater_index = i;
			for (int j = i; j < n; j++) {				
				if (nums[j] > nums[i - 1] && nums[j] < smallest_greater) {
					smallest_greater = nums[j];
					smallest_greater_index = j;
				}
			}
			swap(nums[smallest_greater_index], nums[i - 1]);
			break;
		}
	}
	sort(nums.begin() + i, nums.end());
}


int main () {
	vector<int> nums{2,3,1}; //{1,3,2}; //{1, 2, 3}; //{3, 2, 1};
	if (isReverseSorted(nums))
		sort(nums.begin(), nums.end());
	else
		next_perm(nums);
	for (auto i : nums)
		cout << i << " ";
	cout << endl;
	return 0;
}