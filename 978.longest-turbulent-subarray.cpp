/*
 * @lc app=leetcode id=978 lang=cpp
 *
 * [978] Longest Turbulent Subarray
 *
 * https://leetcode.com/problems/longest-turbulent-subarray/description/
 *
 * algorithms
 * Medium (45.56%)
 * Total Accepted:    8.1K
 * Total Submissions: 17.7K
 * Testcase Example:  '[9,4,2,10,7,8,8,1,9]'
 *
 * A subarray A[i], A[i+1], ..., A[j] of A is said to be turbulent if and only
 * if:
 *
 *
 * For i <= k < j, A[k] > A[k+1] when k is odd, and A[k] < A[k+1] when k is
 * even;
 * OR, for i <= k < j, A[k] > A[k+1] when k is even, and A[k] < A[k+1] when k
 * is odd.
 *
 *
 * That is, the subarray is turbulent if the comparison sign flips between each
 * adjacent pair of elements in the subarray.
 *
 * Return the length of a maximum size turbulent subarray of A.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [9,4,2,10,7,8,8,1,9]
 * Output: 5
 * Explanation: (A[1] > A[2] < A[3] > A[4] < A[5])
 *
 *
 *
 * Example 2:
 *
 *
 * Input: [4,8,12,16]
 * Output: 2
 *
 *
 *
 * Example 3:
 *
 *
 * Input: [100]
 * Output: 1
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
 * 1 <= A.length <= 40000
 * 0 <= A[i] <= 10^9
 *
 */

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxTurbulenceSize(vector<int>& nums) {
    int n = nums.size();
    if (n == 0 || n == 1) return n;
    if (n == 2) return nums[0] == nums[1] ? 1 : 2;

    int res = 1;

    int i = 1;
    int c = 1;
    int comp = 1;

    while (i < n) {
      if (nums[i] == nums[i - 1]) {
        res = max(res, c);
        comp = 0;
        c = 1;
        i++;
        continue;
      }

      if (nums[i] * comp < nums[i - 1] * comp) {
        comp = -comp;
        c++;
        res = max(res, c);
        i++;
      } else {
        comp = nums[i] < nums[i - 1] ? -1 : 1;
        res = max(res, c);
        c = 2;
        res = max(res, c);
        i++;
      }
    }

    return res;
  }
};
