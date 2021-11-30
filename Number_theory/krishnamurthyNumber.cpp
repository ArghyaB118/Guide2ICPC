// 145 = 1! + 4! + 5! => Krishnamurthy Number
#include <iostream>
using namespace std;


int factorial (int n) {
	int fact = 0;
	if (n == 0)
		return 1;
	else if (n == 1)
		return 1;
	else {
		return factorial(n - 1) * n;
	}
}


bool krishnamurthyNumber (int x) {
	int y = 0, z = x;
	while (z != 0) {
		y += factorial(z % 10);
		z /= 10;
	}
	if (x == y)
		return true;
	else
		return false;
}


int main() {
	int x;
	cout << "Enter the number to check: "; cin >> x;
	cout << boolalpha << krishnamurthyNumber(x) << endl;
	return 0;
}