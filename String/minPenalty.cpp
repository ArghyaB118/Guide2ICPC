/* LC#2483
 
 You are given the customer visit log of a shop represented by a 0-indexed string customers consisting only of characters 'N' and 'Y':
 
 if the ith character is 'Y', it means that customers come at the ith hour
 whereas 'N' indicates that no customers come at the ith hour.
 If the shop closes at the jth hour (0 <= j <= n), the penalty is calculated as follows:

 For every hour when the shop is open and no customers come, the penalty increases by 1.
 For every hour when the shop is closed and customers come, the penalty increases by 1.
 Return the earliest hour at which the shop must be closed to incur a minimum penalty.

 Note that if a shop closes at the jth hour, it means the shop is closed at the hour j.
 
 Input: customers = "YYNY"
 Output: 2
 Explanation:
 - Closing the shop at the 0th hour incurs in 1+1+0+1 = 3 penalty.
 - Closing the shop at the 1st hour incurs in 0+1+0+1 = 2 penalty.
 - Closing the shop at the 2nd hour incurs in 0+0+0+1 = 1 penalty.
 - Closing the shop at the 3rd hour incurs in 0+0+1+1 = 2 penalty.
 - Closing the shop at the 4th hour incurs in 0+0+1+0 = 1 penalty.
 Closing the shop at 2nd or 4th hour gives a minimum penalty. Since 2 is earlier, the optimal closing time is 2.
 
 Input: customers = "NNNNN"
 Output: 0
 Explanation: It is best to close the shop at the 0th hour as no customers arrive.
 
 Input: customers = "YYYY"
 Output: 4
 Explanation: It is best to close the shop at the 4th hour as customers arrive at each hour.*/

#include <iostream>
#include <string>
#include <queue>
using namespace std;
typedef pair<int, int> Pair;

class Compare {
public:
    bool operator () (Pair &a, Pair &b) {
        return a.first > b.first;
    }
};

int bestClosingTime (string customers) {
    int y = 0;
    for (auto & ch : customers)
        if (ch == 'Y')
            y++;
    int n = 0;
    priority_queue<Pair, vector<Pair>, Compare> pq;
    pq.push({y + n, 0});
    for (int i = 0; i < customers.length(); i++) {
        if (customers[i] == 'N')
            n++;
        else if (customers[i] == 'Y')
            y--;
        pq.push({y + n, i + 1});
    }
    /*while (!pq.empty()) {
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }*/
    return pq.top().second;
}

int main () {
    string customers = "YYNY";
    cout << bestClosingTime (customers) << endl;
    return 0;
}
