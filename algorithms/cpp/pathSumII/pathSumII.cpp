// Source : https://leetcode.com/problems/path-sum-ii/
// Author : Zhonghuan Gao
// Date   : 2019-05-25

/********************************************************************************** 
*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
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
     * 解法一：DFS and BackTracking
     * 思路：和 Path Sum 这题基本思路一致，只需额外记录当前路径的节点到一个一维vector中，
     * 每次遍历到叶子节点判断这个vector中元素值的和是否等于sum，如果等于，就将一维vector
     * 放进二维vector。另每次回溯的时候，删除一维vector尾部一个元素
     */
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> cur;
        findPath(root, sum, res, cur);
        return res;
    }
    
    void findPath(TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& cur) {
        if (!root) return;
        cur.push_back(root->val);
        if (!root->left && !root->right && root->val == sum)
            res.push_back(cur);
        
        findPath(root->left, sum - root->val, res, cur);
        findPath(root->right, sum - root->val, res, cur);
        cur.pop_back();
    }
};
