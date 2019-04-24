/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (30.79%)
 * Total Accepted:    831.3K
 * Total Submissions: 2.7M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Example:
 *
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 *
 *
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, bool carry = false) {
    if (!l1 && !l2) {
      return carry ? new ListNode(1) : nullptr;
    } else if (!l1 || !l2) {
      ListNode* p = l1 ? l1 : l2;
      if (!carry) return p;
      p->val = p->val + 1;
      carry = p->val / 10;
      p->val %= 10;
      p->next = addTwoNumbers(p->next, nullptr, carry);
      return p;
    }

    int val = l1->val + l2->val + (carry ? 1 : 0);
    carry = val / 10;
    val %= 10;
    ListNode* next = addTwoNumbers(l1->next, l2->next, carry);
    l1->val = val;
    l1->next = next;
    return l1;
  }
};
