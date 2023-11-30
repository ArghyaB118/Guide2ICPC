// parallel_merge_sort
#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
using namespace std;

vector<int> arr = {1, 14, 3, 8, 11, 10, 7, 5, 2, 16, 12, 23, 4, 13, 15, 20};
int max_thread = 4;

void merge_sort (int start, int end) {
	cout << start << end << endl;
	if (start >= end)
		return;
	else if (end == start + 1) {
		int tmp = arr[start];
		arr[start] = min(tmp, arr[end]);
		arr[end] = max(tmp, arr[end]);
		return;
	}
	int mid = start + (end - start + 1) / 2;
	merge_sort(start, mid - 1);
	merge_sort(mid, end);
	std::inplace_merge(arr.begin() + start, arr.begin() + mid, arr.begin() + end + 1); 
	// note that the end element has to be index + 1
}

// template<class Iter>
typedef vector<int>::iterator Iter;

void merge_sort2 (Iter start, Iter end) {
	if (end - start > 1) {
		Iter mid = start + (end - start) / 2;
		merge_sort2(start, mid);
		merge_sort2(mid, end);
		std::inplace_merge(start, mid, end);
	}
}

void print() {
	for (auto& i : arr)
		cout << i << " ";
	cout << endl;
}

// need more work to debug
void merge (int start, int mid, int end) {
	if (end == start + 1) {
		int tmp = arr[start];
		arr[start] = min(tmp, arr[end]);
		arr[end] = max(tmp, arr[end]);
	}
	else {
		vector<int> tmp;
		int i = start, j = mid;
		while (i < mid || j <= end) {
			if (arr[i] < arr[j]) {
				tmp.push_back(arr[i]);
				i++;
			}
			else {
				tmp.push_back(arr[j]);
				j++;
			}
		}
		while (i < mid) {
			tmp.push_back(arr[i]); i++;
		}
		while (j < end + 1) {
			tmp.push_back(arr[j]); j++;
		}
		for (int i = start; i <= end; i++)
			arr[i] = tmp[i - start];
	}
}

void merge_sort_custom_merge (int start, int end) {
	cout << start << end << endl;
	if (start >= end)
		return;
	else if (end == start + 1) {
		int tmp = arr[start];
		arr[start] = min(tmp, arr[end]);
		arr[end] = max(tmp, arr[end]);
		return;
	}
	int mid = start + (end - start + 1) / 2;
	merge_sort(start, mid - 1);
	merge_sort(mid, end);
	merge(start, mid, end);
}

int main () {
	print();
	merge_sort (0, 15); print();
	
	arr = {1, 14, 3, 8, 11, 10, 7, 5, 2, 16, 12, 23, 4, 13, 15, 20};
	merge_sort_custom_merge(0, 15); print();
	
	arr = {1, 14, 3, 8, 11, 10, 7, 5, 2, 16, 12, 23, 4, 13, 15, 20};
	merge_sort2(arr.begin(), arr.end()); print();

	arr = {1, 14, 3, 8, 11, 10, 7, 5, 2, 16, 12, 23, 4, 13, 15, 20};
	int size = arr.size();
	std::thread thread1(merge_sort2, arr.begin(), arr.begin() + size / 2);
	std::thread thread2(merge_sort2, arr.begin() + size / 2, arr.begin() + size);
	thread1.join();	thread2.join();
	std::inplace_merge(arr.begin(), arr.begin() + size / 2, arr.begin() + size);
	print();
	return 0;
}