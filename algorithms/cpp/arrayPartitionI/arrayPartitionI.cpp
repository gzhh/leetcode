// Source : https://leetcode.com/problems/array-partition-i/
// Author : Zhonghuan Gao
// Date   : 2019-10-15

/********************************************************************************** 
*
Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

Example 1:
Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).

Note:
n is a positive integer, which is in the range of [1, 10000].
All the integers in the array will be in the range of [-10000, 10000].
*               
***********************************************************************************/

/**
 * 题意：
 * 给你2n个数，把他们分成两两一对，求所有对数较小数的和的最小数。
 */
class Solution {
public:
    /**
     * 解法一：
     * 先从小到大排序，然后从索引0开始隔一个数累加
     */
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            res += nums[i];
        }
        return res;
    }
};
