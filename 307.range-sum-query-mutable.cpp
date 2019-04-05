/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 *
 * https://leetcode.com/problems/range-sum-query-mutable/description/
 *
 * algorithms
 * Medium (27.95%)
 * Total Accepted:    68K
 * Total Submissions: 243.4K
 * Testcase Example:
 * '["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 *
 * The update(i, val) function modifies nums by updating the element at index i
 * to val.
 *
 * Example:
 *
 *
 * Given nums = [1, 3, 5]
 *
 * sumRange(0, 2) -> 9
 * update(1, 2)
 * sumRange(0, 2) -> 8
 *
 *
 * Note:
 *
 *
 * The array is only modifiable by the update function.
 * You may assume the number of calls to update and sumRange function is
 * distributed evenly.
 *
 *
 */

#include <vector>

using namespace std;

class NumArray {
  vector<int> sums;

 public:
  NumArray(const vector<int>& nums) : sums(vector<int>(nums.size())) {
    if (nums.empty()) return;
    sums[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      sums[i] = sums[i - 1] + nums[i];
    }
  }

  void update(int i, int val) {
    int n = i == 0 ? sums[i] : sums[i] - sums[i - 1];

    for (; i < sums.size(); i++) {
      sums[i] += val - n;
    }
  }

  int sumRange(int i, int j) {
    if (i == 0) return sums[j];
    return sums[j] - sums[i - 1];
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
