#include <iostream>
#include <string>
using namespace std;

int char2int(char c) {
	if (c == '0')
		return 0;
	else if (c == '1')
		return 1;
	else if (c == '2')
		return 2;
	else if (c == '3')
		return 3;
	else if (c == '4')
		return 4;
	else if (c == '5')
		return 5;
	else if (c == '6')
		return 6;
	else if (c == '7')
		return 7;
	else if (c == '8')
		return 8;
	else if (c == '9')
		return 9;
	else
		return -1;
}


int myAtoi(string s) {
	int count = 0, i = 0;
	if (s[0] == ' ') {
		while (s[i] == ' ') {
			++i;
		}
	}
	int k = i + 1;
	while (s[k] == '1' || s[k] == '2' || s[k] == '3' || s[k] == '4' || s[k] == '5' || s[k] == '6' || s[k] == '7' || s[k] == '8' || s[k] == '9' || s[k] == '0')
		k++;
	if (s[i] == '-') {
		for (int j = i + 1; j < k; j++) {
			count *= 10; count += char2int(s[j]);
		}
		count = count * (-1);
	}
	else {
		for (int j = i; j < k; j++) {
			count *= 10; count += char2int(s[j]);
		}
	}
	return count;
}

int main() {
	string s = "  -123 and bluff";
	cout << myAtoi(s) << endl;
	return 0;
}