/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (32.55%)
 * Total Accepted:    132.1K
 * Total Submissions: 405.6K
 * Testcase Example:  '3\n3'
 *
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 *
 * By listing and labeling all of the permutations in order, we get the
 * following sequence for n = 3:
 *
 *
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 *
 *
 * Given n and k, return the kth permutation sequence.
 *
 * Note:
 *
 *
 * Given n will be between 1 and 9 inclusive.
 * Given k will be between 1 and n! inclusive.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3, k = 3
 * Output: "213"
 *
 *
 * Example 2:
 *
 *
 * Input: n = 4, k = 9
 * Output: "2314"
 *
 *
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string getPermutation(int n, int k) {
    string res(n, '0');

    int b = 1;
    for (int i = 2; i < n; i++) {
      b *= i;
    }

    vector<int> remained;
    for (int i = 1; i <= n; i++) {
      remained.push_back(i);
    }

    k--;

    while (remained.size() > 1) {
      int idx = k / b;
      int l = remained[idx];
      res[n - remained.size()] += remained[idx];
      remained.erase(remained.begin() + idx);
      k = k % b;
      b /= remained.size();
    }

    res[n - 1] += remained[0];

    return res;
  }
};
