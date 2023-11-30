/* Write Y in a matrix
 Input: An n * n matrix where n is an odd number 3 \leq n \leq 1000
 matrix[i][j] == 0 or 1 or 2
 In operation, you can only change one cell.
 
 Output: Return the minimum number of operations so that the matrix has the cells that constitute an Y have the same value, and all other cells have a same and different than the former value.
 
 Example:
 1 0 0      0 1 0
 0 2 1  =>  1 0 1
 1 0 1      1 0 1
 */

#include <iostream>
#include <vector>
using namespace std;


int writeY (vector<vector<int>> matrix) {
    int n = matrix.size();
    int a = 0, b = 0, c = 0;
    int d = 0, e = 0, f = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < n / 2 && (i == j || i == n - j - 1)) {
                if (matrix[i][j] == 0)
                    a++;
                else if (matrix[i][j] == 1)
                    b++;
                else if (matrix[i][j] == 2)
                    c++;
            }
            else if (i >= n / 2 && j == n / 2) {
                if (matrix[i][j] == 0)
                    a++;
                else if (matrix[i][j] == 1)
                    b++;
                else if (matrix[i][j] == 2)
                    c++;
            }
            else {
                if (matrix[i][j] == 0)
                    d++;
                else if (matrix[i][j] == 1)
                    e++;
                else if (matrix[i][j] == 2)
                    f++;
            }
        }
    }
    
    cout << a << b << c << d << e << f << endl;
    
    // number of cells out of Y is more than
    // number of cells in the Y
    // possible combinations: (0, 1), (0, 2), (1, 0), (1, 2), (2, 0), (2, 1)
    int count = 0, tmp = 0;
    tmp += b; tmp += c; tmp += d; tmp += f;
    count = tmp; tmp = 0;
    tmp += b; tmp += c; tmp += d; tmp += e;
    count = min(count, tmp); tmp = 0;
    tmp += a; tmp += c; tmp += e; tmp += f;
    count = min(count, tmp); tmp = 0;
    tmp += a; tmp += c; tmp += d; tmp += e;
    count = min(count, tmp); tmp = 0;
    tmp += a; tmp += b; tmp += e; tmp += f;
    count = min(count, tmp); tmp = 0;
    tmp += a; tmp += b; tmp += d; tmp += f;
    count = min(count, tmp); tmp = 0;
    
    return count;
}

int main () {
    vector<vector<int>> matrix = {{1, 0, 0}, {0, 2, 1}, {1, 0, 1}};
    cout << writeY(matrix) << endl;
    return 0;
}

