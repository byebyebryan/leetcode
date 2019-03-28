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
  vector<vector<bool>> cols = vector<vector<bool>>(9, vector<bool>(9, false));
  vector<vector<bool>> rows = vector<vector<bool>>(9, vector<bool>(9, false));
  vector<vector<bool>> zones = vector<vector<bool>>(9, vector<bool>(9, false));
  int filled = 0;

  bool solveSudoku(vector<vector<char>>& board, bool initialize = true) {
    if (initialize) {
      filled = 0;

      cols = vector<vector<bool>>(9, vector<bool>(9, false));
      rows = vector<vector<bool>>(9, vector<bool>(9, false));
      zones = vector<vector<bool>>(9, vector<bool>(9, false));

      for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
          int n = board[y][x] - '1';
          if (n >= 0 && n < 9) {
            cols[x][n] = true;
            rows[y][n] = true;
            zones[(y / 3) * 3 + x / 3][n] = true;
            filled++;
          }
        }
      }
    }

    if (filled == 81) return true;

    vector<int> nums_to_try;
    int min_x;
    int min_y;
    int min_size = -1;

    for (int y = 0; y < 9; y++) {
      for (int x = 0; x < 9; x++) {
        if(board[y][x] != '.') continue;

        vector<int> remaining;

        for (int n = 0; n < 9; n++) {
          if (!cols[x][n] && !rows[y][n] && !zones[(y / 3) * 3 + x / 3][n]) {
            remaining.push_back(n);
          }
        }

        if (remaining.empty()) return false;

        if (min_size == -1 || remaining.size() < min_size) {
          min_x = x;
          min_y = y;
          min_size = remaining.size();
          nums_to_try = remaining;
        }
      }
    }

    for (int n : nums_to_try) {
      int x = min_x;
      int y = min_y;
      board[y][x] = '1' + n;
      cols[x][n] = true;
      rows[y][n] = true;
      zones[(y / 3) * 3 + x / 3][n] = true;
      filled++;

      if (solveSudoku(board, false)) return true;

      board[y][x] = '.';
      cols[x][n] = false;
      rows[y][n] = false;
      zones[(y / 3) * 3 + x / 3][n] = false;
      filled--;
    }

    return false;
  }
};
