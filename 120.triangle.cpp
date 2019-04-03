/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (38.63%)
 * Total Accepted:    174K
 * Total Submissions: 449.5K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step
 * you may move to adjacent numbers on the row below.
 *
 * For example, given the following triangle
 *
 *
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 *
 *
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 *
 * Note:
 *
 * Bonus point if you are able to do this using only O(n) extra space, where n
 * is the total number of rows in the triangle.
 *
 */

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int l = triangle.size();

    if (l == 0) return 0;
    if (l == 1) return triangle[0][0];

    for (int i = 1; i < l; i++) {
      triangle[i][0] += triangle[i - 1][0];
      triangle[i][i] += triangle[i - 1][i - 1];

      for (int j = 1; j < i; j++) {
        triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
      }
    }

    int min_sum = INT_MAX;
    for (int i = 0; i < l; i++) {
      min_sum = min(triangle[l - 1][i], min_sum);
    }

    return min_sum;
  }
};
