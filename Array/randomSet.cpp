/* LC#380

Insert Delete GetRandom O(1)

Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.

bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.

bool remove(int val) Removes an item val from the set if present. 
Returns true if the item was present, false otherwise.

int getRandom() Returns a random element from the current set 
of elements (it's guaranteed that at least one element exists 
when this method is called). 
Each element must have the same probability of being returned.
You must implement the functions of the class such that 
each function works in average O(1) time complexity.
*/

class RandomizedSet {
private:
    vector<int> v;
public:
    RandomizedSet() {
        this->v.clear();        
    }
    
    bool insert(int val) {
        if (find(this->v.begin(), this->v.end(), val) != this->v.end())
            return false;
        this->v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (find(this->v.begin(), this->v.end(), val) == this->v.end())
            return false;
        this->v.erase(find(this->v.begin(), this->v.end(), val));
        return true;
    }
    
    int getRandom() {
        int curr_size = this->v.size();
        int random_index = rand() % curr_size;
        return this->v[random_index];
    }
};

class RandomizedSet2 {
private:
    vector<int> v;
    unordered_set<int> s;
public:
    RandomizedSet2() {
        this->v.clear();
        this->s.clear();
    }
    
    bool insert(int val) {
        if (this->s.find(val) != this->s.end())
            return false;
        this->s.insert(val);
        this->v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (this->s.find(val) == this->s.end())
            return false;
        this->s.erase(val);
        this->v.erase(find(this->v.begin(), this->v.end(), val));
        return true;
    }
    
    int getRandom() {
        int curr_size = this->v.size();
        int random_index = rand() % curr_size;
        return this->v[random_index];
    }
};

class RandomizedSet3 {
private:
    vector<int> v;
    unordered_set<int> s;
public:
    RandomizedSet3() {
        this->v.clear();
        this->s.clear();
    }
    
    bool insert(int val) {
        if (this->s.find(val) != this->s.end())
            return false;
        this->s.insert(val);
        this->v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (this->s.find(val) == this->s.end())
            return false;
        this->s.erase(val);
        return true;
    }
    
    int getRandom() {
        while (true) {
            int curr_size = this->v.size();
            int random_index = rand() % curr_size;
            int element = this->v[random_index];
            if (s.find(element) != s.end())
                return element;
            else
                this->v.erase(find(this->v.begin(), this->v.end(), element));
        }
    }
};

class RandomizedSet4 {
private:
    vector<int> v;
    unordered_set<int> s;
public:
    RandomizedSet4() {
        this->v.clear();
        this->s.clear();
    }
    
    bool insert(int val) {
        if (this->s.find(val) != this->s.end())
            return false;
        this->s.insert(val);
        this->v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (this->s.find(val) == this->s.end())
            return false;
        this->s.erase(val);
        return true;
    }
    
    int getRandom() {
        while (true) {
            int element = this->v[rand() % this->v.size()];
            if (s.find(element) != s.end())
                return element;
            this->v.erase(find(this->v.begin(), this->v.end(), element));
        }
    }
};

class RandomizedSet5 {
private:
    int n;
    vector<int> v;
    unordered_map<int, int> m;
public:
    RandomizedSet5() {
        this->n = 0;
        this->m.clear();
        this->v.clear();
    }
    
    bool insert(int val) {
        if (this->m.find(val) != this->m.end())
            return false;
        this->n++;
        this->m.insert({val, this->n - 1});
        this->v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (this->m.find(val) == this->m.end())
            return false;
        if (this->m[val] == this->n) {
            this->v.pop_back();
            this->m.erase(val);
            this->n--;
            return true;
        }
        else {
            int element = this->v[this->n - 1];
            int index = this->m[val];
            this->v[this->n - 1] = val;
            this->v[index] = element;
            this->m[element] = index;
            this->v.pop_back();
            this->m.erase(val);
            this->n--;
            return true;
        }
    }
    
    int getRandom() {
        return this->v[rand() % this->n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */