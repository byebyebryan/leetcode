/*
 * @lc app=leetcode id=954 lang=cpp
 *
 * [954] Array of Doubled Pairs
 *
 * https://leetcode.com/problems/array-of-doubled-pairs/description/
 *
 * algorithms
 * Medium (34.22%)
 * Total Accepted:    7.7K
 * Total Submissions: 22.5K
 * Testcase Example:  '[3,1,3,6]'
 *
 * Given an array of integers A with even length, return true if and only if it
 * is possible to reorder it such that A[2 * i + 1] = 2 * A[2 * i] for every 0
 * <= i < len(A) / 2.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [3,1,3,6]
 * Output: false
 *
 *
 *
 * Example 2:
 *
 *
 * Input: [2,1,2,6]
 * Output: false
 *
 *
 *
 * Example 3:
 *
 *
 * Input: [4,-2,2,-4]
 * Output: true
 * Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4]
 * or [2,4,-2,-4].
 *
 *
 *
 * Example 4:
 *
 *
 * Input: [1,2,4,16,8,4]
 * Output: false
 *
 *
 *
 *
 * Note:
 *
 *
 * 0 <= A.length <= 30000
 * A.length is even
 * -100000 <= A[i] <= 100000
 *
 *
 *
 *
 *
 *
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  struct AbsCmp {
    bool operator()(const int& a, const int& b) const {
      if (abs(a) == abs(b)) {
        return a < b;
      }
      return abs(a) < abs(b);
    }
  };

 public:
  bool canReorderDoubled(vector<int>& nums) {
    unordered_map<int, int> odd_counts;
    map<int, int, AbsCmp> counts;

    for (int n : nums) {
      if (n % 2 != 0) {
        odd_counts[n]++;
      } else {
        counts[n]++;
      }
    }

    if (counts.find(0) != counts.end()) {
      if (counts[0] % 2 != 0) return false;
      counts.erase(0);
    }

    for (auto it : odd_counts) {
      int n = it.first;
      int c = it.second;

      if (counts.find(n * 2) == counts.end()) return false;
      if (counts[n * 2] < c) return false;
      counts[n * 2] -= c;
      if (counts[n * 2] == 0) counts.erase(n * 2);
    }

    if (counts.empty()) return true;

    while (!counts.empty()) {
      int n = counts.begin()->first;
      int c = counts.begin()->second;

      if (counts.find(n * 2) == counts.end()) return false;
      if (counts[n * 2] < c) return false;
      counts.erase(n);
      counts[n * 2] -= c;
      if (counts[n * 2] == 0) counts.erase(n * 2);
    }

    return counts.empty();
  }
};
