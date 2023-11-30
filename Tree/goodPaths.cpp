/* LC#2421
 
 There is a tree (i.e. a connected, undirected graph with no cycles) consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges.
 
 You are given a 0-indexed integer array vals of length n where vals[i] denotes the value of the ith node. You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

 A good path is a simple path that satisfies the following conditions:

 The starting node and the ending node have the same value.
 All nodes between the starting node and the ending node have values less than or equal to the starting node (i.e. the starting node's value should be the maximum value along the path).
 Return the number of distinct good paths.

 Note that a path and its reverse are counted as the same path. For example, 0 -> 1 is considered to be the same as 1 -> 0. A single node is also considered as a valid path.

 Input: vals = [1,3,2,1,3], edges = [[0,1],[0,2],[2,3],[2,4]]
 Output: 6
 Input: vals = [1,1,2,2,3], edges = [[0,1],[1,2],[2,3],[2,4]]
 Output: 7
 Input: vals = [1], edges = []
 Output: 1
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

vector<vector<int>> makeAdj (int n, vector<vector<int>>& edges) {
    vector<vector<int>> adjList (n, {}); // adjList (vals.size(), vector<int> {}); Required on LC
    for (auto & i : edges) {
        adjList[i[0]].push_back(i[1]);
        adjList[i[1]].push_back(i[0]);
    }
    return adjList;
}

int numberOfGoodPaths (vector<int>& vals, vector<vector<int>>& edges) {
    int n = vals.size();
    int result = 2 * n;
    vector<vector<int>> adjList = makeAdj (n, edges);
    /*for (auto & i : adjList) {
        for (auto & j : i)
            cout << j << " ";
        cout << endl;
    }*/
    queue<vector<int>> q;
    for (int i = 0; i < n; i++) {
        q.push({i});
        while (!q.empty()) {
            vector<int> tmp = q.front(); q.pop();
            /*for (auto & j : tmp)
                cout << j << " ";
            cout << endl;*/
            for (auto & j : adjList[tmp.back()]) {
                if ((tmp.size() <= 1) || (tmp.size() > 1 && j != tmp.rbegin()[1])) {  
                    if (vals[j] == vals[i])
                        result++;
                    if (vals[j] <= vals[i]) {
                        vector<int> tmp1 = tmp;
                        tmp1.push_back(j);
                        q.push(tmp1);
                    }
                }
            }
        }
    }
    return result / 2;
}

/* Improvement: 
    1. instead of saving the whole path of BFS on the fly, just store the last edge. 
    This is enough info to move to the next node avoiding to go the previous one.
    2. Also, only start from the nodes that have repititive values.
*/
typedef pair<int, int> edge;

int numberOfGoodPaths2 (vector<int>& vals, vector<vector<int>>& edges) {
    int n = vals.size();
    int result = 2 * n;
    unordered_set<int> repeated_values, single_values;
    for (auto & i : vals) {
        if (single_values.find(i) != single_values.end()) {
            repeated_values.insert(i);
        }
        single_values.insert(i);
    }
    for (auto & i : single_values)
        cout << i << " ";
    cout << endl;
    for (auto & i : repeated_values)
        cout << i << " ";
    cout << endl;
    if (repeated_values.empty())
        return result / 2;
    vector<vector<int>> adjList = makeAdj (n, edges);
    queue<edge> q;
    for (int i = 0; i < n; i++) {
        if (repeated_values.find(vals[i]) != repeated_values.end()) {
            cout << i << endl;
            q.push({-1,i});
            while (!q.empty()) {
                edge tmp = q.front(); q.pop();
                for (auto & j : adjList[tmp.second]) {
                    if (j != tmp.first) {  
                        if (vals[j] == vals[i])
                            result++;
                        if (vals[j] <= vals[i]) {
                            edge tmp1 = {tmp.second, j};
                            q.push(tmp1);
                        }
                    }
                }
            }
        }
    }
    return result / 2;
}



int main () {
    vector<int> vals = {10,30,20,10,30};
    vector<vector<int>> edges = {{0,1},{0,2},{2,3},{2,4}};
    cout << numberOfGoodPaths2(vals, edges) << endl;
    return 0;
}
