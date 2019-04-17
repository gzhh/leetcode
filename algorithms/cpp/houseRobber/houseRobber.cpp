// Source : https://leetcode.com/problems/house-robber/
// Author : Zhonghuan Gao
// Date   : 2019-04-17

/********************************************************************************** 
*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
*               
**********************************************************************************/

class Solution {
public:
    /**
     * 思路: 动态规划思想
     * 拿一个简单例子[1,2,3,1]，很容易可以看出dp[0] = nums[0] = 1, dp[1] = max(nums[0], nums[1]);
     * 又因为相邻的值不能相加，所以当i=2时，可以让当前值nums[i]与前一个不相邻dp值dp[i-2]的和，
     * 同前一个dp值dp[i-1]相比较，当前dp值dp[i]即为两者相比较大的，即 dp[2] = max(nums[2] + dp[0], dp[1]);
     * 故而可以得出动态规划状态转移方程为: dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
     */
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return nums.empty() ? 0 : nums[0];
        vector<int> dp = {nums[0], max(nums[0], nums[1])};
        for (int i = 2; i < n; i++) {
            dp.push_back(max(nums[i] + dp[i-2], dp[i-1]));
        }   
        return dp.back();
    }  
};
