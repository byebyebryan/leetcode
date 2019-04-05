/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 *
 * https://leetcode.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (47.49%)
 * Total Accepted:    76.1K
 * Total Submissions: 160.3K
 * Testcase Example:  '2'
 *
 * Given a positive integer n, break it into the sum of at least two positive
 * integers and maximize the product of those integers. Return the maximum
 * product you can get.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: 2
 * Output: 1
 * Explanation: 2 = 1 + 1, 1 × 1 = 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 10
 * Output: 36
 * Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 * 
 * Note: You may assume that n is not less than 2 and not larger than 58.
 * 
 * 
 */

// 2 : 1 * 1
// 3 : 1 * 2
// 4 : 2 * 2
// 5 : 2 * 3
// 6 : 3 * 3
// 7 : 3 * 4
// 8 : 2 * 3 * 3 (2 * 6)(3 * 5)
// 9 : 3 * 3 * 3 (2 * 7)(3 * 6)(4 * 5)
// 10 : 3 * 3 * 4 (2 * 8)(3 * 7)
// 11 : 2 * 3 * 3 * 3 (2 * 9)(3 * 8)(4 * 7)(5 * 6)
// 12 : 

#include <algorithm>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        if(n == 4) return 4;
        if(n == 5) return 6;
        if(n == 6) return 9;

        return max(2 * integerBreak(n-2), 3 * integerBreak(n-3));
    }
};
