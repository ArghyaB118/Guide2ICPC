#include <iostream>
#include <vector>
using namespace std;

int main () {
	int a = 5;
	cout << typeid(a).name() << endl;
	vector<int> b{1,2};
	cout << typeid(b).name() << endl;
	return 0;
}