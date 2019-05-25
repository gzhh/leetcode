// Source : https://leetcode.com/problems/symmetric-tree/
// Author : Zhonghuan Gao
// Date   : 2019-05-25

/********************************************************************************** 
*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
*
**********************************************************************************/

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
     * 思考：判断是否是平衡二叉树，假设有两个节点n1,n2，在判断n1左子节点的值和n2右子节点的值是否相同时，
     * 还需判断n1右子节点的值和n2左子节点的值是否相等，依次类推比较完所有子节点。
     */
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isSubSymmetric(root->left, root->right);
    }

    bool isSubSymmetric(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if ((left && !right) || (!left && right) || left->val != right->val) return false;
        return isSubSymmetric(left->left, right->right) && isSubSymmetric(left->right, right->left);
    }
};
