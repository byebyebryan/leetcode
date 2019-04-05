/*
 * @lc app=leetcode id=856 lang=cpp
 *
 * [856] Score of Parentheses
 *
 * https://leetcode.com/problems/score-of-parentheses/description/
 *
 * algorithms
 * Medium (55.50%)
 * Total Accepted:    16.1K
 * Total Submissions: 29K
 * Testcase Example:  '"()"'
 *
 * Given a balanced parentheses string S, compute the score of the string based
 * on the following rule:
 *
 *
 * () has score 1
 * AB has score A + B, where A and B are balanced parentheses strings.
 * (A) has score 2 * A, where A is a balanced parentheses string.
 *
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: "()"
 * Output: 1
 *
 *
 *
 * Example 2:
 *
 *
 * Input: "(())"
 * Output: 2
 *
 *
 *
 * Example 3:
 *
 *
 * Input: "()()"
 * Output: 2
 *
 *
 *
 * Example 4:
 *
 *
 * Input: "(()(()))"
 * Output: 6
 *
 *
 *
 *
 * Note:
 *
 *
 * S is a balanced parentheses string, containing only ( and ).
 * 2 <= S.length <= 50
 *
 *
 *
 *
 *
 *
 */

#include <string>

using namespace std;

class Solution {
 public:
  int scoreOfParentheses(string s) {
    if (s == "()") return 1;

    int r = 1;
    int i = 1;
    for (; i < s.length(); i++) {
      r += s[i] == ')' ? -1 : 1;
      if (r == 0) break;
    }
    if (i == s.length() - 1) {
      return 2 * scoreOfParentheses(s.substr(1, s.length() - 2));
    }
    return scoreOfParentheses(s.substr(0, i + 1)) +
           scoreOfParentheses(s.substr(i + 1, s.length() - i - 1));
  }
};
