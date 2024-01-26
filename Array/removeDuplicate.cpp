/* LC#26

Given an integer array nums sorted in non-decreasing order, 
remove the duplicates in-place such that 
each unique element appears only once. 
The relative order of the elements should be kept the same.

Since it is impossible to change 
the length of the array in some languages, 
you must instead have the result be placed 
in the first part of the array nums. 
More formally, if there are k elements 
after removing the duplicates, 
then the first k elements of nums should 
hold the final result. 
It does not matter what you leave 
beyond the first k elements.

Return k after placing the final result 
in the first k slots of nums.

Do not allocate extra space for another array. 
You must do this by modifying the input array 
in-place with O(1) extra memory.

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
*/

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates (vector<int>& v) {
	if (v.size() == 0 || v.size() == 1) { return 0; }
	int count1 = 1, count2 = 1, temp = v[0];
	while (count2 < v.size()) {
		if (v[count2] != temp) {
			temp = v[count2];
			v[count1] = v[count2];
			count1++; count2++;
		}
		else {
			count2++;
		}
	}
	return count1;
}

/* LC#80

Given an integer array nums sorted in non-decreasing order, 
remove some duplicates in-place such that 
each unique element appears at most twice. 
The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array 
in some languages, you must instead have the result 
be placed in the first part of the array nums. 
More formally, if there are k elements 
after removing the duplicates, 
then the first k elements of nums should hold 
the final result. 
It does not matter what you leave beyond the first k elements.

Return k after placing the final result 
in the first k slots of nums.

Do not allocate extra space for another array. 
You must do this by modifying the input array in-place 
with O(1) extra memory.
*/

int removeDuplicates2 (vector<int>& nums) {
	int n = nums.size();
	if (n < 3)
		return n;
	int k = 1, l = 1;
	bool skip = false;
	while (l < n) {
		if (nums[l] == nums[l - 1] && skip)
			l++;
		else if (nums[l] == nums[l - 1] && !skip) {
			skip = true; 
			nums[k] = nums[l];
			l++; k++;
		}
		else if (nums[l] != nums[l - 1]) {
			skip = false;
			nums[k] = nums[l];
			l++; k++;
		}
	}
	return k;
}

void printVec (vector<int>& v, int num) {
	cout << "The vector till the " << num << "-th number:" << endl;
	for (int i = 0; i < num; i++)
		cout << v[i] << " ";
	cout << endl;
}

int main () {
	std::vector<int> v{0,0,1,1,1,2,2,3,3,4};
	printVec(v, v.size());
	int x = removeDuplicates(v);
	printVec(v, x);

	vector<int> nums = {0,0,1,1,1,1,2,3,3};
	printVec(nums, nums.size());
	printVec(nums, removeDuplicates2(nums));

	return 0;
}