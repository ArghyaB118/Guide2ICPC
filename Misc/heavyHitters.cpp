#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> Pair;
struct cmp {
	bool operator() (const Pair &a, const Pair &b) {
		return a.second < b.second;
	};
};

vector<int> topKelements(vector<int>& arr, int k) {
	vector<int> heavy_hitters;
	unordered_map<int,int> hashmap;
	for (int i = 0; i < arr.size(); i++)
		hashmap[arr[i]]++;
	for (auto x : hashmap)
		cout << x.first << " " << x.second << endl;
	priority_queue<Pair, vector<Pair>, cmp> pq(hashmap.begin(), hashmap.end());
	while (k > 0) {
		heavy_hitters.push_back(pq.top().first);
		pq.pop(); k--;
	}
	return heavy_hitters;
}

int main () {
	vector<int> arr{1,2,4,2,5,5,2,1,2,3,5,1};
	vector<int> heavy_hitters = topKelements(arr, 2);
	for (int i = 0; i < heavy_hitters.size(); i++)
		cout << heavy_hitters[i] << " ";
	cout << endl;
	return 0;
}