// Happy Number: It leads to 1 after a number of steps wherein each step
// a number is replaced by the sum of squares of the digits
#include <iostream> 
#include <algorithm> 
#include <vector> 
#include <math.h>
#include <string>
using namespace std; 

int squareSum (int n) {
	int sum = 0;
	while (n) {
		sum += pow(n % 10, 2);
		n /= 10;
	}
	return sum;
}

// This method uses extra space
bool isHappy (int n, vector<int> allSums) {
	if (n == 1)
		return true;
	for (auto i = allSums.begin(); i != allSums.end(); i++)
		if (*i == n)
			return false;
	allSums.push_back(n);
	return isHappy(squareSum(n), allSums);
}

// This method does not use any extra space
// Uses a slow and a fast pointer
bool isHappy2 (int n) {
	int slow = n, fast = n;
	do {
		slow = squareSum(slow);
		fast = squareSum(squareSum(fast));
	}
	while (slow != fast);
	return (slow == 1);
}

// If a one digit sum comes, it has to be 1 or 7
// Does not require any extra space
bool isHappy3 (int n) {
	while (n / 10 != 0) {
		n = squareSum(n);
	}
	if (n == 1 || n == 7)
		return true;
	return false;
}


int main() {
	cout << "Check the number if Happy Number or not: " << endl;
	int n; cin >> n;
	vector<int> allSums;
	cout << boolalpha << isHappy(n, allSums) << endl;
	cout << boolalpha << isHappy2(n) << endl;
	cout << boolalpha << isHappy3(n) << endl;
	return 0;
}