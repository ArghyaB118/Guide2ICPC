#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
	int capacity;
	unordered_map<int, int> keyValuePairs;

    LRUCache(int capacity) {
        this->capacity = capacity;    
    }
    
    int get(int key) {
        if (keyValuePairs.find(key) != keyValuePairs.end())
        	return keyValuePairs[key];
        else
        	return -1;
    }
    
    void put(int key, int value) {
        if (keyValuePairs.find(key) != keyValuePairs.end())
        	keyValuePairs[key] = value;
        else if (keyValuePairs.size() < capacity)
        	keyValuePairs.insert(make_pair(key, value));
    }
};


int main () {
	int capacity = 5;
	LRUCache* obj = new LRUCache(capacity);
	obj->put(0,1); obj->put(1,2); obj->put(0,3);
 	int param_1 = obj->get(0);
 	cout << param_1 << endl;
	return 0;
}