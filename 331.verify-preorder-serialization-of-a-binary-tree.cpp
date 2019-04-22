/*
 * @lc app=leetcode id=331 lang=cpp
 *
 * [331] Verify Preorder Serialization of a Binary Tree
 *
 * https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (38.31%)
 * Total Accepted:    56.9K
 * Total Submissions: 148.1K
 * Testcase Example:  '"9,3,4,#,#,1,#,#,2,#,6,#,#"'
 *
 * One way to serialize a binary tree is to use pre-order traversal. When we
 * encounter a non-null node, we record the node's value. If it is a null node,
 * we record using a sentinel value such as #.
 *
 *
 * ⁠    _9_
 * ⁠   /   \
 * ⁠  3     2
 * ⁠ / \   / \
 * ⁠4   1  #  6
 * / \ / \   / \
 * # # # #   # #
 *
 *
 * For example, the above binary tree can be serialized to the string
 * "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
 *
 * Given a string of comma separated values, verify whether it is a correct
 * preorder traversal serialization of a binary tree. Find an algorithm without
 * reconstructing the tree.
 *
 * Each comma separated value in the string must be either an integer or a
 * character '#' representing null pointer.
 *
 * You may assume that the input format is always valid, for example it could
 * never contain two consecutive commas such as "1,,3".
 *
 * Example 1:
 *
 *
 * Input: "9,3,4,#,#,1,#,#,2,#,6,#,#"
 * Output: true
 *
 * Example 2:
 *
 *
 * Input: "1,#"
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: "9,#,#,1"
 * Output: false
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isValidSerialization(string preorder) {
    int l = preorder.length();
    if (l == 0) return false;
    if (l == 1) return preorder[0] == '#';
    if (preorder[0] == '#') return false;
    if (l < 5) return false;
    if (preorder[l - 1] != '#') return false;

    vector<int> nodes;

    for (int i = 1; i < preorder.length(); i++) {
      if (preorder[i] != ',') continue;
      if (preorder[i - 1] == '#') {
        nodes.push_back(0);
      } else {
        nodes.push_back(1);
      }
    }
    nodes.push_back(0);

    if (nodes.size() < 3) return false;
    if (nodes.size() % 2 == 0) return false;

    int open = 1;
    for (int i = 0; i < nodes.size(); i++) {
      int n = nodes[i];
      open += n ? 1 : -1;
      if (open < 0) return false;
      if (open == 0 && i != nodes.size() - 1) return false;
    }

    return open == 0;
  }
};
