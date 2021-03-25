// https://www.geeksforgeeks.org/cpp-program-for-quicksort/
#include <iostream>
using namespace std;

// utility function to print the array
void printarray(int* left, int* right) {
	int* temp = left;
	while (temp != right) {
		cout << *temp << " "; temp++;
	}
	cout << endl;
}

int* partition(int* left, int* right) {
	int* pivot = right;
	int* temp1 = left;
	int* temp2 = left;
	if (temp2 == pivot - 1) {
		if (*temp1 > *pivot) {
			swap(*temp1, *pivot); return temp1;
		}
	}
	while (temp2 <= right - 1) {
		if (*temp2 <= *pivot) {
			swap(*temp2, *temp1); temp1++;
		}
		temp2++;
	}
	swap(*temp1, *pivot);
	return temp1;
}

void quickSort(int* left, int* right) {
	if (left == right)
		return;
	else if (left > right)
		return;
	else {
		int* pivot = partition(left, right);
		printarray(left, right + 1);
		quickSort(left, pivot - 1);
		quickSort(pivot + 1, right);
	}
}


int main() {
	int arr[] = {4, 7, 12, 3, 11, 15, 34, 17, 10, 8, 16};
	int n = sizeof(arr) / sizeof(arr[0]);
	printarray(&arr[0], &arr[n]);
	quickSort(&arr[0], &arr[n - 1]);
	printarray(&arr[0], &arr[n]);
	return 0;
}