// Source : https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
// Author : Zhonghuan Gao
// Date   : 2019-11-10

/********************************************************************************** 
*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*               
***********************************************************************************/

/**
 * 题意：
 * 求一个二叉树的层序遍历，按层返回每层节点的值
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
 * 解法一：BFS
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            vector<int> cur;
            for (int i = q.size(); i > 0; i--) {
                TreeNode *t = q.front(); q.pop();
                cur.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res.insert(res.begin(), cur);
        }
        return res;
    }
};

/**
 * 解法二：DFS
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        levelorder(root, 0, res);
        return vector<vector<int>> (res.rbegin(), res.rend());
    }

    void levelorder(TreeNode* node, int level, vector<vector<int>>& res) {
        if (!node) return;
        if (res.size() == level) res.push_back({});
        res[level].push_back(node->val);
        if (node->left) levelorder(node->left, level + 1, res);
        if (node->right) levelorder(node->right, level + 1, res);
    }
};
