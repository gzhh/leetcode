// Source : https://leetcode.com/problems/add-two-numbers
// Author : Zhonghuan Gao
// Date   : 2018-08-22

/**********************************************************************************
**
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
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
     * 思路：建立一个新链表，然后把输入的两个链表从头往后遍历，每两个相加，添加一个新节点到新链表后面，注意需要处理进位问题。
     * 还有就是最高位的进位问题要最后特殊处理一下。时间复杂度O(n)
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = new ListNode(-1);
        ListNode *cur = l3;
        
        int carry = 0, n1, n2, val;
        while (l1 || l2) {
            n1 = l1 ? l1->val : 0;
            n2 = l2 ? l2->val : 0;
            val = n1 + n2 + carry;
            if (val > 9) {
                val -= 10; carry = 1;
            } else {
                carry = 0;
            }
            cur->next = new ListNode(val);
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry) cur->next = new ListNode(1);
        return l3->next;
    }
};
