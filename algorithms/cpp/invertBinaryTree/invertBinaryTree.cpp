// Source : https://leetcode.com/problems/invert-binary-tree/
// Author : Zhonghuan Gao
// Date   : 2019-11-04

/********************************************************************************** 
*
Invert a binary tree.
Example:
Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9

Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1

Trivia:
This problem was inspired by this original tweet by Max Howell:
Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.
*               
***********************************************************************************/

/**
 * 题意：
 * 翻转二叉树
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
/**
 * 解法一：
 * 递归法
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        TreeNode *tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);
        return root;
    }
};

/**
 * 解法二：
 * 迭代法
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *cur = q.front(); q.pop();
            TreeNode *tmp = cur->left;
            cur->left = cur->right;
            cur->right = tmp;
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        return root;
    }
};
