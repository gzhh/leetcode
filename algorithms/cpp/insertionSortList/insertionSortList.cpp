// Source : https://leetcode.com/problems/insertion-sort-list/
// Author : Zhonghuan Gao
// Date   : 2019-06-17

/**********************************************************************************
**
Sort a linked list using insertion sort.


A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list


Algorithm of Insertion Sort:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
It repeats until no input elements remain.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
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
     * 解法一：
     * 链表的插入排序：就是一个元素一个元素的从原链表中取出来，然后按顺序插入到新链表中
     */
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        while (head) {
            while (cur->next && cur->next->val <= head->val) {
                cur = cur->next;
            }
            ListNode *p = head->next;
            head->next = cur->next;
            cur->next = head;
            head = p;
            cur = dummy;
        }
        return dummy->next;
    }
};
