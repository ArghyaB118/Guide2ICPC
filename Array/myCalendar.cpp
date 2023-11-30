/* LC#729
 
 You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a double booking.
 
 A double booking happens when two events have some non-empty intersection (i.e., some moment is common to both events.).

 The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), the range of real numbers x such that start <= x < end.

 Implement the MyCalendar class:

 MyCalendar() Initializes the calendar object.
 boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.
 
 Input
 ["MyCalendar", "book", "book", "book"]
 [[], [10, 20], [15, 25], [20, 30]]
 Output
 [null, true, false, true]
 
 Idea:
 1. Brute force: O(n^2)*/

#include <iostream>
#include <set>
using namespace std;

class MyCalendar {
private:
    set<pair<int, int>> calendar;
public:
    MyCalendar() {
        
    }
    
    bool book (int start, int end) {
        // linear search over the existing entries in calendar.
        // Non-optimal. In fact, the advantage of using a sorted list structure such as set is gone.
        for (auto i : this->calendar) {
            if (start < i.first && end > i.first)
                return false;
            else if (start >= i.first && start < i.second)
                return false;
        }
        this->calendar.insert({start, end});
        return true;
    }
    
    // Observation: Because we do not allow overlap, the calendar structure will never have any unsorted entries. So, if you flat out it as an array, it will be a sorted array.
    /*bool bookOpt (int start, int end) {
        // Binary search on the calendar
        int id = 0;
        if (start < calendar[id].first && end < calendar[id].first)
            break;
        else if (start > calendar[id].second && end < calendar[id].second)
            break;
        id = (id == 0) ? 1 : 2 * id;
        this->calendar.insert({start, end});
        return true;
    }*/

    void printCal () {
        cout << "Printing the calendar:" << endl;
        for (auto i : this->calendar)
            cout << i.first << " " << i.second << endl;
    }
};

int main () {
    MyCalendar* obj = new MyCalendar();
    cout << boolalpha << obj->book(10,20) << endl;
    cout << boolalpha << obj->book(15,25) << endl;
    cout << boolalpha << obj->book(20,25) << endl;
    obj->printCal();
    return 0;
}
