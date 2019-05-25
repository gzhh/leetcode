// Source : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Author : Zhonghuan Gao
// Date   : 2019-05-26

/********************************************************************************** 
*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
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
     * 解法一：二分法
     * 思考：将有序数组转换为二叉搜索树，按照BST概念，如果按中序遍历BST，则能得到
     * 一个有序数组。那么反过来可知BST的根节点即为有序数组的中间点，从中间点分开为
     * 左右两个有序数组，然后再分别从他们左右两个有序数组中找出对应的中间点，到这即
     * 可以得出看出二分思想。
     */
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convert(nums, 0, nums.size() - 1);
    }
    TreeNode* convert(vector<int>& nums, int left, int right) {
        if (left > right) return NULL;
        // int mid = left + (right - left) / 2;
        int mid = left + (right - left + 1)/2;
        TreeNode *cur = new TreeNode(nums[mid]);
        cur->left = convert(nums, left, mid - 1);
        cur->right = convert(nums, mid + 1, right);
        return cur;
    }
};
