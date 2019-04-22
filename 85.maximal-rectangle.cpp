/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (32.65%)
 * Total Accepted:    117.5K
 * Total Submissions: 356.8K
 * Testcase Example:
 * '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing only 1's and return its area.
 *
 * Example:
 *
 *
 * Input:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * Output: 6
 *
 *
 */

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    int m = matrix.size();
    if (m == 0) return 0;
    int n = matrix[0].size();
    if (n == 0) return 0;

    if (m == 1 && n == 1) return matrix[0][0] == '1' ? 1 : 0;

    int res = 0;
    vector<int> heights(n, 0);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int x = matrix[i][j] - '0';
        heights[j] *= x;
        heights[j] += x;
      }
      res = max(res, maxHistogram(heights));
    }

    return res;
  }

  int maxHistogram(vector<int>& heights) {
    int n = heights.size();

    stack<int> monotone_increase;
    vector<int> prev_less(n, -1), next_less(n, -1);

    for (int i = 0; i < n; i++) {
      while (!monotone_increase.empty() &&
             heights[monotone_increase.top()] > heights[i]) {
        next_less[monotone_increase.top()] = i;
        monotone_increase.pop();
      }
      prev_less[i] = monotone_increase.empty() ? -1 : monotone_increase.top();
      monotone_increase.push(i);
    }

    int res = heights[0];
    for (int i = 0; i < n; i++) {
      int width = prev_less[i] < 0 ? i + 1 : i - prev_less[i];
      width += next_less[i] < 0 ? n - i - 1 : next_less[i] - i - 1;
      res = max(res, width * heights[i]);
    }
    return res;
  }
};
