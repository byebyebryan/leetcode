/*
 * @lc app=leetcode id=421 lang=cpp
 *
 * [421] Maximum XOR of Two Numbers in an Array
 *
 * https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/
 *
 * algorithms
 * Medium (50.52%)
 * Total Accepted:    35.2K
 * Total Submissions: 69.5K
 * Testcase Example:  '[3,10,5,25,2,8]'
 *
 * Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai <
 * 231.
 *
 * Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
 *
 * Could you do this in O(n) runtime?
 *
 * Example:
 *
 *
 * Input: [3, 10, 5, 25, 2, 8]
 *
 * Output: 28
 *
 * Explanation: The maximum result is 5 ^ 25 = 28.
 *
 *
 *
 *
 */

#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode2 {
  TreeNode2* left = nullptr;
  TreeNode2* right = nullptr;
};

class Solution {
 public:
  unsigned findMaximumXOR(vector<int>& nums) {
    if (nums.size() == 1) return 0;

    unsigned n_max = 0;

    TreeNode2* root = new TreeNode2();

    unsigned left_most = 1u << 31;

    for (unsigned n : nums) {
      TreeNode2* node = root;
      for (int i = 0; i < 32; i++) {
        if (n & left_most) {
          if (!node->right) {
            node->right = new TreeNode2();
          }
          node = node->right;
        } else {
          if (!node->left) {
            node->left = new TreeNode2();
          }
          node = node->left;
        }
        n = n << 1;
      }
    }

    return findMax(root->left, root->right, 31);
  }

  unsigned findMax(TreeNode2* left, TreeNode2* right, unsigned idx,
                   bool skip = false) {
    unsigned res = 0;
    if (left && right) {
      if (!skip) res = 1u << idx;

      if (!left->left && !right->left) {
        return res | findMax(left->right, right->right, idx - 1, true);
      }
      if (!left->right && !right->right) {
        return res | findMax(left->left, right->left, idx - 1, true);
      }

      if (left->left && right->right && left->right && right->left)
        return max(res | findMax(left->left, right->right, idx - 1),
                   res | findMax(left->right, right->left, idx - 1));

      if (left->left && right->right)
        res |= findMax(left->left, right->right, idx - 1);
      if (left->right && right->left)
        res |= findMax(left->right, right->left, idx - 1);

      return res;
    }
    if (left) {
      res |= findMax(left->left, left->right, idx - 1);
    }
    if (right) {
      res |= findMax(right->left, right->right, idx - 1);
    }

    return res;
  }
};
