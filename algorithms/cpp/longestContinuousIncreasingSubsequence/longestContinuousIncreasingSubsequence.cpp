// Source : https://leetcode.com/problems/longest-continuous-increasing-subsequence/
// Author : Zhonghuan Gao
// Date   : 2019-04-09

/********************************************************************************** 
** 
Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).

Example 1:
Input: [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3.
Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4.
Example 2:
Input: [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2], its length is 1.
Note: Length of the array will not exceed 10,000.
** 
***********************************************************************************/

class Solution {
public:
    /**
     * 贪心法: 遍历数组，若当前元素大于上一个元素，则count+1(当前子连续递增元素的个数)，并与当前最大的连续递增元素的个数相比，保留较大的
     * 若小于等于，则count重新赋值为1，继续向后遍历
     */
    int findLengthOfLCIS(vector<int>& nums) {
        int count = 0, res = 0;
        for (int i = 0, n = nums.size(); i < n; i++) {
            if (i == 0 || nums[i] > nums[i-1]) res = max(res, ++count);
            else count = 1;
        }
        return res;
    }
};
