// Source : https://leetcode.com/problems/binary-tree-path/
// Author : Zhonghuan Gao
// Date   : 2019-05-31

/********************************************************************************** 
*
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
     * 解法一：递归回溯
     * 求二叉树中根节点到所有叶子节点的路径
     * 思路：当递归遇到叶子节点时，即没有左右子节点时，那么就可以得到一条路径；
     * 把之前的节点路径加上当前的节点并 push 到 res 数组中，然后回溯。
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root) findPath(root, "", res);
        return res;
    }

    void findPath(TreeNode* node, string path, vector<string> &res) {
        if (!node->left && !node->right) res.push_back(path + to_string(node->val));
        if (node->left) findPath(node->left, path + to_string(node->val) + "->", res);
        if (node->right) findPath(node->right, path + to_string(node->val) + "->", res);
    }
};
