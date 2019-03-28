/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (23.63%)
 * Total Accepted:    506.4K
 * Total Submissions: 2.1M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 *
 * Note:
 *
 * The solution set must not contain duplicate triplets.
 *
 * Example:
 *
 *
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 *
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 *
 *
 */


#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;

    if(nums.size() < 3) return res;

    unordered_map<int, int> counts;

    vector<int> unique;
    unordered_map<int, int> pos;

    for (int i = 0; i < nums.size(); i++) {
      int x = nums[i];
      counts[x]++;
      if (counts[x] == 1) {
        unique.push_back(x);
        pos[x] = unique.size() - 1;
      }
    }

    for (int i = 0; i < unique.size(); i++) {
      int a = unique[i];
      if (a == 0) {
        if(counts[a] >= 3) res.push_back({0, 0, 0});
      } else if (counts[a] >= 2 && counts.find(-a * 2) != counts.end()) {
        res.push_back({a, a, -a * 2});
      }

      for (int j = i + 1; j < unique.size(); j++) {
        int b = unique[j];
        int c = -a - b;

        if (a == c || b == c) continue;

        if (counts.find(c) != counts.end() && pos[c] > j) {
          res.push_back({a, b, c});
        }
      }
    }

    return res;
  }
};
