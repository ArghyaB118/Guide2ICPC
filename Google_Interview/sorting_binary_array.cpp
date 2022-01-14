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

// two pointers: one left->right, another right->left
void mysort(int* left, int* right) {
	int* temp1 = left;
	int* temp2 = right;
	while(temp1 < temp2) {
		if (*temp1 == 0)
			temp1++;
		if (*temp2 == 1)
			temp2--;
		if (*temp1 == 1 && *temp2 == 0) {
			swap(*temp1, *temp2); temp1++; temp2--;
			printarray(left, right + 1);
			//int temp3 = *temp1; *temp1 = *temp2; *temp2 = temp3;
		}
	}
}

// by counting number of zeros
void mysort2(int* left, int* right) {
	int* temp = left;
	int countZeroes = 0;
	while (temp <= right) {
		if (*temp == 0)
			countZeroes++;
		temp++;
	}
	cout << countZeroes << endl;
	temp = left;
	while(temp <= right) {
		if (countZeroes > 0) {
			*temp = 0; countZeroes--;
		}
		else
			*temp = 1;
		temp++;
	}
} 


int main() {
	int arr[] = {0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0};
	int n = sizeof(arr) / sizeof(arr[0]);
	printarray(&arr[0], &arr[n]);
	mysort(&arr[0], &arr[n - 1]);
	printarray(&arr[0], &arr[n]);
	return 0;
}