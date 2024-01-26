/* LC#162

A peak element is an element 
that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, 
find a peak element, and return its index. 
If the array contains multiple peaks, 
return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. 
In other words, an element is always considered 
to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

Constraints:
1 <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1
nums[i] != nums[i + 1] for all valid i.

Input: nums = [1,2,3,1]
Output: 2
*/

// beats 70% LC users
int findPeakElementLinear (vector<int>& nums) {
	if (nums.size() == 1) { return 0; }
	if (nums[0] > nums[1]) { return 0; }
	int n = nums.size();
	if (nums[n - 1] > nums[n - 2]) { return n - 1; }
	// already ensured that size is > 2
	// as no consecutive elements are equal
	for (int i = 1; i < n - 1; i++) {
		if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
			return i;
	}
	return -1;
}

// beats 70% LC users! No further improvement!
int findPeakElementBinarySearch (vector<int>& nums) {
	if (nums.size() == 1) { return 0; }
	if (nums[0] > nums[1]) { return 0; }
	int n = nums.size();
	if (nums[n - 1] > nums[n - 2]) { return n - 1; }
	int left = 0, right = n - 1;
	while (left < right) {
		// int mid = (left + right) / 2;
		int mid = (left + right) >> 1;
		if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
			return mid;
		// rising slope at mid
		// value lies at the right half
		else if (nums[mid] < nums[mid + 1])
			left = mid + 1;
		// descending slope at mid
		// value lies at the left half
		else if (nums[mid] > nums[mid + 1])
			right = mid;
	}
	return -1;
}