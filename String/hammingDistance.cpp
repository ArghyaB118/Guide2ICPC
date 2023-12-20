/* LC#461

The Hamming distance between two integers is 
the number of positions at which the corresponding bits are different.

Given two integers x and y, return the Hamming distance between them.

Constraint: 0 <= x, y <= 2^31 - 1
Observation: the binary number is 32-bit.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string decimalToBinary(int x) {
	string s = "";
	for (int i = 0; i < 32; i++)
		s.push_back('0');
	if (x == 0)
		return s;
	int i = 1;
	while (x > 0) {
		int tmp = (x % 2);
		if (tmp == 1)
			s[32 - i] = '1';
		x /= 2;
		i++;
	}
	return s;
}

int hammingDistance(int x, int y) {
	string x1 = decimalToBinary(x);
	string y1 = decimalToBinary(y);
	cout << x1 << " " << y1 << endl;
	int distance = 0;
	for (int i = 0; i < x1.length(); i++) {
		if (x1[i] != y1[i])
			distance++;
	}
	return distance;
}

int main () {
	cout << hammingDistance(0, 10) << endl;
	return 0;
}