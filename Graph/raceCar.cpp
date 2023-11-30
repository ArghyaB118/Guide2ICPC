/* LC#818
 Your car starts at position 0 and speed +1 on an infinite number line. Your car can go into negative positions. Your car drives automatically according to a sequence of instructions 'A' (accelerate) and 'R' (reverse):

When you get an instruction 'A', your car does the following:
position += speed
speed *= 2
When you get an instruction 'R', your car does the following:
If your speed is positive then speed = -1
otherwise speed = 1
Your position stays the same.
For example, after commands "AAR", your car goes to positions 0 --> 1 --> 3 --> 3, and your speed goes to 1 --> 2 --> 4 --> -1.

Given a target position target, return the length of the shortest sequence of instructions to get there.

Input: target = 3
Output: 2
Explanation:
The shortest instruction sequence is "AA".
Your position goes from 0 --> 1 --> 3.

Input: target = 6
Output: 5
Explanation:
The shortest instruction sequence is "AAARA".
Your position goes from 0 --> 1 --> 3 --> 7 --> 7 --> 6. */

// Idea: Run BFS

#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

struct container {
    int moves, pos, vel;
};

int racecar (int target) {
    queue<container> q;
    container c{0,0,1};
    q.push(c);
    while (!q.empty()) {
        c = q.front(); q.pop();
        // (moves) moves, (pos) position, (vel) velocity)
        int moves = c.moves, pos = c.pos, vel = c.vel;
        if (pos == target) return moves;
        // 1. Stop whenever we've passed twice the magnitude of target.
        if (abs(pos) > 2 * target) continue;
        // 2. Always consider moving the car in the direction it is already going
        q.push({moves + 1, pos + vel, 2 * vel});
        // 3. Always try to go reverse as well
        q.push({moves + 1, pos, (vel > 0) ? -1 : 1});
    }
    return 0;
}

// Don't Reverse unnecessarily
int racecarOpt (int target) {
    queue<container> q;
    container c{0,0,1};
    q.push(c);
    while (!q.empty()) {
        c = q.front(); q.pop();
        // (moves) moves, (pos) position, (vel) velocity)
        int moves = c.moves, pos = c.pos, vel = c.vel;
        if (pos == target) return moves;
        // 1. Stop whenever we've passed twice the magnitude of target.
        if (abs(pos) > 2 * target) continue;
        // 2. Always consider moving the car in the direction it is already going
        q.push({moves + 1, pos + vel, 2 * vel});
        // 3. Only consider changing the direction of the car if one of the following conditions is true
        //    i.  The car is driving away from the target.
        //    ii. The car will pass the target in the next move.
        if ((pos + vel > target && vel > 0) || (pos + vel < target && vel < 0))
            q.push({moves + 1, pos, (vel > 0) ? -1 : 1});
    }
    return 0;
}

// Don't Reverse unnecessarily
// Better than naive BFS O(2^n)
int racecarVisited (int target) {
    queue<container> q;
    unordered_set<int> visited; visited.insert(0);
    container c{0,0,1};
    q.push(c);
    while (!q.empty()) {
        c = q.front(); q.pop();
        // (moves) moves, (pos) position, (vel) velocity)
        int moves = c.moves, pos = c.pos, vel = c.vel;
        cout << moves << " " << pos << " " << vel << endl;
        if (pos == target) return moves;
        // 1. Stop whenever we've passed twice the magnitude of target.
        if (abs(pos) > 2 * target) continue;
        // 2. Always consider moving the car in the direction it is already going
        q.push({moves + 1, pos + vel, 2 * vel});
        // 3. Go reverse only when it is not visited
        if (visited.find(pos) == visited.end())
            q.push({moves + 1, pos, (vel > 0) ? -1 : 1});
    }
    return 0;
}

// 3. Only consider changing the direction of the car if one of the following conditions is true
//    i.  The car is driving away from the target.
//    ii. The car will pass the target in the next move.
// if ((pos + vel > target && vel > 0) || (pos + vel < target && vel < 0)) {
//    q.push({moves + 1, pos, (vel > 0) ? -1 : 1});
//    cout << "R";
int main () {
    int target = 6;
    cout << racecar(target) << " " << racecarOpt(target) << " " << racecarVisited(target) << endl;
    return 0;
}

