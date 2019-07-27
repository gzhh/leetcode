// Source : https://leetcode.com/problems/merge-k-sorted-lists/
// Author : Zhonghuan Gao
// Date   : 2019-07-26

/**********************************************************************************
*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
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

/**
 * 解法一：最小堆
 * 思路：利用最小堆的特性，先把 K 个链表的首元素都加入最小堆中，最小堆会自动按照
 * 相应的比较贵州来把各个节点排好序。然后我们从最小堆中每次取出最小的元素，加入
 * 到新的链表中，直到堆中没有元素，最后返回新链表的首节点。
 */
class Compare {
public:
    bool operator()(ListNode* p1, ListNode* p2) {
        return p1->val > p2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare > que;

        int k = lists.size();
        for (int i = 0; i < k; ++i) {
            if (lists[i] != NULL)
                que.push(lists[i]);
        }

        ListNode* pHead = new ListNode(-1);
        ListNode* pCur = pHead;

        while (!que.empty()) {
            ListNode *tmp = que.top();
            que.pop();

            pCur->next = tmp;
            pCur = pCur->next;

            if (tmp->next != NULL) {
                que.push(tmp->next);
            }
        }
        pCur = pHead->next;
        delete pHead;

        return pCur;
    }
};
