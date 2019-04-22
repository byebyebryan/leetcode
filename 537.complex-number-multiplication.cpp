/*
 * @lc app=leetcode id=537 lang=cpp
 *
 * [537] Complex Number Multiplication
 *
 * https://leetcode.com/problems/complex-number-multiplication/description/
 *
 * algorithms
 * Medium (65.25%)
 * Total Accepted:    35.3K
 * Total Submissions: 54K
 * Testcase Example:  '"1+1i"\n"1+1i"'
 *
 *
 * Given two strings representing two complex numbers.
 *
 *
 * You need to return a string representing their multiplication. Note i2 = -1
 * according to the definition.
 *
 *
 * Example 1:
 *
 * Input: "1+1i", "1+1i"
 * Output: "0+2i"
 * Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert
 * it to the form of 0+2i.
 *
 *
 *
 * Example 2:
 *
 * Input: "1+-1i", "1+-1i"
 * Output: "0+-2i"
 * Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert
 * it to the form of 0+-2i.
 *
 *
 *
 * Note:
 *
 * The input strings will not have extra blank.
 * The input strings will be given in the form of a+bi, where the integer a and
 * b will both belong to the range of [-100, 100]. And the output should be
 * also in this form.
 *
 *
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string complexNumberMultiply(const string& a, const string& b) {
    int ar, ai, br, bi, yr, yi;
    parse(a, ar, ai);
    parse(b, br, bi);
    yr = ar * br - ai * bi;
    yi = ar * bi + ai * br;
    return to_string(yr) + "+" + to_string(yi) + "i";
  }

  void parse(const string& s, int& r, int& i) {
    int plus = s.find('+');
    r = stoi(s.substr(0, plus));
    i = stoi(s.substr(plus + 1, s.length() - plus - 2));
  }
};
