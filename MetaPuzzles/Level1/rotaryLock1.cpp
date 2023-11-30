/*
You're trying to open a lock. The lock comes with a wheel 
which has the integers from 1 to N arranged in a circle 
in order around it (adjacent to one another). 
The wheel is initially pointing at 1.

It takes 1 second to rotate the wheel by 
1 unit to an adjacent integer in either direction, 
and it takes no time to select an integer once the wheel 
is pointing at it. The lock will open if you enter a certain code. 
The code consists of a sequence of M integers. 
Determine the minimum number of seconds required to select all 
M of the code's integers in order.
*/

long long getMinCodeEntryTime(int N, int M, vector<int> C) {
  // Write your code here
  long long res = 0;
  int current = 1;
  for (int c : C) {
    res += min(abs(c - current), N - abs(c - current));
    current = c;
  }
  return res;
}
