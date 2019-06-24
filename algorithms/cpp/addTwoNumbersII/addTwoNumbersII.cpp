// Source : https://leetcode.com/problems/add-two-numbers-ii/
// Author : Zhonghuan Gao
// Date   : 2019-06-24

/********************************************************************************** 
*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
*               
***********************************************************************************/

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
     * 利用栈来一次存储单链表中元素的值，当取出元素值时，就相当于两个数
     * 从末位开始相加，最后考虑进位即可。
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2, s3;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0, sum;
        while (!s1.empty() && !s2.empty()) {
            sum = s1.top() + s2.top() + carry;
            if (sum >= 10) {
                carry = 1;
                sum -= 10;
            } else {
                carry = 0;
            }
            s1.pop();
            s2.pop();
            s3.push(sum);
        }

        if (s1.empty() && s2.empty()) {
            if (carry) s3.push(1);
        } else if (s1.empty()) {
            while (!s2.empty()) {
                sum = s2.top() + carry;
                if (sum >= 10) {
                    carry = 1;
                    sum -= 10;
                } else {
                    carry = 0;
                }
                s3.push(sum);
                s2.pop();
            }
            if (carry) s3.push(1);
        } else {
            while (!s1.empty()) {
                sum = s1.top() + carry;
                if (sum >= 10) {
                    carry = 1;
                    sum -= 10;
                } else {
                    carry = 0;
                }
                s3.push(sum);
                s1.pop();
            }
            if (carry) s3.push(1);
        }

        ListNode *dummy = new ListNode(-1);
        ListNode *head = dummy;
        while (!s3.empty()) {
            ListNode *node  = new ListNode(0);
            node->val = s3.top();
            head->next = node;
            head = head->next;
            s3.pop();
        }
        head->next = NULL;

        return dummy->next;
    }

    /**
     * 解法一优化
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int sum = 0;
        ListNode *res = new ListNode(0);
        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) {sum += s1.top(); s1.pop();}
            if (!s2.empty()) {sum += s2.top(); s2.pop();}
            res->val = sum % 10;
            ListNode *head = new ListNode(sum / 10);
            head->next = res;
            res = head;
            sum /= 10;
        }
        return res->val == 0 ? res->next : res;
    }
};
