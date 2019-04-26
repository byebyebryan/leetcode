/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 *
 * https://leetcode.com/problems/network-delay-time/description/
 *
 * algorithms
 * Medium (40.81%)
 * Total Accepted:    30.4K
 * Total Submissions: 73.6K
 * Testcase Example:  '[[2,1,1],[2,3,1],[3,4,1]]\n4\n2'
 *
 * There are N network nodes, labelled 1 to N.
 *
 * Given times, a list of travel times as directed edges times[i] = (u, v, w),
 * where u is the source node, v is the target node, and w is the time it takes
 * for a signal to travel from source to target.
 *
 * Now, we send a signal from a certain node K. How long will it take for all
 * nodes to receive the signal? If it is impossible, return -1.
 *
 * Note:
 *
 *
 * N will be in the range [1, 100].
 * K will be in the range [1, N].
 * The length of times will be in the range [1, 6000].
 * All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <=
 * 100.
 *
 *
 *
 *
 */

#include <functional>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    unordered_map<int, unordered_map<int, int>> edges;

    for (auto t : times) {
      edges[t[0]][t[1]] = t[2];
    }

    unordered_set<int> visited;

    auto cmp = [](pair<int, int> left, pair<int, int> right) {
      return left.first > right.first;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> next(
        cmp);
    next.push(make_pair(0, K));

    while (!next.empty()) {
      int t = next.top().first;
      int n = next.top().second;
      next.pop();

      if (visited.find(n) != visited.end()) continue;

      visited.insert(n);
      if (visited.size() == N) return t;

      for (auto it : edges[n]) {
        next.push(make_pair(it.second + t, it.first));
      }
    }

    return -1;
  }
};
