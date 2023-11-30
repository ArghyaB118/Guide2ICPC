/* LC#2249
 
 Given a 2D integer array circles where circles[i] = [xi, yi, ri] represents the center (xi, yi) and radius ri of the ith circle drawn on a grid, return the number of lattice points that are present inside at least one circle.
 
 Note:

 A lattice point is a point with integer coordinates.
 Points that lie on the circumference of a circle are also considered to be inside it.
 
 Input: circles = [[2,2,1]]
 Output: 5
 Explanation:
 The figure above shows the given circle.
 The lattice points present inside the circle are (1, 2), (2, 1), (2, 2), (2, 3), and (3, 2) and are shown in green.
 Other points such as (1, 1) and (1, 3), which are shown in red, are not considered inside the circle.
 Hence, the number of lattice points present inside at least one circle is 5.
 
 Input: circles = [[2,2,2],[3,4,1]]
 Output: 16
 Explanation:
 The figure above shows the given circles.
 There are exactly 16 lattice points which are present inside at least one circle.
 Some of them are (0, 2), (2, 0), (2, 4), (3, 2), and (4, 4).*/

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;
typedef pair<int, int> Point;


int countLatticePointsOpt2 (vector<vector<int>>& circles) {
    unordered_set<string> s;
    for (auto & circle : circles) {
        for (int i = circle[0] - circle[2]; i <= circle[0] + circle[2]; i++) {
            for (int j = circle[1] - circle[2]; j <= circle[1] + circle[2]; j++) {
                string tmp = "";
                tmp = tmp + "x" + to_string(i) + "y" + to_string(j);
                if (s.find(tmp) == s.end()) {
                    if ((i - circle[0]) * (i - circle[0]) + (j - circle[1]) * (j - circle[1]) <= circle[2] * circle[2])
                        s.insert(tmp);
                }
            }
        }
    }
    return s.size();
}

int countLatticePointsOpt (vector<vector<int>>& circles) {
    set<Point> s;
    for (auto & circle : circles) {
        for (int i = circle[0] - circle[2]; i <= circle[0] + circle[2]; i++)
            for (int j = circle[1] - circle[2]; j <= circle[1] + circle[2]; j++)
                if ((i - circle[0]) * (i - circle[0]) + (j - circle[1]) * (j - circle[1]) <= circle[2] * circle[2])
                    if (s.find(make_pair(i, j)) == s.end())
                        s.insert({i, j});
    }
    return s.size();
}

int countLatticePoints (vector<vector<int>>& circles) {
    vector<Point> s;
    for (auto & circle : circles) {
        for (int i = circle[0] - circle[2]; i <= circle[0] + circle[2]; i++)
            for (int j = circle[1] - circle[2]; j <= circle[1] + circle[2]; j++)
                if ((i - circle[0]) * (i - circle[0]) + (j - circle[1]) * (j - circle[1]) <= circle[2] * circle[2])
                    if (find(s.begin(), s.end(), make_pair(i,j)) == s.end())
                        s.push_back({i, j});
    }
    return s.size();
}

int main () {
    vector<vector<int>> circles = {{2,2,2},{3,4,1}};
    cout << countLatticePointsOpt2 (circles) << endl;
    return 0;
}
