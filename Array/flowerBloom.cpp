/* LC#2251
 
 You are given a 0-indexed 2D integer array flowers, 
 where flowers[i] = [starti, endi] means the i-th flower 
 will be in full bloom from start_i to end_i (inclusive). 
 You are also given a 0-indexed integer array persons of size n, 
 where persons[i] is the time that the ith person 
 will arrive to see the flowers.
 
 Return an integer array answer of size n, 
 where answer[i] is the number of flowers 
 that are in full bloom when the ith person arrives.
 
 Input: flowers = [[1,6],[3,7],[9,12],[4,13]], persons = [2,3,7,11]
 Output: [1,2,2,2]
 Explanation: The figure above shows the times 
 when the flowers are in full bloom and when the people arrive.
 For each person, we return the number of flowers 
 in full bloom during their arrival.
 
 Input: flowers = [[1,10],[3,3]], persons = [3,3,2]
 Output: [2,2,1]
 Explanation: The figure above shows the times 
 when the flowers are in full bloom and when the people arrive.
 For each person, we return the number of flowers 
 in full bloom during their arrival.*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;

struct Period {
    int left, right, n;
    Period (int x, int y, int z) {
        left = x; right = y; n = z;
    }
};

/*struct cmp {
    bool operator() (Period& p1, Period& p2) {
        return p1.left > p2.left;
    }
};*/

/*typedef pair<int, int> Pair;

vector<int> fullBloomFlowersOpt (vector<vector<int>>& flowers, vector<int>& persons) {
    stack<Period> st;
    sort(flowers.begin(), flowers.end());
    
    for (auto & flower : flowers)
        cout << flower[0] << flower[1] << endl;
    
    for (auto & flower : flowers) {
        if (st.empty())
            st.push(Period(flower[0], flower[1], 1));
        // Case 1: where the starting of this bloom is greater than the end of the previous bloom
        else if (flower[0] > st.top().right)
            st.push(Period(flower[0], flower[1], 1));
        // Case 2: where the starting of this bloom is equal to the end of the previous bloom
        else if (flower[0] == st.top().right) {
            Period p = st.top();
            st.pop();
            p.right = flower[1];
            st.push(p);
        }
        // Case 3: where the start of the bloom is the same as the previous bloom
        // 3a: end of the bloom is equal to the previous bloom
        else if (flower[0] == st.top().left && st.top().right == flower[1]) {
            Period p = st.top(); st.pop();
            p.n += 1; st.push(p);
        }
        // 3b: end of the bloom is greater than the previous bloom
        else if (flower[0] == st.top().left && st.top().right < flower[1]) {
            Period p = st.top(); st.pop();
            int tmp = p.right;
            p.right = tmp;
            p.n += 1; st.push(p);
            p.left = tmp + 1;
            p.right = flower[1];
            p.n -= 1;
            st.push(p);
        }
        // 3c: end of the previous bloom is less than the previous bloom
        else if (flower[0] == st.top().left && st.top().right > flower[1]) {
            Period p = st.top(); st.pop();
            int tmp = p.right;
            p.right = flower[1];
            p.n += 1; st.push(p);
            p.left = flower[1] + 1;
            p.right = tmp;
            p.n -= 1;
            st.push(p);
        }
        
        // Case 4: where the starting of this bloom overlaps in a way that start of the bloom is greater than the start but less than end of previous bloom.
        // 4a: the end of the bloom is equal to the end of the previous bloom
        else if (flower[0] > st.top().left && flower[0] < st.top().right && flower[1] == st.top().right) {
            Period p = st.top(); st.pop();
            p.right = flower[0] - 1;
            st.push(p);
            p.left = flower[0];
            p.right = flower[1];
            p.n += 1;
            st.push(p);
        }
        // 4b: the end of the bloom is greater than the end of the previous bloom
        else if (flower[0] > st.top().left && flower[0] < st.top().right && flower[1] > st.top().right) {
            Period p = st.top(); st.pop();
            int tmp = p.right;
            p.right = flower[0] - 1;
            st.push(p);
            p.left = flower[0];
            p.right = tmp;
            p.n += 1;
            st.push(p);
            p.left = tmp + 1;
            p.right = flower[1];
            p.n -= 1;
            st.push(p);
        }
        // 4c: the end of the bloom is less than the end of the previous bloom, i.e., both the start and end of the bloom overlaps with the last bloom
        else if (flower[0] > st.top().left && flower[0] < st.top().right && flower[1] < st.top().right) {
            Period p = st.top(); st.pop();
            int tmp = p.right;
            p.right = flower[0] - 1;
            st.push(p);
            p.left = flower[0];
            p.right = flower[1];
            p.n += 1;
            st.push(p);
            p.left = flower[1] + 1;
            p.right = tmp;
            p.n -= 1;
            st.push(p);
        }
        // Case 4: where the starting of this bloom overlaps in a way that start of the bloom is greater than the start but less than end of previous bloom.
        else if (flower[0] < st.top().left && flower[0] < st.top().right && flower[1] < st.top().right)
    }
    // map<Period> mp;
    while (!st.empty()) {
        // mp.insert(st.top());
        cout << st.top().left << st.top().right << st.top().n << endl;
        st.pop();
    }
    // sort(persons.begin(), persons.end(), greater<int>());
    vector<int> blooms = {};
    //for (auto & p : persons) {
      //   for (auto &)
      //  blooms =
    // }
    
    return {};
}*/

