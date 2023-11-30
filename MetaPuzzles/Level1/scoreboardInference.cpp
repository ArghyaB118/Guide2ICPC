/*
You are spectating a programming contest with 
N competitors, each trying to independently solve the same set 
of programming problems. Each problem has a point value, 
which is either 1 or 2. On the scoreboard, you observe that 
the ith competitor has attained a score of S_i, 
which is a positive integer equal to the sum of the point 
values of all the problems they have solved.
The scoreboard does not display the number of problems
in the contest, nor their point values. 
Using the information available, you would like to determine 
the minimum possible number of problems in the contest.
*/

int getMinProblemCount(int N, vector<int> S) {
  // Write your code here
  int m = *max_element(S.begin(), S.end());
  m /= 2;
  for (int s : S) {
    if (s % 2 == 1) {
      m += 1;
      break;
    }    
  }
  return m;
}