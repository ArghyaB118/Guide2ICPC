// https://www.geeksforgeeks.org/double-hashing/

#include <iostream>
using namespace std;

#define PRIME 7

class DoubleHashing {
private:
	int Bucket, curr_size;
	int* HashTable;
public:
	DoubleHashing(int b);
	bool isFull() {
		return (curr_size == Bucket);
	}
	int hash1(int key) {
		return (key % Bucket);
	}
	int hash2(int key) {
		return (PRIME - (key % PRIME)); 
	}
	void insert(int key);
	bool search(int key);
	void display();
};

DoubleHashing::DoubleHashing(int b) {
	this->Bucket = b;
	this->curr_size = 0;
	HashTable = new int[Bucket];
	for (int i = 0; i < Bucket; i++)
		HashTable[i] = -1;
}

void DoubleHashing::insert(int key) {
	if (isFull())
		return;
	int index = hash1(key);
	if (HashTable[index] == -1) {
		HashTable[index] = key;
		curr_size++;
	}
	else {
		int i = 1;
		while (i <= 10) {
			int index2 = hash2(key);
			int new_index = (index + i * index2) % Bucket;
			if (HashTable[new_index] != -1) {
				HashTable[new_index] = key; break;
			}
			i++;
		}
	}
}


bool DoubleHashing::search(int key) {
	int index = hash1(key);
	if (HashTable[index] == key)
		return true;
	else {
		int index2 = hash2(key);
		for (int i = 1; i <= 10; i++) {
			int new_index = (index + i * index2) % Bucket;
			if (HashTable[new_index] == key)
				return true;
			else if (HashTable[new_index] == -1)
				return false;
		}
		return false;
	}
}

void DoubleHashing::display() {
	for (int i = 0; i < Bucket; i++) {
		if (HashTable[i] != -1)
			cout << i << " => " << HashTable[i] << endl;
		else
			cout << i << endl;
	}
}


int main() {
	int arr[] = {15, 5, 13, 21, 12, 18, 7, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	DoubleHashing h(13);
	for (int i = 0; i < n; i++)
		h.insert(arr[i]);
	h.display(); 
	cout << h.search(18) << endl;
	return 0;
}