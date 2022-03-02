/*
You are given a 0-indexed array of positive integers w 
where w[i] describes the weight of the ith index.

You need to implement the function pickIndex(), 
which randomly picks an index in the range [0, w.length - 1] 
(inclusive) and returns it. The probability of picking an index i is w[i] / sum(w).

For example, if w = [1, 3], the probability of picking index 
0 is 1 / (1 + 3) = 0.25 (i.e., 25%), 
and the probability of picking index 1 is 3 / (1 + 3) = 0.75 (i.e., 75%).
*/
#include <iostream>
#include <vector>
using namespace std;

class PDF {
public:
	int cumsum;
	vector<int> nums;
	vector<int> cumsums;

	PDF (vector<int>& w) {
		int cumsum = 0;
		for (int i = 0; i < w.size(); i++) {
			cumsum += w[i];
			this->nums.push_back(w[i]);
			this->cumsums.push_back(cumsum);
		}
		this->cumsum = cumsum;
	}

	int pickIndex () {
		int randnum = rand() % this->cumsum + 1;
		for (int i = 0; i < this->cumsums.size(); i++)
			if (cumsums[i] >= randnum)
				return i;
		return -1;
	}
};

int main () {
	vector<int> w = {1,3};
	PDF* obj = new PDF(w);
	for (int i = 0; i < 10; i++) {
		cout << obj->pickIndex() << " ";
	}
	cout << endl;
	return 0;
}