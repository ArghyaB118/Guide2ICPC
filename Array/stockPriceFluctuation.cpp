/* LC#2034
 You are given a stream of records about a particular stock. Each record contains a timestamp and the corresponding price of the stock at that timestamp.

Unfortunately due to the volatile nature of the stock market, the records do not come in order. Even worse, some records may be incorrect. Another record with the same timestamp may appear later in the stream correcting the price of the previous wrong record.

Design an algorithm that:

Updates the price of the stock at a particular timestamp, correcting the price from any previous records at the timestamp.
Finds the latest price of the stock based on the current records. The latest price is the price at the latest timestamp recorded.
Finds the maximum price the stock has been based on the current records.
Finds the minimum price the stock has been based on the current records.
Implement the StockPrice class:

StockPrice() Initializes the object with no price records.
void update(int timestamp, int price) Updates the price of the stock at the given timestamp.
int current() Returns the latest price of the stock.
int maximum() Returns the maximum price of the stock.
int minimum() Returns the minimum price of the stock.
current, maximum, and minimum will be called only after update has been called at least once.*/

#include <iostream>
#include <unordered_map>
using namespace std;

// typedef pair<int, int> entry;

class StockPrice {
public:
    unordered_map<int, int> entries;
    int minm, maxm, curr, minTime, maxTime, latestTime;
    StockPrice () {
        this->minm = 1000000;
        this->maxm = 0;
    }
    int maximum() { return maxm; }
    int minimum() { return minm; }
    int current() { return curr; }
    void update (int timestamp, int price) {
        // 1. Set minm
        if (this->minm > price) {
            this->minm = price;
            this->minTime = timestamp;
        }
        // 2. Set maxm
        if (this->maxm < price) {
            this->maxm = price;
            this->maxTime = timestamp;
        }
        // 3. Set curr if time is latest
        if (this->latestTime <= timestamp) {
            this->latestTime = timestamp;
            this->curr = price;
        }
        // 4. Make new entry or update entry
        entries[timestamp] = price;
        // 5. Only if this entry is maxm or minm, do linear scan and find if this entry changes the maxm or minm
        if (maxTime == timestamp && maxTime != latestTime) {
            this->maxm = price;
            for (auto i : entries)
                this->maxm = max(this->maxm, i.second);
        }
        if (minTime == timestamp && minTime != latestTime) {
            this->minm = price;
            for (auto i : entries)
                this->minm = min(this->minm, i.second);
        }
    }
};

int main () {
    StockPrice myObj;
    myObj.update(1, 10); myObj.update(2, 5);
    cout << myObj.current() << endl; cout << myObj.maximum() << endl;
    myObj.update(1, 3); cout << myObj.maximum() << endl;
    myObj.update(4, 2); cout << myObj.minimum() << endl;
    for (auto i : myObj.entries)
        cout << i.first << " " << i.second << endl;
    return 0;
}
