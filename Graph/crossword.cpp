/*You are given an m x n matrix board, representing the current state of a crossword puzzle. The crossword contains lowercase English letters (from solved words), ' ' to represent any empty cells, and '#' to represent any blocked cells.
 
 A word can be placed horizontally (left to right or right to left) or vertically (top to bottom or bottom to top) in the board if:

 It does not occupy a cell containing the character '#'.
 The cell each letter is placed in must either be ' ' (empty) or match the letter already on the board.
 There must not be any empty cells ' ' or other lowercase letters directly left or right of the word if the word was placed horizontally.
 There must not be any empty cells ' ' or other lowercase letters directly above or below the word if the word was placed vertically.
 Given a string word, return true if word can be placed in board, or false otherwise.*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool horizontalRun (vector<vector<char>>& board, string word, int m, int n, int i, int j) {
    if (board[i][j] == '#')
        return false;
    else if (j - 1 >= 0 && board[i][j - 1] != '#')
        return false;
    else if (j + word.length() > n)
        return false;
    else if (j + word.length() < n && board[i][j + word.length() - 1] != '#')
        return false;
    else {
        for (int k = 0; k < word.length(); k++) {
            if (j + k >= n)
                return false;
            else if (board[i][j + k] == '#')
                return false;
            else if (board[i][j + k] != ' ' && board[i][j + k] != word[k])
                return false;
        }
    }
    return true;
}

bool verticalRun (vector<vector<char>>& board, string word, int m, int n, int i, int j) {
    if (board[i][j] == '#')
        return false;
    else if (i - 1 >= 0 && board[i - 1][j] != '#')
        return false;
    else if (i + word.length() > m)
        return false;
    else if (i + word.length() < m && board[i + word.length() - 1][j] != '#')
        return false;
    else {
        cout << "here" << endl;
        for (int k = 0; k < word.length(); k++) {
            if (i + k >= n)
                return false;
            else if (board[i + k][j] == '#')
                return false;
            else if (board[i + k][j] != ' ' && board[i + k][j] != word[k])
                return false;
        }
    }
    return true;
}

bool placeWordInCrossword (vector<vector<char>>& board, string word) {
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << i << j << endl;
            if (horizontalRun(board, word, m, n, i , j))
                return true;
            if (verticalRun(board, word, m, n, i , j))
                return true;
        }
    }
    return false;
}

int main () {
    vector<vector<char>> board = {{'#', ' ', '#'}, {' ', ' ', '#'}, {'#', 'c', ' '}};
    string word = "abc";
    cout << boolalpha << placeWordInCrossword (board, word) << endl;
    return 0;
}
