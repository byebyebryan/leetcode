/*
 * @lc app=leetcode id=962 lang=cpp
 *
 * [962] Maximum Width Ramp
 *
 * https://leetcode.com/problems/maximum-width-ramp/description/
 *
 * algorithms
 * Medium (40.94%)
 * Total Accepted:    7.9K
 * Total Submissions: 19.1K
 * Testcase Example:  '[6,0,8,2,1,5]'
 *
 * Given an array A of integers, a ramp is a tuple (i, j) for which i < j and
 * A[i] <= A[j].  The width of such a ramp is j - i.
 *
 * Find the maximum width of a ramp in A.  If one doesn't exist, return 0.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [6,0,8,2,1,5]
 * Output: 4
 * Explanation:
 * The maximum width ramp is achieved at (i, j) = (1, 5): A[1] = 0 and A[5] =
 * 5.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: [9,8,1,0,1,9,4,0,4,1]
 * Output: 7
 * Explanation:
 * The maximum width ramp is achieved at (i, j) = (2, 9): A[2] = 1 and A[9] =
 * 1.
 *
 *
 *
 *
 *
 *
 *
 * Note:
 *
 *
 * 2 <= A.length <= 50000
 * 0 <= A[i] <= 50000
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <vector>

using namespace std;

class Solution {
 public:
  int maxWidthRamp(vector<int>& nums) {
    int res = 0;

    int n = nums.size();

    vector<int> smallest(n);
    vector<int> biggest(n);

    smallest[0] = 0;

    for (int i = 1; i < n; i++) {
      if (nums[i] < nums[smallest[i - 1]]) {
        smallest[i] = i;
      } else {
        smallest[i] = smallest[i - 1];
      }
    }

    biggest[n - 1] = n - 1;

    for (int i = n - 2; i >= 0; i--) {
      if (nums[i] > nums[biggest[i + 1]]) {
        biggest[i] = i;
      } else {
        biggest[i] = biggest[i + 1];
      }
    }

    if (nums[smallest[n - 1]] > nums[biggest[0]]) return 0;

    for (int i = 0; i < n - 1; i++) {
      if (i > 0 && smallest[i] == smallest[i - 1]) {
        continue;
      }

      if (nums[smallest[i]] > nums[biggest[i]]) continue;
      if (nums[smallest[i]] == nums[biggest[i]]) {
        res = res > biggest[i] - smallest[i] ? res : biggest[i] - smallest[i];
      }

      int l = i + 1;
      int r = n - 1;

      int x_idx = smallest[i];
      int x = nums[smallest[i]];

      while (l <= r) {
        int m = (l + r) / 2;

        if (nums[biggest[m]] >= x) {
          res = res > biggest[m] - x_idx ? res : biggest[m] - x_idx;
          l = m + 1;
        } else {
          r = m - 1;
        }
      }
    }

    return res;
  }
};
