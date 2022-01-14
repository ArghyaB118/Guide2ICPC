/*
Rotational Cipher
One simple way to encrypt a string is to "rotate" every alphanumeric character by a certain amount. Rotating a character means replacing it with another character that is a certain number of steps away in normal alphabetic or numerical order.
For example, if the string "Zebra-493?" is rotated 3 places, the resulting string is "Cheud-726?". Every alphabetic character is replaced with the character 3 letters higher (wrapping around from Z to A), and every numeric character replaced with the character 3 digits higher (wrapping around from 9 to 0). Note that the non-alphanumeric characters remain unchanged.
Given a string and a rotation factor, return an encrypted string.

Example:
input = Zebra-493?
rotationFactor = 3
output = Cheud-726?
*/

#include <iostream>
#include <string>
using namespace std;

string rotationalCipher(string input, int rotationFactor) {
	string output;
	for (int i = 0; i < input.length(); i++) {
		if (int(input[i]) >= 65 && int(input[i]) <= 90)
			output.push_back(char((int(input[i]) + rotationFactor) % 91 + ((int(input[i]) + rotationFactor) / 91) * 65));
		else if (int(input[i]) >= 97 && int(input[i]) <= 122)
			output.push_back(char((int(input[i]) + rotationFactor) % 123 + ((int(input[i]) + rotationFactor) / 123) * 97));
		else if (int(input[i]) >= 48 && int(input[i]) <= 57)
			output.push_back(char((int(input[i]) + rotationFactor) % 58 + ((int(input[i]) + rotationFactor) / 58) * 48));
		else
			output.push_back(input[i]);
	}
	return output;
}


int main () {
	string input = "Zebra-493"; int rotationFactor = 3;
	string output = rotationalCipher(input, rotationFactor);
	cout << input << " -> " << output << endl;
	return 0;
}