/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (34.71%)
 * Total Accepted:    215.3K
 * Total Submissions: 619.3K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 *
 *
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 3
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 13
 * Output: false
 *
 */

#include <vector>

using namespace std;

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (!m) return false;
    int n = matrix[0].size();
    if (!n) return false;

    if (target < matrix[0][0] || target > matrix[m - 1][n - 1]) return false;

    int b = 0;
    int t = m - 1;

    int y = -1;

    while (t >= b) {
      int mid = (b + t) / 2;
      if (target >= matrix[mid][0] && target <= matrix[mid][n - 1]) {
        y = mid;
        break;
      } else if (target < matrix[mid][0]) {
        t = mid - 1;
      } else if (target > matrix[mid][n - 1]) {
        b = mid + 1;
      }
    }

    if (y == -1) return false;

    int l = 0;
    int r = n - 1;

    while (r >= l) {
      int mid = (l + r) / 2;
      if (target == matrix[y][mid])
        return true;
      else if (target < matrix[y][mid]) {
        r = mid - 1;
      } else if (target > matrix[y][mid]) {
        l = mid + 1;
      }
    }
    return false;
  }
};
