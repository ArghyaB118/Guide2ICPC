#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define TYPE int


namespace bubbleSort {
	//template <class T, class Compare>
	void swap(int *p1, int *p2) {
		int temp;
		temp = *p1;
		*p1 = *p2;
		*p2 = temp;
		//*p1 ^= *p2; *p2 ^= *p1; *p1 ^= *p2;
	}
	template <class T, class Compare>
	void sort(T* inFirst, T* inLast, Compare comp) {
		unsigned long long size = inLast - inFirst; 
		cout << size << endl;
		int i = *inFirst; cout << i << endl;
		int j = *(inLast - 1); cout << j << endl;
		for (int i = 0; i < size - 1; ++i) {
			for (int* j = inFirst; j < (inLast - i - 1); ++j) {
				int* k = (j + 1);
				if (comp(*j, *k) == 0)
					swap(j, k);
			}
		}
	}
}

