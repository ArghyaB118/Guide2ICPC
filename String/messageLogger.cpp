/* LC#359
 
 Design a logger system that receives a stream of messages along with their timestamps. Each unique message should only be printed at most every 10 seconds (i.e. a message printed at timestamp t will prevent other identical messages from being printed until timestamp t + 10).
 
 All messages will come in chronological order. Several messages may arrive at the same timestamp.

 Implement the Logger class:

 Logger() Initializes the logger object.
 bool shouldPrintMessage(int timestamp, string message) Returns true if the message should be printed in the given timestamp, otherwise returns false.
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Logger {
public:
    unordered_map<string, int> logs;
    
    Logger() {}
        
    bool shouldPrintMessage(int timestamp, string message) {
        if (logs.find(message) == logs.end()) {
            logs[message] = timestamp;
            return true;
        }
        if (logs[message] + 10 <= timestamp) {
            logs[message] = timestamp;
            return true;
        }
        return false;
    }
};

int main () {
    Logger* obj = new Logger();
    cout << boolalpha << obj->shouldPrintMessage (1, "foo") << endl;
    cout << boolalpha << obj->shouldPrintMessage (2, "bar") << endl;
    cout << boolalpha << obj->shouldPrintMessage (3, "foo") << endl;
    cout << boolalpha << obj->shouldPrintMessage (8, "bar") << endl;
    cout << boolalpha << obj->shouldPrintMessage (10, "foo") << endl;
    cout << boolalpha << obj->shouldPrintMessage (11, "foo") << endl;
    return 0;
}
