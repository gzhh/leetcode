// Source : https://leetcode.com/problems/palindrome-linked-list/
// Author : Zhonghuan Gao
// Date   : 2019-04-18

/********************************************************************************** 
*
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
*               
**********************************************************************************/

class Solution {
public:
    /**
     * 思路：使用快慢指针找中点，并逐一将慢指针指向的val压栈，
     * 最后从中点开始向后遍历慢指针，并依次比较当前指针指向的val与栈顶元素是否相等，
     * 若相等则栈顶元素出栈，继续向后遍历，最后返回true；若不相等则返回false；
     */
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        
        ListNode *slow = head, *fast = head;
        stack<int> s;
        s.push(head->val);
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            s.push(slow->val);
        }
        
        if (!fast->next) s.pop();
        while (slow->next) {
            slow = slow->next;
            if (s.top() != slow->val) return false;
            s.pop();
        }
        return true;
    }
};
