/*
Given n non-negative integers representing an elevation map 
where the width of each bar is 1, compute how much water it can trap after raining.

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented 
by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of 
rain water (blue section) are being trapped.

Input: height = [4,2,0,3,2,5]
Output: 9
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
int trap (vector<int>& heights) {
	int trapped  = 0;
	stack<int> s;
	for (int i = 0; i < heights.size(); i++) {
		if (heights[i] == 0 && s.empty())
			continue;
		else if (heights[i] > s.top()) {
			s.pop();
			if (s.empty())
				s.push(heights[i]);
		}


			
	}
	return s.top();
}
*/

int trap (vector<int>& heights) {
	vector<int> max_left;
	max_left.push_back(0); max_left.push_back(heights[0]);
	int tmp = heights[0];
	for (int i = 1; i < heights.size() - 1; i++) {
		if (tmp < heights[i])
			max_left.push_back(heights[i]);
		else
			max_left.push_back(tmp);
	}
	vector<int> max_right{0, heights[heights.size() - 1]};
	tmp = heights[heights.size() - 1];
	for (int i = heights.size() - 2; i >= 1; i--) {
		if (tmp < heights[i])
			max_right.push_back(heights[i]);
		else
			max_right.push_back(tmp);
	}
	reverse(max_right.begin(), max_right.end());
	int waterTrapped = 0;
	for (int i = 1; i < heights.size() - 1; i++) {
		tmp = min(max_left[i], max_right[i]);
		if (tmp > heights[i])
			waterTrapped += (tmp - heights[i]);
	}
	return waterTrapped;
}

int main() {
	vector<int> heights{4,2,0,3,2,5}; //{ 0,1,0,2,1,0,1,3,2,1,2,1 };
	cout << "Water trapped: " << trap(heights) << endl;
	return 0;
}