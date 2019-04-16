/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 *
 * https://leetcode.com/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (47.10%)
 * Total Accepted:    74.9K
 * Total Submissions: 158.4K
 * Testcase Example:  '[ ["a","b"],["b","c"] ]\n[2.0,3.0]\n[
 * ["a","c"],["b","c"],["a","e"],["a","a"],["x","x"] ]'
 *
 *
 * Equations are given in the format A / B = k, where  A and B are variables
 * represented as strings, and k is a real number (floating point number).
 * Given some queries, return the answers. If the answer does not exist, return
 * -1.0.
 *
 * Example:
 * Given  a / b = 2.0, b / c = 3.0. queries are:  a / c = ?,  b / a = ?, a / e
 * = ?,  a / a = ?, x / x = ? . return  [6.0, 0.5, -1.0, 1.0, -1.0 ].
 *
 *
 * The input is:  vector<pair<string, string>> equations, vector<double>&
 * values, vector<pair<string, string>> queries , where equations.size() ==
 * values.size(), and the values are positive. This represents the equations.
 * Return  vector<double>.
 *
 *
 * According to the example above:
 * equations = [ ["a", "b"], ["b", "c"] ],
 * values = [2.0, 3.0],
 * queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]
 * ].
 *
 *
 *
 * The input is always valid. You may assume that evaluating the queries will
 * result in no division by zero and there is no contradiction.
 *
 */

#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<double> calcEquation(vector<pair<string, string>>& equations,
                              vector<double>& values,
                              vector<pair<string, string>>& queries) {
    unordered_map<string, unordered_map<string, double>> graph;

    for (int i = 0; i < equations.size(); i++) {
      graph[equations[i].first][equations[i].second] = values[i];
      graph[equations[i].second][equations[i].first] = 1.0 / values[i];
    }

    vector<double> res;

    for (auto q : queries) {
      res.push_back(calc(graph, q.first, q.second));
    }

    return res;
  }

  double calc(unordered_map<string, unordered_map<string, double>>& graph,
              const string& from, const string& to) {
    if (from == to && graph.find(from) != graph.end()) return 1.0;

    unordered_set<string> visited;

    queue<pair<string, double>> next;

    visited.insert(from);

    for (auto it : graph[from]) {
      next.push(make_pair(it.first, it.second));
    }

    while (!next.empty()) {
      string x = next.front().first;
      double val = next.front().second;
      next.pop();

      if (visited.find(x) != visited.end()) continue;
      if (x == to) return val;

      visited.insert(x);

      for (auto it : graph[x]) {
        next.push(make_pair(it.first, val * it.second));
      }

      if (graph[from].find(x) == graph[from].end()) {
        graph[from][x] = val;
        graph[x][from] = 1.0 / val;
      }
    }

    return -1.0;
  }
};
