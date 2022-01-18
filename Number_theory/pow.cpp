#include <iostream>
using namespace std;

double pow (double x, int n) {
	if (n > 0)
		return x * pow(x, n - 1);
	else if (n < 0)
		return 1 / pow(x, abs(n));
	return 1;
}

int main () {
	cout << pow(2, -2) << endl;
	return 0;
}