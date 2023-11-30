/* LC#1423

 There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.
 
 In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

 Your score is the sum of the points of the cards you have taken.

 Given the integer array cardPoints and the integer k, return the maximum score you can obtain.*/

#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
using namespace std;

struct entry {
    int start, end, k, sum;
};

int maxScore2 (vector<int>& cardPoints, int k) {
    queue<entry> q;
    int score = 0, n = cardPoints.size();
    if (n == k)
        return accumulate(cardPoints.begin(), cardPoints.end(), 0);
    q.push({1, n - 1, 1, cardPoints[0]}); q.push({0, n - 2, 1, cardPoints[n - 1]});
    while (!q.empty()) {
        entry e = q.front(); q.pop();
        if (e.k < k && e.start < e.end) {
            q.push({e.start + 1, e.end, e.k + 1, e.sum + cardPoints[e.start]});
            q.push({e.start, e.end - 1, e.k + 1, e.sum + cardPoints[e.end]});
        }
        cout << e.start << e.end << e.k << " " << e.sum << endl;
        if (e.k == k)
            score = max(score, e.sum);
    }
    return score;
}


// You can break k in two parts k1 and k2, where k1 + k2 = k
// take k1 numbers from beginning and k2 from the end
int maxScore (vector<int>& cardPoints, int k) {
    int score = 0, n = cardPoints.size();
    if (n == k)
        return accumulate(cardPoints.begin(), cardPoints.end(), 0);
    for (int i = 0; i < k; i++) {
        score += cardPoints[i];
    }
    int tmp = score;
    for (int i = 0; i < k; i++) {
        tmp -= cardPoints[k - 1 - i];
        tmp += cardPoints[n - 1 - i];
        score = max(score, tmp);
    }
    return score;
}

int main () {
    vector<int> cardPoints = {1,79,80,1,1,1,200,1}; // {1,2,3,4,5,6,1};
    int k = 3;
    cout << maxScore (cardPoints, k) << endl;
    return 0;
}
