// Given an m x n matrix, return all elements of the matrix in spiral order.
// 1 <= m, n <= 10, -100 <= matrix[i][j] <= 100
#include <stdio.h>
#include <iostream>
#include <vector>
#define visited 1000
using namespace std;

vector<int> spiralOrder (vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> result = {};
    int i = 0, j = 0; char dir = 'E';
    while (result.size() < m * n) {
        if (dir == 'E') {
            cout << "here" << endl;
            while (j < n && matrix[i][j] != visited) {
                cout << "here2" << i << j << matrix[i][j] << endl;
                cout << matrix[i][j] << j << " ";
                result.push_back(matrix[i][j]);
                matrix[i][j] = visited; j++;
            }
            j--; dir = 'S';
        }
        if (dir == 'S') {
            while (matrix[i][j] != visited && i < m) {
                cout << matrix[i][j] << " ";
                result.push_back(matrix[i][j]);
                matrix[i][j] = visited; i++;
            }
            i--; dir = 'W';
        }
        if (dir == 'W') {
            while (matrix[i][j] != visited && j >= 0) {
                cout << matrix[i][j] << " ";
                result.push_back(matrix[i][j]);
                matrix[i][j] = visited; j--;
            }
            j++; dir = 'N';
        }
        if (dir == 'N') {
            while (matrix[i][j] != visited && i >= 0) {
                cout << matrix[i][j] << " ";
                result.push_back(matrix[i][j]);
                matrix[i][j] = visited; i--;
            }
            i++; dir = 'E';
        }
    }
    return {};
}

void printMatrix (vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

void printVector (vector<int>& vector) {
    for (int i = 0; i < vector.size(); i++) {
        cout << vector[i] << " ";
    cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    printMatrix (matrix);
    vector<int> result = spiralOrder (matrix);
    printVector (result);
    return 0;
}
