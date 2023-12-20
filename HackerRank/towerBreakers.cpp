/*
Two players are playing a game of Tower Breakers! 
Player 1 always moves first, 
and both players always play optimally.

The rules of the game are as follows:
Initially there are n towers.
Each tower is of height m.
The players move in alternating turns.
In each turn, a player can choose a tower of height y 
and reduce its height to x, where 1 <= x <= y and x evenly divides y.
If the current player is unable to make a move, they lose the game.
Given the values of n and m, 
determine which player will win. 
If the first player wins, return 1. Otherwise, return 2.
*/

#include <iostream>
using namespace std;

int towerBreakers(int n, int m) {
	if (m == 1)
		return 2;
	if (n == 1 && m > 1)
		return 1;
	if (n % 2 == 1 && m > 1)
		return 1;
	return 2;
}

int main () {
	int n = 12, m = 6;
	cout << towerBreakers (n, m) << endl;
	return 0;
}