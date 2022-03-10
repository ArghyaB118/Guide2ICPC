/*
You are given an integer array height of length n. There are n vertical lines 
drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that 
the container contains the most water.

Return the maximum amount of water a container can store.

height = [1,8,6,2,5,4,8,3,7]
Output: 49
*/

#include <iostream>
#include <vector>
using namespace std;

// Approach: minimum of the two sides * width = water contained
// Reduce width only if it produces more max area
// If left height is less, move the left wall
// If the right height is less, move the right wall
int waterContained(vector<int>& heights) {
	int n = heights.size();
	if (n < 2) { return 0; }
	int l = 0, r = n - 1, maxArea = 0;
	while (l < r) {
		maxArea = max(maxArea, min(heights[l], heights[r]) * (r - l));
		if (heights[l] < heights[r]) { l++; }
		else { r--; }
	}
	return maxArea;
}

int main () {
	vector<int> heights{ 1,8,6,2,5,4,8,3,7 };
	cout << waterContained(heights) << endl;
	return 0;
}