// keep a hashmap of <timespamp, number of flowers>
vector<int> fullBloomFlowers 
    (vector<vector<int>>& flowers, 
        vector<int>& persons) {
    unordered_map<int, int> mp;
    for (auto & flower : flowers) {
        for (int i = flower[0]; i <= flower[1]; i++) {
            if (mp.find(i) != mp.end())
                mp[i]++;
            else
                mp[i] = 1;
        }
    }
    vector<int> result = {};
    for (auto & person : persons)
        result.push_back(mp[person]);
    return result;
}

/*struct cmp {
    bool operator() (const vector<int>& a, const vector<int>& b) {
        return (a[1] <= b[1]) ? a : b;
    };
};*/

static bool cmp (const vector<int>& a, const vector<int>& b) {
    return (a[1] <= b[1]) ? true : false;
};

vector<int> fullBloomFlowers3 
    (vector<vector<int>>& flowers, 
        vector<int>& persons) {
    vector<int> result (persons.size(), 0);
    sort(flowers.begin(), flowers.end());
    
    for (int i = 0; i < persons.size(); i++) {
        for (auto & f : flowers) {
            if (f[0] <= persons[i])
                result[i]++;
            else
                break;
        }
    }
    
    sort (flowers.begin(), flowers.end(), cmp);
    for (auto & f: flowers)
        cout << f[0] << " " << f[1] << endl;
    
    for (int i = 0; i < persons.size(); i++) {
        for (auto & f : flowers) {
            if (f[1] < persons[i])
                    result[i]--;
            else
                break;
        }
    }
    return result;
}

// index of first flower that blooms after the person's visit
// = number of flowers with bloom time <= person's arrival        
int findGreater (vector<vector<int>>& flowers, int person) {
    int left = 0, right = flowers.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (right == left + 1
            && left == 0
            && flowers[left][0] > person)
            return 0;
        else if (right == left + 1
            && right == flowers.size() - 1
            && flowers[right][0] <= person)
            return flowers.size();
        else if (flowers[right][0] > person 
            && flowers[left][0] <= person 
            && right == left + 1)
            return right;
        else if (flowers[mid][0] > person)
            right = mid;
        else if (flowers[mid][0] <= person)
            left = mid;
    }
    return -1;
}

// index of first flower that with end_time >= the person's visit
// = number of flowers with end_time < person's arrival        
int findEqualOrGreater (vector<vector<int>>& flowers, int person) {
    int left = 0, right = flowers.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (right == left + 1
            && left == 0
            && flowers[left][1] >= person)
            return 0;
        else if (right == left + 1
            && right == flowers.size() - 1
            && flowers[right][1] < person)
            return flowers.size();
        else if (flowers[right][1] >= person 
            && flowers[left][1] < person 
            && right == left + 1)
            return right;
        else if (flowers[mid][1] >= person)
            right = mid;
        else if (flowers[mid][1] < person)
            left = mid;
    }
    return -1;
}

vector<int> fullBloomFlowers3a 
    (vector<vector<int>>& flowers, 
        vector<int>& persons) {
    vector<int> result (persons.size(), 0);
    sort(flowers.begin(), flowers.end());
    for (auto & f: flowers)
        cout << "{" << f[0] << " " << f[1] << "} ";
    cout << endl;

    for (int i = 0; i < persons.size(); i++)
        result[i] += findGreater (flowers, persons[i]);
        // cout << findGreater (flowers, persons[i]) << endl;
    
    sort (flowers.begin(), flowers.end(), cmp);
    for (auto & f: flowers)
        cout << "{" << f[0] << " " << f[1] << "} ";
    cout << endl;
    
    for (int i = 0; i < persons.size(); i++)
        result[i] -= findEqualOrGreater(flowers, persons[i]);
        // cout << findEqualOrGreater(flowers, persons[i]) << endl;
    return result;
}


