/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 *
 * https://leetcode.com/problems/arithmetic-slices/description/
 *
 * algorithms
 * Medium (55.44%)
 * Total Accepted:    60K
 * Total Submissions: 107.9K
 * Testcase Example:  '[1,2,3,4]'
 *
 * A sequence of number is called arithmetic if it consists of at least three
 * elements and if the difference between any two consecutive elements is the
 * same.
 *
 * For example, these are arithmetic sequence:
 * 1, 3, 5, 7, 9
 * 7, 7, 7, 7
 * 3, -1, -5, -9
 *
 * The following sequence is not arithmetic. 1, 1, 2, 5, 7
 *
 *
 * A zero-indexed array A consisting of N numbers is given. A slice of that
 * array is any pair of integers (P, Q) such that 0
 *
 * A slice (P, Q) of array A is called arithmetic if the sequence:
 * ⁠   A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this
 * means that P + 1 < Q.
 *
 * The function should return the number of arithmetic slices in the array
 * A.
 *
 *
 * Example:
 *
 * A = [1, 2, 3, 4]
 *
 * return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3,
 * 4] itself.
 *
 */

#include <vector>

using namespace std;

class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    if (nums.size() < 3) return 0;

    vector<int> diffs(nums.size() - 1);
    for (int i = 0; i < nums.size() - 1; i++) {
      diffs[i] = nums[i + 1] - nums[i];
    }

    int res = 0;
    for (int i = 0; i < diffs.size() - 1; i++) {
      if (diffs[i + 1] != diffs[i]) continue;

      int c = 3;
      int j = i + 1;
      while (j + 1 < diffs.size()) {
        if (diffs[j] == diffs[j + 1]) {
          j++;
          c++;
        } else {
          break;
        }
      }

      if (c == 3) {
        i++;
        res += 1;
      } else {
        i = j;
        int x = c - 3 + 1;
        res += (x + 1) * x / 2;
      }
    }

    return res;
  }
};
