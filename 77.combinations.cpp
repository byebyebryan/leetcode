/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (46.50%)
 * Total Accepted:    190.9K
 * Total Submissions: 410.3K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 *
 * Example:
 *
 *
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 *
 *
 */

#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> runner;

    assemble(res, runner, n, k);

    return res;
  }

  void assemble(vector<vector<int>>& res, vector<int>& runner, int n, int k) {
    if (runner.size() == k) {
      res.push_back(runner);
      return;
    }

    if (runner.empty()) {
      for (int i = 1; i <= n - k + 1; i++) {
        runner.push_back(i);
        assemble(res, runner, n, k);
        runner.pop_back();
      }
    } else {
      int m = runner[runner.size() - 1];
      int d = k - runner.size() - 1;
      for (int i = m + 1; i <= n - d; i++) {
        runner.push_back(i);
        assemble(res, runner, n, k);
        runner.pop_back();
      }
    }
  }
};
