/*
K cLosest points
Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct point {
	int x, y;
	double dist;
};

struct cmp {
	bool operator() (const point& p, const point& q) {
		return p.dist < q.dist;
	}
};

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
	priority_queue<point, vector<point>, cmp> pq;
	for (int i = 0; i < k; i++)
		pq.push({points[i][0], points[i][1], sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1])});

	for (int i = k; i < points.size(); i++) {
		pq.push({points[i][0], points[i][1], sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1])});
		pq.pop();
	}
	points.clear();

	while (!pq.empty()) {
		struct point tmp = pq.top();
		cout << tmp.x << tmp.y << tmp.dist << endl;
		pq.pop();
		points.push_back({tmp.x, tmp.y});
	}
	return points;
}

int main () {
	vector<vector<int>> points = {{3,3},{5,-1},{-2,4}};
	int k = 2;
	kClosest(points, k);
	for (auto & p : points)
		cout << p[0] << " " << p[1] << endl;
	return 0;
}