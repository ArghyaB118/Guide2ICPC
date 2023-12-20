#include <iostream>
#include <vector>
using namespace std;

int median (vector<int>& v, int l, int r) {
    int n = r - l + 1;
    if (n % 2 == 0)
        return (v[l + n / 2 - 1] + v[l + n / 2]) / 2;
    else
        return v[l + n / 2];
}

double findMedianSortedArrays (
    vector<int>& nums1, vector<int>& nums2, 
    int l1, int r1, 
    int l2, int r2, 
    int left_accumulation, int right_accumulation) {
    int n = nums1.size() + nums2.size();
    if (left_accumulation == n / 2) {
        if (nums1[l1] < nums2[l2])
            return nums1[l1];
        else
            return nums2[l2];
    }
    if (right_accumulation == n / 2) {
        if (nums1[r1] < nums2[r2])
            return nums1[r1];
        else
            return nums2[r2];
    }
    if (median(v1) < median(v2)) {
        return findMedianSortedArrays
            (v1, v2, 
            nums1.size() / 2, r1, 
            0, nums2.size() / 2, 
            nums1.size() / 2, nums2.size() / 2);
    }
    return 0;
}

double findMedianSortedArraysLinear (vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size() + nums2.size();
    int nn = n / 2; 
    cout << n << " " << nn << endl;
    if (n % 2 == 0) {
        int i = 0, j = 0;
        while (nn > 1 && i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j])
                i++;
            else
                j++;
            nn--;
        }
        if (i == nums1.size()) {
            while (nn > 0) {
                j++; nn--;
            }
        }
        if (j == nums2.size()) {
            while (nn > 0) {
                i++; nn--;
            }
        }
        cout << i << " " << j << " " << endl;
        if (nums1[i] < nums2[j])
            return nums1[i];
        else
            return nums2[j];
        return 0;
    }
    else {
        int i = 0, j = 0;
        while (nn > 0 && i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j])
                i++;
            else
                j++;
            nn--;
        }
        if (i == nums1.size()) {
            while (nn > 0) {
                j++; nn--;
            }
        }
        if (j == nums2.size()) {
            while (nn > 0) {
                i++; nn--;
            }
        }
        cout << i << " " << j << " " << endl;
        if (nums1[i] < nums2[j])
            return nums1[i];
        else
            return nums2[j];
    }
    return 0;
}

int main () {
    vector<int> v1 = {1, 3};
    vector<int> v2 = {2};
    cout << findMedianSortedArraysLinear (v1, v2) << endl;

    vector<int> v3 = {1, 3, 6};
    vector<int> v4 = {4, 7, 10, 12};
    cout << findMedianSortedArrays (v3, v4, 0, 2, 0, 3, 0, 0) << endl;

    return 0;
}