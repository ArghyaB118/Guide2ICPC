/* LC#88

You are given two integer arrays nums1 and nums2, 
sorted in non-decreasing order, 
and two integers m and n, 
representing the number of elements 
in nums1 and nums2 respectively.
 
Merge nums1 and nums2 into a single array 
sorted in non-decreasing order.

The final sorted array should not be returned by the function, 
but instead be stored inside the array nums1. 
To accommodate this, nums1 has a length of m + n, 
where the first m elements denote the elements 
that should be merged, 
and the last n elements are set to 0 
and should be ignored. 
nums2 has a length of n.
 
Follow up: Can you come up with an algorithm 
that runs in O(m + n) time?
*/

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if (n == 0)
        return;
    int i = 0, j = 0;
    vector<int> result;
    while (i < m && j < n) {
        if (nums1[i] <= nums2[j]) {
            result.push_back(nums1[i]);
            i++;
        }
        else {
            result.push_back(nums2[j]);
            j++;
        }
    }
    while (i < m) {
        result.push_back(nums1[i]);
        i++;
    }
    while (j < n) {
        result.push_back(nums2[j]);
        j++;
    }
    for (int k = 0; k < m + n; k++) {
        nums1[k] = result[k];
    }
}

// beats 100% LC users
void mergeOpt (vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int j = 0;
    for (int i = 0; i < n; i++)
        nums1[m + i] = nums2[i];
    sort(nums1.begin(), nums1.end());
}

int main () {
    vector<int> nums1 = {1,2,3}, nums2 = {2,5,6}, tmp(nums2.size(), 0);
    int m = nums1.size(), n = nums2.size();
    nums1.insert(nums1.end(), tmp.begin(), tmp.end());
    merge(nums1, m, nums2, n);
    for (int i : nums1)
        cout << i << " ";
    cout << endl;
    return 0;
}
