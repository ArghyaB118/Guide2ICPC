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

int findKthLargest(vector<int>& nums, int k) {
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < nums.size(); i++) {
		if (pq.size() < k)
			pq.push(nums[i]);
		else {
			pq.push(nums[i]); pq.pop();
		}
	}
	return pq.top();
}

/* LC#1838
 
 The frequency of an element is the number of times it occurs in an array.
 
 You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

 Return the maximum possible frequency of an element after performing at most k operations.
 
 Input: nums = [1,2,4], k = 5
 Output: 3
 Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
 4 has a frequency of 3.
 
 Input: nums = [1,4,8,13], k = 5
 Output: 2
 Explanation: There are multiple optimal solutions:
 - Increment the first element three times to make nums = [4,4,8,13]. 4 has a frequency of 2.
 - Increment the second element four times to make nums = [1,8,8,13]. 8 has a frequency of 2.
 - Increment the third element five times to make nums = [1,4,13,13]. 13 has a frequency of 2.
 
 Input: nums = [3,9,6], k = 2
 Output: 1
*/

int maxFrequency (vector<int>& nums, int k) {
    if (nums.size() == 1)
        return 1;
    sort(nums.begin(), nums.end());
    int num = 0, tmp = nums[0], count = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (tmp == nums[i])
            count++;
        else {
            num = max(num, count);
            count = 1;
        }
    }
    cout << num << endl;
    for (int i = num; i < nums.size(); i++) {
        count = k, tmp = 1;
        int j = i - 1;
        while (count > 0 && j >= 0) {
            if ((nums[i] - nums[j]) <= count) {
                count = count - (nums[i] - nums[j]);
                tmp++; j--;
            }
            else
                break;
        }
        num = max(num, tmp); cout << i << " " << num << endl;
    }
    return num;
}

int main () {
	vector<int> arr{1,2,4,2,5,5,2,1,2,3,5,1};
	vector<int> heavy_hitters = topKelements(arr, 2);
	for (int i = 0; i < heavy_hitters.size(); i++)
		cout << heavy_hitters[i] << " ";
	cout << endl;

	arr = {1,2,3,4,5};
	cout << "The kth largest element: " << findKthLargest(arr, 2) << endl;
    
    arr = {1, 2, 4}; // {1,4,8,13};
    int k = 5;
    cout << maxFrequency(arr, k) << endl;
	return 0;
}
