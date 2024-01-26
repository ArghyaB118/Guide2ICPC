/* LC#283

Given an integer array nums, 
move all 0's to the end of it 
while maintaining the relative order of the non-zero elements.

Note that you must do this in-place 
without making a copy of the array.

Follow up: 
Could you minimize the total number of operations done?
*/

#include <iostream>
#include <vector>
using namespace std;

// two pointers: one from left, one from right
// does not respect order
void moveZeroes2(vector<int>& nums) {
	int left = 0, right = nums.size() - 1;
	while (left < right) {
		if (nums[left] != 0)
			left++;
		else if (nums[right] == 0)
			right--;
		else if (nums[left] == 0 && nums[right] != 0) {
			nums[left] = nums[right];
			nums[right] = 0;
		}
	}
}

// store how many zeroes are
// at the left of each index
// beats ~99% LC users
void moveZeroes(vector<int>& nums) {
	vector<int> num_zeroes_leftward(nums.size(), -1);
	int count = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == 0)
			count++;
		else
			num_zeroes_leftward[i] = count;
	}
	for (auto &i : num_zeroes_leftward)
		cout << i << " ";
	cout << endl;
	for (int i = 0; i < nums.size(); i++) {
		cout << i << endl;
		if (num_zeroes_leftward[i] > 0)
			nums[i - num_zeroes_leftward[i]] = nums[i];
		if (i >= nums.size() - count)
			nums[i] = 0;
	}
}

int main () {
	vector<int> nums = {0, 1, 0, 3, 12};
	moveZeroes (nums);
	for (auto &i : nums)
		cout << i << " ";
	cout << endl;
	return 0;
}