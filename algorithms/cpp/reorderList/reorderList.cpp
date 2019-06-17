// Source : https://leetcode.com/problems/reorder-list/
// Author : Zhonghuan Gao
// Date   : 2019-06-17

/**********************************************************************************
**
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
**
**********************************************************************************/

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
        if (!head || !head->next || !head->next->next) return;

        // 快慢指针找中点 (On)
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 按中点前后分割链表，并反转后链表半部分
        ListNode *mid = slow->next;
        slow->next = NULL;
        
        stack<ListNode*> s;
        while (mid) {
            s.push(mid);
            mid = mid->next;
        }
       
        // 将后链表半部分插入前半部分
        while (head && s.size()) {
            ListNode *next = head->next;
            head->next = s.top();
            s.pop();
            head->next->next = next;
            head = next;
        }
    }
};
