// Given an array of integers nums and an integer target, return indices of the two numbers 
// such that they add up to target. 
// Assumption: Each input would have exactly one solution, and same element can't be used twice.

#include <iostream>
using namespace std;

// O(n ^ 2)
pair<int,int> targetSum (int arr[], int n, int target) {
	for (int i = 0; i < n; i++) {
		if (arr[i] < target) {
			for (int j = i + 1; j < n; j++) {
				if (arr[j] == target - arr[i])
					return make_pair(arr[i], arr[j]);
			}
		}
	}
	return make_pair(-1,-1);
}

// For sorted array = O(n)
// For unsorted array = O(n log n)
pair<int, int> targetPairSum (int arr[], int n, int target) {
	sort(arr, arr + n);
	int low = 0, high = n - 1;
	while(low < high) {
		if (arr[low] + arr[high] == target)
			return make_pair(arr[low], arr[high]);
		else if (arr[low] + arr[high] <= target)
			low++;
		else if (arr[low] + arr[high] >= target)
			high--;
	} 
	return make_pair(-1,-1);
}


int main() {
	int arr[] = {1, 2, 3, 4};
	int n = sizeof(arr) / sizeof(arr[0]);
	int target = 7;
	cout << targetSum(arr, n, target).first << " " << targetSum(arr, n, target).second << endl; 
	cout << targetPairSum(arr, n, target).first << " " << targetPairSum(arr, n, target).second << endl; 
	return 0;
}