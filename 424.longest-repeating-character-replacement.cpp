/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 *
 * https://leetcode.com/problems/longest-repeating-character-replacement/description/
 *
 * algorithms
 * Medium (43.86%)
 * Total Accepted:    29K
 * Total Submissions: 66K
 * Testcase Example:  '"ABAB"\n2'
 *
 * Given a string that consists of only uppercase English letters, you can
 * replace any letter in the string with another letter at most k times. Find
 * the length of a longest substring containing all repeating letters you can
 * get after performing the above operations.
 *
 * Note:
 * Both the string's length and k will not exceed 104.
 *
 *
 *
 * Example 1:
 *
 * Input:
 * s = "ABAB", k = 2
 *
 * Output:
 * 4
 *
 * Explanation:
 * Replace the two 'A's with two 'B's or vice versa.
 *
 *
 *
 *
 * Example 2:
 *
 * Input:
 * s = "AABABBA", k = 1
 *
 * Output:
 * 4
 *
 * Explanation:
 * Replace the one 'A' in the middle with 'B' and form "AABBBBA".
 * The substring "BBBB" has the longest repeating letters, which is 4.
 *
 *
 */

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int characterReplacement(const string& s, int k) {
    int res = 0;

    vector<vector<pair<int, int>>> range(26);
    vector<int> count(26, 0);

    for (int i = 0; i < s.length(); i++) {
      int c = s[i] - 'A';

      int j = i + 1;
      while (j < s.length()) {
        if (s[j] == s[i]) {
          j++;
        } else {
          break;
        }
      }
      j--;
      range[c].push_back(make_pair(i, j));
      count[c] += j - i + 1;
      i = j;
    }

    for (int c = 0; c < 26; c++) {
      if (!range[c].size()) continue;
      if (range[c].size() == 1) {
        int l = range[c][0].second - range[c][0].first + 1;
        if (l + k >= s.length()) return s.length();
        res = max(res, l + k);
        continue;
      }
      if (count[c] + k >= s.length()) return s.length();

      for (int i = 0; i < range[c].size(); i++) {
        int start = range[c][i].first;
        int end = range[c][i].second;
        int r = k;
        int j = i + 1;
        while (j < range[c].size() && r > 0) {
          if (end + r + 1 >= range[c][j].first) {
            r -= range[c][j].first - end - 1;
            end = range[c][j].second;
            j++;
          } else {
            break;
          }
        }
        res = max(res, end - start + 1 + r);
      }
    }

    return res;
  }
};
