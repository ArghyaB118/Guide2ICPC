/* LC#55
You are given an integer array nums. 
You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump 
length at that position.

Return true if you can reach the last index, or false otherwise.
*/

#include <iostream>
#include <vector>
using namespace std;

// Approach 2: bottom-up DP
bool canJump2 (vector<int>& nums) {
	if (nums.size() == 1)
		return true;
	vector<bool> reachable(nums.size(), false);
	reachable[nums.size() - 1] = true;
	for (int i = nums.size() - 2; i >= 0; i--) {
		// cout << i << " " << nums[i] << endl;
		if (nums[i] == 0)
			continue;
		bool tmp = false;
		for (int j = 1; j <= nums[i] && i + j < nums.size(); j++) {
			tmp = tmp || reachable[i + j];
		}
		reachable[i] = tmp;
	}
	// for (int i = 0; i < reachable.size(); i++)
	//	cout << reachable[i] << " ";
	// cout << endl;
	return reachable[0];
}

bool canJump2a (vector<int>& nums) {
	if (nums.size() == 1)
		return true;
	vector<bool> reachable(nums.size(), false);
	reachable[nums.size() - 1] = true;
	for (int i = nums.size() - 2; i >= 0; i--) {
		if (nums[i] == 0)
			continue;
		for (int j = 1; j <= nums[i] && i + j < nums.size(); j++) {
			reachable[i] = reachable[i] || reachable[i + j];
		}
	}
	return reachable[0];
}

bool canJumpUtil (vector<int>& nums, int index) {
	if (index >= nums.size())
		return false;
	else if (index == nums.size() - 1)
		return true;
	else if (nums[index] == 0)
		return false;
	else {
		// Approach 1: backtracking
		/*for (int i = 1; i <= nums[index]; i++)
			if (canJumpUtil(nums, index + i))
				return true;*/

		// Approach 1a: backtracking but with maximum jump
		for (int i = nums[index]; i >= 1; i--)
			if (canJumpUtil(nums, index + i))
				return true;
		
		return false;
	}
}

bool canJump (vector<int>& nums) {
	return canJumpUtil (nums, 0);
}

int main () {
	vector<int> nums = {2, 3, 1, 1, 4}; // {3, 2, 1, 0, 4};
	cout << boolalpha << canJump(nums) << endl;
	cout << boolalpha << canJump2a(nums) << endl;
	return 0;
}
