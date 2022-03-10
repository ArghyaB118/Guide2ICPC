#include <iostream>
using namespace std;

struct Fraction {
	int numerator;
	int denominator;
};

Fraction getfraction() {
	Fraction frac;
	cout << "Enter numerator \n";
	cin >> frac.numerator;
	cout << "Enter denominator \n";
	cin >> frac.denominator;
	return frac;
}

void multiply(Fraction frac1, Fraction frac2) {
	int numerator = frac1.numerator * frac2.numerator;
	int denominator = frac1.denominator * frac2.denominator;
    cout << numerator << "\n";
    cout << denominator << "\n";
    cout << static_cast<float>(frac1.numerator * frac2.numerator) / (frac1.denominator* frac2.denominator) << "\n";
}

int main() {
	Fraction f1 = getfraction();
	Fraction f2 = getfraction();
	multiply(f1, f2);
	return 0;
}
