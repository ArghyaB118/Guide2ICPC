// Ore Number: #divisors / sum(divisors) is an integer
#include <iostream>
#include <vector>
using namespace std;

vector<int> divisors;

void getDivisors (int x) {
	for (int i = 1; i <= x; i++)
		if (x % i == 0)
			divisors.push_back(i);
}

void getDivisorsMod (int x) {
	int i = 1, j = x;
	while (i < j) {
		if (x % i == 0) {
			divisors.push_back(i); 
			divisors.push_back(x / i);
			j = x / i;
		}
		i++;
	}
}

bool oreNumber (int x) {
	getDivisors(x);
	float sum = 0, item = 1.0;
	for (auto i = divisors.begin(); i != divisors.end(); ++i) {
		item = item / (*i); sum += 1.0 / (*i); cout << *i << " ";
	}
	cout << sum << endl;
	sum = divisors.size() / sum; 
	cout << sum << endl;
	if (sum - (int)sum == 0)
		return true;
	else
		return false;
}

int main() {
	int x;
	cout << "Enter the number to check: "; cin >> x;
	cout << boolalpha << oreNumber(x) << endl;
	return 0;
}