/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 *
 * https://leetcode.com/problems/possible-bipartition/description/
 *
 * algorithms
 * Medium (40.30%)
 * Total Accepted:    11.8K
 * Total Submissions: 29.3K
 * Testcase Example:  '4\n[[1,2],[1,3],[2,4]]'
 *
 * Given a set of N people (numbered 1, 2, ..., N), we would like to split
 * everyone into two groups of any size.
 *
 * Each person may dislike some other people, and they should not go into the
 * same group. 
 *
 * Formally, if dislikes[i] = [a, b], it means it is not allowed to put the
 * people numbered a and b into the same group.
 *
 * Return true if and only if it is possible to split everyone into two groups
 * in this way.
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
 * Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
 * Output: true
 * Explanation: group1 [1,4], group2 [2,3]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
 * Output: false
 *
 *
 *
 * Example 3:
 *
 *
 * Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
 * Output: false
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= N <= 2000
 * 0 <= dislikes.length <= 10000
 * 1 <= dislikes[i][j] <= N
 * dislikes[i][0] < dislikes[i][1]
 * There does not exist i != j for which dislikes[i] == dislikes[j].
 *
 *
 *
 *
 *
 */

#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
    vector<unordered_set<int>> dis(N);
    vector<int> groups(N);

    for (int i = 0; i < dislikes.size(); i++) {
      int a = dislikes[i][0] - 1;
      int b = dislikes[i][1] - 1;

      dis[a].insert(b);
      dis[b].insert(a);
    }

    queue<pair<int, int>> next;

    for (int i = 0; i < N; i++) {
      if (groups[i] != 0) continue;

      next.push(make_pair(i, 1));

      while (!next.empty()) {
        int j = next.front().first;
        int g = next.front().second;

        next.pop();

        if (groups[j] == 0) {
          groups[j] = g;
          for (int x : dis[j]) {
            next.push(make_pair(x, -g));
          }
        } else {
          if (groups[j] != g) {
            return false;
          }
        }
      }
    }

    return true;
  }
};
