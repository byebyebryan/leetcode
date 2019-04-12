/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (50.60%)
 * Total Accepted:    322K
 * Total Submissions: 633.6K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 *
 * Example:
 *
 *
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 *
 * Output: [1,2,3]
 *
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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

#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;

    stack<TreeNode*> next;
    next.push(root);

    while (!next.empty()) {
      TreeNode* node = next.top();
      next.pop();

      if (node)
        res.push_back(node->val);
      else
        continue;

      if (node->right) next.push(node->right);
      if (node->left) next.push(node->left);
    }

    return res;
  }
};
