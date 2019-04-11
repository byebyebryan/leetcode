/*
 * @lc app=leetcode id=848 lang=cpp
 *
 * [848] Shifting Letters
 *
 * https://leetcode.com/problems/shifting-letters/description/
 *
 * algorithms
 * Medium (39.93%)
 * Total Accepted:    11.7K
 * Total Submissions: 29.1K
 * Testcase Example:  '"abc"\n[3,5,9]'
 *
 * We have a string S of lowercase letters, and an integer array shifts.
 *
 * Call the shift of a letter, the next letter in the alphabet, (wrapping
 * around so that 'z' becomes 'a'). 
 *
 * For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
 *
 * Now for each shifts[i] = x, we want to shift the first i+1 letters of S, x
 * times.
 *
 * Return the final string after all such shifts to S are applied.
 *
 * Example 1:
 *
 *
 * Input: S = "abc", shifts = [3,5,9]
 * Output: "rpl"
 * Explanation:
 * We start with "abc".
 * After shifting the first 1 letters of S by 3, we have "dbc".
 * After shifting the first 2 letters of S by 5, we have "igc".
 * After shifting the first 3 letters of S by 9, we have "rpl", the answer.
 *
 *
 * Note:
 *
 *
 * 1 <= S.length = shifts.length <= 20000
 * 0 <= shifts[i] <= 10 ^ 9
 *
 *
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string shiftingLetters(string s, vector<int>& shifts) {
    for (int i = 0; i < shifts.size(); i++) {
      shifts[i] %= 26;
    }

    for (int i = shifts.size() - 2; i >= 0; i--) {
      shifts[i] += shifts[i + 1];
    }

    for (int i = 0; i < shifts.size(); i++) {
      int c = s[i] - 'a';
      c = (c + shifts[i]) % 26;
      s[i] = 'a' + c;
    }

    return s;
  }
};
