// Source : https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
// Author : Zhonghuan Gao
// Date   : 2019-05-27

/********************************************************************************** 
*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * 解法一：二分法
     * 思考：将有序链表转换为二叉搜索树，和上面一题类似，不过上一题是有序数组，而这题是有序链表。
     * 数组可以直接通过索引来找到中间点，而链表则需要借助快慢指针来找中间点。
     */
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        return convert(head, NULL);
    }

    TreeNode* convert(ListNode* head, ListNode* tail) {
        if (head == tail) return NULL;

        ListNode *slow = head, *fast = head;
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *cur = new TreeNode(slow->val);

        cur->left = convert(head, slow);
        cur->right = convert(slow->next, tail);
        return cur;
    }
};
