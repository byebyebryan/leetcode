/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (47.14%)
 * Total Accepted:    159.8K
 * Total Submissions: 337.9K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 *
 * Example:
 *
 *
 * Input: [1,2,3,null,5,null,4]
 * Output: [1, 3, 4]
 * Explanation:
 *
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
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

#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> res;

    if (!root) return res;

    queue<pair<TreeNode*, int>> next;

    next.push(make_pair(root, 0));

    while (!next.empty()) {
      TreeNode* node = next.front().first;
      int idx = next.front().second;

      next.pop();
      if (idx == res.size()) {
        res.push_back(node->val);
      }
      if (node->right) next.push(make_pair(node->right, idx + 1));
      if (node->left) next.push(make_pair(node->left, idx + 1));
    }

    return res;
  }
};
