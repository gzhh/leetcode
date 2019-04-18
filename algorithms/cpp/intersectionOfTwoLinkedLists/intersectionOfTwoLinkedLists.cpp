// Source : https://leetcode.com/problems/intersection-of-two-linked-lists/
// Author : Zhonghuan Gao
// Date   : 2019-04-18

/********************************************************************************** 
*
Write a program to find the node at which the intersection of two singly linked lists begins.

Example 1:
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
Output: Reference of the node with value = 8
Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,0,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.

Example 2:
Input: intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Reference of the node with value = 2
Input Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [0,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.

Example 3:
Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: null
Input Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.


Notes:
If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
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
    /** 思路：先求两个链表的长度，将长度更长的链表头指针向后移动|lenA - lenB|位
     * 然后两个链表同时开始向后遍历，直至任意一个链表到头或两个链表的当前节点相等就停止
     * 判断当前两个节点是否相等
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;

        int lenA = getLen(headA), lenB = getLen(headB);
        if (lenA < lenB) {
            for (int i = 0; i < lenB - lenA; i++)
                headB = headB->next;
        } else {
            for (int i = 0; i < lenA - lenB; i++)
                headA = headA->next;
        }

        while (headA && headB && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA && headB ? headA : NULL;
    }

    int getLen(ListNode *head) {
        int len = 0;
        while (head->next) {
            head = head->next;
            len++;
        }
        return len;
    }
};
