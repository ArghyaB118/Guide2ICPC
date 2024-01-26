/* LC#398

Given an integer array nums with possible duplicates, 
randomly output the index of a given target number. 
You can assume that 
the given target number must exist in the array.

Implement the RandomPickIndex class:

RandomPickIndex(int[] nums) 
Initializes the object with the array nums.

int pick(int target) 
Picks a random index i from nums where nums[i] == target. 
If there are multiple valid i's, 
then each index should have an equal probability of returning.
*/

// beats ~70% LC users
class RandomPickIndex {
private:
    unordered_map<int, vector<int>> target_indices;
public:
    RandomPickIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (target_indices.find(nums[i]) == target_indices.end())
                target_indices[nums[i]] = {i};
            else
                target_indices[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int size = target_indices[target].size();
        int pick = rand() % size;
        return target_indices[target][pick];
    }
};