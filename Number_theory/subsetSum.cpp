#include <iostream>
#include <vector>
#include <numeric>
using namespace std;


void print (vector<int> vec) {
	for (int i = 0; i < vec.size(); i++)
			cout << vec[i] << " ";
		cout << endl;
}

bool subsetSum (int arr[], int n, int sum, int x, vector<int> subset) {
	int sum_elts = accumulate(subset.begin(), subset.end(), 0);
	if (sum_elts == sum) {
		print(subset); return true;
	}
	if (sum_elts > sum)
		return false; 
	if (sum_elts < sum) {
		subset.push_back(arr[x]); print(subset);
		if (x < n - 1) {
			if (!subsetSum(arr, n, sum, x + 1, subset))
				return false;
		}
	}
}


int main() {
	int arr[] = {10, 7, 5, 18, 12, 20, 15};
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 32;
	vector<int> subset;
	subsetSum(arr, n, sum, 0, subset);
	return 0;
}