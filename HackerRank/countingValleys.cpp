/*
An avid hiker keeps meticulous records of their hikes. 
During the last hike that took exactly  steps, for every step it was noted 
if it was an uphill, or a downhill, step. 
Hikes always start and end at sea level, and each step up or down represents a 
unit change in altitude. We define the following terms:

A mountain is a sequence of consecutive steps above sea level, 
starting with a step up from sea level and ending with a step down to sea level.

A valley is a sequence of consecutive steps below sea level, 
starting with a step down from sea level and ending with a step up to sea level.

Given the sequence of up and down steps during a hike, 
find and print the number of valleys walked through.

Example:
The hiker first enters a valley units deep. 
Then they climb out and up onto a mountain units high. 
Finally, the hiker returns to sea level and ends the hike.

Function Description
Complete the countingValleys function in the editor below.
countingValleys has the following parameter(s):
int steps: the number of steps on the hike
string path: a string describing the path
Returns
int: the number of valleys traversed
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

/*
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */

int countingValleys(int steps, string path) {
	int level = 0, count = 0;
	bool valleyStart = false;
	for (int i = 0; i < steps; i++) {
		if (path[i] == 'U')
			level++;
		else if (path[i] == 'D')
			level--;

		if (level == -1 && valleyStart == false)
			valleyStart = true;
		if (level == 0 && valleyStart == true) {
			count++; valleyStart = false;
		}
	}
	return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string steps_temp;
    getline(cin, steps_temp);

    int steps = stoi(ltrim(rtrim(steps_temp)));

    string path;
    getline(cin, path);

    int result = countingValleys(steps, path);

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
