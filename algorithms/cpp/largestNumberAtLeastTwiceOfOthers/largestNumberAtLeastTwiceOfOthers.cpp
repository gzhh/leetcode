// Source : https://leetcode.com/problems/largest-number-at-least-twice-of-others/
// Author : Zhonghuan Gao
// Date   : 2019-10-21

/********************************************************************************** 
*
In a given integer array nums, there is always exactly one largest element.
Find whether the largest element in the array is at least twice as much as every other number in the array.
If it is, return the index of the largest element, otherwise return -1.

Example 1:
Input: nums = [3, 6, 1, 0]
Output: 1
Explanation: 6 is the largest integer, and for every other number in the array x,
6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.

Example 2:
Input: nums = [1, 2, 3, 4]
Output: -1
Explanation: 4 isn't at least as big as twice the value of 3, so we return -1.
 
Note:
nums will have a length in the range [1, 50].
Every nums[i] will be an integer in the range [0, 99].
*               
***********************************************************************************/

/**
 * 题意：
 * 给一个整数数组，求数组中最大那个数是否大于任何其他数的两倍，如果大于返回最大数的索引，否则返回-1
 */
class Solution {
public:
    /**
     * 解法一：
     * 计算出第一大数和第二大数，判断是否第一大数是否大于或等于第二大数的两倍
     * 若返回第一大数的索引，否则返回-1
     */
    int dominantIndex(vector<int>& nums) {
        int n = nums.size(), max = INT_MIN, secondMax = INT_MIN, maxInd = 0;
        if (n == 1) return 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > max) {
                secondMax = max;
                max = nums[i];
                maxInd = i;
            } else if (nums[i] > secondMax) {
                secondMax = nums[i];
            }
        }
        return (max - secondMax >= secondMax) ? maxInd : -1;
    }
};
