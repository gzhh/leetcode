// Source : https://leetcode.com/problems/longest-increasing-subsequence/
// Author : Zhonghuan Gao
// Date   : 2019-04-19

/**********************************************************************************
*
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
*
**********************************************************************************/

class Solution {
public:
    /**
     * 思路: 动态规划
     * 对于长度为N的数组A[N] = {a0, a1, a2, ..., an-1}，假设假设我们想求以aj结尾的最大递增子序列长度，
     * 设为L[j]，那么L[j] = max(L[i]) + 1, where i < j && a[i] < a[j], 也就是i的范围是0到j - 1。
     * 这样，想求aj结尾的最大递增子序列的长度，我们就需要遍历j之前的所有位置i（0到j-1），找出a[i] < a[j]，
     * 计算这些i中，能产生最大L[i]的i，之后就可以求出L[j]。之后我对每一个A[N]中的元素都计算以他们各自
     * 结尾的最大递增子序列的长度，这些长度的最大值，就是我们要求的问题——数组A的最大递增子序列。
     */
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int dp[n], maxLen = 1;
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};
