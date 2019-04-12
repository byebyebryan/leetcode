/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 *
 * https://leetcode.com/problems/01-matrix/description/
 *
 * algorithms
 * Medium (34.91%)
 * Total Accepted:    39.7K
 * Total Submissions: 113.1K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * Given a matrix consists of 0 and 1, find the distance of the nearest 0 for
 * each cell.
 *
 * The distance between two adjacent cells is 1.
 *
 *
 *
 * Example 1:
 *
 *
 * Input:
 * [[0,0,0],
 * ⁠[0,1,0],
 * ⁠[0,0,0]]
 *
 * Output:
 * [[0,0,0],
 * [0,1,0],
 * [0,0,0]]
 *
 *
 * Example 2:
 *
 *
 * Input:
 * [[0,0,0],
 * ⁠[0,1,0],
 * ⁠[1,1,1]]
 *
 * Output:
 * [[0,0,0],
 * ⁠[0,1,0],
 * ⁠[1,2,1]]
 *
 *
 *
 *
 * Note:
 *
 *
 * The number of elements of the given matrix will not exceed 10,000.
 * There are at least one 0 in the given matrix.
 * The cells are adjacent in only four directions: up, down, left and right.
 *
 *
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> dist(m, vector<int>(n, -1));

    unordered_set<int> ping;
    unordered_set<int> pong;
    bool flip = false;

    for (int y = 0; y < m; y++) {
      for (int x = 0; x < n; x++) {
        if (matrix[y][x] == 0) {
          ping.insert(y * 10000 + x);
          dist[y][x] = 0;
        }
      }
    }

    int d = 1;

    while (true) {
      unordered_set<int>& from = flip ? pong : ping;
      unordered_set<int>& to = flip ? ping : pong;

      to.clear();

      for (auto it : from) {
        int y = it / 10000;
        int x = it % 10000;

        if (y - 1 >= 0) {
          if (dist[y - 1][x] < 0) {
            to.insert((y - 1) * 10000 + x);
          }
        }
        if (y + 1 < m) {
          if (dist[y + 1][x] < 0) {
            to.insert((y + 1) * 10000 + x);
          }
        }
        if (x - 1 >= 0) {
          if (dist[y][x - 1] < 0) {
            to.insert(y * 10000 + x - 1);
          }
        }
        if (x + 1 < n) {
          if (dist[y][x + 1] < 0) {
            to.insert(y * 10000 + x + 1);
          }
        }
      }

      if (to.empty()) break;

      for (auto it : to) {
        int y = it / 10000;
        int x = it % 10000;

        dist[y][x] = d;
      }

      d++;
      flip = !flip;
    }

    return dist;
  }
};
