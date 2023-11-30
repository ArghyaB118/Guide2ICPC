/*Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
 
 Integers in each row are sorted from left to right.
 The first integer of each row is greater than the last integer of the previous row.*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool search (vector<int>& row, int l, int r, int target) {
    if (l == r) {
        if (row[l] == target)
            return true;
        else
            return false;
    }
    else if (l + 1 == r) {
        if (row[l] == target || row[r] == target)
            return true;
        else
            return false;
    }
    else {
        if (target >= row[(l + r) / 2] && target <= row[r])
            return search (row, (l + r) / 2, r, target);
        else if (target >= row[l] && target <= row[(l + r) / 2])
            return search (row, l, (l + r) / 2, target);
    }
    return false;
}

// stream over m rows, search in one. cost = O(m + log n)
bool searchMatrix (vector<vector<int>>& matrix, int target) {
    for (auto i : matrix) {
        if (target >= i[0] && target <= i[i.size() - 1])
            return search(i, 0, i.size() - 1, target);
    }
    return false;
}

/*Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
 
 Integers in each row are sorted in ascending from left to right.
 Integers in each column are sorted in ascending from top to bottom.*/

bool searchCol (vector<vector<int>>& matrix, int t, int b, int col, int target) {
    cout << t << " " << b << " " << col << endl;
    if (t == b) {
        if (matrix[t][col] == target)
            return true;
        else
            return false;
    }
    else if (t + 1 == b) {
        cout << "here" << endl;
        if (matrix[t][col] == target || matrix[b][col] == target) {
            return true; cout << "match" << endl; }
        else
            return false;
    }
    else {
        if (target >= matrix[(t + b) / 2][col] && target <= matrix[b][col])
            return searchCol (matrix, (t + b) / 2, b, col, target);
        else if (target >= matrix[t][col] && target <= matrix[(t + b) / 2][col])
            return searchCol (matrix, t, (t + b) / 2, col, target);
    }
    return false;
}

//
bool searchMatrix2 (vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    cout << m << " " << n << endl;
    for (int i = 0; i < n; i++)
        if (target >= matrix[0][i] && target<= matrix[m - 1][i])
            return searchCol (matrix, 0, m - 1, i, target);
    cout << "here?" << endl;
    return false;
}

int main () {
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout << boolalpha << searchMatrix (matrix, 16) << endl;
    
    matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    cout << boolalpha << searchMatrix2 (matrix, 14) << endl;
    return 0;
}
