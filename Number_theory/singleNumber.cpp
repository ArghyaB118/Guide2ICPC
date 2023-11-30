/* Given a non-empty array of integers nums,
 every element appears twice except for one. Find that single one.
 You must implement a solution with a linear runtime complexity
 and use only constant extra space. */

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Idea: 0 xor a = a and a xor a = 0
// Hence, product(nums[i]) forall i = single number
int singleNumber (vector<int>& nums) {
    int result = 0;
    for (int i = 0; i < nums.size(); i++) {
        result = result ^ nums[i];
    }
    return result;
}

int singleNumberOpt (vector<int>& nums) {
    int result = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        nums[0] = nums[0] ^ nums[i];
    }
    return nums[0];
}

// O(1) insert, lookup, and delete in expectation
// overall cost = O(n)
int singleNumberHash (vector<int>& nums) {
    unordered_set<int> hashset;
    for (int i = 0; i < nums.size(); i++) {
        if (hashset.find(nums[i]) != hashset.end())
            hashset.erase(nums[i]);
        else
            hashset.insert(nums[i]);
    }
    unordered_set<int> ::iterator i = hashset.begin();
    return *i;
}

int main () {
    vector<int> nums = {2, 1, 4, 2, 1};
    cout << singleNumber (nums) << " " << singleNumberOpt (nums) << endl;
    nums = {2, 1, 4, 2, 1};
    cout << singleNumberHash (nums) << endl;
    return 0;
}
