#include <iostream>
#include <vector>
#include <stack>
using namespace std;


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

int main() {
	vector<int> heights{ 0, 1, 2, 3 };
	cout << "Water trapped: " << trap(heights) << endl;
	return 0;
}