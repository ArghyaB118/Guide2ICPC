/* 

Given an unsorted array and an element,
Find k closest elements to the given element from the array.

Complexity allowed: O(n log k)
*/

#include <iostream>	
#include <queue>
using namespace std;


typedef pair<int, int> Pair;
struct cmp {
	bool operator() (const Pair &a, const Pair &b) {
		return a.first < b.first;
	};
};

void kClosest(int array[], int size, int x, int k) {
	priority_queue<Pair, vector<Pair>, cmp> pq;
	for (int i = 0; i < k; ++i) {
		pq.push({abs(array[i] - x), i});
	}
	for (int i = k; i < size; ++i) {
		int diff = abs(array[i] - x);
		if (diff < pq.top().first) {
			pq.pop();
			pq.push({diff, i});
		}
	}
	while (!pq.empty()) {
		cout << array[pq.top().second] << ' ';
		pq.pop();
	}
}
int main() {
	int array[] = {-10, -50, 20, 5, 67, 54, -3};
	int x = 20, k = 3;
	int sizeofarray = sizeof(array) / sizeof(array[0]);
	kClosest(array, sizeofarray, x, k); 
	return 0;
}