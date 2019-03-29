/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (23.31%)
 * Total Accepted:    240.3K
 * Total Submissions: 1M
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * the length of shortest transformation sequence from beginWord to endWord,
 * such that:
 *
 *
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 *
 *
 * Note:
 *
 *
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 *
 * Output: 5
 *
 * Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" ->
 * "dog" -> "cog",
 * return its length 5.
 *
 *
 * Example 2:
 *
 *
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 *
 * Output: 0
 *
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 *
 *
 *
 *
 *
 */

// hot dot dog lot log cog
//
// oth otd ogd otl ogl ogc
// tho tdo gdo tlo glo gco

// h o t
// d o t
//     g
// l o t
//     g
// c o g

// o t h
//     d
//     l
//   g d
//     l
//     c

// t h o
//   d o
//   l o
// g d o
//   l o
//   c o

#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int source = -1;
    int dest = -1;

    int m = wordList.size();

    for (int i = 0; i < m; i++) {
      if (wordList[i] == beginWord) {
        source = i;
      } else if (wordList[i] == endWord) {
        dest = i;
      }

      if (source > -1 && dest > -1) break;
    }
    if (dest == -1) return 0;

    if (getDist(beginWord, endWord) == 1) return 2;

    bool checked[m];
    for (int i = 0; i < m; i++) {
      checked[i] = false;
    }

    if (source > -1) checked[source] = true;

    queue<pair<int, int>> next;

    for (int i = 0; i < m; i++) {
      if (checked[i]) continue;

      if (getDist(beginWord, wordList[i]) == 1) {
        next.push(make_pair(i, 1));
        checked[i] = true;
      }
    }

    while (!next.empty()) {
      int x = next.front().first;
      int l = next.front().second;

      next.pop();

      if (x == dest) return l + 1;

      for (int i = 0; i < m; i++) {
        if (checked[i]) continue;

        if (getDist(wordList[x], wordList[i]) == 1) {
          next.push(make_pair(i, l + 1));
          checked[i] = true;
        }
      }
    }

    return 0;
  }

  int getDist(string& a, string& b) {
    int dist = 0;
    for (int i = 0; i < a.length(); i++) {
      if (a[i] != b[i]) {
        dist++;
        if (dist > 1) return dist;
      }
    }

    return dist;
  }
};
