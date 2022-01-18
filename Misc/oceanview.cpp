/*
There are n buildings in a line. You are given an integer array heights of size n that represents the heights of the buildings in the line.

The ocean is to the right of the buildings. A building has an ocean view if the building can see the ocean without obstructions. Formally, a building has an ocean view if all the buildings to its right have a smaller height.

Return a list of indices (0-indexed) of buildings that have an ocean view, sorted in increasing order.

Input: heights = [4,2,3,1]
Output: [0,2,3]

Input: heights = [4,3,2,1]
Output: [0,1,2,3]

Input: heights = [1,3,2,4]
Output: [3]
*/

#include<iostream>
#include <vector>
using namespace std;

vector<int> findBuildings(vector<int>& heights) {
	vector<int> oceanview;
	int max_obstacle = heights[heights.size() - 1];
	oceanview.push_back(heights.size() - 1);
	for (int i = heights.size() - 2; i >= 0; i--) {
		if (heights[i] > max_obstacle)
			oceanview.push_back(i);
		max_obstacle = max(max_obstacle, heights[i]);
	}
	sort(oceanview.begin(), oceanview.end());
	return oceanview;
}

int main () {
	vector<int> heights = {4,2,3,1};
	for (auto & x : findBuildings(heights))
		cout << x << " ";
	cout << endl;
	return 0;
}