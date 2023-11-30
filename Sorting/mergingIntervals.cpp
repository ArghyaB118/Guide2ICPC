/* LC#56
 
 Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
 
 Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
 Output: [[1,6],[8,10],[15,18]]
 Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
 
 Input: intervals = [[1,4],[4,5]]
 Output: [[1,5]]
 Explanation: Intervals [1,4] and [4,5] are considered overlapping.*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct comparator {
	bool operator() (const vector<int>& a, const vector<int>& b) {
		return a[0] < b[0];
	};
} cmp;

vector<vector<int>> merge (vector<vector<int>>& intervals) {
	sort(intervals.begin(), intervals.end(), cmp);
	stack<vector<int>> st; st.push(intervals[0]);
	for (int i = 0; i < intervals.size(); i++) {
		if (st.top()[1] < intervals[i][0])
			st.push(intervals[i]);
		else {
			vector<int> tmp = st.top(); st.pop();
			st.push({min(tmp[0], intervals[i][0]), max(tmp[1], intervals[i][1])});
		}
	}
	intervals.clear();
	while (!st.empty()) {
		intervals.push_back(st.top());
		st.pop();
	}
	sort(intervals.begin(), intervals.end(), cmp); // It may be skipped depending on the requirement on the output
	return intervals;
}

// Although this is more simplified as a code, but using only vector is not a good idea in terms of performance.
// Cost = O(sort) + O(n) = O(n log n)
vector<vector<int>> merge2 (vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result;
    for (auto i : intervals)
        cout << i[0] << " " << i[1] << endl;
    for (auto i : intervals) {
        if (result.empty())
            result.push_back(i);
        else {
            if (i[0] > result.back()[1])
                result.push_back(i);
            else {
                vector<int> tmp = {min(i[0], result.back()[0]), max(i[1], result.back()[1])};
                result.back() = tmp;
            }
        }
    }
    return result;
}

int main () {
	vector<vector<int>> intervals{{2,6},{1,3},{8,10},{9,15}};
	merge(intervals);
	for (auto & x : intervals) {
		for (auto & y : x)
			cout << y << " ";
		cout << endl;
	}
    
    intervals = {{2,6},{1,3},{8,10},{9,15}};
    vector<vector<int>> result = merge2(intervals);
    for (auto i : result)
        cout << i[0] << " " << i[1] << endl;
	return 0;
}
