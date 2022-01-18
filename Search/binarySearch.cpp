#include <iostream>
#include <algorithm>
#include <vector>
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


// Searching for an element in a circular sorted array
int findPivot (vector<int>& nums, int left, int right) {
	if (nums.size() == 1)
		return 0;
	if (left == right)
		return left;
	if (left == right - 1)
		if (nums[left] > nums[right])
			return right;
	int mid = left + (right - left + 1) / 2;
	if (nums[left] < nums[mid])
		return findPivot(nums, mid, right);
	return findPivot(nums, left, mid);
}

int binary_search (vector<int>& nums, int left, int right, int key) {
	int mid = left + (right - left + 1) / 2;
	if (nums[mid] == key)
		return mid;
	if (nums[mid] > key)
		return binary_search(nums, left, mid, key);
	return binary_search(nums, mid, right, key);
}

int circularRotatedSearch (vector<int>& nums, int key) {
	int pivot = findPivot(nums, 0, nums.size() - 1);
	if (key >= nums[0])
		return binary_search(nums, 0, pivot - 1, key);
	else
		return binary_search(nums, pivot, nums.size() - 1, key);
	return -1;
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

	vector<int> rotatedArray{6,7,8,1,2,3,4,5};
	cout << circularRotatedSearch(rotatedArray, 3) << endl;
	return 0;
}