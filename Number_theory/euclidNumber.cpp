// Euclid number: E_n = p_n + 1
// p_n = product of first n prime integers

#include <iostream>
using namespace std;

bool isPrime (int x) {
	if (x == 1 || x == 2 || x == 3)
		return true;
	for (int i = 2; i < x - 1; i++)
		if (x % i == 0)
			return false;
	return true;
}

bool euclidNumber (int x) {
	int n = 1, i = 1;
	while (n < x - 1) {
		if (isPrime(i))
			n = n * i;
		i++;
	}
	if (n + 1 == x)
		return true;
	else
		return false;
}

int main() {
	int x;
	cout << "Enter the number to check: "; cin >> x;
	cout << boolalpha << euclidNumber(x) << endl;
	return 0;
}