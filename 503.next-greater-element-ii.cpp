/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 *
 * https://leetcode.com/problems/next-greater-element-ii/description/
 *
 * algorithms
 * Medium (50.32%)
 * Total Accepted:    46.6K
 * Total Submissions: 92.4K
 * Testcase Example:  '[1,2,1]'
 *
 *
 * Given a circular array (the next element of the last element is the first
 * element of the array), print the Next Greater Number for every element. The
 * Next Greater Number of a number x is the first greater number to its
 * traversing-order next in the array, which means you could search circularly
 * to find its next greater number. If it doesn't exist, output -1 for this
 * number.
 *
 *
 * Example 1:
 *
 * Input: [1,2,1]
 * Output: [2,-1,2]
 * Explanation: The first 1's next greater number is 2; The number 2 can't find
 * next greater number; The second 1's next greater number needs to search
 * circularly, which is also 2.
 *
 *
 *
 * Note:
 * The length of given array won't exceed 10000.
 *
 */

#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return vector<int>();
    vector<int> res(n, -1);
    if (n == 1) return res;

    stack<int> monotone_decrease;
    for (int i = 0; i < 2 * n; i++) {
      while (!monotone_decrease.empty() &&
             nums[monotone_decrease.top()] < nums[i % n]) {
        res[monotone_decrease.top()] = nums[i % n];
        monotone_decrease.pop();
      }
      monotone_decrease.push(i % n);
    }

    return res;
  }
};
