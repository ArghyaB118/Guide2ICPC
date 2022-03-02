/*
Possible Bipartition:
We want to split a group of n people (labeled from 1 to n) 
into two groups of any size. Each person may dislike some other people, 
and they should not go into the same group.

Given the integer n and the array dislikes where dislikes[i] = [ai, bi] 
indicates that the person labeled ai does not like the person labeled bi, 
return true if it is possible to split everyone into two groups in this way.
*/

#include <iostream> 
#include <vector> 
using namespace std;

bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
	
}

int main () {
	int n = 4;
	vector<vector<int>> dislikes{{1,2},{1,3},{2,4}};
	cout << boolalpha << possibleBipartition(n, dislikes) << endl;
	return 0;
}