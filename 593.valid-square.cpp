/*
 * @lc app=leetcode id=593 lang=cpp
 *
 * [593] Valid Square
 *
 * https://leetcode.com/problems/valid-square/description/
 *
 * algorithms
 * Medium (40.22%)
 * Total Accepted:    18.1K
 * Total Submissions: 45K
 * Testcase Example:  '[0,0]\n[1,1]\n[1,0]\n[0,1]'
 *
 * Given the coordinates of four points in 2D space, return whether the four
 * points could construct a square.
 *
 * The coordinate (x,y) of a point is represented by an integer array with two
 * integers.
 *
 * Example:
 *
 * Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
 * Output: True
 *
 * 1,1 1,-1
 *
 * ⁠Note:
 *
 * All the input integers are in the range [-10000, 10000].
 * A valid square has four equal sides with positive length and four equal
 * angles (90-degree angles).
 * Input points have no order.
 *
 *
 */

#include <vector>

using namespace std;

class Solution {
 public:
  bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3,
                   vector<int>& p4) {
    int d12 = dist(p1, p2);
    int d13 = dist(p1, p3);
    int d14 = dist(p1, p4);
    int d23 = dist(p2, p3);
    int d24 = dist(p2, p4);
    int d34 = dist(p3, p4);

    if (!d12 || !d13 || !d14 || !d23 || !d24 || !d34) return false;

    if (d12 != d34 || d13 != d24 || d14 != d23) return false;

    return d12 == d13 || d12 == d14 || d13 == d14;
  }

  int dist(vector<int>& a, vector<int>& b) {
    int x = a[0] - b[0];
    int y = a[1] - b[1];
    return x * x + y * y;
  }
};
