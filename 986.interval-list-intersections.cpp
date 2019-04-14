/*
 * @lc app=leetcode id=986 lang=cpp
 *
 * [986] Interval List Intersections
 *
 * https://leetcode.com/problems/interval-list-intersections/description/
 *
 * algorithms
 * Medium (62.65%)
 * Total Accepted:    10.4K
 * Total Submissions: 16.5K
 * Testcase Example:
 * '[[0,2],[5,10],[13,23],[24,25]]\n[[1,5],[8,12],[15,24],[25,26]]'
 *
 * Given two lists of closed intervals, each list of intervals is pairwise
 * disjoint and in sorted order.
 *
 * Return the intersection of these two interval lists.
 *
 * (Formally, a closed interval [a, b] (with a <= b) denotes the set of real
 * numbers x with a <= x <= b.  The intersection of two closed intervals is a
 * set of real numbers that is either empty, or can be represented as a closed
 * interval.  For example, the intersection of [1, 3] and [2, 4] is [2,
 * 3].)
 *
 *
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: A = [[0,2],[5,10],[13,23],[24,25]], B =
 * [[1,5],[8,12],[15,24],[25,26]]
 * Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
 * Reminder: The inputs and the desired output are lists of Interval objects,
 * and not arrays or lists.
 *
 *
 *
 *
 * Note:
 *
 *
 * 0 <= A.length < 1000
 * 0 <= B.length < 1000
 * 0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
 *
 *
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<Interval> intervalIntersection(const vector<Interval>& a,
                                        const vector<Interval>& b) {
    vector<Interval> res;

    int ai = 0;
    int a_size = a.size();

    int bi = 0;
    int b_size = b.size();

    if (a_size == 0 || b_size == 0) return res;

    while (true) {
      bool flipped = a[ai].start > b[bi].start;

      auto& x = flipped ? b : a;
      auto& y = flipped ? a : b;

      int& xi = flipped ? bi : ai;
      int& yi = flipped ? ai : bi;

      int& x_size = flipped ? b_size : a_size;
      int& y_size = flipped ? a_size : b_size;

      while (x[xi].end < y[yi].start) {
        xi++;
        if (xi == x_size) break;
      }

      if (xi == x_size) continue;

      if (x[xi].start > y[yi].start) continue;

      while (x[xi].end >= y[yi].start) {
        res.push_back(Interval(y[yi].start, x[xi].end));
        yi++;
        if (yi == y_size) break;
      }
    }

    return res;
  }
};
