/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (35.88%)
 * Total Accepted:    101.2K
 * Total Submissions: 280.9K
 * Testcase Example:  '10'
 *
 * Write a program to find the n-th ugly number.
 *
 * Ugly numbers are positive numbers whose prime factors only include 2, 3,
 * 5. 
 *
 * Example:
 *
 *
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 *
 * Note:  
 *
 *
 * 1 is typically treated as an ugly number.
 * n does not exceed 1690.
 *
 */

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int nthUglyNumber(int n) {
    vector<int> nums;
    nums.push_back(1);
    int i2 = 0, i3 = 0, i5 = 0;

    for (int i = 1; i < n; i++) {
      nums.push_back(min(nums[i2] * 2, min(nums[i3] * 3, nums[i5] * 5)));
      if (nums[nums.size() - 1] == nums[i2] * 2) i2++;
      if (nums[nums.size() - 1] == nums[i3] * 3) i3++;
      if (nums[nums.size() - 1] == nums[i5] * 5) i5++;
    }

    return nums[n - 1];
  }
};
