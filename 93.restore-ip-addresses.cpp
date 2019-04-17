/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (30.99%)
 * Total Accepted:    135.2K
 * Total Submissions: 434.5K
 * Testcase Example:  '"25525511135"'
 *
 * Given a string containing only digits, restore it by returning all possible
 * valid IP address combinations.
 *
 * Example:
 *
 *
 * Input: "25525511135"
 * Output: ["255.255.11.135", "255.255.111.35"]
 *
 *
 */

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> restoreIpAddresses(const string& s) {
    vector<string> res;
    if (s.length() == 4) {
      res.push_back(separate(s, {1, 2, 3}));
      return res;
    }

    vector<int> lens;
    fill(res, s, lens);

    return res;
  }

  void fill(vector<string>& res, const string& s, vector<int>& lens) {
    if (lens.size() == 3 && check(s.substr(lens[2]))) {
      res.push_back(separate(s, lens));
      return;
    }

    int start = 0;
    if (!lens.empty()) {
      start = lens[lens.size() - 1];
    }

    int r = s.length() - start;
    int r_seg = 3 - lens.size();

    for (int i = max(1, r - r_seg * 3); i <= min(3, r - r_seg); i++) {
      if (check(s.substr(start, i))) {
        lens.push_back(start + i);
        fill(res, s, lens);
        lens.pop_back();
      }
    }
  }

  bool check(const string& s) {
    int n = stoi(s);
    if (n >= 256) return false;
    if (n < 10 && s.length() != 1) return false;
    if (n < 100 && s.length() == 3) return false;
    return true;
  }

  string separate(const string& s, vector<int> lens) {
    string res = s.substr(0, lens[0]);
    res += '.';
    res += s.substr(lens[0], lens[1] - lens[0]);
    res += '.';
    res += s.substr(lens[1], lens[2] - lens[1]);
    res += '.';
    res += s.substr(lens[2]);
    return res;
  }
};
