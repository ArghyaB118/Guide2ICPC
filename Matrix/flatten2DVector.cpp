/* LC#251

Design an iterator to flatten a 2D vector. It should support the next and hasNext operations.

Implement the Vector2D class:

Vector2D(int[][] vec) initializes the object with the 2D vector vec.
next() returns the next element from the 2D vector and moves the pointer one step forward. You may assume that all the calls to next are valid.
hasNext() returns true if there are still some elements in the vector, and false otherwise.
*/

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Vector2D {
    vector<int> v;
    int cursor;
public:
    Vector2D(vector<vector<int>>& vec) {
        for (auto &i : vec) {
            for (auto &j : i) {
                this->v.push_back(j);
            }
        }
        this->cursor = 0;
    }
    
    // efficiency increases if you don't define an extra integer.
    int next() {
        cursor++;
        return this->v[this->cursor - 1];
        // int x = this->v[this->cursor];
        // cursor++;
        // return x;
    }
    
    bool hasNext() {
        return (this->cursor < this->v.size()) ? true : false;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main () {
	vector<vector<int>> vec = {{1, 2}, {3}, {4}};
	Vector2D* obj = new Vector2D(vec);
	cout << obj->next() << endl;
	cout << obj->hasNext() << endl;
	return 0;
}