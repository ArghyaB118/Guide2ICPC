/* LC#1101
 
 There are n people in a social group labeled from 0 to n - 1. You are given an array logs where logs[i] = [timestampi, xi, yi] indicates that xi and yi will be friends at the time timestampi.
 
 Friendship is symmetric. That means if a is friends with b, then b is friends with a. Also, person a is acquainted with a person b if a is friends with b, or a is a friend of someone acquainted with b.

 Return the earliest time for which every person became acquainted with every other person. If there is no such earliest time, return -1.
 
 Input: logs = [[20190101,0,1],[20190104,3,4],[20190107,2,3],[20190211,1,5],[20190224,2,4],[20190301,0,3],[20190312,1,2],[20190322,4,5]], n = 6
 Output: 20190301
 Explanation:
 The first event occurs at timestamp = 20190101 and after 0 and 1 become friends we have the following friendship groups [0,1], [2], [3], [4], [5].
 The second event occurs at timestamp = 20190104 and after 3 and 4 become friends we have the following friendship groups [0,1], [2], [3,4], [5].
 The third event occurs at timestamp = 20190107 and after 2 and 3 become friends we have the following friendship groups [0,1], [2,3,4], [5].
 The fourth event occurs at timestamp = 20190211 and after 1 and 5 become friends we have the following friendship groups [0,1,5], [2,3,4].
 The fifth event occurs at timestamp = 20190224 and as 2 and 4 are already friends anything happens.
 The sixth event occurs at timestamp = 20190301 and after 0 and 3 become friends we have that all become friends.
 
 Input: logs = [[0,2,0],[1,0,1],[3,0,3],[4,1,2],[7,3,1]], n = 4
 Output: 3
 
 Constraints:

 2 <= n <= 100
 1 <= logs.length <= 104
 logs[i].length == 3
 0 <= timestampi <= 109
 0 <= xi, yi <= n - 1
 xi != yi
 All the values timestampi are unique.
 All the pairs (xi, yi) occur at most one time in the input.*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class UnionFind {
    unordered_map<int, int> umap;
public:
    int Find (int k) {
        if (this->umap[k] == k)
            return k;
        this->umap[k] = Find(umap[k]); // 2. path compression optimization added by this line, whenever find is used, the path is also modified.
        return this->umap[k];
    }
    
    void Union (int i, int j) {
        int x = Find(i), y = Find(j);
        if (x != y)
            umap[y] = x;
    }
    
    int earliestAcq (vector<vector<int>>& logs, int n) {
        int horizon = 0;
        sort(logs.begin(), logs.end());
        for (int i = 0; i < n; i++)
            umap[i] = i;
        for (auto log : logs) {
            cout << horizon << endl;
            for (auto i : umap)
                cout << i.first << " " << i.second << endl;
            Union (min(log[1], log[2]), max(log[1], log[2])); // 1. union by rank optimization is added by this line by doing unions that are always sorted.
            horizon = max(horizon, log[0]);
            
            int count = 1;
            for (int i = 1; i < n; i++) {
                if (Find(i) == Find(0))
                    count++;
                else
                    break;
            }
            if (count == n)
                return horizon;
        }
        
        cout << endl;
        for (auto i : umap)
            cout << i.first << " " << i.second << endl;
        return -1;
    }
};

int main () {
    vector<vector<int>> logs =
    {{20190101,0,1},{20190104,3,4},{20190107,2,3},{20190211,1,5},{20190224,2,4},{20190301,0,3},{20190312,1,2},{20190322,4,5}};
    int n = 6;
    // logs = {{0,2,0},{1,0,1},{3,0,3},{4,1,2},{7,3,1}};
    // int n = 4;
    
    UnionFind *obj = new UnionFind();
    cout << obj->earliestAcq (logs, n) << endl;
    return 0;
}
