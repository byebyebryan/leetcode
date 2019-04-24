/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (30.52%)
 * Total Accepted:    167.7K
 * Total Submissions: 544.8K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 *
 *
 *
 *
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 *
 *
 *
 *
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 *
 *
 *
 * Example:
 *
 *
 * Input: [2,1,5,6,2,3]
 * Output: 10
 *
 *
 */

#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    if (n == 0) return 0;
    if (n == 1) return heights[0];

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
      res = max(res, heights[i] * width);
    }

    return res;
  }
};
