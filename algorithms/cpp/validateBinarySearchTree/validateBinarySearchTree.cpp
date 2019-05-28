// Source : https://leetcode.com/problems/validate-binary-search-tree/
// Author : Zhonghuan Gao
// Date   : 2019-05-28

/********************************************************************************** 
*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
*
***********************************************************************************/

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
     * 验证二叉搜索树
     * 解法一：用二叉搜索树本身的性质来做，即左<根<右
     * 初始化时带入系统最大值和最小值，在递归过程中换成它们自己的节点值
     * 这里用 long 代替 int 就是为了包括 int 的边界条件
     */
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }

    bool validate(TreeNode* root, long mn, long mx) {
        if (!root) return true;
        if (root->val <= mn || root->val >= mx) return false;
        return validate(root->left, mn, root->val) && validate(root->right, root->val, mx);
    }

    /**
     * 解法二：中序遍历解法
     * 中序遍历二叉树，并将各个节点的值存入一个数组，最后判断这个数组是否是排好序的
     */
};
