/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 *
 * https://leetcode.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (33.26%)
 * Total Accepted:    188.9K
 * Total Submissions: 567.9K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 *
 * Now consider if some obstacles are added to the grids. How many unique paths
 * would there be?
 *
 *
 *
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 *
 * Note: m and n will be at most 100.
 *
 * Example 1:
 *
 *
 * Input:
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * Output: 2
 * Explanation:
 * There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 *
 *
 */
#include <vector>

using namespace std;

class Solution {
 public:
  unsigned uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int m = grid.size();
    if (!m) return 0;
    int n = grid[0].size();
    if (!n) return 0;

    if (m == 1 || n == 1) {
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (grid[i][j]) return 0;
        }
      }

      return 1;
    }

    unsigned paths[m][n];

    bool blocked = false;

    for (int i = 0; i < m; i++) {
      if (grid[i][0]) blocked = true;
      paths[i][0] = blocked ? 0 : 1;
    }

    blocked = false;

    for (int j = 0; j < n; j++) {
      if (grid[0][j]) blocked = true;
      paths[0][j] = blocked ? 0 : 1;
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        paths[i][j] = grid[i][j] ? 0 : paths[i][j - 1] + paths[i - 1][j];
      }
    }

    return paths[m - 1][n - 1];
  }
};
