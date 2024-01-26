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
    long long int count = 0; int i = 0, mult = 0;
    // get rid of the leading whitespaces
    if (s[0] == ' ') {
        while (s[i] == ' ') {
            ++i;
        }
    }
    if (s[i] == '+') {
        mult = 1; i++;
    }
    else if (s[i] == '-') {
        mult = -1; i++;
    }
    else
        mult = 1;
    // ignoring trailing string
    while (int(s[i]) >= 48 && int(s[i]) <= 57) {
        count *= 10; count += char2int(s[i]); i++;
    }
    int result = mult * (count % 2147483648); count *= mult;
    return result;
}

/* LC#415

Given two non-negative integers, 
num1 and num2 represented as string, 
return the sum of num1 and num2 as a string.

You must solve the problem without using 
any built-in library for handling large integers 
(such as BigInteger). 
You must also not convert the inputs to integers directly.

1 <= num1.length, num2.length <= 10^4
num1 and num2 consist of only digits.
num1 and num2 don't have any leading zeros except for the zero itself.
*/

// goes out of bound
string addStrings(string num1, string num2) {
    unsigned long long sum = stoull(num1) + stoull(num2);
    return to_string(sum);
}

// respects the 0 padding at the left
string addStringsUtil(string num1, string num2) {
    unsigned long long sum = stoull(num1) + stoull(num2);
    string s = to_string(sum);
    if (s.length() < 10)
    	for (int i = 0; i < 10 - s.length(); i++)
    		s = "0" + s;
    return s;
}

// how about we chop the strings in lengths of 10
string addLargeStrings(string num1, string num2) {
	int n = max(num1.length(), num2.length());
	if (n % 10 != 0) { n += (10 - n % 10); }
	cout << n << endl;
	if (num1.length() < n) {
		string tmp = "";
		for (int i = 0; i < n - num1.length(); i++)
			tmp.push_back('0');
		num1 = tmp + num1;
	}
	if (num2.length() < n) {
		string tmp = "";
		for (int i = 0; i < n - num2.length(); i++)
			tmp.push_back('0');
		num2 = tmp + num2;
	}
	cout << num1 << " " << num2 << endl;
	string remainder = "0", result = "";
	for (int i = n - 10; i >= 0; i = i - 10) {
		string tmp1 = "", tmp2 = "";
		for (int j = 0; j < 10; j++) {
			tmp1.push_back(num1[i + j]);
			tmp2.push_back(num2[i + j]);
		}
		string tmpsum = addStrings(tmp1, tmp2);
		tmpsum = addStrings(tmpsum, remainder);
		remainder = "0";
		if (tmpsum.length() > 10) {
			remainder = tmpsum[0];
			tmpsum.erase(0, 1);
		}
		result = tmpsum + result;
	}
	cout << result << endl;
	int zero_padding = 0;
	for (zero_padding = 0; zero_padding < n; zero_padding++) {
		if (result[zero_padding] != '0')
			break;
	}
	result.erase(0, zero_padding);
	if (result == "") { return "0"; }
	return result;
}

int main() {
	string s = "  -123 and bluff";
	cout << myAtoi(s) << endl;

	cout << addLargeStrings ("0", "0") << endl;
	return 0;
}
