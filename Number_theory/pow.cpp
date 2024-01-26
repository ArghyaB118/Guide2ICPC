// g++ -std=c++17 pow.cpp

#include <iostream>
#include <algorithm>
#include <numeric>
#include <math.h>
using namespace std;

double pow (double x, int n) {
	if (n > 0)
		return x * pow(x, n - 1);
	else if (n == -2147483648)
		return 1 / (x * pow(x, abs(n + 1)));
	else if (n < 0 && n != -2147483648)
		return 1 / pow(x, abs(n));
	return 1;
}

bool isPrime(int n) {
    	int j = sqrt(n);
    	for(int i = 2; i <= j; ++i) {
        	if (n % i == 0)
            	return false;
        }   
        return true;
}

bool isCoprime (int x, int y) {
	return std::gcd(x, y) == 1 ? true : false;
}

int pow_int (int x, int n) {
	if (n == 0)
		return 1;
	else if (n == 1)
		return x;
	else
		return x * pow_int(x, n - 1);
}

int pow_mod(int c, int e, int n) {
	return (int)pow_int(c, e) % n;
}

int pow_mod_optimized (int c, int e, int n) {
	if (isPrime(n))
		if (isCoprime(c, n))
			return (int)pow_int(c, (e % (n - 1))) % n;
	return -1;
}

double myPow(double x, int n) {
	if (n == 0)
	    return 1;
	else if (x == 0)
	    return 0;
	else if (n == 1 || x == 1)
	    return x;
	else if (n < 0)
	    return myPow(x, n + 1) / x;
	else if (0 < x && x < 1) {
	    if (n > 1000000)
	        return 0;
	    return 1 / myPow(1 / x, n);
	}
	else if (x < 0 && n % 2 == 0)
	    return myPow((-1) * x, n);
	else if (x < 0 && n % 2 == 1)
	    return (-1) * myPow((-1) * x, n);
	else
	    return x * myPow(x, n - 1);   
}

int main () {
	cout << pow(2, -2) << endl;
	cout << pow_mod(2, 10, 5) << " " << pow_mod_optimized(2, 10, 5) << endl;
	return 0;
}
