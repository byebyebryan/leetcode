/*
 * @lc app=leetcode id=845 lang=cpp
 *
 * [845] Longest Mountain in Array
 *
 * https://leetcode.com/problems/longest-mountain-in-array/description/
 *
 * algorithms
 * Medium (33.96%)
 * Total Accepted:    15.8K
 * Total Submissions: 46.5K
 * Testcase Example:  '[2,1,4,7,3,2,5]'
 *
 * Let's call any (contiguous) subarray B (of A) a mountain if the following
 * properties hold:
 *
 *
 * B.length >= 3
 * There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i-1] <
 * B[i] > B[i+1] > ... > B[B.length - 1]
 *
 *
 * (Note that B could be any subarray of A, including the entire array A.)
 *
 * Given an array A of integers, return the length of the longest mountain. 
 *
 * Return 0 if there is no mountain.
 *
 * Example 1:
 *
 *
 * Input: [2,1,4,7,3,2,5]
 * Output: 5
 * Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
 *
 *
 * Example 2:
 *
 *
 * Input: [2,2,2]
 * Output: 0
 * Explanation: There is no mountain.
 *
 *
 * Note:
 *
 *
 * 0 <= A.length <= 10000
 * 0 <= A[i] <= 10000
 *
 *
 * Follow up:
 *
 *
 * Can you solve it using only one pass?
 * Can you solve it in O(1) space?
 *
 *
 */

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestMountain(vector<int>& nums) {
    int grad = 0;
    int res = 0;

    int len = 0;

    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == nums[i - 1]) {
        if (grad == 0) {
          continue;
        } else if (grad == 1) {
          grad = 0;
          len = 0;
          continue;
        } else {
          res = max(res, len);
          grad = 0;
          len = 0;
        }
      } else if (nums[i] > nums[i - 1]) {
        if (grad == 0) {
          grad = 1;
          len = 2;
        } else if (grad == 1) {
          len++;
        } else {
          res = max(res, len);
          grad = 1;
          len = 2;
        }
      } else {
        if (grad == 0) {
          grad = -1;
        } else if (grad == 1) {
          grad = -1;
          len++;
        } else {
          if (len > 0) len++;
        }
      }
    }

    if (grad == -1) res = max(res, len);

    return res;
  }
};
