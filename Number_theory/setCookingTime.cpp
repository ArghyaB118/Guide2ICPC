/*A generic microwave supports cooking times for:
 
 at least 1 second.
 at most 99 minutes and 99 seconds.
 To set the cooking time, you push at most four digits. The microwave normalizes what you push as four digits by prepending zeroes. It interprets the first two digits as the minutes and the last two digits as the seconds. It then adds them up as the cooking time. For example,

 You push 9 5 4 (three digits). It is normalized as 0954 and interpreted as 9 minutes and 54 seconds.
 You push 0 0 0 8 (four digits). It is interpreted as 0 minutes and 8 seconds.
 You push 8 0 9 0. It is interpreted as 80 minutes and 90 seconds.
 You push 8 1 3 0. It is interpreted as 81 minutes and 30 seconds.
 You are given integers startAt, moveCost, pushCost, and targetSeconds. Initially, your finger is on the digit startAt. Moving the finger above any specific digit costs moveCost units of fatigue. Pushing the digit below the finger once costs pushCost units of fatigue.

 There can be multiple ways to set the microwave to cook for targetSeconds seconds but you are interested in the way with the minimum cost.

 Return the minimum cost to set targetSeconds seconds of cooking time.

 Remember that one minute consists of 60 seconds.

 Input: startAt = 1, moveCost = 2, pushCost = 1, targetSeconds = 600
 Output: 6
 Explanation: The following are the possible ways to set the cooking time.
 - 1 0 0 0, interpreted as 10 minutes and 0 seconds.
   The finger is already on digit 1, pushes 1 (with cost 1), moves to 0 (with cost 2), pushes 0 (with cost 1), pushes 0 (with cost 1), and pushes 0 (with cost 1).
   The cost is: 1 + 2 + 1 + 1 + 1 = 6. This is the minimum cost.
 - 0 9 6 0, interpreted as 9 minutes and 60 seconds. That is also 600 seconds.
   The finger moves to 0 (with cost 2), pushes 0 (with cost 1), moves to 9 (with cost 2), pushes 9 (with cost 1), moves to 6 (with cost 2), pushes 6 (with cost 1), moves to 0 (with cost 2), and pushes 0 (with cost 1).
   The cost is: 2 + 1 + 2 + 1 + 2 + 1 + 2 + 1 = 12.
 - 9 6 0, normalized as 0960 and interpreted as 9 minutes and 60 seconds.
   The finger moves to 9 (with cost 2), pushes 9 (with cost 1), moves to 6 (with cost 2), pushes 6 (with cost 1), moves to 0 (with cost 2), and pushes 0 (with cost 1).
   The cost is: 2 + 1 + 2 + 1 + 2 + 1 = 9.
 
 Input: startAt = 0, moveCost = 1, pushCost = 2, targetSeconds = 76
 Output: 6
 Explanation: The optimal way is to push two digits: 7 6, interpreted as 76 seconds.
 The finger moves to 7 (with cost 1), pushes 7 (with cost 2), moves to 6 (with cost 1), and pushes 6 (with cost 2). The total cost is: 1 + 2 + 1 + 2 = 6
 Note other possible ways are 0076, 076, 0116, and 116, but none of them produces the minimum cost.
 
 Constraints:

 0 <= startAt <= 9
 1 <= moveCost, pushCost <= 105
 1 <= targetSeconds <= 6039*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int minCostSetTime (int startAt, int moveCost, int pushCost, int targetSeconds) {
    vector<int> possible = {};
    if (targetSeconds < 100)
        possible.push_back(targetSeconds);
    if (targetSeconds / 60 > 0) {
        int minutes = targetSeconds / 60;
        minutes = minutes * 100 + (targetSeconds % 60);
        possible.push_back(minutes);

        if (targetSeconds % 60 <= 39) {
            minutes = targetSeconds / 60 - 1;
            minutes = minutes * 100 + (targetSeconds % 60) + 60;
            possible.push_back(minutes);
        }
    }
    
    int cost = 1000000;
    for (auto i : possible) {
        int currAt = startAt; cout << "f" << currAt << endl;
        cout << i << endl;
        int tmpCost = 0; bool start = false;
        if (i / 1000 != 0) {
            start = true;
            if (i / 1000 != currAt)
                tmpCost += moveCost;
            tmpCost += pushCost;
            currAt = i / 1000; cout << "f" << currAt << endl;
        }
        i = i % 1000;
        if (start == true || i / 100 != 0) {
            start = true;
            if ((i / 100) != currAt) {
                cout << "e" << (i / 100) << currAt << startAt << endl;
                tmpCost += moveCost;
            }
            tmpCost += pushCost;
            currAt = i / 100;
        }
        i = i % 100;
        if (start == true || i / 10 != 0) {
            start = true;
            if (i / 10 != currAt)
                tmpCost += moveCost;
            tmpCost += pushCost;
            currAt = i / 10;
        }
        i = i % 10;
        if (start == true || i / 1 != 0) {
            start = true;
            if (i / 1 != currAt)
                tmpCost += moveCost;
            tmpCost += pushCost;
            currAt = i / 1;
        }
        cost = min(cost, tmpCost);
    }
    return cost;
}

int main () {
    int startAt = 4, moveCost = 7, pushCost = 6, targetSeconds = 312;
    // int startAt = 1, moveCost = 2, pushCost = 1, targetSeconds = 600;
    cout << minCostSetTime (startAt, moveCost, pushCost, targetSeconds) << endl;
    return 0;
}
