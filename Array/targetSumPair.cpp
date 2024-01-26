// Given an array of integers nums and an integer target, 
// return indices of the two numbers 
// such that they add up to target. 
// Assumption: Each input would have exactly one solution, 
// and same element can't be used twice.

#include <iostream>
#include <vector>
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


/*
Given a list of n integers arr[0..(n-1)], determine the number of different 
pairs of elements within it which sum to k.
If an integer appears in the list multiple times, 
each copy is considered to be different; that is, 
two pairs are considered different if one pair includes at least 
one array index which the other doesn't, even if they include the same values.
*/

int numTargetPairSum (vector<int>& arr, int k) {
	int num = 0, left = 0, right = arr.size() - 1;
	sort(arr.begin(), arr.end()); // O(n log n)
	while (left < right) {
		if (arr[left] + arr[right] == k) {
			num++;
			if (arr[left + 1] == arr[left]) {
				if (right > left + 1)
					if (arr[left] + arr[left + 1])
						num++;
				left++;
			}
			else
				right--;
		}
		else if (arr[left] + arr[right] >= k)
			right--;
		else if (arr[left] + arr[right] <= k)
			left++;
	}
	return num;
}


int main() {
	int arr[] = {1, 2, 3, 4};
	int n = sizeof(arr) / sizeof(arr[0]);
	int target = 7;
	cout << targetSum(arr, n, target).first << " " << targetSum(arr, n, target).second << endl; 
	cout << targetPairSum(arr, n, target).first << " " << targetPairSum(arr, n, target).second << endl;

	//vector<int> v{1,2,3,4,3}; 
	vector<int> v{1,3,3,3,5}; int k = 6; cout << numTargetPairSum(v, k) << endl; 
	return 0;
}