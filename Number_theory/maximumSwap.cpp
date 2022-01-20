#include <iostream>
#include <vector>
using namespace std;


int maxSwap (int num) {
	vector<int> v;
	while (num) {
		v.push_back(num % 10);
		num /= 10;
	}
	reverse(v.begin(), v.end());
	for (int & i : v)
		cout << i << " ";
	cout << endl;
	vector<int> maxRightIndex; int maxRight = v.size() - 1;
	for (int i = v.size() - 1; i >= 0; i--) {
		if (v[i] > v[maxRight]) {
			maxRight = i;
			maxRightIndex.push_back(maxRight);
		}
		else
			maxRightIndex.push_back(maxRight);
	}
	reverse(maxRightIndex.begin(), maxRightIndex.end());
	for (int & i : maxRightIndex)
		cout << i << " ";
	cout << endl;

	for (int i = 0; i < v.size(); i++) {
		if (i != maxRightIndex[i] && v[i] < v[maxRightIndex[i]]) {
			swap(v[i], v[maxRightIndex[i]]);
			break;
		}
	}

	num = 0;
	for (int & i : v)
		num = num * 10 + i;
	return num;
}

int main () {
	int num = 937909;
	cout << "Number after max swap: " << maxSwap(num) << endl; 
	return 0;
}