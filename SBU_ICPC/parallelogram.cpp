#include <iostream>
using namespace std;


struct pos {
	int x, y;
} ;

int main() {
	int arr[] = {4, 6, 1, 3, 1, 3, 6, 2};
	int len = sizeof(arr)/sizeof(arr[0]);
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	pos p1 = {arr[0], arr[1]};
	pos p2 = {arr[2], arr[3]};
	pos p3 = {arr[6], arr[7]};
	pos p4;
	p4.x = p1.x + p3.x - p2.x;
	p4.y = p1.y + p3.y - p2.y;
	cout << p4.x << " " <<  p4.y << endl;
	return 0;
}