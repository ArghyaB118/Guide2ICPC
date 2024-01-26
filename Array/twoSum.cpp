/* LC#1

 Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

 You may assume that each input would have exactly one solution, and you may not use the same element twice.

 You can return the answer in any order.
 
 
 Idea:

 Clarification questions:
 1. data types
 2. length of input (in memory or out-of-memory)
 3. negative numbers

 Solution 1: Brute-force: O(n^2)
 Nested for loops: for every pair of elements, check if the sum os the target or not.
 
 Solution 2: Binary-search: O(n log n)
 For every element num[i], binary search in the array if target - num[i] is present or not.
 
 Solution 3: Two-pointer: O(n)
 Note 1: Only works if the array is sorted. O(n log n) to sort the array if it is unsorted.
 Note 2: But, it can allow repeated elements.
 Initiate two pointer at index left = 0 and right = n - 1.
 if the sum == target, return the indices.
 else if the sum < target, left++.
 else if the sum > target, right--.
 
 Solution 4: Hashmap: O(n)
 Note 1: This method works for an unsorted array as well.
 Note 2: If I need to return the indices, instead of an unordered_set, we will use an unordered_map.
 Note 3: Downside: This method will not work if there are repeated elements (easy workaround is there).
 Make a pass and store all the elements in an unordered_set.
 For every element num[i], if find(target - num[i]) == true, return true. Every lookup is O(1) amortized lookup.
 
 Solution 4a: Still Hashmap: O(n)
 Make only one pass.
 maintain an unordered_set
 For num[i], if find (num[i]) == true, return true
 else target - num[i] is inserted in the unordered_set.
 
 Test:
 Make example inputs + test your solution.
*/


#include <iostream>
#include <vector>
using namespace std;

// Two sums problems after sorting the array
// O(sorting) + O(n) = O(n log n)
// Only works for the sorted array or when you need the boolean response.
// Otherwise the indices are lost
bool twoSum(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end()); // Sorting: O(n log n)
	int i = 0, j = nums.size() - 1;
	// Traverese the array with two pointers: O(n)
	while (i < j) { 
		if (nums[i] + nums[j] == target) {
			cout << "The indices are: " << i << ", " << j << endl;
			return true;
		}
		else if (nums[i] + nums[j] >= target)
			j--;
		else if (nums[i] + nums[j] <= target)
			i++;
	}
	return false;
} 

// Brute force + returns indices
vector<int> twoSum(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        int num = target - nums[i];
        for (int j = 0; j < nums.size(); j++) {
            if (j != i) {
                if (nums[j] == num)
                    return {i, j};
            }
        }
    }
    return {-1,-1};
}

// Use a hashmap: O(1) lookup for the target - nums[i]
// Overall cost: O(n)
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hashmap;
    for (int i = 0; i < nums.size(); i++)
        hashmap.insert(make_pair(nums[i], i));
    for (int i = 0; i < nums.size(); i++) {
        if (hashmap.find(target - nums[i]) != hashmap.end()) {
            if (i != hashmap[target - nums[i]])
                return {i, hashmap[target - nums[i]]};
        }
    }
    return {-1,-1};
}

/* LC#167 

Two Sum II - Input Array Is Sorted

Given a 1-indexed array of integers numbers 
that is already sorted in non-decreasing order, 
find two numbers such that they add up to a specific target number. 
Let these two numbers be numbers[index1] and numbers[index2] 
where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, 
index1 and index2, added by one as an integer array 
[index1, index2] of length 2.

The tests are generated 
such that there is exactly one solution. 
You may not use the same element twice.

Your solution must use only constant extra space.
Hence, you may not use any additional data container like hashset.
*/

int binary_search (vector<int>& numbers, int target) {
	int left = 0, right = numbers.size() - 1;
	while (left < right) {
		if (left == right - 1) {
			if (numbers[left] == target)
				return left;
			else if (numbers[right] == target)
				return right;
			return -1;
		}
		int mid = left + (right - left) / 2;
		if (numbers[mid] == target)
			return mid;
		else if (numbers[mid] < target) {
			left = mid;
		}
		else if (numbers[mid] > target) {
			right = mid;
		}
	}
	return -1;
}

vector<int> twoSum (vector<int>& numbers, int target) {
	for (int i = 0; i < numbers.size(); i++) {
		if (i > 0 && numbers[i] == numbers[i - 1])
			continue;
		if (2 * numbers[i] == target && i + 1 < numbers.size()) {
			if (numbers[i + 1] == numbers[i])
				return {i + 1, i + 2};
			else
				return {-1, -1};
		}
		int j = binary_search(numbers, target - numbers[i]);
		if (j > 0)
			return {i + 1, j + 1};
	}
	return {-1, -1};
}

int main() {
	std::vector<int> nums{2, 7, 15, 11};
	int target = 18;
	cout << "The two sum problem could be solved: " << boolalpha << twoSum(nums, target) << endl;
}
