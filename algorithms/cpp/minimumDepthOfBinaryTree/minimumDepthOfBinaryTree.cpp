// Source : https://leetcode.com/problems/minimum-depth-of-binary-tree/
// Author : Zhonghuan Gao
// Date   : 2019-05-30

/********************************************************************************** 
*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.
*
*********************************************************************************/

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
     * 解法一：
     * 求二叉树的最小深度，即路径+1
     * 从 root 开始逐渐 DFS 遍历每个节点，当节点为空时，直接返回 0，
     * 当节点的左子子节点为空时，那么就对节点的右子节点求深度；
     * 反之当节点的右子节点为空时，那么就对节点的左子节点求深度。
     * 最后返回左右子节点较小的那个值+1
     */
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left) return 1 + minDepth(root->right);
        if (!root->right) return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
