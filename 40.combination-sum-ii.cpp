/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (40.72%)
 * Total Accepted:    213K
 * Total Submissions: 519.2K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 *
 * Each number in candidates may only be used once in the combination.
 *
 * Note:
 *
 *
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 *
 *
 * Example 1:
 *
 *
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 *
 *
 */

#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    map<int, int> counts;

    for (int n : candidates) {
      counts[n]++;
    }

    vector<pair<int, int>> nums;
    for (auto it : counts) {
      nums.push_back(make_pair(it.first, it.second));
    }

    return helper(nums, target, nums.size() - 1);
  }

  vector<vector<int>> helper(vector<pair<int, int>>& nums, int target,
                             int idx) {
    vector<vector<int>> res;

    if (target < 0) return res;
    if (target == 0) {
      res.push_back(vector<int>());
      return res;
    }

    int n = nums[idx].first;
    int m = nums[idx].second;
    int count = 0;

    if (idx == 0) {
      if (target % n == 0 && target / n <= m) {
        res.push_back(vector<int>(target / n, n));
        return res;
      } else {
        return res;
      }
    }

    while (target >= 0 && count <= m) {
      auto r = helper(nums, target, idx - 1);
      if (!r.empty()) {
        for (int i = 0; i < r.size(); i++) {
          for (int j = 0; j < count; j++) {
            r[i].push_back(n);
          }
          res.push_back(r[i]);
        }
      }
      target -= n;
      count++;
    }

    return res;
  }
};