/* This is the final answer
beats 88.71% users */
int findGreaterBegin (vector<int> &flower_begin, int person) {
    int left = 0, right = flower_begin.size() - 1;
    if (left == right) {
        if (flower_begin[0] <= person)
            return 1;
        else
            return 0;
    }
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (right == left + 1
            && left == 0
            && flower_begin[left] > person)
            return 0;
        else if (right == left + 1
            && right == flower_begin.size() - 1
            && flower_begin[right] <= person)
            return flower_begin.size();
        else if (flower_begin[right] > person 
            && flower_begin[left] <= person 
            && right == left + 1)
            return right;
        else if (flower_begin[mid] > person)
            right = mid;
        else if (flower_begin[mid] <= person)
            left = mid;
    }
    return -1;
}

int findEqualOrGreaterEnd (vector<int> &flower_end, int person) {
    int left = 0, right = flower_end.size() - 1;
    if (left == right) {
        if (flower_end[0] < person)
            return 1;
        else
            return 0;
    }
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (right == left + 1
            && left == 0
            && flower_end[left] >= person)
            return 0;
        else if (right == left + 1
            && right == flower_end.size() - 1
            && flower_end[right] < person)
            return flower_end.size();
        else if (flower_end[right] >= person 
            && flower_end[left] < person 
            && right == left + 1)
            return right;
        else if (flower_end[mid] >= person)
            right = mid;
        else if (flower_end[mid] < person)
            left = mid;
    }
    return -1;
}

vector<int> fullBloomFlowers3b 
    (vector<vector<int>>& flowers, 
        vector<int>& persons) {
    vector<int> result (persons.size(), 0);
    vector<int> flower_begin, flower_end;

    for (auto &f : flowers) {
        flower_begin.push_back(f[0]);
        flower_end.push_back(f[1]);
    }

    sort(flower_begin.begin(), flower_begin.end());
    sort(flower_end.begin(), flower_end.end());

    for (auto &i : flower_begin)
        cout << i << " ";
    cout << endl;

    for (auto &i : flower_end)
        cout << i << " ";
    cout << endl;

    for (int i = 0; i < persons.size(); i++)
        result[i] += findGreaterBegin (flower_begin, persons[i]);

    for (auto &i : result)
        cout << i << " ";
    cout << endl;

    for (int i = 0; i < persons.size(); i++)
        result[i] -= findEqualOrGreaterEnd(flower_end, persons[i]);
    return result;
}



// time limit exceeded
// O(np) - for each person, for each flower
// sort the flowers first, once the start time exceeds, break.
vector<int> fullBloomFlowers2 
    (vector<vector<int>>& flowers, 
        vector<int>& persons) {
    vector<int> result (persons.size(), 0);
    sort(flowers.begin(), flowers.end());
    
    for (int i = 0; i < persons.size(); i++) {
        for (auto & f : flowers) {
            if (f[0] <= persons[i]) {
                if (f[1] >= persons[i])
                    result[i]++;
                else
                    continue;
            }
            else
                break;
        }
    }
    
    return result;
}

// O(np) - for each person, for each flower
vector<int> fullBloomFlowersNaive (vector<vector<int>>& flowers, vector<int>& persons) {
    vector<int> result (persons.size(), 0);
    
    for (int i = 0; i < persons.size(); i++) {
        for (auto & f : flowers) {
            if (f[0] <= persons[i] && f[1] >= persons[i])
                result[i]++;
        }
    }
    
    return result;
}

int main () {
    // vector<vector<int>> flowers = {{1,6},{3,7},{9,12},{1,4},{4,13}};
    // vector<int> persons = {2,3,7,11};

    vector<vector<int>> flowers = {{1,1}};
    vector<int> persons = {1};
    
    // vector<vector<int>> flowers = {{19,37},{19,38},{19,35}};
    // vector<int> persons = {6,7,21,1,13,37,5,37,46,43};
    
    vector<int> blooms = fullBloomFlowers3b (flowers, persons);
    for (auto i : blooms)
        cout << i << " ";
    cout << endl;
    return 0;
}
