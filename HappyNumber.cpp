#include <iostream> 
#include <algorithm> 
#include <vector> 
#include <math.h>
#include <string>
using namespace std; 

int squareSum(int n) {
	int sum = 0;
	while (n) {
		sum += pow(n % 10, 2);
		n /= 10;
	}
	return sum;
}


bool isHappy(int n) {
	if (n == 1)
		return true;
	vector<int> allSums;
	while(n) {
		if (n != 1) {
			for (int i = 0; i < allSums.size(); ++i)
				if (allSums[i] == n)
					return false;
			n = squareSum(n);
			allSums.insert(allSums.begin(), n);
		}
		else
			return true;
	}
}

int main() {
	int n = 15;
	bool is_happy = 1;
	is_happy = isHappy(n);
	string out;
	is_happy == 1 ? out = "true" : out = "false";
	cout << out << endl;
	return 0;
}