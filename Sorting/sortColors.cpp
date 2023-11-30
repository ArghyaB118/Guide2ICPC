/* LC#75
 
 Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
 
 We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
 nums[i] is either 0, 1, or 2.
 You must solve this problem without using the library's sort function.
 
 Follow up: Could you come up with a one-pass algorithm using only constant extra space?*/

#include <iostream>
#include <vector>
using namespace std;

// two-pass algorithm using counting sort
void sortColors (vector<int>& nums) {
    int counts[3] = { 0 };
    for (int i : nums)
        counts[i]++;
    for (int i = 0; i < nums.size(); i++) {
        if (i < counts[0])
            nums[i] = 0;
        else if (i < counts[0] + counts[1])
            nums[i] = 1;
        else
            nums[i] = 2;
    }
    return;
}

/* one-pass algorithm: only works for 3 colors
 Idea:
 1. If you see 0, swap with left pointer.
 2. If you see 2, swap with right pointer.
 3. If you see 1, increase counter.
 */
void sortColorsOnePass (vector<int>& nums) {
    int l = 0, r = nums.size() - 1, i = 0, tmp = 0;
    // for (int i = 0; i < nums.size(); i++)
    while (i <= r) {
        if (nums[i] == 0) {
            tmp = nums[l];
            nums[l] = nums[i];
            nums[i] = tmp; l++;
            if (i < l)
                i++;
        }
        else if (nums[i] == 2) {
            tmp = nums[r];
            nums[r] = nums[i];
            nums[i] = tmp; r--;
        }
        else
            i++;
    }
    return;
}

int main () {
    vector<int> nums = {2,0,2,1,1,0};
    for (int i : nums)
        cout << i << " ";
    cout << endl;
    sortColors (nums);
    for (int i : nums)
        cout << i << " ";
    cout << endl;
    nums = {2, 0, 1}; // {2,0,2,1,1,0};
    sortColorsOnePass (nums);
    for (int i : nums)
        cout << i << " ";
    cout << endl;
    return 0;
}

