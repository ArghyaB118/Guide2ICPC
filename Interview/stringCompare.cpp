/* Compare s and t
 Return the count that is the number of times the following happens.
s[i] = t[0] && s[i + 2] = t[1] && s[i + 4] = t[2]
 */

#include <iostream>
#include <string>
using namespace std;

int stringCompare (string s, string t) {
    if (t == "")
        return 0;
    else if (t == " ")
        return 0;
    else if (t.length() < 5)
        return 0;
    int count = 0;
    for (int i = 0; i <= t.length() - 5; i++) {
        if (t[i] == s[0]) {
            if (t[i + 2] == s[1]) {
                if (t[i + 4] == s[2]) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main () {
    string s = "abc", t = "acbdctt";
    cout << stringCompare (s, t) << endl;
    return 0;
}
