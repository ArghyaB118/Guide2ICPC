// Given an m x n integer matrix matrix, if an element is 0,
// set its entire row and column to 0's. You must do it in place.
#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_set>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    unordered_set<int> zeroRows, zeroCols;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 0) {
                zeroRows.insert(i); zeroCols.insert(j);
            }
        }
    }
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (zeroRows.find(i) != zeroRows.end() || zeroCols.find(j) != zeroCols.end()) {
                matrix[i][j] = 0;
            }
        }
    }
    return;
}

void printMatrix(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    printMatrix(matrix); setZeroes(matrix); printMatrix(matrix);
    return 0;
}
