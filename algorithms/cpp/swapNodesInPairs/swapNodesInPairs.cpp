// Source : https://leetcode.com/problems/swap-nodes-in-pairs/
// Author : Zhonghuan Gao
// Date   : 2019-04-23

/********************************************************************************** 
*
Given a linked list, swap every two adjacent nodes and return its head.
You may not modify the values in the list's nodes, only nodes itself may be changed.

Example:
Given 1->2->3->4, you should return the list as 2->1->4->3.
*               
**********************************************************************************/

class Solution {
public:
    /**
     * 思路：递归遍历到链表末尾，然后先交换末尾两个，然后回溯依次往前交换
     */
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *newHead = head->next;
        head->next = swapPairs(head->next->next);
        newHead->next = head;
        return newHead;
    }
};
