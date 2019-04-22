/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 *
 * https://leetcode.com/problems/sum-of-subarray-minimums/description/
 *
 * algorithms
 * Medium (25.85%)
 * Total Accepted:    9.1K
 * Total Submissions: 34.7K
 * Testcase Example:  '[3,1,2,4]'
 *
 * Given an array of integers A, find the sum of min(B), where B ranges over
 * every (contiguous) subarray of A.
 *
 * Since the answer may be large, return the answer modulo 10^9 + 7.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [3,1,2,4]
 * Output: 17
 * Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2],
 * [1,2,4], [3,1,2,4].
 * Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.
 *
 *
 *
 * Note:
 *
 *
 * 1 <= A.length <= 30000
 * 1 <= A[i] <= 30000
 *
 *
 *
 *
 *
 *
 */

#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  int sumSubarrayMins(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    int res = 0;
    int mod = 1e9 + 7;

    stack<int> monotone_increase;
    vector<int> prev_less(n, -1), next_less(n, -1);

    for (int i = 0; i < n; i++) {
      while (!monotone_increase.empty() &&
             nums[monotone_increase.top()] > nums[i]) {
        next_less[monotone_increase.top()] = i;
        monotone_increase.pop();
      }
      prev_less[i] = monotone_increase.empty() ? -1 : monotone_increase.top();
      monotone_increase.push(i);
    }

    for (int i = 0; i < n; i++) {
      res += nums[i] * (prev_less[i] < 0 ? i + 1 : i - prev_less[i]) *
             (next_less[i] < 0 ? n - i : next_less[i] - i);
      res %= mod;
    }

    return res;
  }
};
