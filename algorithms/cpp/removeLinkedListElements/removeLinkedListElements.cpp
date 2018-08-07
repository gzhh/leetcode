// Source : https://leetcode.com/problems/remove-linked-list-elements/description/
// Author : Zhonghuan Gao
// Date   : 2018-08-07

/**********************************************************************************
**
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val) {
       	if (head == NULL) return head;
        ListNode *newHead = new ListNode(0), *pre = newHead;
        newHead->next = head;
        while (pre && pre->next) {
            if (pre->next->val == val) {
                pre->next = pre->next->next;
            } else {
                pre = pre->next;
            }
        }
        return newHead->next;	 
    }
};
