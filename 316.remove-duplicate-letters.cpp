/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 *
 * https://leetcode.com/problems/remove-duplicate-letters/description/
 *
 * algorithms
 * Hard (32.07%)
 * Total Accepted:    54.9K
 * Total Submissions: 170.4K
 * Testcase Example:  '"bcabc"'
 *
 * Given a string which contains only lowercase letters, remove duplicate
 * letters so that every letter appear once and only once. You must make sure
 * your result is the smallest in lexicographical order among all possible
 * results.
 *
 * Example 1:
 *
 *
 * Input: "bcabc"
 * Output: "abc"
 *
 *
 * Example 2:
 *
 *
 * Input: "cbacdcbc"
 * Output: "acdb"
 *
 */

#include <algorithm>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string removeDuplicateLetters(string s) {
    if (s.length() == 0) return "";
    if (s.length() == 1) return s;

    vector<int> count(26, 0);
    for (char c : s) {
      count[c - 'a']++;
    }

    vector<bool> added(26, false);
    stack<char> x;

    for (char c : s) {
      int i = c - 'a';
      count[i]--;
      if (added[i]) continue;
      while (!x.empty() && x.top() > i && count[x.top()] > 0) {
        added[x.top()] = false;
        x.pop();
      }
      x.push(i);
      added[i] = true;
    }

    string res = "";
    while (!x.empty()) {
      char c = 'a' + x.top();
      res = c + res;
      x.pop();
    }

    return res;
  }
};
