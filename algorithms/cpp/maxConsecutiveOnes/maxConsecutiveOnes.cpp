// Source : https://leetcode.com/problems/max-consecutive-ones/
// Author : Zhonghuan Gao
// Date   : 2019-10-15

/********************************************************************************** 
*
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.

Note:
The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
*               
***********************************************************************************/

/**
 * 题意：给你一个只包含0和1的数组，求最大连续1的个数
 */
class Solution {
public:
    /**
     * 解法一：
     */
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(), res, cnt = 1;
        if (n > 0 && nums[0] == 0) res = 0;
        else res = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == 1) {
                if (nums[i] == nums[i-1]) {
                    cnt++;
                } else {
                    cnt = 1;
                }
                res = max(res, cnt);
            }
        }
        return res;
    }

    /**
     * 解法一的优化
     */
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, cnt = 0;
        for (int num : nums) {
            cnt = (num == 0) ? 0 : cnt + 1;
            res = max(res, cnt);
        }
        return res;
    }
};
