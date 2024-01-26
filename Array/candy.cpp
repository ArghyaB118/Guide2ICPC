#include <iostream>
#include <vector>
#include <numeric> // for accumulate
#include <queue>
using namespace std;

int candy(vector<int>& ratings) {
	int n = ratings.size();
	if (n < 2)
		return n;
	vector<int> candies(n, 1);
	vector<bool> final(n, false);
	int min_elt = *min_element(ratings.begin(), ratings.end());
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (ratings[i] == min_elt) {
			q.push(i);
			final[i] = true;
		}
	}
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		if (tmp + 1 < n && ratings[tmp + 1] == ratings[tmp]) {
			if (!final[tmp + 1]) {
				q.push(tmp + 1);
				final[tmp + 1] = true;
			}
		}
		if (tmp + 1 < n && ratings[tmp + 1] < ratings[tmp]) {
			if (!final[tmp + 1]) {
				q.push(tmp + 1);
				final[tmp + 1] = true;
			}
			else if (final[tmp + 1] && candies[tmp + 1] >= candies[tmp]) {
				candies[tmp] = candies[tmp + 1] + 1;
				q.push(tmp);
			}
		}
		if (tmp + 1 < n && ratings[tmp + 1] > ratings[tmp]) {
			if (candies[tmp + 1] <= candies[tmp]) {
				candies[tmp + 1] = candies[tmp] + 1;
				q.push(tmp + 1);
			}
			final[tmp + 1] = true;
		}

		if (tmp - 1 >= 0 && ratings[tmp - 1] == ratings[tmp]) {
			if (!final[tmp - 1]) {
				q.push(tmp - 1);
				final[tmp - 1] = true;
			}
		}
		if (tmp - 1 >= 0 && ratings[tmp - 1] < ratings[tmp]) {
			if (!final[tmp - 1]) {
				q.push(tmp - 1);
				final[tmp - 1] = true;
			}
			else if (final[tmp - 1] && candies[tmp - 1] >= candies[tmp]) {
				candies[tmp] = candies[tmp - 1] + 1;
				q.push(tmp);
			}
		}
		if (tmp - 1 >= 0 && ratings[tmp - 1] > ratings[tmp]) {
			if (candies[tmp - 1] <= candies[tmp]) {
				candies[tmp - 1] = candies[tmp] + 1;
				q.push(tmp - 1);
			}
			final[tmp - 1] = true;
		}
	}
	for (auto &i : candies)
		cout << i << " ";
	cout << endl;
	return accumulate(candies.begin(), candies.end(), 0);
}

int main () {
	vector<int> ratings = {29,51,87,87,72,12}; // {1,0,2};
	cout << candy(ratings) << endl;
	return 0;
}