/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (35.05%)
 * Total Accepted:    133.4K
 * Total Submissions: 378.6K
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1 ... n.
 *
 * Example:
 *
 *
 * Input: 3
 * Output:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 *
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 *
 *
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <vector>

using namespace std;

class Solution {
 public:
  vector<TreeNode*> generateTrees(int n) { return generateTrees(1, n); }

  vector<TreeNode*> generateTrees(int left, int right) {
    vector<TreeNode*> res;

    if (left > right) return res;
    if (left == right) {
      res.push_back(new TreeNode(left));
      return res;
    }

    for (int i = left; i <= right; i++) {
      vector<TreeNode*> lefts = generateTrees(left, i - 1);
      vector<TreeNode*> rights = generateTrees(i + 1, right);
      if (lefts.empty()) {
        for (auto r : rights) {
          TreeNode* root = new TreeNode(i);
          root->right = r;
          res.push_back(root);
        }
        continue;
      }
      if (rights.empty()) {
        for (auto l : lefts) {
          TreeNode* root = new TreeNode(i);
          root->left = l;
          res.push_back(root);
        }
        continue;
      }

      for (auto l : lefts) {
        for (auto r : rights) {
          TreeNode* root = new TreeNode(i);
          root->left = l;
          root->right = r;
          res.push_back(root);
        }
      }
    }

    return res;
  }
};
