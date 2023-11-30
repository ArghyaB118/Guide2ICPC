/*You are given an integer n. There are n rooms numbered from 0 to n - 1.
 
 You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held during the half-closed time interval [starti, endi). All the values of starti are unique.

 Meetings are allocated to rooms in the following manner:

 Each meeting will take place in the unused room with the lowest number.
 If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration as the original meeting.
 When a room becomes unused, meetings that have an earlier original start time should be given the room.
 Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.

 A half-closed interval [a, b) is the interval between a and b including a and not including b.

*/

#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> interval;

int mostBooked (int n, vector<vector<int>>& meetings) {
    vector<vector<interval>> schedule (n, vector<interval> {});
    // assuming meeetings is sorted based on the starting time.
    for (int i = 0; i < meetings.size(); i++) {
        bool scheduled = false;
        int vacant = 100, machine = -1;
        for (int j = 0; j < schedule.size(); j++) {
            if (schedule[j].empty()) {
                schedule[j].push_back({meetings[i][0], meetings[i][1]});
                scheduled = true; break;
            }
            else if (schedule[j].back().second < vacant) {
                machine = j; vacant = schedule[j].back().second;
            }
        }
        if (scheduled == false)
            schedule[machine].push_back({vacant, vacant + meetings[i][1] - meetings[i][0]});
    }
    
    for (auto i : schedule) {
        for (auto j : i)
            cout << j.first << " " << j.second << endl;
        cout << endl;
    }
    
    int num = 0, index = 0;
    for (int i = 0; i < schedule.size(); i++) {
        if (schedule[i].size() > num) {
            index = i; num = schedule[i].size();
        }
    }
    return index;
}

int main () {
    int n = 2;
    vector<vector<int>> meetings = {{0,10},{1,5},{2,7},{3,4}};
    cout << mostBooked(n, meetings) << endl;
    return 0;
}