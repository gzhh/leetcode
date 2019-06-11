// Source : https://leetcode.com/problems/reverse-linked-list-ii/
// Author : Zhonghuan Gao
// Date   : 2019-06-12

/********************************************************************************** 
** 
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
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
     * 解法一：
     * 遍历链表，记录反转区间最左节点的前一个节点为pre，反转区间最左节点为cur，
     * 每次将cur下一个节点指向pre的next节点，并且调整相应指针，直到最右区间
     *
     * 例子：
     * 1 -> 2 -> 3 -> 4 -> 5 -> NULL
     * 1 -> 3 -> 2 -> 4 -> 5 -> NULL
     * 1 -> 4 -> 3 -> 2 -> 5 -> NULL
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy;
        for (int i = 0; i < m - 1; i++) pre = pre->next;
        ListNode *cur = pre->next;
        for (int i = m; i < n; i++) {
            ListNode *tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
        }
        return dummy->next;
    }
};
