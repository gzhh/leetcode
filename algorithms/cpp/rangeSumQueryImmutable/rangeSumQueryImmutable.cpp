// Source : https://leetcode.com/problems/range-sum-query-immutable/
// Author : Zhonghuan Gao
// Date   : 2019-10-23

/********************************************************************************** 
*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]
sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*               
***********************************************************************************/

/**
 * 题意：
 * 给你一个整数数组，在给你若干个坐标区间，求这些区间内的数组之和
 */

/**
 * 解法一：
 * 区间累加
 */
class NumArray {
public:
    vector<int> nums;

    NumArray(vector<int>& nums) {
        this->nums = nums;
    }

    int sumRange(int i, int j) {
        int sum = 0;
        return accumulate(this->nums.begin() + i, this->nums.begin() + j + 1, 0);
    }
};

/**
 * 解法二：动态规划
 * 假设 dp[i] 等于 0-i 直接数的和
 * 那么 i 到 j 之间数的和即等于 dp[j] - dp[i-1]，注意当 i == 0 时直接返回 dp[j]
 */
class NumArray {
private:
    vector<int> dp;
public:
    NumArray(vector<int> &nums) {
        dp = nums;
        for (int i = 1; i < nums.size(); i++) {
            dp[i] += dp[i - 1];
        }
    }
    int sumRange(int i, int j) {
        return i == 0 ? dp[j] : dp[j] - dp[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
