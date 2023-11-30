/*Given an m x n board of characters and a list of strings words, return all words on the board.
 
 Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

bool startDFS (vector<vector<char>>& board, int row, int col, vector<vector<bool>>& visited, string word, int n) {
    cout << row << col << endl;
    if (n == word.length())
        return true;
    if (row < 0 || row >= board.size())
        return false;
    if (col < 0 || col >= board[row].size())
        return false;
    if (board[row][col] != word[n])
        return false;
    if (visited[row][col] == true)
        return false;
    visited[row][col] = true;
    return startDFS (board, row + 1, col, visited, word, n + 1) || startDFS (board, row - 1, col, visited, word, n + 1) || startDFS (board, row, col + 1, visited, word, n + 1) || startDFS (board, row, col - 1, visited, word, n + 1);
}

bool findWord (vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board[i].size(); j++)
            if (board[i][j] == word[0]) {
                vector<vector<bool>> visited (board.size(), vector<bool> (board[0].size(), false));
                if (startDFS (board, i, j, visited, word, 0))
                    return true;
            }
    return false;
}

vector<string> findWords (vector<vector<char>>& board, vector<string>& words) {
    vector<string> res;
    for (auto word : words)
        if (findWord (board, word))
            res.push_back(word);
    return res;
}

int main () {
    vector<vector<char>> board = {{'a','b','c'},{'a','e','d'},{'a','f','g'}}; // {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> words = {"eaabcdgfa"}; // {"abcdefg","gfedcbaaa","eaabcdgfa","befa","dgc","ade"}; // {"oath","pea","eat","rain","ethii","iflk"};
    vector<string> res = findWords (board, words);
    for (auto i : res)
        cout << i << endl;
    return 0;
}

