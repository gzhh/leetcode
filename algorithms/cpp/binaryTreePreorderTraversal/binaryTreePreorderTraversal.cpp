// Source : https://leetcode.com/problems/binary-tree-preorder-traversal/
// Author : Zhonghuan Gao
// Date   : 2019-11-02

/********************************************************************************** 
*
Given a binary tree, return the preorder traversal of its nodes' values.

Example:
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]

Follow up: Recursive solution is trivial, could you do it iteratively?
*               
***********************************************************************************/

/**
 * 题意：
 * 求一个二叉树的先序遍历
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
        if (root == NULL) return;
        res.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        rec(root);
        return res;
    }
};

/**
 * 解法二：迭代
 * 1.先把根节点push到栈中
 * 2.循环检测栈是否为空，若不空，则取出栈顶元素，保存其值，然后看其右子节点是否存在，
 * 若存在则push到栈中。再看其左子节点，若存在，则push到栈中。
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> s{{root}};
        while (!s.empty()) {
            TreeNode *t = s.top(); s.pop();
            res.push_back(t->val);
            if (t->right) s.push(t->right);
            if (t->left) s.push(t->left);
        }
        return res;
    }
};

