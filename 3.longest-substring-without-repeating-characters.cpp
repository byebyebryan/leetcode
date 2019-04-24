/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.10%)
 * Total Accepted:    877.4K
 * Total Submissions: 3.1M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 *
 *
 * Example 1:
 *
 *
 * Input: "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 *
 *
 * Example 3:
 *
 *
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 *
 *
 *
 *
 */

#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int n = s.length();
    if (n <= 1) return n;

    int res = 0;
    unordered_map<char, int> last_idx;
    int start = 0;
    int end = 0;
    last_idx[s[0]] = 0;

    for (int i = 1; i < n; i++) {
      if (last_idx.find(s[i]) != last_idx.end()) {
        int idx = last_idx[s[i]];
        if (idx >= start) {
          start = idx + 1;
        }
      }
      last_idx[s[i]] = i;
      end = i;
      res = max(res, end - start + 1);
    }

    return res;
  }
};
