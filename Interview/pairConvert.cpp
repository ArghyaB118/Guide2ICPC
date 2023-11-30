/* Ignore numbers[i] if it is >= numbers.size() or < 0
 take i, j so that nums[i] < nums[j]
 increase count only if number of digits same and only one digit is different.
 Return the count.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> createVector (int n) {
    vector<int> nums = {};
    for (int i = 0; i < n; i++) {
        int tmp = rand() % n;
        nums.push_back(tmp);
    }
    return nums;
}

int countDigits (int num) {
    int digit = 0;
    while (num > 0) {
        digit++;
        num /= 10;
    }
    return digit;
}

bool isConvertible (int x, int y) {
    int a = 0;
    while (x > 0 && y > 0) {
        if (x % 10 != y % 10)
            a++;
        if (a > 1)
            return false;
        x /= 10; y /= 10;
    }
    return true;
}

int countCovertibles (vector<int> nums) {
    int count = 0;
    for (int i = 0; i < nums.size() && nums[i] >= 0 && nums[i] < nums.size(); i++) {
        for (int j = 0; j != i && j < nums.size() && nums[i] != nums[j] && nums[j] >= 0 && nums[j] < nums.size(); j++) {
            if (countDigits(nums[i]) == countDigits(nums[j]) && isConvertible (nums[i], nums[j])) {
                count++;
            }
        }
    }
    return count;
}


int main () {
    int n = 500;
    vector<int> nums = createVector (n);
    cout << countCovertibles (nums) << endl;
    return 0;
}
