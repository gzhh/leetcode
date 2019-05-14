// Source : https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Author : Zhonghuan Gao
// Date   : 2019-05-14

/********************************************************************************** 
*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
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
     * 解法一：递归
     */
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);
        return (lDepth > rDepth ? lDepth : rDepth) + 1;
    }

    /**
     * 解法二：先层次遍历二叉树，计算总层数，即为二叉树的深度
     */
};
