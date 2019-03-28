/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (39.80%)
 * Total Accepted:    219K
 * Total Submissions: 550.1K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given the below binary tree and sum = 22,
 * 
 * 
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \    / \
 * 7    2  5   1
 * 
 * 
 * Return:
 * 
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;

        vector<int> runner;

        dig(root, 0, sum, res, runner);

        return res;
    }

    void dig(TreeNode* node, int sum, int target, vector<vector<int>>& res, vector<int>& runner) {
        if(!node) return;

        sum += node->val;

        runner.push_back(node->val);    
        
        if(sum == target && !node->left && !node->right) {
            res.push_back(runner);
            runner.pop_back();
            return;
        }

        if(node->left) {
            dig(node->left, sum, target, res, runner);
        }

        if(node->right) {
            dig(node->right, sum, target, res, runner);
        }

        runner.pop_back();
    }
};
