// Source : https://leetcode.com/problems/binary-tree-postorder-traversal/
// Author : Zhonghuan Gao
// Date   : 2019-11-24

/********************************************************************************** 
*
Given a binary tree, return the postorder traversal of its nodes' values.

Example:
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]

Follow up: Recursive solution is trivial, could you do it iteratively?
*               
***********************************************************************************/

/**
 * 题意：
 * 求一个二叉树的后序遍历
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
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        res.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        rec(root);
        return res;
    }
};

/**
 * 解法二：迭代
 * 0.由于后序遍历的顺序是左右根，可以基于先序遍历的根左右做些小改动，
 * 使其遍历顺序变成根右左，我们再反向加入节点值到结果res，最后就可以
 * 得到左右根遍历得出节点值的顺序
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while (!s.empty() || p) {
            if (p) {
                s.push(p);
                res.insert(res.begin(), p->val);
                p = p->right;
            } else {
                TreeNode *t = s.top(); s.pop();
                p = t->left;
            }
        }
        return res;
    }
};

