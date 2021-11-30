// Emirp Number: The number is prime and when reversed it is again prime
#include <iostream>
using namespace std;

bool isPrime (int x) {
	for (int i = 2; i < x; i++)
		if (x % i == 0)
			return false;
	return true;
}

int reverse (int x) {
	int y = 0;
	while (x != 0) {
		y *= 10;
		y += (x % 10);
		x /= 10;
	}
	return y;
}

bool emirpNumber (int x) {
	if (!isPrime(x))
		return false;
	x = reverse(x);
	if (!isPrime(x))
		return false;
	return true;
}

int main() {
	int x;
	cout << "Enter the number to check: "; cin >> x;
	cout << boolalpha << emirpNumber(x) << endl;
	return 0;
}