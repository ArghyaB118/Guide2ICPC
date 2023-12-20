/* 
Given two arrays of integers, 
calculate the max distance of two contiguous subsequences
of the same length of the given arrays.

The distance is the l1 distance between two arrays.

Example:
a = {10, 50, 30}
b = {4, 20, 75, 50}

d(a[0:1], b[0:1]) = |10 - 4| + |50 - 20| = 6 + 30 = 36
answer: max of d = 81
d(a[0:2], b[1:3]) = |10 - 20| + |50 - 75| + |30 - 50| = 55
d(a[0:2], b[0:2]) = |10 - 4| + |50 - 20| + |30 - 75| = 81

Note: don't feel the length of the subsequence is min(a.size(), b.size())
Counter example:
a = {100, 10}
b = {100, 10}
answer: max of d = 90
*/

#include <iostream>
#include <vector>
using namespace std;

/* Naive algorithm:
Observation: a sliding window is a poor choice. 
As it is pairwise distance, it requires a whole new calculation.

1. make sure a is smaller one and b is larger one
2. for all starting index on a
3. for all starting index on b
4. for all possible lengths of subarray

Cost = |a| * |b| * min(|a|, |b|)
*/

int maxDistance (vector<int>& a, vector<int>& b) {
	if (a.size() > b.size())
		maxDistance(b, a);
	int max_dist = 0, tmp_max_dist = 0;
	for (int starting_index_a = 0; 
		starting_index_a < a.size(); 
		starting_index_a++) {
		for (int starting_index_b = 0; 
			starting_index_b < b.size(); 
			starting_index_b++) {
			tmp_max_dist = abs(a[starting_index_a] - b[starting_index_b]);
			int max_window_size = min(a.size() - starting_index_a, 
				b.size() - starting_index_b);
			if (max_window_size > 1) {
				for (int window_size = 1; 
					window_size < max_window_size; 
					window_size++) {
					tmp_max_dist += 
						abs(a[starting_index_a + window_size] 
							- b[starting_index_b + window_size]);
				}
			}
			max_dist = max(max_dist, tmp_max_dist);
		}
	}
	return max_dist;
}

int main () {
	vector<int> a = {10, 50, 30};
	vector<int> b = {4, 20, 75, 50};
	cout << maxDistance (a, b) << endl;
	return 0;
}

