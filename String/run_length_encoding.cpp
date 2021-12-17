#include <iostream>
using namespace std;

// Run length encoding
// O(n)
string encode(string str) {
	if (str == "")
		return "";
	char prevChar = str[0];
	string output = "";
	int count = 1;
	for (int i = 1; i < str.length(); i++) {
		if (str[i] != prevChar) {
			output.append(to_string(prevChar)); output.append(to_string(count)); 
			count = 1; prevChar = str[i];
		}
		else {
			count++;
		}
	}
	return output;
}

// Run length decoding
// O(m)
void decode(string str) {
	string output = "";
	if (str == "")
		return;
	cout << str << str.length() << endl;
	for (int i = 0; i < str.length() / 2; i++)
		for (int j = 0; j < str[2*i + 1]; j++)
			output.push_back(str[2*i]);
	cout << output;
}

void print(string str) {
	cout << str << endl;
}

int main() {
	string str = "uvxxxyyyyzzzzvvvvy"; print(str);
	cout << encode(str) << endl; string str2 = "w4u2";
	decode(str2);
	return 0;
}