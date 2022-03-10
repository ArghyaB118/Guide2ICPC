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

void reverseString(vector<char>& v) {
    size_t numofchar = v.size();
    //for (const char &c : v)
    //  cout << c;
    //vector<char> v2; int i = 0;
    if (numofchar == 1)
        cout << v[0] << endl;
    else
    {
        cout << v[numofchar - 1];
        //v2[i] = v[numofchar - 1];
        //i = i + 1;
        vector<char> v1(v.begin(), v.end() - 1);
        v = v1;
        reverseString(v);
    }
    //for (const char &c : v2)
      //  cout << c;
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