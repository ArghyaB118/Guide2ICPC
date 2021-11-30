// Buzz number: The number is either divisble by 7 or has 7 at one's.
#include <iostream>
using namespace std;

bool buzzNumber (int x) {
	return (x % 10 == 7 || x % 7 == 0);
}

int main() {
	int x;
	cout << "Enter the number to check: "; cin >> x;
	cout << boolalpha << buzzNumber(x) << endl;
	return 0;
}