// https://www.geeksforgeeks.org/bloom-filters-introduction-and-python-implementation/
// knapsack: https://www.tutorialspoint.com/cplusplus-program-to-solve-knapsack-problem-using-dynamic-programming

// https://www.geeksforgeeks.org/c-program-hashing-chaining/
#include <iostream>
#include <list>
using namespace std;

class Hashing {
private:
	int Bucket;
	list<int> *HashTable;
public:
	Hashing(int b); // constructor
	void insert(int key);
	void deletekey(int key);
	int hashfn(int key) {
		return(key % Bucket);
	}
	void display();
	//~Hashing();
};

Hashing::Hashing(int b) {
	this->Bucket = b;
	HashTable = new list<int>[Bucket];
}

void Hashing::insert(int key) {
	int index = hashfn(key);
	HashTable[index].push_back(key);
}

void Hashing::deletekey(int key) {
	int index = hashfn(key);
	list <int> :: iterator i; 
	for (i = HashTable[index].begin(); i != HashTable[index].end(); i++) { 
		if (*i == key) 
	  		break; 
	}   
	// if key is found in hash table, remove it 
	if (i != HashTable[index].end()) 
    	HashTable[index].erase(i); 
}

void Hashing::display() {
	for (int i = 0; i < Bucket; i++) {
		cout << i << " => ";
		for (auto x : HashTable[i])
			cout << x << " ";
		cout << endl;
	}
}

int main() {
	int arr[] = {15, 5, 13, 21, 12, 18, 7, 3};
	int n = sizeof(arr) / sizeof(arr[0]);

	Hashing h(7);
	for (int i = 0; i < n; i++)
		h.insert(arr[i]);
	h.display();
	h.deletekey(13); h.deletekey(7);
	h.display();
	h.insert(13); h.insert(7);
	h.display();
	return 0;
}

