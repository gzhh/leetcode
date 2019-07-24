// Source : https://leetcode.com/problems/next-greater-node-in-linked-list/
// Author : Zhonghuan Gao
// Date   : 2019-07-24

/**********************************************************************************
**
We are given a linked list with head as the first node.  Let's number the nodes in the list: node_1, node_2, node_3, ... etc.
Each node may have a next larger value: for node_i, next_larger(node_i) is the node_j.val such that j > i, node_j.val > node_i.val, and j is the smallest possible choice.  If such a j does not exist, the next larger value is 0.
Return an array of integers answer, where answer[i] = next_larger(node_{i+1}).
Note that in the example inputs (not outputs) below, arrays such as [2,1,5] represent the serialization of a linked list with a head node value of 2, second node value of 1, and third node value of 5.

Example 1:
Input: [2,1,5]
Output: [5,5,0]

Example 2:
Input: [2,7,4,3,5]
Output: [7,0,5,5,0]

Example 3:
Input: [1,7,5,1,9,2,5,1]
Output: [7,9,9,9,0,5,0,0]

Note:
1 <= node.val <= 10^9 for each node in the linked list.
The given list has length in the range [0, 10000].
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
     * 将链表各个节点的值存到数组中，然后遍历数组求各个值对应的next grater数
     */
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> v;
        ListNode *cur = head;
        while (cur) {
            v.push_back(cur->val);
            cur = cur->next;
        }

        vector<int> res;
        int len = v.size(), i, j;
        for (i = 0; i < len; i++) {
            int flag = false;
            for (j = i + 1; j < len; j++) {
                if (v[j] > v[i]) {
                    flag = true;
                    break;
                }
            }
            if (flag) res.push_back(v[j]);
            else res.push_back(0);
        }

        return res;
    }
};
