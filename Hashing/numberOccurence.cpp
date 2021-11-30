// Which number is repeated how many times
#include <iostream>
#include <map>
#include <iterator>
using namespace std;

void numberOccurence (int* left, int* right) {
	map<int, int> m;
	map<int, int>::iterator itr;
	while (left < right) {
		if (m.find(*left) == m.end())
			m.insert(pair<int, int> (*left, 1));
		else
			m.find(*left)->second++;	
		left++;
	}
	for (itr = m.begin(); itr != m.end(); itr++)
		cout << itr->first << " => " << itr->second << endl;
}

int main () {
	int arr[] = {2, 3, 6, 10, 11, 2, 3, 11, 6, 3, 10, 6};
	int n = sizeof(arr) / sizeof(arr[0]); cout << n << endl;
	numberOccurence(&arr[0], &arr[n]);
	return 0;
}