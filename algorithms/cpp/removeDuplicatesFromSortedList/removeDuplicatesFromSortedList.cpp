// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
// Author : Zhonghuan Gao
// Date   : 2018-07-30

/**********************************************************************************
**
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
**
**********************************************************************************/



class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head;
        while (cur) {
            while (cur->next && cur->val == cur->next->val) {
                cur->next = cur->next->next; 
            }
            cur = cur->next;
        }
        return head;
    } 
};
