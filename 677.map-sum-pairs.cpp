/*
 * @lc app=leetcode id=677 lang=cpp
 *
 * [677] Map Sum Pairs
 *
 * https://leetcode.com/problems/map-sum-pairs/description/
 *
 * algorithms
 * Medium (51.24%)
 * Total Accepted:    24.3K
 * Total Submissions: 47.4K
 * Testcase Example:  '["MapSum", "insert", "sum", "insert", "sum"]\n[[],
 * ["apple",3], ["ap"], ["app",2], ["ap"]]'
 *
 *
 * Implement a MapSum class with insert, and sum methods.
 *
 *
 *
 * For the method insert, you'll be given a pair of (string, integer). The
 * string represents the key and the integer represents the value. If the key
 * already existed, then the original key-value pair will be overridden to the
 * new one.
 *
 *
 *
 * For the method sum, you'll be given a string representing the prefix, and
 * you need to return the sum of all the pairs' value whose key starts with the
 * prefix.
 *
 *
 * Example 1:
 *
 * Input: insert("apple", 3), Output: Null
 * Input: sum("ap"), Output: 3
 * Input: insert("app", 2), Output: Null
 * Input: sum("ap"), Output: 5
 *
 *
 *
 */

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class TrieNode {
 public:
  int val;
  vector<TrieNode*> next;

  TrieNode() : val(0), next(256, nullptr) {}
};

class MapSum {
  unordered_map<string, int> values;
  TrieNode* root;

 public:
  /** Initialize your data structure here. */
  MapSum() { root = new TrieNode(); }

  void insert(const string& key, int val) {
    if (values.find(key) != values.end()) {
      int t = val;
      val -= values[key];
      values[key] = t;
    } else {
      values[key] = val;
    }

    TrieNode* node = root;

    for (char c : key) {
      if (!node->next[c]) {
        node->next[c] = new TrieNode();
      }

      node = node->next[c];
      node->val += val;
    }
  }

  int sum(const string& prefix) {
    TrieNode* node = root;

    for (char c : prefix) {
      if (!node->next[c]) return 0;

      node = node->next[c];
    }

    return node->val;
  }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
