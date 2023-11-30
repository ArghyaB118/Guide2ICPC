/*
There are N dishes in a row on a kaiten belt, with the 
ith dish being of type D. Some dishes may be of the same type 
as one another. You're very hungry, but you'd also like to 
keep things interesting. The N dishes will arrive in front of you,
one after another in order, and for each one you'll eat 
it as long as it isn't the same type as any of the previous 
K dishes you've eaten. You eat very fast, so you can consume 
a dish before the next one gets to you. 
Any dishes you choose not to eat as they pass will be eaten 
by others. Determine how many dishes you'll end up eating.
*/

#include <bits/stdc++.h>
using namespace std;
// Write any include statements here
#include <queue>
#include <unordered_set>

int getMaximumEatenDishCount(int N, vector<int> D, int K) {
  // Write your code here
  queue<int> q;
  unordered_set<int> us;
  int res = 0;
  for (auto d : D) {
    if (us.empty()) {
      q.push(d); res++; us.insert(d);
    }
    else if (us.find(d) != us.end())
       continue;
    else {
      if (us.size() < K) {
        q.push(d); res++; us.insert(d);
      }
      else {
        us.erase(q.front()); q.pop();
        q.push(d); res++; us.insert(d);
      }
    }
  }
  return res;
}