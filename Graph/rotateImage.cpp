/*You are given an n x n 2D matrix representing an image,
 rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place,
 which means you have to modify the input 2D matrix directly.
 DO NOT allocate another 2D matrix and do the rotation.*/
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void rotate (vector<vector<int>>& matrix) {
    int n = matrix.size();
    // for n = 4; i = 0, 1; j = 0, 1, 2 and 1, 2
    // for n = 5; i = 0, 1; j = 0, 1, 2, 3 and 1, 2, 3
    for (int i = 0; i < n / 2; i++) {
        for (int j = i; j < n - 1 - i; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[j][n - 1 - i];
            matrix[j][n - 1 - i] = tmp;
            
            tmp = matrix[i][j];
            matrix[i][j] = matrix[n - 1 - i][n - 1 - j];
            matrix[n - 1 - i][n - 1 - j] = tmp;
            
            tmp = matrix[i][j];
            matrix[i][j] = matrix[n - 1 - j][i];
            matrix[n - 1 - j][i] = tmp;
        }
    }
}

void printMatrix (vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    // {{1,2,3},{4,5,6},{7,8,9}};
    printMatrix (matrix); rotate (matrix); printMatrix (matrix);
}
