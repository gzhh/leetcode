// Source : https://leetcode.com/problems/reverse-nodes-in-k-group/
// Author : Zhonghuan Gao
// Date   : 2019-07-29

/********************************************************************************** 
*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5

Note:
Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
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
    /**
     * 解法一：
     * 首先计算出链表长度，然后遍历链表，依次反转长度为 k 的子链表
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) return head;
        ListNode *dummy = new ListNode(-1), *pre = dummy, *cur = pre, *tmp;
        dummy->next = head;
        int num = 0;
        while (cur = cur->next) num++;
        while (num >= k) {
            cur = pre->next;
            for (int i = 1; i < k; i++) {
                tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = pre->next;
                pre->next = tmp;
            }
            pre = cur;
            num -= k;
        }
        return dummy->next;
    }
};
