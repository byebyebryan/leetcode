/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 *
 * https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
 *
 * algorithms
 * Medium (45.95%)
 * Total Accepted:    35.8K
 * Total Submissions: 77.9K
 * Testcase Example:  '[[10,16],[2,8],[1,6],[7,12]]'
 *
 * There are a number of spherical balloons spread in two-dimensional space.
 * For each balloon, provided input is the start and end coordinates of the
 * horizontal diameter. Since it's horizontal, y-coordinates don't matter and
 * hence the x-coordinates of start and end of the diameter suffice. Start is
 * always smaller than end. There will be at most 104 balloons.
 *
 * An arrow can be shot up exactly vertically from different points along the
 * x-axis. A balloon with xstart and xend bursts by an arrow shot at x if
 * xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be
 * shot. An arrow once shot keeps travelling up infinitely. The problem is to
 * find the minimum number of arrows that must be shot to burst all balloons.
 *
 * Example:
 *
 * Input:
 * [[10,16], [2,8], [1,6], [7,12]]
 *
 * Output:
 * 2
 *
 * Explanation:
 * One way is to shoot one arrow for example at x = 6 (bursting the balloons
 * [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two
 * balloons).
 *
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findMinArrowShots(vector<pair<int, int>>& points) {
    int arrows = 0, i = 0, n = points.size();
    sort(points.begin(), points.end(),
         [](pair<int, int>& a, pair<int, int>& b) {
           return a.second < b.second;
         });
    while (i < n) {
      arrows++;
      int p = points[i++].second;
      while (i < n && points[i].first <= p) {
        i++;
      }
    }
    return arrows;
  }
};
