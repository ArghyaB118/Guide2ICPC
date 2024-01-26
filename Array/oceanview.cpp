/* LC#1762

There are n buildings in a line. 
You are given an integer array heights of size n 
that represents the heights of the buildings in the line.

The ocean is to the right of the buildings. 
A building has an ocean view if the building 
can see the ocean without obstructions. 
Formally, a building has an ocean view if 
all the buildings to its right have a smaller height.

Return a list of indices (0-indexed) of buildings 
that have an ocean view, sorted in increasing order.

Input: heights = [4,2,3,1]
Output: [0,2,3]

Input: heights = [4,3,2,1]
Output: [0,1,2,3]

Input: heights = [1,3,2,4]
Output: [3]
*/

#include<iostream>
#include <vector>
#include <stack>
using namespace std;


// Idea: maintain an integer that says max_obstacle = maximum element rightward
// If an element is greater than the max_obstacle, it has oceanview
vector<int> findBuildings (vector<int>& heights) {
	if (heights.size() == 0)
		return {};
	if (heights.size() == 1)
		return {0};
	int max_obstacle = heights[heights.size() - 1];
	vector<int> oceanview{int(heights.size() - 1)};
	for (int i = heights.size() - 2; i >= 0; i--) {
		if (heights[i] > max_obstacle)
			oceanview.push_back(i);
		max_obstacle = max(max_obstacle, heights[i]);
	}
	//sort is a much faster function than reverse! Use sort.
	sort(oceanview.begin(), oceanview.end());
	return oceanview;
}

// beats > 97% LC users
vector<int> findBuildings2 (vector<int>& heights) {
	int n = heights.size();
	if (n == 0)
		return {};
	if (n == 1)
		return {0};
	stack<int> oceanview; oceanview.push(n - 1);
	int curr_highest_from_right = heights.back();
	for (int i = n - 2; i >= 0; i--) {
		if (heights[i] > curr_highest_from_right)
			oceanview.push(i);
		curr_highest_from_right = max(curr_highest_from_right, heights[i]);
	}
	vector<int> result;
	while (!oceanview.empty()) {
		result.push_back(oceanview.top());
		oceanview.pop();
	}
	return result;
}

int main () {
	vector<int> heights = {4,2,3,1};
	for (auto & x : findBuildings2(heights))
		cout << x << " ";
	cout << endl;

	return 0;
}