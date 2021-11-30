#include <iostream>
#include <vector>
#include <string>
using namespace std;


// using O(1) space
// in-place operations on input string
void reverseString(vector<char>& s) {
	char temp;
	for (int i = 0; i < (int) s.size() / 2; i++) {
		temp = s[i]; 
		s[i] = s[s.size() - 1 - i]; s[s.size() - 1 - i] = temp; 
	}
}


int main() {
	string sa = "argo";
	vector<char> s(sa.begin(), sa.end());
	for (const char &c : s)
		cout << c << " ";
	reverseString(s);
	for (const char &c : s)
		cout << c << " ";
	return 0;
}