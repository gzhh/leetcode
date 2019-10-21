// Source : https://leetcode.com/problems/find-pivot-index/
// Author : Zhonghuan Gao
// Date   : 2019-10-21

/********************************************************************************** 
*
Given an array of integers nums, write a method that returns the "pivot" index of this array.
We define the pivot index as the index where the sum of the numbers to the left of the index is equal to the sum of the numbers to the right of the index.
If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.

Example 1:
Input: 
nums = [1, 7, 3, 6, 5, 6]
Output: 3
Explanation: 
The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of index 3.
Also, 3 is the first index where this occurs.

Example 2:
Input: 
nums = [1, 2, 3]
Output: -1
Explanation: 
There is no index that satisfies the conditions in the problem statement.
 
Note:
The length of nums will be in the range [0, 10000].
Each element nums[i] will be an integer in the range [-1000, 1000].
*               
***********************************************************************************/

/**
 * 题意：
 * 给定一个整数类型的数组 nums，请编写一个能够返回数组“中心索引”的方法。
 * 我们是这样定义数组中心索引的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。
 * 如果数组不存在中心索引，那么我们应该返回 -1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。
 */
class Solution {
public:
    /**
     * 解法一：
     * 先求数组的和sum，然后遍历数组并维护一个当前数组之和curSum，
     * 当sum减去当前数恰好是curSum的两倍时，那么当前数即为pivot数
     */
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size(), curSum = 0;
        for (int i = 0; i < n; i++) {
            if (sum - nums[i] == 2 * curSum) return i;
            curSum += nums[i];
        }
        return -1;
    }
};
