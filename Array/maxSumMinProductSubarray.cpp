/* LC#1856

The min-product of an array is equal to 
the minimum value in the array multiplied by the array's sum.

For example, the array [3,2,5] (minimum value is 2) 
has a min-product of 2 * (3+2+5) = 2 * 10 = 20.
Given an array of integers nums, 
return the maximum min-product of any non-empty subarray of nums. 
Since the answer may be large, return it modulo 10^9 + 7.

Note that the min-product should be maximized 
before performing the modulo operation. 
Testcases are generated such that 
the maximum min-product without modulo will fit 
in a 64-bit signed integer.

A subarray is a contiguous part of an array.
*/

#include <iostream>
#include <vector>
using namespace std;

// memory limit exceeded
int maxSumMinProduct (vector<int>& nums) {
	int n = nums.size();
	vector<vector<int>> mins(n, vector<int>(n, 0));
	vector<vector<unsigned long long int>> sums(n, vector<unsigned long long int>(n, 0));
	for (int i = 0; i < n; i++) {
		sums[i][i] = nums[i];
		mins[i][i] = nums[i];
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			mins[i][j] = min(nums[j], mins[i][j - 1]);
			sums[i][j] = nums[j] + sums[i][j - 1];
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << mins[i][j] << " ";
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << sums[i][j] << " ";
		cout << endl;
	}*/
	unsigned long long int result = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j < n; j++) {
			result = max(result, mins[i][j] * sums[i][j]);
		}
	}
	int result_actual = result % 1000000007;
	return result_actual;
}

// time limit exceeded
int maxSumMinProduct2 (vector<int>& nums) {
	int n = nums.size();
	vector<vector<int>> mins(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		mins[i][i] = nums[i];
	}
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			mins[i][j] = min(nums[j], mins[i][j - 1]);

	unsigned long long int result = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		result = max(result, (unsigned long long int)nums[i] * nums[i]);
		sum = nums[i];
		for (int j = i + 1; j < n; j++) {
			sum += nums[j];
			result = max(result, mins[i][j] * sum);
		}
	}
	int result_actual = result % 1000000007;
	return result_actual;
}

int main () {
	vector<int> nums = {3,1,5,6,4,2};
	cout << maxSumMinProduct2(nums) << endl;
	return 0;
}