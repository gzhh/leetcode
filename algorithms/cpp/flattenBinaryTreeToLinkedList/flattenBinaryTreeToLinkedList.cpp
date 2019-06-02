// Source : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Author : Zhonghuan Gao
// Date   : 2019-06-02

/********************************************************************************** 
*
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
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
     * 解法一：DFS
     * 思路：先找到最左子节点，然后回到其父节点，把其父节点和右子节点断开，
     * 将原左子结点连上父节点的右子节点上，然后再把原右子节点连到新右子节点的右子节点上，
     * 然后再回到上一父节点做相同操作。
     */
    void flatten(TreeNode* root) {
        if (!root) return;
        if (root->left) flatten(root->left);
        if (root->right) flatten(root->right);
        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = NULL;
        while (root->right) root = root->right;
        root->right = tmp;
    }
};
