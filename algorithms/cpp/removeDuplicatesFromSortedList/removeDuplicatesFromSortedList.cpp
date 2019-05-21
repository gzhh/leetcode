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
    /**
     * 解法一
     */
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

    /**
     * 解法二：
     * 移除给定有序链表的重复项，那么我们可以遍历这个链表，每个结点和其后面的结点比较，
     * 如果结点值相同了，我们只要将前面结点的next指针跳过紧挨着的相同值的结点，指向后面一个结点。
     */
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head;
        while (cur && cur->next) {
            if (cur->val == cur->next->val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};
