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

int main() {
	string s = "  -123 and bluff";
	cout << myAtoi(s) << endl;
	return 0;
}
