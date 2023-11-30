/* LC#2184
You are given integers height and width which specify the dimensions of a brick wall you are building. You are also given a 0-indexed array of unique integers bricks, where the ith brick has a height of 1 and a width of bricks[i]. You have an infinite supply of each type of brick and bricks may not be rotated.
 
 Each row in the wall must be exactly width units long. For the wall to be sturdy, adjacent rows in the wall should not join bricks at the same location, except at the ends of the wall.

 Return the number of ways to build a sturdy wall. Since the answer may be very large, return it modulo 109 + 7.
 
 
 Idea:
 1. Break the problem
    - find all possible brick arrangements.
        - BFS
    - find the valid couples among them.
        - find the interim borders of bricks
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<vector<int>, int> arrangement;

void printVec (vector<vector<int>>& vec) {
    for (auto i : vec) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}


vector<vector<int>> brickArrangements (int width, vector<int>& bricks) {
    queue<arrangement> q; vector<vector<int>> arrangements = {};
    for (int i : bricks)
        q.push({{i}, i});
    while (!q.empty()) {
        arrangement a = q.front(); q.pop();
        if (a.second == width)
            arrangements.push_back(a.first);
        else if (a.second < width) {
            for (int i : bricks) {
                arrangement a0 = a;
                a0.first.push_back(i);
                a0.second += i;
                q.push(a0);
            }
        }
    }
    return arrangements;
}

vector<vector<int>> validArrangements (vector<vector<int>>& arrangements) {
    vector<vector<int>> Varrangements (arrangements.size(), vector<int> {});
    // brick boundaries are saved from 0 to length - 2 index
    for (int i = 0; i < arrangements.size(); i++) {
        for (int j = 1; j < arrangements[i].size(); j++)
            arrangements[i][j] += arrangements[i][j - 1];
    }
    printVec (arrangements);
    //
    for (int i = 0; i < arrangements.size(); i++) {
        for (int j = 0; j != i && j < arrangements.size(); j++) {
            bool tmp = true;
            for (int k = 0; k < arrangements[i].size() - 1; k++) {
                if (find(arrangements[j].begin(), arrangements[j].end(), arrangements[i][k]) != arrangements[j].end())
                    tmp = false;
            }
            if (tmp)
                Varrangements[i].push_back(j);
        }
    }
    return Varrangements;
}

int buildWall (int height, int width, vector<int>& bricks) {
    vector<vector<int>> arrangements = brickArrangements (width, bricks); printVec (arrangements);
    vector<vector<int>> Varrangements = validArrangements (arrangements); printVec (Varrangements);
    if (height == 1)
        return arrangements.size();
    return 0;
}

int main () {
    int height = 2, width = 3;
    vector<int> bricks = {1,2};
    cout << buildWall(height, width, bricks) << endl;
    return 0;
}
