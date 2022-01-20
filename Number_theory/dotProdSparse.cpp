#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class SparseVector {
	unordered_map<int, int> hashmap;
public:
	SparseVector (vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != 0)
				hashmap[i] = nums[i];
		}
	}

	int dotProduct (SparseVector& vec) {
		int product = 0;
		unordered_map<int, int>::iterator it = this->hashmap.begin();
		while (it != this->hashmap.end()) {
			if (vec.hashmap.find(it->first) != vec.hashmap.end())
				product += it->second * vec.hashmap[it->first];
			it++;
		}
		return product;
	}
};

int main () {
	vector<int> nums1{0,1,0,0,2,0,0}, nums2{1,0,0,0,3,0,4};
	SparseVector v1(nums1), v2(nums2);
	cout << "The dot product is: " << v1.dotProduct(v2) << endl;
	return 0;
}