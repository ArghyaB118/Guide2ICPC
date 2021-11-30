// A Backtracking program in
// C++ to solve Sudoku problem

// https://www.geeksforgeeks.org/sudoku-backtracking-7/
// https://www.tutorialspoint.com/sudoku-solver-in-cplusplus

// Solve a Sudoku using Backtracking
// Time: O(9^(n * n))
// Space: O(n * n)

#include <iostream>
#include <utility>
#include <fstream>
#include <string.h>
#include <sstream>
#include <cstdlib>
using namespace std;

//pair<int, int> cell;

#define UNASSIGNED 0
#define n 9

class Sudoku {
private:
	int grid[n][n];
public:
	Sudoku() {
		memset(grid, UNASSIGNED, sizeof(grid));
		readSudoku();
	}

	void readSudoku() {
		std::ifstream file; file.open("input.csv");
		std::string line;
		int i = 0;
		while (i < n) {
			getline(file, line);
			std::stringstream ss(line);
			int j = 0;
			while (ss.good() && j < n) {
				std::string substr;
				getline(ss, substr, ',');
				grid[i][j] = stoi(substr);
				j++;
			}
			i++;
		}
		file.close();
	}

	void displaySudoku() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << grid[i][j] << " ";
			cout << endl;
		}
	}

	bool inRow (int rowNum, int num) {
		for (int i = 0; i < n; i++)
			if (grid[rowNum][i] == num)
				return true;
		return false;
	}
	bool inCol (int colNum, int num) {
		for (int i = 0; i < n; i++)
			if (grid[i][colNum] == num)
				return true;
		return false;
	}
	bool inBox (int rowNum, int colNum, int num) {
		for (int i = 0; i < n / 3; i++)
			for (int j = 0; j < n / 3; j++)
				if (grid[rowNum + i][colNum + j] == num)
					return true;
		return false;
	}

	bool isSafe (int rowNum, int colNum, int num) {
		return (!inRow(rowNum, num) && !inCol(colNum, num) 
			&& !inBox(rowNum - rowNum / 3, colNum - colNum / 3, num) 
			&& grid[rowNum][colNum] == UNASSIGNED);
	}

	bool isSolved() {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (grid[i][j] == UNASSIGNED)
					return false;
		return true;
	}

	pair<int, int> findUnassined (pair<int, int> cell) {
		int row = cell.first, col = cell.second;
		for (int i = row; i < n; i++)
			for (int j = col; j < n; j++)
				if (grid[i][j] == UNASSIGNED)
					return make_pair(i,j);
		return make_pair(-1,-1);
	}

	bool solveSudoku(pair<int, int> cell) {
		int row1 = cell.first, col1 = cell.second; cout << row1 << " " << col1 << endl;
		if (isSolved())
			return true;
		cell = findUnassined(cell);
		int row = cell.first, col = cell.second;
		for (int num = 1; num <= 9; num++) {
			if (isSafe(row, col, num)) {
				grid[row][col] = num;
				if (col < n - 1) {
					if (solveSudoku(make_pair(row, col + 1)))
						return true;
				}
				else {
					if (solveSudoku(make_pair(row + 1, 0)))
						return true;
				}
				grid[row][col] = UNASSIGNED;
			}
		}
		return false;
	}
};


int main() {
	Sudoku s; 
	cout << "Input Sudoku" << endl; s.displaySudoku();
	cout << "Solved Sudoku" << endl; s.solveSudoku(make_pair(0,0));
	s.displaySudoku();
	return 0;
}