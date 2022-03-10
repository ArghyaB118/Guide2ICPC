// how does pointers work
#include <iostream>
using namespace std;

int main() {
	int* arr;
	for (int i = 0; i < 5; i++) {
		*(arr + i) = i;
	}
	for (int i = 0; i < 5; i++) {
		cout << *(arr + i) << " ";
	}
	cout << endl;
	return 0;
}