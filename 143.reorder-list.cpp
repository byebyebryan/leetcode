/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 *
 * https://leetcode.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (30.21%)
 * Total Accepted:    147.5K
 * Total Submissions: 488.3K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 *
 * Example 1:
 *
 *
 * Given 1->2->3->4, reorder it to 1->4->2->3.
 *
 * Example 2:
 *
 *
 * Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
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
  void reorderList(ListNode* head) {
    if (!head) return;
    if (!head->next) return;
    if (!head->next->next) return;

    ListNode* p1 = head;
    ListNode* p2 = head;

    while (p2->next && p2->next->next) {
      p1 = p1->next;
      p2 = p2->next->next;
    }

    if (!p2->next) {
      p2 = p1->next;
      p1->next = nullptr;
    } else if (!p2->next->next) {
      p2 = p1->next->next;
      p1->next->next = nullptr;
    }

    p2 = reverse(p2);
    p1 = head;

    while (p2) {
      ListNode* p1_next = p1->next;
      ListNode* p2_next = p2->next;
      p1->next = p2;
      p2->next = p1_next;
      p1 = p1_next;
      p2 = p2_next;
    }
  }

  // 1->2->3
  //

  ListNode* reverse(ListNode* head) {
    ListNode* p = head;
    ListNode* prev = nullptr;

    while (p) {
      ListNode* p_next = p->next;
      p->next = prev;
      prev = p;
      p = p_next;
    }

    return prev;
  }
};
