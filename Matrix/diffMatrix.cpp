/* LC#2482
 
 You are given a 0-indexed m x n binary matrix grid.
 
 A 0-indexed m x n difference matrix diff is created with the following procedure:

 Let the number of ones in the ith row be onesRowi.
 Let the number of ones in the jth column be onesColj.
 Let the number of zeros in the ith row be zerosRowi.
 Let the number of zeros in the jth column be zerosColj.
 diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj
 Return the difference matrix diff.

 Input: grid = [[0,1,1],[1,0,1],[0,0,1]]
 Output: [[0,0,4],[0,0,4],[-2,-2,2]]
 Explanation:
 - diff[0][0] = onesRow0 + onesCol0 - zerosRow0 - zerosCol0 = 2 + 1 - 1 - 2 = 0
 - diff[0][1] = onesRow0 + onesCol1 - zerosRow0 - zerosCol1 = 2 + 1 - 1 - 2 = 0
 - diff[0][2] = onesRow0 + onesCol2 - zerosRow0 - zerosCol2 = 2 + 3 - 1 - 0 = 4
 - diff[1][0] = onesRow1 + onesCol0 - zerosRow1 - zerosCol0 = 2 + 1 - 1 - 2 = 0
 - diff[1][1] = onesRow1 + onesCol1 - zerosRow1 - zerosCol1 = 2 + 1 - 1 - 2 = 0
 - diff[1][2] = onesRow1 + onesCol2 - zerosRow1 - zerosCol2 = 2 + 3 - 1 - 0 = 4
 - diff[2][0] = onesRow2 + onesCol0 - zerosRow2 - zerosCol0 = 1 + 1 - 2 - 2 = -2
 - diff[2][1] = onesRow2 + onesCol1 - zerosRow2 - zerosCol1 = 1 + 1 - 2 - 2 = -2
 - diff[2][2] = onesRow2 + onesCol2 - zerosRow2 - zerosCol2 = 1 + 3 - 2 - 0 = 2*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
    vector<int> onesRows (grid.size(), 0);
    vector<int> onesCols (grid[0].size(), 0);
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1) {
                onesRows[i]++; onesCols[j]++;
            }
        }
    }
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            grid[i][j] = (onesRows[i] + onesCols[j]) - (grid.size() + grid[0].size() - onesRows[i] - onesCols[j]);
        }
    }
    return grid;
}

int main () {
    vector<vector<int>> grid = {{0,1,1},{1,0,1},{0,0,1}};
    grid = onesMinusZeros (grid);
    for (auto & i : grid) {
        for (auto & j : i)
            cout << j << " ";
        cout << endl;
    }
}
