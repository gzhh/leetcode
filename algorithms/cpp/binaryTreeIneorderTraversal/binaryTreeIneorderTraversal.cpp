// Source : https://leetcode.com/problems/binary-tree-inorder-traversal/
// Author : Zhonghuan Gao
// Date   : 2019-11-03

/********************************************************************************** 
*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
*               
***********************************************************************************/

/**
 * 题意：
 * 求一个二叉树的中序遍历
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
 * 解法一：递归
 */
class Solution {
public:
    vector<int> res;

    void rec(TreeNode* root) {
        if (!root) return;
        rec(root->left);
        res.push_back(root->val);
        rec(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        rec(root);
        return res;
    }
};


/**
 * 解法二：迭代
 * 从根节点开始，先将根节点压入栈，然后再将其所有左子结点压入栈，然后取出栈顶节点，保存节点值，
 * 再将当前指针移到其右子节点上，若存在右子节点，则在下次循环时又可将其所有左子结点压入栈中。
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            p = s.top(); s.pop();
            res.push_back(p->val);
            p = p->right;
        }
        return res;
    }
};
