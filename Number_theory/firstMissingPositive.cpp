/* LC#41
Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int firstMissingPositive (vector<int>& nums) {
	unordered_set<int> s;
	int maxm = 0;
	for (auto & i : nums) {
		if (i > 0) {
			s.insert(i);
			maxm = max(maxm, i);
		}
	}
	if (maxm == 0)
		return 1;
	for (int i = 1; i <= maxm; i++)
		if (s.find(i) == s.end())
			return i;
	return maxm + 1;
}

// no need to keep maxm
int firstMissingPositive2 (vector<int>& nums) {
	unordered_set<int> s;
	for (auto & i : nums)
		if (i > 0)
			s.insert(i);
	int i = 1;
	while (true) {
		if (s.find(i) == s.end())
			return i;
		i++;
	}
	return -1;
}

int main () {
	vector<int> nums = {1}; // {3,4,-1,1};
	cout << firstMissingPositive2 (nums) << endl;
	return 0;
}