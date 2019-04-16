/*
 * @lc app=leetcode id=988 lang=cpp
 *
 * [988] Smallest String Starting From Leaf
 *
 * https://leetcode.com/problems/smallest-string-starting-from-leaf/description/
 *
 * algorithms
 * Medium (49.74%)
 * Total Accepted:    8.3K
 * Total Submissions: 17.1K
 * Testcase Example:  '[0,1,2,3,4,3,4]'
 *
 * Given the root of a binary tree, each node has a value from 0 to 25
 * representing the letters 'a' to 'z': a value of 0 represents 'a', a value of
 * 1 represents 'b', and so on.
 * 
 * Find the lexicographically smallest string that starts at a leaf of this
 * tree and ends at the root.
 * 
 * (As a reminder, any shorter prefix of a string is lexicographically smaller:
 * for example, "ab" is lexicographically smaller than "aba".  A leaf of a node
 * is a node that has no children.)
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: [0,1,2,3,4,3,4]
 * Output: "dba"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: [25,1,3,1,3,0,2]
 * Output: "adz"
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: [2,2,1,null,1,0,null,0]
 * Output: "abc"
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of nodes in the given tree will be between 1 and 8500.
 * Each node in the tree will have a value between 0 and 25.
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

#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct TrieNode {
    bool end = false;
    vector<TrieNode*> next;
};

class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        vector<vector<int>> words;

        fill(root, vector<int>(), words);


    }

    void fill(TreeNode* node, vector<int> word, vector<vector<int>>& words){
        if(!node) return;

        word.push_back(node->val);

        if(!node->left && !node->right) {
            vector<int> r(word.size());
            for(int i=0; i<word.size();i++){
                r[word.size()-1-i] = word[i];
            }
            words.push_back(r);
            return;
        }

        if(node->left) {
            fill(node->left, word, words);
        }
        if(node->right) {
            fill(node->right, word, words);
        }
    }
};
