// https://www.geeksforgeeks.org/cuckoo-hashing/
#include <iostream>
using namespace std;
#define MAX_ITR 10

class CuckooHashing {
private:
	int Bucket;
	int* HashTable1; 
	int* HashTable2;
public:
	CuckooHashing(int b);
	int hash1 (int key) {
		return key % Bucket;
	}
	int hash2 (int key) {
		return (key / Bucket) % Bucket;
	}
	void insert(int key, int table, int count);
	bool search(int key);
	void display();
};



CuckooHashing::CuckooHashing (int b) {
	this->Bucket = b;
	HashTable1 = new int[Bucket];
	HashTable2 = new int[Bucket];
	for (int i = 0; i < Bucket; i++) {
		HashTable1[i] = INT_MIN;
		HashTable2[i] = INT_MIN;
	}
}



void CuckooHashing::insert(int key, int table, int count) {
	if (count > MAX_ITR)
		return;
	int index1 = hash1(key);
	int index2 = hash2(key);
	if (HashTable1[index1] == key || HashTable2[index2] == key)
		return;
	if (table == 1) {
		if (HashTable1[index1] == INT_MIN)
			HashTable1[index1] = key;
		else {
			int new_key = HashTable1[index1];
			HashTable1[index1] = key; CuckooHashing::insert(new_key, 2, count + 1);
		}
	}
	if (table == 2) {
		if (HashTable2[index2] == INT_MIN)
			HashTable2[index2] = key;
		else {
			int new_key = HashTable2[index2];
			HashTable2[index2] = key; CuckooHashing::insert(new_key, 1, count + 1);
		}
	}
}

void CuckooHashing::display() {
	cout << "Table1: ";
	for (int i = 0; i < Bucket; i++) {
		if (HashTable1[i] != INT_MIN)
			cout << HashTable1[i] << " ";
		else
			cout << "*" << " ";
	}
	cout << endl << "Table2: ";
	for (int i = 0; i < Bucket; i++) {
		if (HashTable2[i] != INT_MIN)
			cout << HashTable2[i] << " ";
		else
			cout << "*" << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = {20, 50, 53, 75, 100, 67, 105, 3, 36, 39, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	CuckooHashing h(11);
	for (int i = 0; i < n; i++)
		h.insert(arr[i], 1, 0);
	h.display();
	return 0;
}


