// Source : https://leetcode.com/problems/remove-nth-node-from-end-of-list
// Author : Zhonghuan Gao
// Date   : 2018-08-24

/**********************************************************************************
**
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
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
    /**
     * 题意: 删除倒数第n个元素
     * 思路: 利用快慢指针,首先快指针先走n步,如果走到头,那么倒数第n个元素就是头元素;
     * 如果没有走到头,那么此时慢指针和快指针一起往前走,直到快指针走到头,此时慢指针
     * 的位置就是倒数第n个元素的位置了
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return NULL;
        ListNode *fast = head, *slow = head;
        
        for (int i = 0; i < n; ++i) fast = fast->next;
        
        // 1.删除头元素(特例)
        if (!fast) return head->next;
        
        // 2.删除倒数第n个元素(常例)
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        
        return head;
    }
};
