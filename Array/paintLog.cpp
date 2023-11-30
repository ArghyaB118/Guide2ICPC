/* LC#2158
 
 There is a long and thin painting that can be represented by a number line. You are given a 0-indexed 2D integer array paint of length n, where paint[i] = [starti, endi]. This means that on the ith day you need to paint the area between starti and endi.
 
 Painting the same area multiple times will create an uneven painting so you only want to paint each area of the painting at most once.

 Return an integer array worklog of length n, where worklog[i] is the amount of new area that you painted on the ith day.
 
 Input: paint = [[1,4],[4,7],[5,8]]
 Output: [3,3,1]
 
 Input: paint = [[1,4],[5,8],[4,7]]
 Output: [3,3,1]*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

typedef pair<int, int> area;

vector<int> getWorklog (vector<area>& paint) {
    unordered_set<int> map;
    vector<int> result;
    for (area i : paint) {
        int count = 0;
        for (int j = i.first; j < i.second; j++) {
            if (map.find(j) == map.end()) {
                count++;
                map.insert(j);
            }
        }
        result.push_back(count);
    }
    return result;
}

vector<int> amountPainted (vector<vector<int>>& paint) {
    int min_start = 50000, max_end = 0;
    for (auto i : paint) {
        min_start = min(min_start, i[0]);
        max_end = max(max_end, i[1]);
    }
    vector<int> result = {};
    set<int> s;
    for (int i = min_start; i < max_end; i++)
        s.insert(i);
    for (auto i : paint) {
        int count = 0;
        for (int j = i[0]; j < i[1]; j++) {
            if (s.find(j) != s.end()) {
                count++; s.erase(j);
            }
        }
        result.push_back(count);
    }
    return result;
}

int main () {
    vector<area> paint = {{1,4}, {5,8}, {4,7}};
    vector<int> worklog = getWorklog (paint);
    for (auto i : worklog)
        cout << i << " ";
    cout << endl;
    
    vector<vector<int>> paint2 = {{1,4}, {5,8}, {4,7}};
    vector<int> worklog2 = amountPainted (paint2);
    for (auto i : worklog2)
        cout << i << " ";
    cout << endl;
    return 0;
}
