/* #LC#15
 
 Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
 
 0 <= a, b, c, d < n
 a, b, c, and d are distinct.
 nums[a] + nums[b] + nums[c] + nums[d] == target
 You may return the answer in any order.
 
 Input: nums = [1,0,-1,0,-2,2], target = 0
 Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 
 Input: nums = [2,2,2,2,2], target = 8
 Output: [[2,2,2,2]]
 
 Constraints:
 1 <= nums.length <= 200
 -109 <= nums[i] <= 109
 -109 <= target <= 109*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<int>> fourSum (vector<int>& nums, int target) {
    vector<vector<int>> solutions = {};
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size() && j != i; j++) {
            unordered_map<int, int> um;
            for (int k = 0; k < nums.size() && k != i && k != j; k++) {
                um[target - nums[i] - nums[j] - nums[k]] = k;
            }
            for (int k = 0; k < nums.size() && k != i && k != j; k++) {
                if (um.find(target - nums[i] - nums[j] - nums[k]) != um.end())
                    if (um[target - nums[i] - nums[j] - nums[k]] != k)
                        solutions.push_back({i, j, k, um[target - nums[i] - nums[j] - nums[k]]});
            }
        }
    }
    return solutions;
}

int main () {
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> solutions = fourSum(nums, target);
    for (auto i : solutions) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
