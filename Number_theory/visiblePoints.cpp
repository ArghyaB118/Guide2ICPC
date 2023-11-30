/* LC#1610
 
 You are given an array points, an integer angle, and your location, where location = [posx, posy] and points[i] = [xi, yi] both denote integral coordinates on the X-Y plane.
 
 Initially, you are facing directly east from your position. You cannot move from your position, but you can rotate. In other words, posx and posy cannot be changed. Your field of view in degrees is represented by angle, determining how wide you can see from any given view direction. Let d be the amount in degrees that you rotate counterclockwise. Then, your field of view is the inclusive range of angles [d - angle/2, d + angle/2].
 
 You can see some set of points if, for each point, the angle formed by the point, your position, and the immediate east direction from your position is in your field of view.

 There can be multiple points at one coordinate. There may be points at your location, and you can always see these points regardless of your rotation. Points do not obstruct your vision to other points.

 Return the maximum number of points you can see.
 
 Idea:
 1. find the individual angles, theta_i, of the points with the location w.r.t x-axis.
 2. the view can be span_i = [theta_i - angle/2, theta/2 + angle/2] to see point i.
 3. find a value of view, d, so that maximum points are visible, i.e., maximum of span_i's are intersected.*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define PI 3.14

int visiblePoints (vector<vector<int>>& points, int angle, vector<int>& location) {
    if (angle == 360)
        return points.size();
    vector<int> angles = {};
    for (auto i : points) {
        if ((location[1] - i[1]) < 0 && (location[0] - i[0]) < 0)
            angles.push_back((int)(atan((location[1] - i[1]) / (location[0] - i[0])) * 180 / PI) - 180);
        else if ((location[1] - i[1]) > 0 && (location[0] - i[0]) < 0)
            angles.push_back((int)(atan((location[1] - i[1]) / (location[0] - i[0])) * 180 / PI) + 180);
        else
            angles.push_back((int)(atan((location[1] - i[1]) / (location[0] - i[0])) * 180 / PI));
    }
    sort(angles.begin(), angles.end());
    for (auto i : angles)
        cout << i << endl;
    int count = 0;
    for (int i = -180 + angle / 2; i <= 180 - angle / 2; i++) {
        int tmp = 0;
        for (int j : angles)
            if (j >= i - angle / 2 && j <= i + angle / 2)
                tmp++;
        count = max(count, tmp);
    }
    return count;
}

int main() {
    vector<vector<int>> points = {{2,1}, {2,2}, {3,4}, {1,1}};
    int angle = 90;
    vector<int> location = {1,1};
    cout << visiblePoints(points, angle, location) << endl;
    return 0;
}
