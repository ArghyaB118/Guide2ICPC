//
//  fibonacciSum.cpp
//  Given a list of numbers, determine if each number is the sum of two Fibonacci numbers.
//
//  Created by Arghya Bhattacharya on 8/27/22.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

vector<long long> makeFib (int num) {
    vector<long long> fib;
    fib.push_back(0); fib.push_back(1);
    while (fib.back() < num)
        fib.push_back(fib[fib.size() - 2] + fib[fib.size() - 1]);
    return fib;
}

vector<bool> solution (vector<long long> &a) {
    vector<bool> result;
    int maxnum = *max_element(a.begin(), a.end());
    cout << maxnum << endl;
    vector<long long> fib = makeFib(maxnum);
    for (int i = 0; i < a.size(); i++) {
        long long tmp = a[i];
        for (int i = 0; i < fib.size(); i++) {
            if (find(fib.begin(), fib.end(), tmp - fib[i]) != fib.end()) {
                result.push_back(true);
                break;
            }
        }
        if (result.size() < i + 1)
            result.push_back(false);
    }
    return result;
}

void printArray (vector<long long> &a) {
    cout << "The array is: ";
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;
}

void printResult (vector<bool> &a) {
    cout << "The result is: ";
    for (int i = 0; i < a.size(); i++)
        cout << boolalpha << a[i] << " ";
    cout << endl;
}

int main() {
    vector<long long> a{2, 5, 17};
    printArray(a);
    vector<bool> result = solution(a);
    printResult(result);
    return 0;
}
