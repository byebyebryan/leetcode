/*
 * @lc app=leetcode id=979 lang=cpp
 *
 * [979] Distribute Coins in Binary Tree
 *
 * https://leetcode.com/problems/distribute-coins-in-binary-tree/description/
 *
 * algorithms
 * Medium (66.06%)
 * Total Accepted:    10.3K
 * Total Submissions: 15.5K
 * Testcase Example:  '[3,0,0]'
 *
 * Given the root of a binary tree with N nodes, each node in the tree has
 * node.val coins, and there are N coins total.
 *
 * In one move, we may choose two adjacent nodes and move one coin from one
 * node to another.  (The move may be from parent to child, or from child to
 * parent.)
 *
 * Return the number of moves required to make every node have exactly one
 * coin.
 *
 *
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: [3,0,0]
 * Output: 2
 * Explanation: From the root of the tree, we move one coin to its left child,
 * and one coin to its right child.
 *
 *
 *
 * Example 2:
 *
 *
 *
 *
 * Input: [0,3,0]
 * Output: 3
 * Explanation: From the left child of the root, we move two coins to the root
 * [taking two moves].  Then, we move one coin from the root of the tree to the
 * right child.
 *
 *
 *
 * Example 3:
 *
 *
 *
 *
 * Input: [1,0,2]
 * Output: 2
 *
 *
 *
 * Example 4:
 *
 *
 *
 *
 * Input: [1,0,0,null,3]
 * Output: 4
 *
 *
 *
 *
 * Note:
 *
 *
 * 1<= N <= 100
 * 0 <= node.val <= N
 *
 *
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

#include <utility>

using namespace std;

class Solution {
 public:
  int distributeCoins(TreeNode* root) { return helper(root).first; }

  pair<int, int> helper(TreeNode* node) {
    if (!node) return make_pair(0, 0);

    auto l = helper(node->left);
    auto r = helper(node->right);

    int def_l = l.second;
    int def_r = r.second;

    int def = 1 - (node->val - def_l - def_r);

    int moves = l.first + r.first + abs(def);
    return make_pair(moves, def);
  }
};
