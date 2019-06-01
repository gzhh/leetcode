// Source : https://leetcode.com/problems/leaf-similar-trees/
// Author : Zhonghuan Gao
// Date   : 2019-06-01

/********************************************************************************** 
*
Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.



For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 

Note:

Both of the given trees will have between 1 and 100 nodes.
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
     * 解法一：
     * 求两个树的叶子所有节点是否相等
     * 思路：先序遍历树，将树的叶子节点存入数组，判断两个数组是否相等
     */
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1, leaf2;
        getLeafNodes(root1, leaf1);
        getLeafNodes(root2, leaf2);
        return leaf1 == leaf2;
    }
    void getLeafNodes(TreeNode* node, vector<int>& leaf) {
        if (!node) return;
        if (!node->left && !node->right) leaf.push_back(node->val);
        getLeafNodes(node->left, leaf);
        getLeafNodes(node->right, leaf);
    }
};
