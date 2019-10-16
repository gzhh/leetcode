// Source : https://leetcode.com/problems/missing-number/
// Author : Zhonghuan Gao
// Date   : 2019-10-16

/********************************************************************************** 
*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:
Input: [3,0,1]
Output: 2

Example 2:
Input: [9,6,4,2,3,5,7,0,1]
Output: 8

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*               
***********************************************************************************/

/**
 * 题意：
 * 给你一个整数数组，求 0~len 缺少的整数
 */
class Solution {
public:
    /**
     * 解法一：
     * 将 1~len 的数累加起来的和减去 nums 数组累加起来的和即为缺少的数
     */
    int missingNumber(vector<int>& nums) {
        int sum1 = 0, len = nums.size();
        int sum2 = (len + 1) * len / 2;
        for (int n : nums) {
            sum1 += n;
        }
        return sum2 - sum1;
    }
};
