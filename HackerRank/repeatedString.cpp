/*
There is a string, s, of lowercase English letters that is repeated infinitely many times. 
Given an integer, n, find and print the number of letter a's in the first n letters 
of the infinite string.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <fstream>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
const std::string WHITESPACE = " \n\r\t\f\v";
vector<string> split(const string &);

/*
 * Complete the 'repeatedString' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. LONG_INTEGER n
 */

long repeatedString(string s, long n) {
	long num1 = n / s.length(), num2 = n % s.length();
	long result = 0;
	for (long i = 0; i < s.length(); i++) {
		if (s[i] == 'a')
			result++;
	}
	result *= num1;
	for (long i = 0; i < num2; i++) {
		if (s[i] == 'a')
			result++;
	}
	return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = repeatedString(s, n);

    fout << result << "\n";
    fout.close();
    cout << result << endl;

    return 0;
}

std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
 
std::string rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
