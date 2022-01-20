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
				return this->nums[i];
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