#include <iostream>
#include <vector>
using namespace std;

bool vectorComparator (vector<int> &p, vector<int> &q) {
	for (int i = 0; i < p.size(); i++)
		if (p[i] != q[i])
			return false;
	return true;
}

void minimumBribes (vector<int> q) {
	for (int i = 0; i < q.size(); i++) {
		if (i + 1 < q[i] && q[i] - i - 1 > 2) {
			cout << "Too chaotic" << endl;
			return; 
		}
	}
	int bribe = 0;
	vector<int> p = q;
	sort(p.begin(), p.end());
	while (!vectorComparator(p, q)) {
		for (int i = 0; i < q.size() - 1; i++) {
			if (q[i] > q[i + 1]) {
				swap(q[i], q[i + 1]);
				bribe++;
			}
		}
	}
	cout << bribe << endl;
}

int main () {
	vector<int> q = {1, 2, 5, 3, 7, 8, 6, 4}; // {4, 1, 2, 3};
	minimumBribes (q);
	return 0;
}