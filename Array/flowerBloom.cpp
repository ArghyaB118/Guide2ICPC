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

vector<int> fullBloomFlowers (vector<vector<int>>& flowers, vector<int>& persons) {
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

vector<int> fullBloomFlowers3 (vector<vector<int>>& flowers, vector<int>& persons) {
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

vector<int> fullBloomFlowers2 (vector<vector<int>>& flowers, vector<int>& persons) {
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
    vector<vector<int>> flowers = {{1,6},{3,7},{9,12},{1,4},{4,13}};
    vector<int> persons = {2,3,7,11};
    
    // vector<vector<int>> flowers = {{19,37},{19,38},{19,35}};
    // vector<int> persons = {6,7,21,1,13,37,5,37,46,43};
    
    vector<int> blooms = fullBloomFlowers3 (flowers, persons);
    for (auto i : blooms)
        cout << i << " ";
    cout << endl;
    return 0;
}
