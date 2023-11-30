/*Suppose you are at a party with n people labeled from 0 to n - 1 and among them, there may exist one celebrity. The definition of a celebrity is that all the other n - 1 people know the celebrity, but the celebrity does not know any of them.

Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to do is ask questions like: "Hi, A. Do you know B?" to get information about whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).

You are given a helper function bool knows(a, b) that tells you whether A knows B. Implement a function int findCelebrity(n). There will be exactly one celebrity if they are at the party.

Return the celebrity's label if there is a celebrity at the party. If there is no celebrity, return -1.*/

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> graph;

bool knows (int a, int b) {
    if (graph[a][b] == 1)
        return true;
    return false;
}

int findCelebrity (int n) {
    vector<int> arr(n, 0), result;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (knows(i, j))
                arr[j]++;
    }
    for (int i = 0; i < n; i++)
        if (arr[i] == n)
            result.push_back(i);
    if (result.size() == 1)
        return result[0];
    return -1;
}

int main () {
    graph = {{1,1,0},{0,1,1},{0,1,1}};
    // {{1,1}, {1,1}}; // {{1,1,0},{0,1,0},{1,1,1}};
    cout << "The celebrity is: " << findCelebrity(graph.size()) << endl;
}
