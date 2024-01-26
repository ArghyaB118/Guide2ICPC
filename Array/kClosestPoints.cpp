/* LC#973

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
//		cout << tmp.x << tmp.y << tmp.dist << endl;
		pq.pop();
		points.push_back({tmp.x, tmp.y});
	}
	return points;
}

struct pp {
	int x, y;
};

struct comp {
	bool operator() (const pp& p, const pp& q) {
		return ((p.x * p.x + p.y * p.y) < (q.x * q.x + q.y * q.y));
	}
};

vector<vector<int>> kClosestOptimized (vector<vector<int>>& points, int k) {
	priority_queue<pp, vector<pp>, comp> pq;
	for (int i = 0; i < k; i++)
		pq.push({points[i][0], points[i][1]});

	for (int i = k; i < points.size(); i++) {
		pq.push({points[i][0], points[i][1]});
		pq.pop();
	}
	points.clear();

	while (!pq.empty()) {
		struct pp tmp = pq.top();
//		cout << tmp.x << tmp.y << tmp.dist << endl;
		pq.pop();
		points.push_back({tmp.x, tmp.y});
	}
	return points;
}

// beats ~98% LC users
typedef pair<int, int> point;
struct cmp {
	bool operator() (const point &a, const point &b) {
		return a.first * a.first + a.second * a.second > b.first * b.first + b.second * b.second;
	};
};

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
	vector<vector<int>> result;
	priority_queue<point, vector<point>, cmp> pq;
	for (int i = 0; i < points.size(); i++)
		pq.push({points[i][0], points[i][1]});
	while (k > 0) {
		result.push_back({pq.top().first, pq.top().second});
		pq.pop(); k--;
	}
	return result;
}

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


int main () {
	vector<vector<int>> points = {{3,3},{5,-1},{-2,4}};
	int k = 2;
	kClosest(points, k);
	for (auto & p : points)
		cout << p[0] << " " << p[1] << endl;

	points.clear();
	points = {{3,3},{5,-1},{-2,4}};
	kClosestOptimized(points, k);
	for (auto & p : points)
		cout << p[0] << " " << p[1] << endl;

	int array[] = {-10, -50, 20, 5, 67, 54, -3};
	int x = 20, k = 3;
	int sizeofarray = sizeof(array) / sizeof(array[0]);
	kClosest(array, sizeofarray, x, k); 

	return 0;
}