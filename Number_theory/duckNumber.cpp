// Duck number: if there is any zero in the number or not
// The leading zeroes are ignored

#include <iostream>
using namespace std;


bool duckNumber (int x) {
	while (x > 0) {
		if (x % 10 == 0)
			return true;
		else
			x /= 10;
	}
	return false;
}


int main() {
	int x;
	cout << "Enter the number to check: "; cin >> x;
	cout << boolalpha << duckNumber(x) << endl;
	return 0;
}