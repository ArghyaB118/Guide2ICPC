//
//  minDistanceGroup.cpp
//  
//
//  Created by Arghya Bhattacharya on 10/11/22.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> boundaries;

void recursiveCheck (int maxm, int minm, vector<vector<int>>& groups) {
  int cutoff = 4, range = (maxm - minm + 1) / cutoff;
  bool b = false;
  for (auto i : groups) {
    for (auto j : i) {
      if (j <= maxm && j >= minm)
        b = true;
    }
    if (b != true)
      return;
  }
  boundaries.push_back(maxm); boundaries.push_back(minm);
  for (int i = 0; i < cutoff; i++) {
    int minm1 = minm + i * range, maxm1 = minm + (i + 1) * range;
    recursiveCheck (maxm1, minm1, groups);
  }
}

vector<int> setSelect (vector<vector<int>>& groups) {
  vector<int> result;
  int maxm = 0, minm = 0;
  for (auto i : groups) {
    for (auto j : i) {
      maxm = max (maxm, j);
      minm = min (minm, j);
    }
  }
  // around 300 is the maxm range in the test cases
  cout << maxm << " " << minm << endl;
  recursiveCheck (maxm, minm, groups);
  for (auto i : boundaries)
    cout << i << endl;
  
  int minRange = 0, maxB = boundaries[0], minB = boundaries[1];
  for (int i = 0; i < boundaries.size() - 1; i = i + 2) {
    if (boundaries[i] - boundaries[i + 1] < minRange) {
      minRange = boundaries[i] - boundaries[i + 1];
      maxB = boundaries[i]; minB = boundaries[i + 1];
    }
  }
  
  cout << minB << maxB << endl;
  
  for (auto i : groups)
    for (auto j : i)
      if (j <= maxB && j >= minB)
        result.push_back(j);
  
  return result;
}

int main() {
  vector<vector<int>> groups;
  string line;
  while (getline(cin, line)) {
    vector<int> nums;
    string word = "";
    for (auto i : line) {
      if (i == ' ') {
        nums.push_back(stoi(word));
        word = "";
      }
      else {
        word = word + i;
      }
    }
    groups.push_back(nums);
    /* for (auto i : groups)
      for (auto j : i)
        cout << j << endl;*/
    
    vector<int> result = setSelect (groups);
    for (auto i : result)
      cout << i << " ";
    // cout << line << endl;
  }
}
