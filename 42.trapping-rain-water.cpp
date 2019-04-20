/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (42.46%)
 * Total Accepted:    277.9K
 * Total Submissions: 651.3K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 *
 *
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 *
 * Example:
 *
 *
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int trap(vector<int>& height) {
    int n = height.size();
    if (n <= 1) return 0;

    vector<int> max_from_right(n);
    max_from_right[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      max_from_right[i] = max(height[i], max_from_right[i + 1]);
    }

    int res = 0;

    int i = 0;
    while (i < n - 1) {
      if (height[i] <= height[i + 1]) {
        i++;
        continue;
      }

      int h = min(height[i], max_from_right[i + 1]);
      int j = i + 1;
      for (; j < n && height[j] < h; j++) {
        res += h - height[j];
      }
      i = j;
    }

    return res;
  }
};
