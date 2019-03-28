/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (35.98%)
 * Total Accepted:    121.2K
 * Total Submissions: 336.8K
 * Testcase Example:
 * '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 * A sudoku solution must satisfy all of the following rules:
 *
 *
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 *
 *
 * Empty cells are indicated by the character '.'.
 *
 *
 * A sudoku puzzle...
 *
 *
 * ...and its solution numbers marked in red.
 *
 * Note:
 *
 *
 * The given board contain only digits 1-9 and the character '.'.
 * You may assume that the given Sudoku puzzle will have a single unique
 * solution.
 * The given board size is always 9x9.
 *
 *
 */
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  void reduce(int x, int y, int n,
              vector<vector<unordered_set<int>>>& possible) {
    possible[x][y].clear();
    for (int i = 0; i < 9; i++) {
      if (i != x) possible[i][y].erase(n);
      if (i != y) possible[x][i].erase(n);
      int x1 = i % 3 + (x / 3) * 3;
      int y1 = i / 3 + (y / 3) * 3;
      if (x1 != x || y1 != y) possible[x1][y1].erase(n);
    }
  }

  bool solver(vector<vector<char>>& board,
              vector<vector<unordered_set<int>>>& possible, int filled) {
    if (filled == 81) return true;

    int min_x = -1;
    int min_y = -1;
    int min_size = -1;

    for (int y = 0; y < 9; y++) {
      for (int x = 0; x < 9; x++) {
        if (board[x][y] != '.') continue;

        if (possible[x][y].empty()) return false;
        if (possible[x][y].size() == 1) {
          int n = *possible[x][y].begin();
          board[x][y] = '1' + n;
          auto org = possible;
          reduce(x, y, n, possible);
          if (solver(board, possible, filled + 1)) return true;
          board[x][y] = '.';
          possible = org;
          return false;
        }
        if (min_size == -1) {
          min_size = possible[x][y].size();
          min_x = x;
          min_y = y;
        } else {
          if (possible[x][y].size() < min_size) {
            min_size = possible[x][y].size();
            min_x = x;
            min_y = y;
          }
        }
      }
    }

    auto org = possible;

    for (auto n : org[min_x][min_y]) {
      board[min_x][min_y] = '1' + n;
      reduce(min_x, min_y, n, possible);
      if (solver(board, possible, filled + 1)) return true;
      board[min_x][min_y] = '.';
      possible = org;
    }

    return false;
  }

  void solveSudoku(vector<vector<char>>& board) {
    int filled = 0;
    for (int y = 0; y < 9; y++) {
      for (int x = 0; x < 9; x++) {
        if (board[x][y] != '.') filled++;
      }
    }
    if (filled == 81) return;

    vector<vector<unordered_set<int>>> possible(
        9, vector<unordered_set<int>>(9, {0, 1, 2, 3, 4, 5, 6, 7, 8}));

    for (int y = 0; y < 9; y++) {
      for (int x = 0; x < 9; x++) {
        int n = board[x][y] - '1';

        if (n >= 0 && n < 9) {
          reduce(x, y, n, possible);
        }
      }
    }

    solver(board, possible, filled);
  }
};
