/*A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Given the locations and heights of all the buildings, return the skyline formed by these buildings collectively.

The geometric information of each building is given in the array buildings where buildings[i] = [lefti, righti, heighti]:
lefti is the x coordinate of the left edge of the ith building.
righti is the x coordinate of the right edge of the ith building.
heighti is the height of the ith building.
You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.
buildings is sorted by lefti in non-decreasing order.

The skyline should be represented as a list of "key points" sorted by their x-coordinate in the form [[x1,y1],[x2,y2],...]. Each key point is the left endpoint of some horizontal segment in the skyline except the last point in the list, which always has a y-coordinate 0 and is used to mark the skyline's termination where the rightmost building ends. Any ground between the leftmost and rightmost buildings should be part of the skyline's contour.*/

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void deduplicate (vector<vector<int>>& skyLine) {
    vector<int> tmp;
    int i = 0;
    while (i < skyLine.size()) {
        if (tmp.empty()) {
            tmp = skyLine[i]; i++;
        }
        else if (tmp[1] != skyLine[i][1] && tmp[0] != skyLine[i][0]) {
            tmp = skyLine[i]; i++;
        }
        else if (tmp[1] == skyLine[i][1])
            skyLine.erase(skyLine.begin() + i);
        else if (tmp[0] == skyLine[i][0]) {
            skyLine[i - 1][1] = max(tmp[1], skyLine[i][1]);
            tmp[1] = max(tmp[1], skyLine[i][1]);
            skyLine.erase(skyLine.begin() + i);
        }
    }
}

vector<vector<int>> getSkyline (vector<vector<int>>& buildings) {
    int xlimit = 0;
    vector<vector<int>> skyLine;
    for (int i = 0; i < buildings.size(); i++) {
        if (buildings[i][0] >= xlimit) {
            if (xlimit != 0 && buildings[i][0] > xlimit)
                skyLine.push_back({xlimit, 0});
            skyLine.push_back({buildings[i][0], buildings[i][2]});
            xlimit = buildings[i][1];
        }
        else if (buildings[i][0] >= skyLine.back()[0]) {
            if (buildings[i][2] >= skyLine.back()[1] && xlimit <= buildings[i][1]) {
                skyLine.push_back({buildings[i][0], buildings[i][2]});
                xlimit = buildings[i][1];
            }
            else if (buildings[i][2] >= skyLine.back()[1] && xlimit > buildings[i][1]) {
                int tmp = skyLine.back()[1];
                skyLine.push_back({buildings[i][0], buildings[i][2]});
                skyLine.push_back({buildings[i][1], tmp});
            }
            else if (buildings[i][2] < skyLine.back()[1] && xlimit < buildings[i][1]) {
                skyLine.push_back({xlimit, buildings[i][2]});
                xlimit = buildings[i][1];
            }
        }
        else {
            if (xlimit <= buildings[i][1]) {
                skyLine.push_back({xlimit, buildings[i][2]});
                xlimit = buildings[i][1];
            }
            int j = skyLine.size() - 1;
            while (j >= 0 && skyLine[j][0] >= buildings[i][0]) {
                if (skyLine[j][0] < buildings[i][1] && skyLine[j][0] >= buildings[i][0]) {
                    skyLine[j][1] = max(skyLine[j][1], buildings[i][2]);
                }
                j--;
            }
            if (j >= 0 && skyLine[j][1] < buildings[i][2])
                skyLine.insert(skyLine.begin() + j + 1, {buildings[i][0], buildings[i][2]});
        }
    }
    skyLine.push_back({xlimit, 0});
    deduplicate (skyLine);
    return skyLine;
}

int main () {
    vector<vector<int>> buildings = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    vector<vector<int>> skyLine = getSkyline (buildings);
    for (auto i : skyLine)
        cout << i[0] << " " << i[1] << endl;
    return 0;
}
// [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
// [[0,2,3],[2,5,3]]
// [[1,2,1],[1,2,2],[1,2,3]]
// fails: 
