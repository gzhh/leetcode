// Source : https://leetcode.com/problems/merge-two-sorted-lists/
// Author : Zhonghuan Gao
// Date   : 2018-08-13

/**********************************************************************************
*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*
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
    /*
     * 解法一：按顺序不断取两个链表表头中较小的结点放入新的链表中，看哪个链表还有剩余，将剩下的部分加到新链表的后面。
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
            p->next = NULL;
        }
        if (l1 != NULL)
            p->next = l1;
        if (l2 != NULL)
            p->next = l2;
        return head->next;
    }

    /*
     * 解法二：递归, 自己调用自己，分析此题的特点满足：函数输出可以作为输入，进而更新输入，直到两个链表都为空。
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }
};
