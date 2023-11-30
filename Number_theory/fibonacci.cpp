/* LC#509

The Fibonacci numbers, commonly denoted F(n) form a sequence, 
called the Fibonacci sequence, such that each number is the sum 
of the two preceding ones, starting from 0 and 1. That is,
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).
*/

#include <iostream>
using namespace std;

/*Interesting observation: 
Defining the integer here versus outside the for loop
Defining here makes the memory fluctuate during the prorgam as it defines the inetger over and over => Runtime increase
Defining outside makes the overall memory requirement increase

Another interesting improvement: 
Save the work for the last iteration 
Mention the base case earlier for n = 2 */
    
int fib (int n) {
    if (n == 0) {return 0; }
    else if (n == 1 || n == 2) {return 1; }
    else {
        int zero = 0, one = 1;
        for (int i = 2; i < n; i++) {
            int tmp = zero + one; zero = one; one = tmp;
        }
        return zero + one;
    }
}

int fib_q (int n) {
    if (n == 0) {return 0; }
    else if (n == 1) {return 1; }
    else {
        queue<int> q;
        q.push(0); q.push(1);
        for (int i = 2; i <= n; i++) {
            q.push(q.front() + q.back()); q.pop();
        }    
        return q.back();
    }
}
    
int fib_dp(int n) {
    if (n == 0) {return 0; }
    else if (n == 1) {return 1; }
    else {return fib(n - 1) + fib(n - 2); }
}