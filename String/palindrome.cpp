/* LC#125

A phrase is a palindrome if, 
after converting all uppercase letters into lowercase letters 
and removing all non-alphanumeric characters, 
it reads the same forward and backward. 
Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, 
or false otherwise.

Input: s = "A man, a plan, a canal: Panama"
Output: true
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

// use two pointers
// beats 100% LC users
bool isPalindrome(string s) {
	int left = 0, right = s.length() - 1;
	while (left < right) {
		if (!isalnum(s[left]))
			left++;
		else if (!isalnum(s[right]))
			right--;
		else if (tolower(s[left]) != tolower(s[right]))
			return false;
		else if (tolower(s[left]) == tolower(s[right])) {
			left++; right--;
		}
	}
	return true;
}

// push back in a new string
bool isPalindrome(string s) {
    string t;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] != '\n' && s[i] != ' ' && ispunct(s[i]) == false)
            t.push_back(tolower(s[i]));
    }
    for (int i = 0; i < t.length() / 2; i++)
        if (t[i] != t[t.length() - i - 1])
            return false;
    return true;
}

// modify the same string
bool isPalindromeInPlace (string s) {
    s.erase(remove(s.begin(), s.end(), '\n'), s.end());
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    for (int i = 0, len = s.length(); i < len; i++) {
        if (ispunct(s[i])) {
            s.erase(i--,1); len = s.length();
        }
    }
    for (int i = 0; i < s.length(); i++)
        s[i] = tolower(s[i]);
    cout << s;
    for (int i = 0; i < s.length() / 2; i++)
        if (s[i] != s[s.length() - i - 1])
            return false;
    return true;
}

string removeNonAlphaNumerics(string s) {
	string s1;
	for (int i = 0; i < s.length(); i++) {
		if (int(s[i]) >= 97 && int(s[i]) <= 122)
			s1.push_back(s[i]);
		else if (int(s[i]) >= 65 && int(s[i]) <= 90)
			s1.push_back(char(int(s[i]) + 32));
		else if (int(s[i]) >= 48 && int(s[i]) <= 57)
			s1.push_back(s[i]);
	}
	return s1; 
}

bool isPalindrome (string s) {
	if (s.length() == 0 || s.length() == 1)
		return true;
	stack<char> s1;
	for (int i = 0; i < s.length(); i++)
		s1.push(char(s[i]));
	for (int i = 0; i < s.length(); i++) {
		char ch = s1.top(); s1.pop();
		if (ch != s[i])
			return false;
	}
	return true;
}

/* LC#680

Given a string s, return true if the s can be palindrome 
after deleting at most one character from it.
*/

bool useDeletion = false;
// Use two pointers
bool validPalindromeWithDeletion (string s) {
	int left = 0, right = s.length() - 1;
	while (left < right) {
		if (s[left] != s[right] && useDeletion == true)
			return false;
		else if (s[left] != s[right] && useDeletion == false) {
			useDeletion = true;
			if (left + 1 == right)
				return true;
			else if (s[left + 1] == s[right] && s[left] == s[right - 1])
				return (validPalindromeWithDeletion (s.substr(left, right - left)) || validPalindromeWithDeletion (s.substr(left + 1, right - left)));
			else if (s[left + 1] == s[right] && s[left] != s[right - 1])
				left++;
			else if (s[left] == s[right - 1] && s[left + 1] != s[right])
				right--;
		}
		else {
			left++; right--;
		}
	}
	return true;
}


// A much faster way is not to define a global boolean
// Instead have a root function and a utility funtion
bool validPalindromeWithDeletionUtil (string s, bool useDelete, int left, int right) {
	while (left < right) {
		if (s[left] != s[right] && useDelete == true)
			return false;
		else if (s[left] != s[right] && useDelete == false) {
			useDelete = true;
			if (left + 1 == right)
				return true;
			else if (s[left + 1] == s[right] && s[left] == s[right - 1])
				return (validPalindromeWithDeletionUtil (s, useDelete, left, right - 1) || validPalindromeWithDeletionUtil (s, useDelete, left + 1, right));
			else if (s[left + 1] == s[right] && s[left] != s[right - 1])
				left++;
			else if (s[left] == s[right - 1] && s[left + 1] != s[right])
				right--;
		}
		else {
			left++; right--;
		}
	}
	return true;
}

bool validPalindromeWithDeletionRoot (string s) {
	if (s.length() == 0)
		return true;
	else if (s.length() == 1)
		return true;
	return validPalindromeWithDeletionUtil (s, false, 0, s.length() - 1);
}


// dp[i][j] = (dp[i + 1][j - 1]) && (is s[i] == s[j])
// Anything between two same letters is palindromic or not
//   a b c b d
// a 1 0 0 0 0
// b   1 0 1 0
// c     1 0 0
// b       1 0
// d         1

int longestPalindromicSubstring (string s) {
	bool dp[s.length()][s.length()];
	int max_length = 1;
	for (int i = 0; i < s.length(); i++) {
		dp[i][i] = true;
		int j = 0;
		while (j < i) {
			dp[i][j] = false;
			j++;
		}
	}
	for (int i = s.length() - 2; i >= 0; i--) {
		for (int j = i + 1; j < s.length(); j++) {
			if (dp[i+1][j-1] == true && s[i] == s[j]) {
				dp[i][j] = true;
				if (j - i + 1 > max_length)
					max_length = j - i + 1;
			}
			else
				dp[i][j] = false;
		}
	}
	return max_length;
}

int main () {
	string s = "A man, a plan, a canal: Panama";
	s = removeNonAlphaNumerics(s);
	cout << "Is " << s << " a palindrome? " << boolalpha << isPalindrome(s) << endl;
	string s1 = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
	cout << "Is s1 a palindrome after deleting at most one char? " << validPalindromeWithDeletionRoot(s1) << endl;
	cout << "Length of longest palindromic substring of abcbd: " << longestPalindromicSubstring("abcbd") << endl; 
	return 0;
}
