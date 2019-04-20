/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (29.96%)
 * Total Accepted:    223.7K
 * Total Submissions: 743.1K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 *
 * Example 1:
 *
 *
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 *
 *
 * Example 2:
 *
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;

    int m = matrix.size();
    if (m == 0) return res;
    int n = matrix[0].size();
    if (n == 0) return res;

    if (m == 1) {
      for (int i = 0; i < n; i++) {
        res.push_back(matrix[0][i]);
      }
      return res;
    }
    if (n == 1) {
      for (int i = 0; i < m; i++) {
        res.push_back(matrix[i][0]);
      }
      return res;
    }

    int l = 0;

    while (l < m && l < n) {
      for (int i = l; i < n; i++) {
        res.push_back(matrix[l][i]);
      }
      for (int i = l + 1; i < m - 1; i++) {
        res.push_back(matrix[i][n - 1]);
      }
      if (m - l > 1) {
        for (int i = n - 1; i >= l; i--) {
          res.push_back(matrix[m - 1][i]);
        }
      }
      if (n - l > 1) {
        for (int i = m - 2; i > l; i--) {
          res.push_back(matrix[i][l]);
        }
      }

      l++;
      n--;
      m--;
    }

    return res;
  }
};
