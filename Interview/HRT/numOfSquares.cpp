/*Given a list of 4≤N≤1000 points on a Cartesian Plane,
 count the number of squares such that all 4 corners
 of the square lie on the points.
All points will have integer values for x and y
and no point will be repeated.
 Each point satisfies −1000≤x_i,y_i≤1000

Note: the square does not need to be axis aligned.*/

#include <stdio.h>
#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;

typedef pair<int, int> point;
typedef pair<point, point> pairOfPoints;

int numOfSquares (vector<int> &x, vector<int> &y) {
    if (x.size() != y.size())
        return -1;
    int count = 0;
    vector<point> points;
    for (int i = 0; i < x.size(); i++)
        points.push_back(make_pair(x[i], y[i]));
    
    // is there at least 4 arms with the same length?
    // store the end points of such arms.
    unordered_map<double, vector<pairOfPoints>> hashmap;
    for (int i = 0; i < points.size() - 1; i++) {
        for (int j = i + 1; j < points.size(); j++) {
            double distSq = (points[i].first - points[j].first) * (points[i].first - points[j].first) + (points[i].second - points[j].second) * (points[i].second - points[j].second);
            hashmap[distSq].push_back(make_pair(points[i], points[j]));
        }
    }
    
    for (auto i : hashmap) {
        cout << i.first << " " << i.second.size() << endl;
        if (i.second.size() >= 4) {
            count++;
            vector<point> vertices;
            vertices.push_back(i.second[0].first, i.second[0].second);
            for (int j = 1; j < i.second.size(); ) {
                
            }
        }
    }
    
/*    for (int i = 0; i < x.size(); i++) {
        point point1 = points[i];
        for (int j = i + 1; j < x.size(); j++) {
            cout << "here1" << endl;
            point point2 = points[j];
            double m1 = (point2.second - point1.second) / (point2.first - point1.first);
            cout << "m1:" << m1 << endl;
            for (int k = j + 1; k < x.size(); k++) {
                point point3 = points[k];
                double m2 = (point3.second - point1.second) / (point3.first - point1.first);
                cout << "m2:" << m2 << endl;
                if (m1 * m2 == -1) {
                    cout << "here2" << endl;
                    for (int l = j + 1; l < x.size(); l++) {
                        if (l != k) {
                            cout << "here3" << endl;
                            point point4 = points[l];
                            double m3 = (point4.second - point2.second) / (point4.first - point2.first);
                            if (m1 * m3 == -1) {
                                cout << "here4" << endl;
                                long long dist1 = pow(point3.second - point1.second, 2) + pow(point3.first - point1.first, 2);
                                long long dist2 = pow(point4.second - point2.second, 2) + pow(point4.first - point2.first, 2);
                                if (dist1 == dist2)
                                    num++;
                            }
                        }
                    }
                }
            }
        }
    } */
    return count;
}

int main () {
    vector<int> x{0, 0, 1, 1}, y{0, 1, 0, 1};
    cout << "The number of squares: " << numOfSquares(x, y) << endl;
    return 0;
}
