#include <iostream>
#include <algorithm>
using namespace std;

bool search (int arr[], int n, int key) {
	for (int i = 0; i < n; i++)
		if (arr[i] == key)
			return true;
	return false;
}

// binary search recursive
bool bsr (int arr[], int left, int right, int key) {
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == key)
			return true;
		else if (arr[mid] < key)
			return bsr(arr, mid + 1, right, key);
		else if (arr[mid] > key)
			return bsr(arr, left, mid - 1, key);
	}
	return false;
}

// binary search iterative
bool bsi (int arr[], int left, int right, int key) {
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == key)
			return true;
		else if (arr[mid] < key)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return false;
}

int findPivot(vector<int>& nums) {
	int n = nums.size();
	if (n == 1)
		return 0;
	int i = 1;
	while (nums[i] <= nums)
}

int searchRotated (vector<int>& nums, int target) {
	int pivot = findPivot(nums);
	if (target >= nums[0]) {
		binary_search(nums, target);
	}
}


int main() {
	int arr[] = {10, 4, 15, 7, 19, 5, 1, 3, 12};
	int n = sizeof(arr) / sizeof(arr[0]);
	sort(arr , arr + n);
	int key; cout << "Enter the key to search : "; cin >> key;
	if (is_sorted(arr, arr + n) == false)
		cout << boolalpha << search(arr, n, key) << endl; // cost = O(n), cannot be proved unless the array is sorted.
	else {
		cout << boolalpha << bsr(arr, 0, n-1, key) << endl;
		cout << boolalpha << bsi(arr, 0, n-1, key) << endl;
	}
	return 0;
}