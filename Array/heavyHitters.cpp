/* LC#347

Given an integer array nums 
and an integer k, 
return the k most frequent elements. 
You may return the answer in any order.

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
*/

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

// beats ~83% LC users
vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> heavy_hitters;
    unordered_map<int,int> count;
    for (int i = 0; i < nums.size(); i++) {
        if (count.find(nums[i]) == count.end())
            count[nums[i]] = 1;
        else
            count[nums[i]]++;
    }
    priority_queue<Pair, vector<Pair>, cmp> pq(count.begin(), count.end());
    while (k > 0) {
        heavy_hitters.push_back(pq.top().first);
        pq.pop(); k--;
    }
    return heavy_hitters;
}

/* LC#215

Given an integer array nums and an integer k, 
return the kth largest element in the array.

Note that it is the kth largest element 
in the sorted order, not the kth distinct element.

Can you solve it without sorting?
*/

// beats ~70% LC users
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int &num : nums) {
        if (pq.size() < k)
            pq.push(num);
        else if (pq.size() == k && num > pq.top()) {
            pq.pop(); pq.push(num);
        }
    }
    return pq.top();
}

/* LC#1838
 
 The frequency of an element is the number of times 
 it occurs in an array.
 
 You are given an integer array nums and an integer k. 
 In one operation, you can choose an index of nums 
 and increment the element at that index by 1.

 Return the maximum possible frequency of an element 
 after performing at most k operations.
 
 Input: nums = [1,2,4], k = 5
 Output: 3
 Explanation: Increment the first element three times 
 and the second element two times to make nums = [4,4,4].
 4 has a frequency of 3.
 
 Input: nums = [1,4,8,13], k = 5
 Output: 2
 Explanation: There are multiple optimal solutions:
 - Increment the first element three times to make nums = [4,4,8,13]. 
 4 has a frequency of 2.
 - Increment the second element four times to make nums = [1,8,8,13]. 
 8 has a frequency of 2.
 - Increment the third element five times to make nums = [1,4,13,13]. 
 13 has a frequency of 2.
 
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
	cout << "The kth largest element: " << findKthLargest2(arr, 2) << endl;
    
    arr = {1, 2, 4}; // {1,4,8,13};
    int k = 5;
    cout << maxFrequency(arr, k) << endl;
	return 0;
}
