/*
 * @lc app=leetcode id=419 lang=cpp
 *
 * [419] Battleships in a Board
 *
 * https://leetcode.com/problems/battleships-in-a-board/description/
 *
 * algorithms
 * Medium (65.32%)
 * Total Accepted:    60.4K
 * Total Submissions: 92.3K
 * Testcase Example:  '[["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]'
 *
 * Given an 2D board, count how many battleships are in it. The battleships are
 * represented with 'X's, empty slots are represented with '.'s. You may assume
 * the following rules:
 *
 *
 * You receive a valid board, made of only battleships or empty slots.
 * Battleships can only be placed horizontally or vertically. In other words,
 * they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1
 * column), where N can be of any size.
 * At least one horizontal or vertical cell separates between two battleships -
 * there are no adjacent battleships.
 *
 *
 * Example:
 * X..X
 * ...X
 * ...X
 *
 * In the above board there are 2 battleships.
 *
 * Invalid Example:
 * ...X
 * XXXX
 * ...X
 *
 * This is an invalid board that you will not receive - as battleships will
 * always have a cell separating between them.
 *
 * Follow up:Could you do it in one-pass, using only O(1) extra memory and
 * without modifying the value of the board?
 */

#include <vector>

using namespace std;

class Solution {
 public:
  int countBattleships(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();

    int res = 0;
    for (int y = 0; y < m; y++) {
      for (int x = 0; x < n; x++) {
        if (board[y][x] != '.') {
          if (x == 0 && y == 0)
            res++;
          else if (x == 0) {
            if (board[y - 1][x] == '.') res++;
          } else if (y == 0) {
            if (board[y][x - 1] == '.') res++;
          } else {
            if (board[y - 1][x] == '.' && board[y][x - 1] == '.') res++;
          }
        }
      }
    }

    return res;
  }
};
