// Source : https://leetcode.com/problems/single-number/
// Author : Zhonghuan Gao
// Date   : 2019-04-15

/********************************************************************************** 
**
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
** 
***********************************************************************************/

class Solution {
public:
    /**
     * 思考：位操作
     * i XOR 0 = i, i XOR i = 0
     */
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0, n = nums.size(); i < n; i++) {
            res ^= nums[i];
        }
        return res;
    }
};
