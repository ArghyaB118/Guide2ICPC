/* LC#1636
 
 Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.
 
 Return the sorted array.
 
 Input: nums = [1,1,2,2,2,3]
 Output: [3,1,1,2,2,2]
 Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
 
 Input: nums = [2,3,1,3,2]
 Output: [1,3,3,2,2]
 Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
// map 'm' stores <element, count>
// priority_queue 'pq' stores <count, element>
typedef pair<int, int> Pair;

/*
 Comparator logic:
 if (a.first < b.first)
    return a;
 else if (a.first > b.first)
    return b;
 else if (a.first == b.first)
    if (a.second > b.second)
        return a;
    else
        return b;
 */
struct cmp {
    bool operator() (const Pair &a, const Pair &b) {
        return (a.first == b.first) ? (a.second < b.second) : (a.first > b.first);
    };
};

vector<int> frequencySort (vector<int>& nums) {
    vector<int> result = {};
    map<int, int> m;
    for (auto i : nums) {
        if (m.find(i) != m.end())
            m[i]++;
        else
            m[i] = 1;
    }
    priority_queue<Pair, vector<Pair>, cmp> pq;
    for (auto i : m) {
        pq.push({i.second, i.first});
    }
    while (!pq.empty()) {
        Pair p = pq.top(); pq.pop();
        for (int i = 0; i < p.first; i++)
            result.push_back(p.second);
    }
    return result;
}

int main () {
    vector<int> a = {2,3,1,3,2};
    vector<int> b = frequencySort(a);
    for (int i : b)
        cout << i << " ";
    cout << endl;
    return 0;
}
