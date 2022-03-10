#include <iostream>
#include <math.h>
#include <queue>
using namespace std;

bool isPrime(int n) {
    int j = sqrt(n);
    for(int i = 2; i <= j; ++i) {
        if (n % i == 0)
            return false;
        }
        return true;
    }
int countPrimes(int n) {
    if (n == 0 || n == 1 || n ==2)
        return 0;
    int num = 1;
    for (int i = 3; i < n; i = i + 2) {
        if (isPrime(i) == true)
            ++num;
        }
        return num;
    }


int countPrimesAlt(int n) {
    if (n == 0 || n == 1 || n ==2)
        return 0;
    if (n == 3)
        return 1;
    vector<int> v;
    v.insert(v.begin(), 2);
    for (int i = 3; i < n; i = i + 2) {

    }
}

int main() {
    int num = 499979;
    cout << "Number of primes are: " << countPrimes(num) << endl;
    return 0;
}