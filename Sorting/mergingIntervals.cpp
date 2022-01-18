#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct comparator {
	bool operator() (const vector<int>& a, const vector<int>& b) {
		return a[0] < b[0];
	};
} cmp;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
	sort(intervals.begin(), intervals.end(), cmp);
	stack<vector<int>> st; st.push(intervals[0]);
	for (int i = 0; i < intervals.size(); i++) {
		if (st.top()[1] < intervals[i][0])
			st.push(intervals[i]);
		else {
			vector<int> tmp = st.top(); st.pop();
			st.push({tmp[0], max(tmp[1], intervals[i][1])});
		}
	}
	intervals.clear();
	while (!st.empty()) {
		intervals.push_back(st.top());
		st.pop();
	}
	sort(intervals.begin(), intervals.end(), cmp);
	return intervals;
}

int main () {
	vector<vector<int>> intervals{{2,6},{1,3},{8,10},{9,15}};
	merge(intervals);
	for (auto & x : intervals) {
		for (auto & y : x)
			cout << y << " ";
		cout << endl;
	}
	return 0;
}