// Source : https://leetcode.com/problems/maximumProductOfThreeNumbers/
// Author : Zhonghuan Gao
// Date   : 2019-10-19

/********************************************************************************** 
*
Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:
Input: [1,2,3]
Output: 6
 
Example 2:
Input: [1,2,3,4]
Output: 24

Note:
The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
*               
***********************************************************************************/

/**
 * 题意：
 * 给你一个整数数组，求任意三个数相乘的最大值
 */
class Solution {
public:
    /**
     * 解法一：
     * 首先我们先将数组排序，然后我们列举几种负数存在的情况
     * 1.0和1个负数：可知结果为nums[n-1] * nums[n-2] * nums[n-3]
     * 2.>=2个负数：nums[n-1] * max(nums[0] * nums[1], nums[n-2] * nums[n-3])
     */
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (nums[1] >= 0) {
            return nums[n-1] * nums[n-2] * nums[n-3];
        }
        return nums[n-1] * max(nums[0] * nums[1], nums[n-2] * nums[n-3]);
    }
};
