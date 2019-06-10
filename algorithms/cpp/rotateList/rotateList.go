// Source : https://leetcode.com/problems/rotate-list/
// Author : Zhonghuan Gao
// Date   : 2019-06-10

/********************************************************************************** 
** 
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
**
************************************************************************************/

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
     * 思路：先求链表的长度，然后把表头和表尾连接起来，
     * 再往后走 len - k / len 个节点就得到新链表的头节点，并断开链表
     */
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;

        ListNode *cur = head;
        int len = 1;
        while (cur->next) {
            cur = cur->next;
            len++;
        }
        cur->next = head;

        int len1 = len - k % len;
        for (int i = 0; i < len1; i++)
            cur = cur->next;
        ListNode *res = cur->next;
        cur->next = NULL;

        return res;
    }
};
