/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 *
 * https://leetcode.com/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (32.95%)
 * Total Accepted:    103K
 * Total Submissions: 312.1K
 * Testcase Example:  '"3+2*2"'
 *
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string contains only non-negative integers, +, -, *, /
 * operators and empty spaces  . The integer division should truncate toward
 * zero.
 * 
 * Example 1:
 * 
 * 
 * Input: "3+2*2"
 * Output: 7
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: " 3/2 "
 * Output: 1
 * 
 * Example 3:
 * 
 * 
 * Input: " 3+5 / 2 "
 * Output: 5
 * 
 * 
 * Note:
 * 
 * 
 * You may assume that the given expression is always valid.
 * Do not use the eval built-in library function.
 * 
 * 
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        vector<int> nums;
        vector<char> opts;

        int i=0;
        while(i < s.length()){
            if(s[i] == ' ') {
                i++;
                continue;
            }
            
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                opts.push_back(s[i]);
                i++;
                continue;
            }
            
            int n = 0;
            while(i < s.length()){
                int m = s[i] - '0';
                if(m >= 0 && m <= 9){
                    n = n*10 + m;
                    if(i == s.length()-1) nums.push_back(n);
                    i++;
                }
                else{
                    nums.push_back(n);
                    break;
                }
            }

        }

        if(nums.size() == 1) return nums[0];

        vector<int> nums2;
        vector<char> opts2;

        nums2.push_back(nums[0]);

        for(i =0; i<opts.size(); i++) {
            if(opts[i] == '*') {
                nums2[nums2.size()-1] *= nums[i+1];
            }
            else if(opts[i] == '/') {
                nums2[nums2.size()-1] /= nums[i+1];
            }
            else {
                nums2.push_back(nums[i+1]);
                opts2.push_back(opts[i]);
            }
        }

        int res = nums2[0];
        for(i = 0; i<opts2.size(); i++) {
            if(opts2[i] == '+') {
                res += nums2[i+1];
            }
            else if(opts2[i] == '-') {
                res -= nums2[i+1];
            }
        }

        return res;
    }
};
