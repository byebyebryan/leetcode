/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (47.26%)
 * Total Accepted:    319K
 * Total Submissions: 673.5K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 *
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
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
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 *
 *
 */

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());

    return helper(candidates, target, candidates.size() - 1);
  }

  vector<vector<int>> helper(vector<int>& nums, int target, int idx) {
    vector<vector<int>> res;

    if (target < 0) return res;
    if (target == 0) {
      res.push_back(vector<int>());
      return res;
    }

    int n = nums[idx];
    int count = 0;

    if (idx == 0) {
      if (target % n == 0) {
        res.push_back(vector<int>(target / n, n));
        return res;
      } else {
        return res;
      }
    }

    while (target >= 0) {
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
