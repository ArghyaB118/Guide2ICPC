/* LC#2485
 
 Given a positive integer n, find the pivot integer x such that:
 
 The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
 Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at most one pivot index for the given input.
 
 Input: n = 8
 Output: 6
 Explanation: 6 is the pivot integer since: 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.
 
 Input: n = 1
 Output: 1
 Explanation: 1 is the pivot integer since: 1 = 1.
 
 Input: n = 4
 Output: -1
 Explanation: It can be proved that no such integer exist.*/

#include <iostream>
using namespace std;

int pivotInteger (int n) {
    if (n == 0 || n == 1)
        return n;
    int sum = n * (n + 1) / 2;
    int i = (int)(n / 2) + 1, subSum = (int)(n / 2) * ((int)(n / 2) + 1) / 2;
    while (i < n) {
        subSum += i;
        cout << i << " " << subSum << " " << sum << endl;
        if (subSum == sum - subSum + i)
            return i;
        else if (subSum < sum - subSum + i)
            i++;
        else if (subSum > sum - subSum + i)
            return -1;
    }
    return -1;
}

int main () {
    cout << pivotInteger (49) << endl;
    return 0;
}

