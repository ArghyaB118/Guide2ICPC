/* LC#905
 
 Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.
 
 Return any array that satisfies this condition.*/

#include <iostream>
#include <vector>
using namespace std;

void swap (int *p1, int *p2) {
    int tmp;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

vector<int> sortArrayByParity (vector<int>& A) {
    int left = 0, right = A.size() - 1;
    while (left < right) {
        if (A[left] % 2 == 0)
            left++;
        else {
            swap(&A[left], &A[right]);
            right--;
        }
    }
    return A;
}

int main () {
    vector<int> A = {3,1,2,4};
    vector<int> B = sortArrayByParity(A);
    for (int b : B)
        cout << b << " ";
    cout << endl;
    return 0;
}
