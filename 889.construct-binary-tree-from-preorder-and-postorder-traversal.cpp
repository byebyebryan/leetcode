/*
 * @lc app=leetcode id=889 lang=cpp
 *
 * [889] Construct Binary Tree from Preorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (58.93%)
 * Total Accepted:    13.3K
 * Total Submissions: 22.6K
 * Testcase Example:  '[1,2,4,5,3,6,7]\n[4,5,2,6,7,3,1]'
 *
 * Return any binary tree that matches the given preorder and postorder
 * traversals.
 *
 * Values in the traversals pre and post are distinct positive integers.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
 * Output: [1,2,3,4,5,6,7]
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= pre.length == post.length <= 30
 * pre[] and post[] are both permutations of 1, 2, ..., pre.length.
 * It is guaranteed an answer exists. If there exists multiple answers, you can
 * return any of them.
 *
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

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    int pre_l = 0;
    int pre_r = pre.size() - 1;
    int post_l = 0;
    int post_r = pre.size() - 1;
    unordered_map<int, int> pre_finder;
    unordered_map<int, int> post_finder;

    for (int i = 0; i < pre.size(); i++) {
      pre_finder[pre[i]] = i;
      post_finder[post[i]] = i;
    }

    return constructFromPrePost(pre, post, pre_l, pre_r, post_l, post_r,
                                pre_finder, post_finder);
  }

  TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post, int pre_l,
                                 int pre_r, int post_l, int post_r,
                                 unordered_map<int, int>& pre_finder,
                                 unordered_map<int, int>& post_finder) {
    if (pre_l == pre_r) return new TreeNode(pre[pre_l]);

    TreeNode* node = new TreeNode(pre[pre_l]);

    if (pre_l == pre_r - 1) {
      node->left = new TreeNode(pre[pre_r]);
      return node;
    }

    int l = pre[pre_l + 1];
    int r = post[post_r - 1];

    if (l == r) {
      node->left = constructFromPrePost(pre, post, pre_l + 1, pre_r, post_l,
                                        post_r - 1, pre_finder, post_finder);
      return node;
    }

    node->left =
        constructFromPrePost(pre, post, pre_l + 1, pre_finder[r] - 1, post_l,
                             post_finder[l], pre_finder, post_finder);
    node->right = constructFromPrePost(pre, post, pre_finder[r], pre_r,
                                       post_finder[l] + 1, post_r - 1,
                                       pre_finder, post_finder);
    return node;
  }
};
