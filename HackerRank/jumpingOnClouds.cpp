/*
There is a new mobile game that starts with consecutively numbered clouds. 
Some of the clouds are thunderheads and others are cumulus. 
The player can jump on any cumulus cloud having a number that is 
equal to the number of the current cloud plus 1 or 2. 
The player must avoid the thunderheads. 
Determine the minimum number of jumps it will take to jump 
from the starting postion to the last cloud. 
It is always possible to win the game.
For each game, you will get an array of clouds numbered 0 if they are safe 
or 1 if they must be avoided.

Example 

c = [0 1 0 0 0 1 0]
Index the array from 0..6. 
The number on each cloud is its index in the list so the player must avoid the clouds 
at indices 1 and 5. They could follow these two paths: 0 2 4 6 or 0 2 3 4 6. 
The first path takes 3 jumps while the second takes 4. Return 3.
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
 * Complete the 'jumpingOnClouds' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY c as parameter.
 */

int jumpingOnClouds(vector<int> c) {
	if (c.size() == 0)
		return 0;
	else if (c.size() == 1)
		return 1;
	else if (c.size() == 2)
		return 2;
	int count = 0, pos = 0;
	while (pos < c.size() - 2) {
		if (c[pos + 2] == 0) {
			pos = pos + 2;
			count++;
		}
		else {
			pos = pos + 1;
			count++;
		}
	}
	if (pos == c.size() - 2)
		return count + 1;
	return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split(rtrim(c_temp_temp));

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = jumpingOnClouds(c);

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


vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
