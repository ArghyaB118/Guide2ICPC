/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, 
return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
*/

#include <iostream>
#include <vector>
using namespace std;


// Traverse through both the arrays
// Stopping criterion: when find the median/ one of the arrays end
// Cost: O(m + n)
int findMedian(vector<int>& nums1, vector<int>& nums2) {
	int m = nums1.size(), n = nums2.size(), count = 0, count1 = 0, count2 = 0, median = -1;
	if ((m + n) % 2 == 1) {
		while (count < (m + n) / 2) {
			if (count1 < m && count2 < n) {
				if (nums1[count1] < nums2[count2]) {
					count1++; count++;
					median = nums1[count1];
				}
				else {
					median = nums2[count2];
					count2++; count++;
				}
			}
			else if (count1 == m) {
				median = nums2[count2 + (m + n) / 2 - count];
			}
			else if (count2 == n) {
				median = nums1[count1 + (m + n) / 2 - count];
			}
		}
	} 
	return median;
}

/*
Can we do better?
O(log (m + n)) -- 
Idea: Do binary search. 
If one of the arrays have size 0, 
	return median of the other array
If both the medians are the same, 
	return that as the overall median
If size(smaller array) = 1: 
		If size(larger array) = 1, return average 
		Else if size(larger array) = even, return median after merge 
Else
	Recursively find out the half that do not contribute to the answer
*/

struct vec {
	vector<int> v;
	int left, right;
};

int median(struct vec v1) {
	return (((v1.right - v1.left) / 2) % 2 == 0) ? v1.v[(v1.left + v1.right) / 2] : (v1.v[(v1.left + v1.right) / 2 - 1] + v1.v[(v1.left + v1.right) / 2]) / 2;
}

int findMedian2(struct vec v1, struct vec v2) {
	if (median(v1) == median(v2))
		return median(v1);
	else if (median(v1) <= median(v2)) {
		v1.left = v1.left + (v1.right - v1.left) / 2;
		return findMedian2(v1, v2);
	}
	return 0;
}



int main() {
	vector<int> nums1{1,2,3,4,5};
	vector<int> nums2{2,3,5,7};
	cout << "The median is: " << findMedian(nums1, nums2) << endl;
	struct vec v1 = {nums1, 0, 4}, v2 = {nums2, 0, 3};
	cout << findMedian2(v1, v2) << endl;
	return 0;
}