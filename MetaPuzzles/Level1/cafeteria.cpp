/*
A cafeteria table consists of a row of 
N seats, numbered from 1 to N
from left to right. Social distancing guidelines require
that every diner be seated such that
K seats to their left and 
K seats to their right (or all the remaining seats to that side
if there are fewer than K) remain empty.
There are currently M diners seated at the table, the 
ith of whom is in seat S_i. No two diners are sitting 
in the same seat, and the social distancing guidelines 
are satisfied. Determine the maximum number of additional diners
who can potentially sit at the table without 
social distancing guidelines being violated 
for any new or existing diners, assuming that the existing diners
cannot move and that the additional diners will cooperate 
to maximize how many of them can sit down.
*/

long long getMaxAdditionalDinersCount(long long N, long long K, int M, vector<long long> S) {
  // Write your code here
  // Note that S cannot be empty as per the constraint
  long long res = 0;
  std::sort(S.begin(), S.end());
  res += (S[0] - 1) / (K + 1);
  res += (N - S.back()) / (K + 1);
  for (long long i = 1; i < M; i++) {
    if (S[i] - S[i - 1] - 1 < 2 * K + 1)
      continue;
    long long tmp = (S[i] - S[i - 1] - 1) - (2 * K + 1);
    res++;
    res += (tmp / (K + 1));
  }
  return res;
}