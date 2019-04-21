/*
 * @lc app=leetcode id=524 lang=cpp
 *
 * [524] Longest Word in Dictionary through Deleting
 *
 * https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/
 *
 * algorithms
 * Medium (45.30%)
 * Total Accepted:    41.2K
 * Total Submissions: 90.7K
 * Testcase Example:  '"abpcplea"\n["ale","apple","monkey","plea"]'
 *
 *
 * Given a string and a string dictionary, find the longest string in the
 * dictionary that can be formed by deleting some characters of the given
 * string. If there are more than one possible results, return the longest word
 * with the smallest lexicographical order. If there is no possible result,
 * return the empty string.
 *
 * Example 1:
 *
 * Input:
 * s = "abpcplea", d = ["ale","apple","monkey","plea"]
 *
 * Output:
 * "apple"
 *
 *
 *
 *
 * Example 2:
 *
 * Input:
 * s = "abpcplea", d = ["a","b","c"]
 *
 * Output:
 * "a"
 *
 *
 *
 * Note:
 *
 * All the strings in the input will only contain lower-case letters.
 * The size of the dictionary won't exceed 1,000.
 * The length of all the strings in the input won't exceed 1,000.
 *
 *
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Trie {
  int next_count = 0;
  vector<Trie*> next = vector<Trie*>(256, nullptr);
};

class Solution {
 public:
  string findLongestWord(string s, vector<string>& d) {
    int l = s.length();
    if (l == 0) return "";
    if (d.size() == 0) return "";

    vector<vector<int>> finder(l, vector<int>(26, -1));
    vector<int> letter_count(26, 0);

    for (char c : s) {
      letter_count[c - 'a']++;
    }

    finder[l - 1][s[l - 1] - 'a'] = l - 1;
    for (int i = l - 2; i >= 0; i--) {
      vector<int> post = finder[i + 1];
      post[s[i] - 'a'] = i;
      finder[i] = post;
    }

    sort(d.begin(), d.end(), [](string& a, string& b) {
      if (a.length() > b.length()) return true;
      if (a.length() < b.length()) return false;
      return a < b;
    });

    for (string& str : d) {
      if (str.length() > s.length()) continue;

      vector<int> letter_count_d(26, 0);
      bool skip = false;
      for (char c : str) {
        int i = c - 'a';
        letter_count_d[i]++;
        if (letter_count_d[i] > letter_count[i]) {
          skip = true;
          break;
        }
      }
      if (skip) continue;

      int p = 0;
      for (int i = 0; i < str.length(); i++) {
        int c = str[i] - 'a';
        if (p >= l) {
          skip = true;
          break;
        }
        if (finder[p][c] < 0) {
          skip = true;
          break;
        }
        p = finder[p][c] + 1;
      }

      if (!skip) return str;
    }

    return "";
  }
};
