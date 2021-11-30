#include <iostream>
#include <vector>
using namespace std;



vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
	vector<vector<int> > queue;
	int pos = 0, count = 0;
	int temp1 = INT_MAX, temp2 = 0;
	while (!people.empty()) {
		bool temp3 = FALSE;
		for (auto &i : people) {
			if (i[1] == pos) {
				temp3 = TRUE; break;
			}
		}
		if (!temp3)
			pos++;
		temp3 = FALSE;
		for (auto &i : people) {
			if (i[1] == count && i[0] < temp1) {
				temp1 = i[0]; temp2 = i[1]; temp3 = TRUE;
			}
			if (temp3) {
				queue.push_back({temp1, temp2});
				remove(people.begin(), people.end(), {temp1, temp2});
				count++; 
			}
			if (i[1] == pos || i[1] == count) {
				if (temp1 > i[0]) {
					temp1 = i[0]; temp2 = i[1];
				}
			}
		}
		queue.push_back({temp1, temp2});
		remove(people.begin(), people.end(), {temp1, temp2});
		count++; 
	}
	return queue; 
}


int main() {
	vector<vector<int> > people, queue;
	people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
	queue = reconstructQueue(people);
	return 0;
}