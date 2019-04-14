/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (43.82%)
 * Total Accepted:    299.2K
 * Total Submissions: 680.2K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 *
 *
 *
 * Example:
 *
 *
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
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
  ListNode* swapPairs(ListNode* head) {
    if (!head) return head;
    if (!head->next) return head;

    ListNode* next2;
    if (head->next->next) {
      next2 = swapPairs(head->next->next);
    } else {
      next2 = nullptr;
    }

    ListNode* res = head->next;
    head->next->next = head;
    head->next = next2;

    return res;
  }
};
