// Source : https://leetcode.com/problems/linked-list-components/
// Author : Zhonghuan Gao
// Date   : 2019-06-28

/********************************************************************************** 
*
We are given head, the head node of a linked list containing unique integer values.

We are also given the list G, a subset of the values in the linked list.

Return the number of connected components in G, where two values are connected if they appear consecutively in the linked list.

Example 1:

Input: 
head: 0->1->2->3
G = [0, 1, 3]
Output: 2
Explanation: 
0 and 1 are connected, so [0, 1] and [3] are the two connected components.
Example 2:

Input: 
head: 0->1->2->3->4
G = [0, 3, 1, 4]
Output: 2
Explanation: 
0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] are the two connected components.
Note:

If N is the length of the linked list given by head, 1 <= N <= 10000.
The value of each node in the linked list will be in the range [0, N - 1].
1 <= G.length <= 10000.
G is a subset of all values in the linked list.

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
     * 求有多少个相连的子链表
     * 解法一：
     * 将链表所有值的子集放入hashset，遍历链表，如果当前节点的值在hashset中存在，
     * 并且当前节点的next节点为空或当前节点的next节点值不在hashset中，那么增加
     * 一个子链表，继续遍历完。
     */
    int numComponents(ListNode* head, vector<int>& G) {
        int sum = 0;
        set<int> s(G.begin(), G.end());

        while (head) {
            if (s.count(head->val) && (!head->next || !s.count(head->next->val))) {
                sum++;
            }
            head = head->next;
        }

        return sum;
    }
};
