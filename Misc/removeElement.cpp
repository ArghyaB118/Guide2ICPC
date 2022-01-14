/*
Given an integer array nums and an integer val, remove all occurrences 
of val in nums in-place. The relative order of the elements may be changed.

Since it is impossible to change the length of the array in some languages, 
you must instead have the result be placed in the first part of the array nums. 
More formally, if there are k elements after removing the duplicates, 
then the first k elements of nums should hold the final result. 
It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying 
the input array in-place with O(1) extra memory.

Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
*/

#include <iostream>
#include <vector>
using namespace std;

//Check the edge cases -- Due
int removeElement (vector<int>& v, int num) {
	int count1 =0, count2 = 0;
	while(count2 < v.size()) {
		if (v[count2] != num) {
			v[count1] = v[count2];
			count1++, count2++;
		}
		else {
			count2++;
		}
	}
	return count1;
}

void printVec (vector<int>& v, int num) {
	cout << "The vector till the " << num << "-th number:" << endl;
	for (int i = 0; i < num; i++)
		cout << v[i] << " ";
	cout << endl;
}

int main () {
	vector<int> v{0,1,2,1,4,1,3,5,4,1,0};
	printVec(v, v.size());
	int x = removeElement(v, 1);
	printVec(v, x);
	return 0;
}