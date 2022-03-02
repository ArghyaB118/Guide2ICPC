/*
Give a binary string s, return the number of non-empty substrings 
that have the same number of 0's and 1's, and all the 0's 
and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int countBinarySubstrings(string s) {
	int count = 0, zeros = 0, ones = 0;
	for (int i = 0; i < s.length(); i++) {
		if (zeros == 0 && ones == 0) {
			if (s[i] == '0')
				zeros++;
			else
				ones++;
		}
		else if (zeros != 0 && ones != 0 && zeros == ones) {
			if (s[i] == '0') { zeros++; ones = 0; }
			else { ones++; zeros = 0; }
		}
		else if (zeros > ones) {
			if (s[i] == '0') {
				zeros = 1; ones = 0;
			}
			else {
				count++; ones++;
			}
		}
		else if (zeros < ones) {
			if (s[i] == '0') {
				count++; zeros++;	
			}
			else {
				ones = 1; zeros = 0;
			}
		}
	}
	return count;
}

int main () {
	string s = "00110011";
	cout << "Number of binary substrings: " << countBinarySubstrings(s) << endl;
	return 0;
}