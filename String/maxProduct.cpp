#include <iostream>
#include <vector>
using namespace std;

int maxProduct (vector<int> &nums) {
	int max_prod = 0, curr_prod = 1;
	for (int i = 0; i < nums.size(); i++) {
		if (curr_prod * nums[i] > curr_prod)
			curr_prod *= nums[i];
		else {
			max_prod = (max_prod > curr_prod) ? max_prod : curr_prod;
			curr_prod = nums[i];
		}
	}
	max_prod = max(curr_prod, max_prod);
	return max_prod;
}

int main() {
	vector<int> v = { 2,3,-2,4 };
	cout << maxProduct(v) << endl;
	return 0;
}