/*
Given a array of positive integers. 
Find the subarray having maximum sum among all subarrays 
having unique elements and return its sum.

Example 1:
Input array = [23, 2, 23, 2, 4, 2, 6, 7]

Output: 23 + 2 + 4 = 29

Example 2:
Input array = [1, 2, 3, 5, 3, 20]

We maintain the following two integers and one hashmap as we traverse through the vector.
1. runningsum = 23
2. maxsum = 23
3. unordered_map<int, int> dict {3, 20}
When we see the repeatation:
1. maxSum = max(maxSum, runningSum)
2. runningSum = 0 + repeatedElement
3. hashmap is cleared
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int maxSum (vector<int>& nums) {
    int maxSum = 0, running_sum = 0;
    unordered_map<int, int> dict;
    for (int i = 0; i < nums.size(); i++) {
        if (dict.find(nums[i]) == dict.end()) {
            dict[nums[i]] = i;
            running_sum += nums[i];
            maxSum = max(maxSum, running_sum);
        }
        else {
            int pos = dict[nums[i]];
            dict[nums[i]] = i;
            unordered_map<int, int>::iterator it;
            vector<int> deletes;
            for (it = dict.begin(); it != dict.end(); it++) {
                if (it->second < pos) {
                    running_sum -= it->first;
                    //dict.erase(it);
                    deletes.push_back(it->first);
                }
            }
            for (int i = 0; i < deletes.size(); i++) {
                dict.erase(deletes[i]);
            }
            maxSum = max(maxSum, running_sum);
        }
    }
    return maxSum;
}

int main () {
    vector<int> nums{23, 2, 23, 2, 4, 2, 6, 7}; //{1,2,3,5,3,20};
    cout << maxSum (nums) << endl;
    return 0;
}