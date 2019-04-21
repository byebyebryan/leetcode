/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 *
 * https://leetcode.com/problems/subarray-sums-divisible-by-k/description/
 *
 * algorithms
 * Medium (43.20%)
 * Total Accepted:    8.9K
 * Total Submissions: 20.3K
 * Testcase Example:  '[4,5,0,-2,-3,1]\n5'
 *
 * Given an array A of integers, return the number of (contiguous, non-empty)
 * subarrays that have a sum divisible by K.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: A = [4,5,0,-2,-3,1], K = 5
 * Output: 7
 * Explanation: There are 7 subarrays with a sum divisible by K = 5:
 * [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2,
 * -3]
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= A.length <= 30000
 * -10000 <= A[i] <= 10000
 * 2 <= K <= 10000
 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int subarraysDivByK(vector<int>& nums, int k) {
    int n = nums.size();

    int res = 0;

    vector<int> finder(k, 0);
    int sum = 0;

    for (int i = 0; i < n; i++) {
      sum += nums[i];
      sum %= k;
      sum = sum < 0 ? sum + k : sum;
      if (sum == 0) res++;
      res += finder[sum];
      finder[sum]++;
    }

    return res;
  }
};
