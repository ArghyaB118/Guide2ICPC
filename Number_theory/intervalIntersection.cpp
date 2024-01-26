/* LC#986

You are given two lists of closed intervals, 
firstList and secondList, 
where firstList[i] = [starti, endi] 
and secondList[j] = [startj, endj]. 
Each list of intervals is 
pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

A closed interval [a, b] (with a <= b) denotes 
the set of real numbers x with a <= x <= b.

The intersection of two closed intervals is 
a set of real numbers that are either empty or 
represented as a closed interval. 
For example, 
the intersection of [1, 3] and [2, 4] is [2, 3].

Input: 
firstList = [[0,2],[5,10],[13,23],[24,25]], 
secondList = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
using namespace std;

int get_span (vector<vector<int>>& List) {
	int span = 0;
	for (auto &i : List)
		span += (i[1] - i[0]);
	return span;
}

// this approach treats [15, 24]
// and [15, 23] and [24, 24] as the same.
vector<vector<int>> intervalIntersection
	(vector<vector<int>>& firstList, 
		vector<vector<int>>& secondList) {
	vector<vector<int>> result;
	//int spanFirstList = get_span(firstList);
	//int spanSecondList = get_span(secondList);
	//if (spanFirstList < spanSecondList) {
		unordered_set<int> items;
		for (auto &i : firstList) {
			for (int j = i[0]; j <= i[1]; j++)
				items.insert(j);
		}
		for (auto &i : secondList) {
			int j = i[0], start = 0;
			bool continuing = false;
			while (j <= i[1]) {
				if (items.find(j) == items.end() && !continuing)
					j++;
				else if (items.find(j) == items.end() && continuing) {
					result.push_back({start, j - 1}); 
					continuing = false; j++;
				}
				else if (items.find(j) != items.end() && continuing) {
					j++;
				}
				else if (items.find(j) != items.end() && !continuing) {
					start = j; continuing = true; j++;
				}
			}
			if (continuing) {
				result.push_back({start, i[1]});
			}
		}
	//}
	return result;
}

// beats ~47% LC users
vector<vector<int>> intervalIntersection2
(vector<vector<int>>& firstList, 
	vector<vector<int>>& secondList) {
	vector<vector<int>> result;
	if (firstList.size() == 0 || secondList.size() == 0)
		return result;
	int i = 0, j = 0;
	while (i < firstList.size() && j < secondList.size()) {
		if (firstList[i][1] < secondList[j][0])
			i++;
		else if (secondList[j][1] < firstList[i][0])
			j++;

		else {
			result.push_back({max(firstList[i][0], secondList[j][0]), 
				min(firstList[i][1], secondList[j][1])});
			if (firstList[i][1] < secondList[j][1])
				i++;
			else
				j++;
		}
	}
	return result;
}

int main () {
	vector<vector<int>> intervals1{{0,2},{5,10},{13,23},{24,25}};
    vector<vector<int>> intervals2{{1,5},{8,12},{15,24},{25,26}};
    
    vector<vector<int>> result = intervalIntersection2 (intervals1, intervals2);
    for (auto i : result)
        cout << i[0] << " " << i[1] << endl;
	return 0;
}