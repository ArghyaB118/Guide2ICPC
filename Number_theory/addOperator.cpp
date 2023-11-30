/*Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.
 
 Note that operands in the returned expressions should not contain leading zeros.*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, string> expression;

vector<string> addOperators (string num, int target) {
    int idx = 0;
    queue<expression> q; vector<string> vec;
    string tmpS = ""; tmpS.push_back(num[0]);
    int tmpN = (int)num[0] - 48;
    q.push({tmpN, tmpS});
    
    while (!q.empty()) {
        expression exp = q.front();
        cout << exp.first << " " << exp.second << endl;
        q.pop();
        if (idx == num.length() - 1) {
            if (exp.first == target)
                vec.push_back(exp.second);
        }
        else if (idx < num.length() - 1) {
            idx++;
            tmpS = exp.second; tmpS.push_back('+'); tmpS.push_back(num[idx]);
            tmpN = exp.first; tmpN += (int)num[idx] - 48; q.push({tmpN, tmpS});
            tmpS = exp.second; tmpS.push_back('-'); tmpS.push_back(num[idx]);
            tmpN = exp.first; tmpN -= (int)num[idx] - 48; q.push({tmpN, tmpS});
            tmpS = exp.second; tmpS.push_back('*'); tmpS.push_back(num[idx]);
            tmpN = exp.first; tmpN *= (int)num[idx] - 48; q.push({tmpN, tmpS});
        }
    }
    
    return vec;
}

int main() {
    string num = "232";
    int target = 8;
    vector<string> expressions = addOperators (num, target);
    for (auto i : expressions)
        cout << i << endl;
    return 0;
}
