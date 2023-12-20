/*
Julius Caesar protected his confidential information 
by encrypting it using a cipher. 
Caesar's cipher shifts each letter by a number of letters. 
If the shift takes you past the end of the alphabet, 
just rotate back to the front of the alphabet. 
In the case of a rotation by 3, w, x, y and z 
would map to z, a, b and c.
*/

#include <iostream>
#include <string>
using namespace std;

string caesarCipher (string s, int k) {
	k %= 26; // size of alphabet = 26
	for (auto &ch : s) {
		int tmp = (int)ch;
		if (tmp >= (int)'a' && tmp <= (int)'z') {
			tmp += k;
			if (tmp > (int)'z')
				tmp -= 26;
		}
		else if (tmp >= (int)'A' && tmp <= (int)'Z') {
			tmp += k;
			if (tmp > (int)'Z')
				tmp -= 26;
		}
		ch = static_cast<char>(tmp);
	}
	return s;
}

int main () {
	string s = "abcd-efg hi";
	cout << caesarCipher(s, 3) << endl;
	return 0;
}