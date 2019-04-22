/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (43.22%)
 * Total Accepted:    347.8K
 * Total Submissions: 795.7K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 *
 * Note: You may not slant the container and n is at least 2.
 *
 *
 *
 *
 *
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
 * this case, the max area of water (blue section) the container can contain is
 * 49.
 *
 *
 *
 * Example:
 *
 *
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 *
 */

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int n = height.size();
    if (n == 2) return min(height[0], height[1]);

    int l = 0, r = n - 1;
    int res = 0;
    while (l < r) {
      res = max(res, min(height[l], height[r]) * (r - l));
      if (height[l] < height[r])
        l++;
      else
        r--;
    }

    return res;
  }
};
