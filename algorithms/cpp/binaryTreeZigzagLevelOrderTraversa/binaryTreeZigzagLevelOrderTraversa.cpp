// Source : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Author : Zhonghuan Gao
// Date   : 2019-11-17

/********************************************************************************** 
*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*               
***********************************************************************************/

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
 * 题意：
 * 给一个二叉树，按层级返回每个节点的值，结果是二维数组
 * 解法一：
 * 递归法
 */
class Solution {
public:
    vector<vector<int>> v;

    void buildVector(TreeNode* root, int depth) {
        if (!root) return;
        if (v.size() == depth) v.push_back(vector<int> {});
        if (depth % 2 == 0) {
            v[depth].push_back(root->val);
        } else {
            v[depth].insert(v[depth].begin(), root->val);
        }
        buildVector(root->left, depth + 1);
        buildVector(root->right, depth + 1);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        buildVector(root, 0);
        return v;
    }
};

/**
 * 解法二：
 * BFS
 */
class Solution {
public:
    /**
     * 建立一个 queue，先把根节点放进去，当 queue 不为空时一直循环，循环内新建一个 vector，把跟节点的值放进去，
     * 用一个变量来计数当前树的 level，若为奇数则往内部数组插入元素是从 vector 头部插入，偶数则相反。
     * 然后找根节点的左右两个子节点，放入 queue 中，并去掉根节点，此时 queue 里的元素就是下一层的所有节点，
     * 用一个 for 循环遍历它们，然后存到上面新建的 vector 里，遍历完之后再把这个 vector 存到全局二维 vector 里，
     * 以此类推，可以完成层序遍历
     */
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q{{root}};
        int cnt = 0;
        while (!q.empty()) {
            vector<int> curLevel;
            for (int i = q.size(); i > 0; i--) {
                TreeNode *t = q.front(); q.pop();
                if (cnt % 2 == 0) {
                    curLevel.push_back(t->val);
                } else {
                    curLevel.insert(curLevel.begin(), t->val);
                }
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res.push_back(curLevel);
            cnt++;
        }
        return res;
    }
};
