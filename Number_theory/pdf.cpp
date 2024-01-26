/* LC#528
 
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

class PDFOpt {
private:
    vector<int> cumsums;
public:
    PDFOpt (vector<int>& w) {
        int cumsum = 0;
        for (int i = 0; i < w.size(); i++) {
            cumsum += w[i];
            this->cumsums.push_back(cumsum);
        }
    }

    int pickIndex () {
        int randnum = rand() % this->cumsums.back() + 1;
        // linear search on the cumsum array :(
        for (int i = 0; i < this->cumsums.size(); i++)
            if (this->cumsums[i] >= randnum)
                return i;
        return -1;
    }
    
    int pickIndex2 () {
        if (this->cumsums.size() == 1)
            return 0;
        int randnum = rand() % this->cumsums.back() + 1;
        //cout << randnum << endl;
        // binary search on the cumsum array with repeated doubling :)
        int left = 0, right = cumsums.size() - 1, jump = 1;
        while (left < right) {
            if (cumsums[left] >= randnum)
                return left;
            else if (cumsums[left] < randnum && cumsums[left + 1] >= randnum)
                return (left + 1);
            else if (left + jump < right) {
                left = left + jump;
                jump *= 2;
            }
            else {
                jump = 1;
            }
        }
        return -1;
    }

    // beats aroundd ~75% LC users
    int pickIndex3 () {
        if (this->cumsums.size() == 1)
            return 0;
        int randnum = rand() % this->cumsums.back() + 1;
        // binary search on the cumsum array
        int left = 0, right = cumsums.size() - 1;
        while (left < right) {
            if (cumsums[left] >= randnum)
                return left;
            if (right == left)
                return left;
            if (right == left + 1)
                if (cumsums[right] >= randnum && cumsums[left] < randnum)
                    return right;
            int mid = left + (right - left) / 2;
            if (cumsums[mid] == randnum)
                return mid;
            else if (cumsums[mid] > randnum)
                right = mid;
            else
                left = mid;
        }
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
	
    PDFOpt* obj1 = new PDFOpt(w);
    for (int i = 0; i < 10; i++) {
        cout << obj1->pickIndex2() << " ";
    }
    cout << endl;
    
    return 0;
}
