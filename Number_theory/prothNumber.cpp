// Proth number: x = k * 2 ^ n + 1 
// where n and k are integers : k is odd and 2^n > k

#include <iostream>
using namespace std;

bool prothNumber (int x) {
	int y = x, n = 0;
	x = x - 1;
	while (x % 2 == 0) {
		x /= 2; n++;
	}
	if (x % 2 == 0)
		return false;
	else if (y - 1 <= x * x)
		return false;
	return true;
}

int main() {
	int x;
	cout << "Enter the number to check: "; cin >> x;
	cout << boolalpha << prothNumber(x) << endl;
	return 0;
}