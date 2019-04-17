/*
 * @lc app=leetcode id=769 lang=cpp
 *
 * [769] Max Chunks To Make Sorted
 *
 * https://leetcode.com/problems/max-chunks-to-make-sorted/description/
 *
 * algorithms
 * Medium (51.15%)
 * Total Accepted:    21.7K
 * Total Submissions: 42.2K
 * Testcase Example:  '[4,3,2,1,0]'
 *
 * Given an array arr that is a permutation of [0, 1, ..., arr.length - 1], we
 * split the array into some number of "chunks" (partitions), and individually
 * sort each chunk.  After concatenating them, the result equals the sorted
 * array.
 *
 * What is the most number of chunks we could have made?
 *
 * Example 1:
 *
 *
 * Input: arr = [4,3,2,1,0]
 * Output: 1
 * Explanation:
 * Splitting into two or more chunks will not return the required result.
 * For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1,
 * 2], which isn't sorted.
 *
 *
 * Example 2:
 *
 *
 * Input: arr = [1,0,2,3,4]
 * Output: 4
 * Explanation:
 * We can split into two chunks, such as [1, 0], [2, 3, 4].
 * However, splitting into [1, 0], [2], [3], [4] is the highest number of
 * chunks possible.
 *
 *
 * Note:
 *
 *
 * arr will have length in range [1, 10].
 * arr[i] will be a permutation of [0, 1, ..., arr.length - 1].
 *
 *
 *
 *
 */

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxChunksToSorted(vector<int>& arr, int start = 0) {
    if (arr.size() == 1) return 1;

    if (start == arr.size()) return 0;

    unordered_set<int> required;

    required.insert(start);

    int i = start;
    int m = start;
    while (!required.empty()) {
      int x = arr[i];
      if (required.find(x) != required.end()) {
        required.erase(x);
      } else {
        for (int j = m + 1; j < x; j++) {
          required.insert(j);
        }
        m = x;
      }
      i++;
    }

    return 1 + maxChunksToSorted(arr, i);
  }
};
