// Source : https://leetcode.com/problems/linked-list-cycle/description/                                                                                                                                            
// Author : Zhonghuan Gao
// Date   : 2018-08-08

/**********************************************************************************
**
Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
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
     * 1.Use two pointers, walker and runner.
     * 2.walker moves step by step. runner moves two steps at time.
     * 3.if the Linked List has a cycle walker and runner will meet at some point.
     */
    bool hasCycle(ListNode head) {
        if(head==null) return false;
        ListNode walker = head;
        ListNode runner = head;
        while(runner.next!=null && runner.next.next!=null) {
            walker = walker.next;
            runner = runner.next.next;
            if(walker==runner) return true;
        }   
        return false;
    }   

    // simplified
    bool hasCycle(ListNode *head) {
        ListNode *follow = head;
        while (head && head->next) {
            head = head->next->next;
            follow = follow->next;
            if (head == follow) return true;
        }   
        return false;
    }   
};

