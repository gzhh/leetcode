// Source : https://leetcode.com/problems/maximum-subarray/
// Author : Zhonghuan Gao
// Date   : 2019-03-15

/**********************************************************************************
*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*
**********************************************************************************/
class Solution {
/**
 * 思路: 使用DP，动态规划方程式 Max(i) = Max(i-1) + a[i]
 */
public:
    int maxSubArray(vector<int>& nums) {
        int curMax = 0, max = INT_MIN;
        for (int num : nums) {
            curMax = curMax > 0 ? (curMax + num) : num;
            if (curMax > max) max = curMax;
        }
        return max;
    }
};
