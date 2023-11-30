#include <iostream>
#include <vector>
#include <numeric>
#include <queue>
using namespace std;
// pair of current_value_collected, current_expected_value_in_the_room
typedef pair<double, double> value_tmp;

double getMaxExpectedProfit(int N, vector<int> V, int C, double S) {
  // Write your code here
  if (N == 1)
    return max(V[0] - C, 0);
  else if (S == 0)
    return max(accumulate(V.begin(), V.end(), 0) - C, 0);

  double res = 0;
  queue<value_tmp> q;
  q.push({V[0] - C, 0});
  q.push({0, V[0]});
  for (int i = 1; i < N; i++) {
    long long numIter = q.size(); 
    for (long long j = 0; j < numIter; j++) {
      value_tmp tmp = q.front();
      q.pop();
      q.push({tmp.first + tmp.second * (1 - S) + V[i] - C, 0});
      q.push({tmp.first, tmp.second * (1 - S) + V[i]});
    }
  }
  while (!q.empty()) {
    res = max(res, q.front().first);
    q.pop();
  }
  return res;
}

int main () {
  cout << getMaxExpectedProfit (5, {10, 2, 8, 6, 4}, 3, 0.15) << endl;
  return 0;
}