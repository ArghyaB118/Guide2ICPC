//https://www.geeksforgeeks.org/cuckoo-hashing/
#include <iostream>
using namespace std;
#define MAXN 37 //a PRIME number, little larger than the original size
const int ver = 2; //number of hash functions and hence possible positions
int hashtable[ver][MAXN];
int pos[ver]; 

void initTable() { 
    for (int j = 0; j < MAXN; ++j) 
        for (int i = 0; i < ver; ++i) 
            hashtable[i][j] = INT_MIN; //using dummy_variable
} 

void printTable() {
	cout << "Final Hash Tables:" << endl;
	for (int i = 0; i < ver; ++i, cout << "\n") //cool way of writing it
		for (int j = 0; j < MAXN; ++j)
			(hashtable[i][j]==INT_MIN) ? cout << " - ": cout << hashtable[i][j] << " ";
	cout << endl;
}

int hashing(int function, int key) { 
    switch (function) { 
        //case 1: return (key * (key + 3)) % MAXN;  // Cormen's hashing, crude division
        case 1: return (key * (key + 3)) % MAXN;  //Knuth's hashing
        case 2: return ((key * (key + 3)) / MAXN) % MAXN; 
        default: return 0;
    } 
} 

void place(int key, int tableid, int cnt, int n) {
	if (cnt == n) { 
		cout << key << " unpositioned. Cycle present. REHASH.\n";
        return; //void function returns
    } 
    for (int i = 0; i < ver; ++i) { //for the two tables storing the consecutive positions
        pos[i] = hashing(i+1, key); 
        if (hashtable[i][pos[i]] == key)  //checking if the key already exists
           return; 
    }
    //if: the hashtable already contains a key, we need to displace the old key
    if (hashtable[tableid][pos[tableid]] != INT_MIN) { 
        int displaced_key = hashtable[tableid][pos[tableid]];  //placing the new key
        hashtable[tableid][pos[tableid]] = key; 
        place(displaced_key, (tableid + 1) % ver, cnt + 1, n); //trying to place the old key in the next table
    }                                                          //see the tableID trick, to get the tableID 0 or 1
    else //else: place the new key in its position 
       hashtable[tableid][pos[tableid]] = key; 
}

void cuckooHashing(int keys[], int n) {
	initTable(); int cnt = 0;
	for (int i = 0; i < n; ++i)
		place(keys[i], 0, cnt, n);
	printTable();
}

int main() {
	//int setofkeys[] = {20, 50, 53, 75, 100, 67, 105, 3, 36, 39};
    int setofkeys[30];
    for (int i = 0; i < 30; ++i) //randomly generated numbers
        setofkeys[i] = rand() % 100;
	int sizeoftable = sizeof(setofkeys) / sizeof(setofkeys[0]);
	cout << "The size of the table is: " << sizeoftable << "\n";
	cuckooHashing(setofkeys, sizeoftable); 
}