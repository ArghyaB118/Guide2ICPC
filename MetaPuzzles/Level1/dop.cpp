/*
A photography set consists of 
N cells in a row, numbered from 
1 to N in order, and can be represented by a string 
C of length N. Each cell 
i is one of the following types:
“P”, it is allowed to contain a photographer
“A”, it is allowed to contain an actor
“B”, it is allowed to contain a backdrop
“.”, it must be left empty

A photograph consists of a photographer, an actor, 
and a backdrop, such that each of them is placed 
in a valid cell, and such that the actor is between 
the photographer and the backdrop. 
Such a photograph is considered artistic if the distance 
between the photographer and the actor is between 
X and Y cells (inclusive), and the distance between the actor 
and the backdrop is also between X and Y cells (inclusive). 
The distance between cells i and j is ∣i−j∣ 
(the absolute value of the difference between their indices).
Determine the number of different artistic photographs 
which could potentially be taken at the set. 
Two photographs are considered different if they involve 
a different photographer cell, actor cell, and/or backdrop cell.
*/

int getArtisticPhotographCount(int N, string C, int X, int Y) {
  // Write your code here
  vector<int> actors;
  unordered_set<int> photographers, backdrops;
  for (int i = 0; i < C.length(); i++) {
    if (C[i] == 'A')
      actors.push_back(i);
    else if (C[i] == 'P')
      photographers.insert(i);
    else if (C[i] == 'B')
      backdrops.insert(i);
  }
  int res = 0;
  for (int actor : actors) {
    int tmpPleft = 0, tmpPright = 0, tmpBleft = 0, tmpBright = 0;
    for (int i = X; i <= Y; i++) {
      if (photographers.find(actor + i) != photographers.end())
        tmpPright++;
      if (backdrops.find(actor - i) != backdrops.end())
        tmpBleft++;
      if (photographers.find(actor - i) != photographers.end())
        tmpPleft++;
      if (backdrops.find(actor + i) != backdrops.end())
        tmpBright++;
    }
    res += tmpPright * tmpBleft;
    res += tmpPleft * tmpBright;
  }
  return res;
}

