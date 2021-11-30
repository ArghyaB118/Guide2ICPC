#include <iostream>
#include <vector>
using namespace std;



int uglyNumberdynamic(int n) {
	int i = 1, count = 1, count1 = 0, count2 = 0, count3 = 0;
	int next_multiple_of_2 = 2, next_multiple_of_3 = 3, next_multiple_of_5 = 5;
	vector<int> uglyNums;
	uglyNums.push_back(i); // cout << i << endl;
	while (count < n) {
		i = min(next_multiple_of_2, min(next_multiple_of_3, next_multiple_of_5));
		uglyNums.push_back(i); // cout << i << endl;
		if (i == next_multiple_of_2) {
			count1++;
			next_multiple_of_2 = uglyNums[count1] * 2;
		}
		if (i == next_multiple_of_3) {
			count2++;
			next_multiple_of_3 = uglyNums[count2] * 3;
		}
		if (i == next_multiple_of_5) {
			count3++;
			next_multiple_of_5 = uglyNums[count3] * 5;
		}
		count++;
	}
	return uglyNums[n - 1];
}





bool isUgly(int n) {
	if (n == 1)
		return true;
	if (n % 2 == 0)
		return isUgly(n / 2);
	if (n % 3 == 0)
		return isUgly(n / 3);
	if (n % 5 == 0)
		return isUgly(n / 5);
	return false;
}

int uglyNumber(int n) {
	int i = 1, count = 1;
	while (count < n) {
		i++; // cout << i << " " << isUgly(i) << endl;
		if (isUgly(i))
			count++;
	}
	return i;
}

int main() {
	int n = 150;
	cout << "The " << n << "-th ugly number is " << uglyNumber(n) << " " << uglyNumberdynamic(n) << endl;
	return 0;
}