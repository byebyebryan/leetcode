/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (45.83%)
 * Total Accepted:    132.5K
 * Total Submissions: 287.8K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate a square matrix filled with elements
 * from 1 to n2 in spiral order.
 *
 * Example:
 *
 *
 * Input: 3
 * Output:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 *
 *
 */

#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, n * n));

    int l = 0;
    int r = n - 1;

    int x = 1;

    while (l < r) {
      for (int i = l; i < r; i++) {
        res[l][i] = x++;
      }
      for (int i = l; i < r; i++) {
        res[i][r] = x++;
      }
      for (int i = r; i > l; i--) {
        res[r][i] = x++;
      }
      for (int i = r; i > l; i--) {
        res[i][l] = x++;
      }
      l++;
      r--;
    }

    return res;
  }
};
