/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (45.97%)
 * Total Accepted:    216.4K
 * Total Submissions: 470.6K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 * Example:
 *
 *
 * Input:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 *
 *
 */

#include <vector>

using namespace std;

class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    if (!m) return 0;
    int n = grid[0].size();
    if (!n) return 0;

    int path[m][n];

    path[0][0] = grid[0][0];

    for (int i = 1; i < m; i++) {
      path[i][0] = path[i - 1][0] + grid[i][0];
    }

    for (int j = 1; j < n; j++) {
      path[0][j] = path[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        path[i][j] = min(path[i - 1][j], path[i][j - 1]) + grid[i][j];
      }
    }

    return path[m - 1][n - 1];
  }
};
