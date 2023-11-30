/* LC#2475
 
 You are given a 0-indexed array of positive integers nums. Find the number of triplets (i, j, k) that meet the following conditions:
 
 0 <= i < j < k < nums.length
 nums[i], nums[j], and nums[k] are pairwise distinct.
 In other words, nums[i] != nums[j], nums[i] != nums[k], and nums[j] != nums[k].
 Return the number of triplets that meet the conditions.
 
 Input: nums = [4,4,2,4,3]
 Output: 3
 Explanation: The following triplets meet the conditions:
 - (0, 2, 4) because 4 != 2 != 3
 - (1, 2, 4) because 4 != 2 != 3
 - (2, 3, 4) because 2 != 4 != 3
 Since there are 3 triplets, we return 3.
 Note that (2, 0, 4) is not a valid triplet because 2 > 0.
 
 Input: nums = [1,1,1,1,1]
 Output: 0
 Explanation: No triplets meet the conditions so we return 0.*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int unequalTriplets(vector<int>& nums) {
    unordered_map<int, int> hashmap;
    for (auto & i : nums) {
        if (hashmap.find(i) != hashmap.end())
            hashmap[i]++;
        else
            hashmap[i] = 1;
    }
    if (hashmap.size() < 3)
        return 0;
    else if (hashmap.size() == 3) {
        int count = 1;
        for (auto it = hashmap.begin(); it != hashmap.end(); it++)
            count *= it->second;
        return count;
    }
    int count = 0;
    for (auto it1 = hashmap.begin(); it1 != hashmap.end(); it1++)
        for (auto it2 = hashmap.begin(); it2->first != it1->first && it2 != hashmap.end(); it2++)
            for (auto it3 = hashmap.begin(); it3->first != it2->first && it3->first != it1->first && it3 != hashmap.end(); it3++)
                count += (it1->second * it2->second * it3->second);

    return count;
}

int main () {
    vector<int> nums = {4,4,2,4,3,5};
    cout << unequalTriplets (nums) << endl;
    return 0;
}
