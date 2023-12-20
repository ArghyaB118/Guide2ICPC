/* LC#146
 
 Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

struct Node  {
    int key, value;
    Node *left, *right;
    Node (int key_, int value_) {
        key = key_;
        value = value_;
    }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> keyValuePairs;
    struct Node* head = new Node(-1, -1);
    struct Node* tail = new Node(-1, -1);
public:
    LRUCache (int capacity_) {
        this->capacity = capacity_;
        head->right = tail; head->left = NULL;
        tail->left = head; tail->right = NULL;
    }
    
    void MoveToEnd (Node* node) {
        node->left->right = node->right;
        node->right->left = node->left;
        Node* tmp = this->tail->left;
        tmp->right = node;
        node->left = tmp;
        node->right = this->tail;
        this->tail->left = node;
    }
    
    int get (int key) {
        if (this->keyValuePairs.find(key) != this->keyValuePairs.end()) {
            Node* tmp = keyValuePairs[key];
            MoveToEnd (tmp);
            return tmp->value;
        }
        return -1;
    }
    
    void put (int key, int value) {
        if (this->keyValuePairs.find(key) != this->keyValuePairs.end()) {
            Node* tmp = keyValuePairs[key];
            tmp->value = value;
            MoveToEnd (tmp);
        }
        else {
            if (this->keyValuePairs.size() >= this->capacity) {
                keyValuePairs.erase(this->head->right->key);
                Node* tmp = this->head->right;
                tmp->left->right = tmp->right;
                tmp->right->left = tmp->left;
            }
            
            if (keyValuePairs.empty()) {
                struct Node* node = new Node(key, value);
                this->head->right = node;
                node->left = this->head;
                node->right = this->tail;
                this->tail->left = node;
                keyValuePairs[key] = node;
            }
            else {
                struct Node* node = new Node(key, value);
                this->tail->left->right = node;
                node->left = this->tail->left;
                node->right = this->tail;
                this->tail->left = node;
                keyValuePairs[key] = node;
            }
        }
        
        cout << "Keys" << endl;
        for (auto & i : this->keyValuePairs) {
            Node* tmp = i.second;
            cout << tmp->key << " " << tmp->value << endl;
        }
    }
};


class LRUCacheList {
public:
    int capacity;
    unordered_map<int, int> keyValuePairs;
    list<int> keys;
    
    LRUCacheList (int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (keyValuePairs.find(key) != keyValuePairs.end()) {
            /* Note: unfortunately, list.remove is O(n). 
            We have used it in 2 other places. 
            Hence, overall it is O(n). Useless!*/
            keys.remove(key);
            keys.push_back(key);
            return keyValuePairs[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (keys.size() < capacity) {
            if (keyValuePairs.find(key) != keyValuePairs.end())
                keys.remove(key);
            keys.push_back(key);
            keyValuePairs[key] = value;
        }
        else {
            if (keyValuePairs.find(key) != keyValuePairs.end()) {
                keyValuePairs[key] = value;
                keys.remove(key);
                keys.push_back(key);
            }
            else {
                keyValuePairs.erase(keys.front());
                keys.pop_front();
                keys.push_back(key);
                keyValuePairs[key] = value;
            }
        }
    }
};



class LRUCacheVec {
public:
    int capacity;
    unordered_map<int, int> keyValuePairs;
    vector<int> keys;
    
    LRUCacheVec (int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (keyValuePairs.find(key) != keyValuePairs.end()) {
            /* Note: Any combination using std::remove does not work 
            as after it removes 1 from {1, 2} it makes {2 2}, 
            so finally it becomes {2 2 1} instead of {2 1} 
            after the final push_back.
            // keys.push_back(key);
            // remove(keys.begin(), keys.end() - 1, key);
            Unfortunately, now the way we are removing elements, 
            is still O(n). */
            
            for (int i = 0; i < keys.size(); i++)
                if (keys[i] == key)
                    keys.erase(keys.begin() + i);
            
            keys.push_back(key);
            return keyValuePairs[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (keys.size() < capacity) {
            if (keyValuePairs.find(key) != keyValuePairs.end())
                for (int i = 0; i < keys.size(); i++)
                    if (keys[i] == key)
                        keys.erase(keys.begin() + i);
            keyValuePairs[key] = value;
            keys.push_back(key);
        }
        else {
            if (keyValuePairs.find(key) != keyValuePairs.end()) {
                keyValuePairs[key] = value;
                for (int i = 0; i < keys.size(); i++)
                    if (keys[i] == key)
                        keys.erase(keys.begin() + i);
                keys.push_back(key);
            }
            else {
                keyValuePairs.erase(keys.front());
                keys.erase(keys.begin());
                keys.push_back(key);
                keyValuePairs[key] = value;
            }
        }
    }
};


int main () {
	int capacity = 2;
	LRUCache* obj = new LRUCache (capacity);
    obj->put(0,1); obj->put(1,2); obj->put(0,3); obj->put(3,4);
    cout << obj->get(0) << " " << obj->get(3) << " " << obj->get(1) << endl;
	return 0;
}
