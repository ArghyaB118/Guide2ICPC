/*The power of an integer x is defined as the number of steps needed to transform x into 1 using the following steps:
 
 if x is even then x = x / 2
 if x is odd then x = 3 * x + 1
 For example, the power of x = 3 is 7 because 3 needs 7 steps to become 1 (3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1).

 Given three integers lo, hi and k. The task is to sort all integers in the interval [lo, hi] by the power value in ascending order, if two or more integers have the same power value sort them by ascending order.

 Return the kth integer in the range [lo, hi] sorted by the power value.

 Notice that for any integer x (lo <= x <= hi) it is guaranteed that x will transform into 1 using these steps and that the power of x is will fit in a 32-bit signed integer.
 
 Input: lo = 12, hi = 15, k = 2
 Output: 13
 Explanation: The power of 12 is 9 (12 --> 6 --> 3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1)
 The power of 13 is 9
 The power of 14 is 17
 The power of 15 is 17
 The interval sorted by the power value [12,13,14,15]. For k = 2 answer is the second element which is 13.
 Notice that 12 and 13 have the same power value and we sorted them in ascending order. Same for 14 and 15.
*/

#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
typedef pair<int, int> p;

struct cmp {
    bool operator() (const p &a, const p &b) {
        if (a.second < b.second)
            return false;
        else if (a.second == b.second) {
            if (a.first <= b.first)
                return false;
            return true;
        }
        return true;
    };
};

int power (int i, int j) {
    if (i == 1)
        return j;
    if (i % 2 == 0) {
        i /= 2; j++;
        return power(i, j);
    }
    if (i % 2 != 0) {
        i = 3 * i + 1; j++;
        return power(i, j);
    }
    return -1;
}

int getKth (int lo, int hi, int k) {
    priority_queue<p, vector<p>, cmp> pq;
    for (int i = lo; i <= hi; i++) {
        cout << i << " " << power(i, 0) << endl;
        pq.push({i, power(i, 0)});
    }
    for (int i = 0; i < k - 1; i++) {
        cout << pq.top().first << endl;
        pq.pop();
    }
    return pq.top().first;
}

// Maybe defining this global structure takes away the advantage
unordered_map<int, int> dict;
int power2 (int i, int j) {
    if (i == 1) {
        dict[i] = j;
        return j;
    }
    else if (dict.find(i) != dict.end())
        return dict[i];
    else if (i % 2 == 0) {
        i /= 2; j++;
        return power2 (i, j);
    }
    else if (i % 2 != 0) {
        i = 3 * i + 1; j++;
        return power2 (i, j);
    }
    return -1;
}

int getKth2 (int lo, int hi, int k) {
    priority_queue<p, vector<p>, cmp> pq;
    for (int i = lo; i <= hi; i++)
        pq.push({i, power2 (i, 0)});
    for (int i = 0; i < k - 1; i++)
        pq.pop();
    return pq.top().first;
}

int main () {
    int lo = 12, hi = 15, k = 2;
    cout << getKth2 (lo, hi, k) << endl;
    return 0;
}
