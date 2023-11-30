#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;


// using O(1) space
// in-place operations on input string
void reverseString(vector<char>& s) {
	char temp;
    //for (const char &c : v)
    //  cout << c;
	for (int i = 0; i < (int) s.size() / 2; i++) {
		temp = s[i]; 
		s[i] = s[s.size() - 1 - i]; s[s.size() - 1 - i] = temp; 
	}
}


// Use recursion
void reverseStringRecur(vector<char>& v) {
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
        reverseStringRecur(v);
    }
    //for (const char &c : v2)
      //  cout << c;
}

/*Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.
Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.*/

string reverseWordsStack (string s) {
    string tmp; stack<string> st;
    for (int i = 0; i < s.length(); i++) {
        if ((int(s[i]) >= 65 && int(s[i]) <= 90) || (int(s[i]) >= 97 && int(s[i]) <= 122) || (int(s[i]) >= 48 && int(s[i]) <= 57))
            tmp.push_back(s[i]);
        else {
            if (tmp.size() != 0)
                st.push(tmp);
            tmp.clear();
        }
    }
    if (tmp.size() != 0) {
        st.push(tmp); tmp.clear();
    }
    if (!st.empty()) {
        tmp = st.top(); st.pop();
    }
    while (!st.empty()) {
        tmp = tmp + " " + st.top();
        st.pop();
    }
    return tmp;
}

string reverseWords (string s) {
    string tmp, result;
    for (int i = 0; i < s.length(); i++) {
        if ((int(s[i]) >= 65 && int(s[i]) <= 90) || (int(s[i]) >= 97 && int(s[i]) <= 122) || (int(s[i]) >= 48 && int(s[i]) <= 57))
            tmp.push_back(s[i]);
        else {
            if (tmp.size() != 0) {
                if (result.size() == 0)
                    result = tmp;
                else
                    result = tmp + " " + result;
            }
            tmp.clear();
        }
    }
    if (tmp.size() != 0 && result.size() != 0)
        result = tmp + " " + result;
    else if (tmp.size() != 0 && result.size() == 0)
        result = tmp;
    return result;
}


/*s[i] is an English letter (uppercase or lowercase), digit, or space ' '.
There is at least one word in s.
s does not contain leading or trailing spaces.
All the words in s are guaranteed to be separated by a single space.*/
string reverse (string s, int l, int r) {
    while (l < r) {
        char tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        l++; r--;
    }
    return s;
}

void reverseWordsInPlace (string s) {
    // Idea: reverse the words + reverse the whole thing
    s.push_back(' '); // so that the last word reverses
    int j = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            s = reverse(s, j, i);
            j = i + 1;
        }
    }
    s = reverse(s, 0, s.length() - 1);
    s.pop_back(); cout << s << endl;
}


int main() {
	string sa = "argo";
	vector<char> s(sa.begin(), sa.end());
	for (const char &c : s)
		cout << c << " ";
	reverseString(s);
	for (const char &c : s)
		cout << c << " ";
    cout << endl;
    string sent = "reverse me if you can";
    string tnes = reverseWords(sent);
    cout << sent << " and " << tnes << endl;
    reverseWordsInPlace(sent);
	return 0;
}
