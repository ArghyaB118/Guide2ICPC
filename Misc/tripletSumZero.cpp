// Given an array nums of n integers, are there elements a, b, c in nums 
// such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

#include <iostream>
using namespace std;

// Cost = Sort + O(n ^ 2)
bool tripletSum(int arr[], int n) {
	sort(arr, arr + n);
	// basic intuition is the valid arr[i] is definitely negative
	for (int i = 0; i < n - 2; i++) {
		int target = 0 - arr[i], low = i + 1, high = n - 1; // target is definitely positive
		while (low < high) {
			if (arr[low] + arr[high] == target)
				return true;
			else if (arr[low] + arr[high] <= target)
				low++;
			else if (arr[low] + arr[high] >= target)
				high--;
		}
	}
	return false;
}


int main () {
	int arr[] = {1, -2, -3, 4, -2};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << boolalpha << tripletSum(arr, n) << endl;
	return 0;
}