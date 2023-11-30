/*You are given an integer finalSum. Split it into a sum of a maximum number of unique positive even integers.
 
 For example, given finalSum = 12, the following splits are valid (unique positive even integers summing up to finalSum): (12), (2 + 10), (2 + 4 + 6), and (4 + 8). Among them, (2 + 4 + 6) contains the maximum number of integers. Note that finalSum cannot be split into (2 + 2 + 4 + 4) as all the numbers should be unique.
 Return a list of integers that represent a valid split containing a maximum number of integers. If no valid split exists for finalSum, return an empty list. You may return the integers in any order.*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<long long> maximumEvenSplit (long long finalSum) {
    if (finalSum % 2 != 0)
        return {};
    vector<long long> result = {};
    result.push_back(2); finalSum -= 2;
    while (finalSum > 0) {
        cout << finalSum << endl;
        if (find(result.begin(), result.end(), finalSum) == result.end()) {
            finalSum -= result.back() + 2;
            result.push_back(result.back() + 2);
        }
        else if (find(result.begin(), result.end(), finalSum) != result.end()) {
            int tmp = result.back();
            result.pop_back();
            tmp += finalSum;
            result.push_back(tmp);
            finalSum = 0;
        }
    }
    return result;
}

int main () {
    long long finalSum = 28;
    vector<long long> result = maximumEvenSplit (finalSum);
    for (auto i : result)
        cout << i << " ";
    cout << endl;
    return 0;
}
