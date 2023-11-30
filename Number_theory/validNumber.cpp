/* LC#65

A valid number can be split up into these components (in order):

A decimal number or an integer.
(Optional) An 'e' or 'E', followed by an integer.
A decimal number can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
One of the following formats:
One or more digits, followed by a dot '.'.
One or more digits, followed by a dot '.', followed by one or more digits.
A dot '.', followed by one or more digits.
An integer can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
One or more digits.
For example, all the following are valid numbers: 
["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"], 
while the following are not valid numbers: ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isInteger (string s) {
	if (s[0] == '+' || s[0] == '-') {
		if (s.length() == 1)
			return false;
		for (int i = 1; i < s.length(); i++)
			if (int(s[i]) < 48 || int(s[i]) > 57)
				return false;
		return true;	
	}
	for (int i = 0; i < s.length(); i++)
		if (int(s[i]) < 48 || int(s[i]) > 57)
			return false;
	return true;
}

bool isDecimal (string s) {
	return true;
}

bool invalidChar (string s) {
	for (int i = 0; i < s.length(); i++)
		if (int(s[i]) < 48 || int(s[i]) > 57)
			if (s[i] != '+' && s[i] != '-')
				if (s[i] != '.' && s[i] != 'e' && s[i] != 'E')
					return true;
	return false;
}

/*bool isBadExponent (string s) {
	int count = 0;
	for (auto & ch : s) {
		if (ch == 'e' || ch == 'E') {
			ch = 'e'; count++;
		}
	}
	if (count > 1)
		return true;
}

bool validNumber2 (string s) {
	if (invalidChar(s))
		return false;
	if (isBadExponent(s))
		return false;
	string tmp = "";
	for (auto & ch : s)
		if (ch == 'e')
			tmp += 
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'e' || s[i] == 'E') {
			if (i == 0 || i == s.length() - 1)
				return false;
			return isDecimal(s.substr(0, i)) && isInteger(s.substr(i+1, s.length()));
		}
	}
	return isDecimal(s);
}*/

bool validIntUtil (string s) {
	if (s == "")
		return true;
	int idx = 0;
	if (s[0] == '+' || s[0] == '-') {
		if (s.length() < 2)
			return false;
		idx++;
	}
	for (int i = idx; i < s.length(); i++) {
		if (int(s[i]) < 48 || int(s[i]) > 57)
			return false;
	}
	return true;
}

bool validNumberUtil (string s) {
	int idx = 0;
	if (s[0] == '+' || s[0] == '-') {
		if (s.length() < 2)
			return false;
		idx++;
	}
	// if (s == ".")
		// return false;
	string tmp = "";
	bool fraction = false, whole = false;
	for (int i = idx; i < s.length(); i++) {
		if (int(s[i]) >= 48 && int(s[i]) <= 57)
			tmp += s[i];
		else if (s[i] == '.') {
			if (fraction)
				return false;
			fraction = true;
			if (tmp != "")
				whole = true;
			if (!validIntUtil (tmp))
				return false;
			tmp = "";
		}
		else
			return false;
	}
	if (tmp == "" && fraction && !whole)
		return false;
	else if (tmp == "" && fraction && whole)
		return true;
	else if (tmp == "")
		return true;
	else if (validIntUtil (tmp))
		return true;
	return false;
}

bool validNumber (string s) {
	string tmp = "";
	bool exponent = false;
	for (auto & ch : s) {
		if (int(ch) >= 48 && int(ch) <= 57)
			tmp += ch;
		else if (ch == '+' || ch == '-')
			tmp += ch;
		else if (ch == '.')
			tmp += ch;
		else if (ch == 'e' || ch == 'E') {
			if (exponent || tmp == "")
				return false;
			exponent = true;
			if (!validNumberUtil (tmp))
				return false;
			tmp = "";
		}
		else
			return false;
	}
	if (tmp == "" && !exponent)
		return true;
	else if (tmp == "" && exponent)
		return false;
	else if (!exponent && validNumberUtil (tmp))
		return true;
	else if (exponent && validIntUtil (tmp))
		return true;
	return false;
}


int main () {
	vector<string> nums{"2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"};
	nums.insert(nums.end(), {"abc", "1a", "1e", "e3", "99e2.5", "99e2.5E3", "--6", "-+3", "95a54e53", "+34.345.6", ".", "+."});
	for (string & s : nums)
		cout << boolalpha << validNumber(s) << endl;
	return 0;
}