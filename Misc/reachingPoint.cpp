/*
Reaching Points:
Given four integers sx, sy, tx, and ty, 
return true if it is possible to convert the point (sx, sy) 
to the point (tx, ty) through some operations, or false otherwise.

The allowed operation on some point (x, y) is to convert it to 
either (x, x + y) or (x + y, y).
*/
#include <iostream>
using namespace std;

bool reachingPoint (int sx, int sy, int dx, int dy) {
	if (dx == 0 || dy == 0 || dx < sx || dy < sy)
		return false;
	else if (sx == dx && sy == dy)
		return true;
	return reachingPoint(sx, sy + sx, dx, dy) || reachingPoint(sx + sy, sy, dx, dy);
}

int main () {
	int sx = 35, sy = 13, dx = 455955547, dy = 420098884;
	cout << boolalpha << reachingPoint(sx,sy,dx,dy) << endl;
	return 0;
}